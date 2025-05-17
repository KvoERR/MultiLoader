#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include <nlohmann/json.hpp>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

System::String^ getTags(System::String^ name)
{
    try {
        std::string stdName = msclr::interop::marshal_as<std::string>(name);

        // Заменяем пробелы на %20
        std::replace(stdName.begin(), stdName.end(), ' ', '+');

        std::string request = "https://suggestqueries.google.com/complete/search?q=" + stdName + "&client=chrome&hl=ru&ds=yt";

        CURL* curl;
        CURLcode res;
        std::string readBuffer;

        curl = curl_easy_init();
        if (!curl) {
            throw gcnew System::Exception("Не удалось инициализировать CURL");
        }

        curl_easy_setopt(curl, CURLOPT_URL, request.c_str());
        curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::string error = "Ошибка CURL: ";
            error += curl_easy_strerror(res);
            curl_easy_cleanup(curl);
            throw gcnew System::Exception(gcnew System::String(error.c_str()));
        }
        std::cout << readBuffer;
        curl_easy_cleanup(curl);

        
        size_t count = 0;
        int i = 0;
        std::string alphabet = { '[',']','{','}','"' };

        for (char c : alphabet) {
            while ((readBuffer.find(c)) != std::string::npos) {
                readBuffer.replace(readBuffer.find(c), 1, "");
            }
        }
        readBuffer.replace(0, 1 + stdName.length(), "");
        while (count < 5) {
            if (i >= readBuffer.length()) {
                break; // Защита от выхода за границы
            }
            if (readBuffer[i] == ',') count++;
            i++;
        }

        readBuffer.replace(i, readBuffer.length() - i + 1, "");

        return msclr::interop::marshal_as<System::String^>(readBuffer);


        /*nlohmann::json j = nlohmann::json::parse(readBuffer);
        nlohmann::json suggestions = j[1];

        std::string result;
        for (const auto& item : suggestions) {
            result += item.get<std::string>() + ", ";
        }

        if (!result.empty()) {
            result.erase(result.length() - 2); // удалить последнюю ", "
        }

        return gcnew System::String(result.c_str());*/
    }
    catch (const std::exception& ex) {
        return "Ошибка: " + gcnew System::String(ex.what());
    }
}

