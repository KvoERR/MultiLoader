#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include <curl/curl.h>

using namespace System;
using namespace msclr::interop;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

String^ getTags(String^ name)
{
    try {
        // Конвертируем String^ в std::string
        std::string stdName = marshal_as<std::string>(name);

        // Заменяем пробелы на %20
        size_t start_pos = 0;
        while ((start_pos = stdName.find(" ")) != std::string::npos) {
            stdName.replace(start_pos, 1, "%20");
            start_pos += 3;
        }

        // Формируем URL запроса
        std::string request = "https://rapidtags.io/api/generator?query=" + stdName + "&type=YouTube";

        // Выполняем HTTP-запрос
        CURL* curl;
        CURLcode res;
        std::string readBuffer;
        curl = curl_easy_init();

        if (!curl) {
            throw gcnew System::Exception("Не удалось инициализировать соединение");
        }

        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);       // Включить проверку сертификата
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);       // Строгая проверка имени хоста
        //curl_easy_setopt(curl, CURLOPT_CAINFO, "/etc/ssl/certs/ca-certificates.crt"); // Путь к CA-сертификатам
        curl_easy_setopt(curl, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_2); // Только TLS 1.2+
        curl_easy_setopt(curl, CURLOPT_SSLCERTTYPE, "PEM");       // Формат сертификата
        //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_URL, request.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
        

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::string error = "Ошибка соединения: " + std::string(curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            throw gcnew System::Exception(gcnew String(error.c_str()));
        }

        curl_easy_cleanup(curl);



        // Обработка ответа
        readBuffer.replace(0, 21 + stdName.length(), "");
        size_t count = 0;
        int i = 0;
        std::string alphabet = { '[',']','{','}','"' };

        for (char c : alphabet) {
            while ((readBuffer.find(c)) != std::string::npos) {
                readBuffer.replace(readBuffer.find(c), 1, "");
            }
        }
        while (count < 5) {
            if (i >= readBuffer.length()) {
                break; // Защита от выхода за границы
            }
            if (readBuffer[i] == ',') count++;
            i++;
        }

        readBuffer.replace(i, readBuffer.length() - i + 1, "");

        return marshal_as<String^>(readBuffer);
    }
    catch (const std::exception& ex) {
        throw gcnew System::Exception(gcnew String(ex.what()));
    }
}