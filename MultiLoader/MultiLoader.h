#pragma once
#include "UIAuto.h"
#include "curlAuto.h"
#include "Resource.h"

namespace MultiLoader {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	public ref class MultiLoader : public System::Windows::Forms::Form
	{
	private:
		String^ file_link;
		String^ picture_link;
		String^ name;
		String^ description;

	public:
		MultiLoader(void)
		{
			file_link = "C:\\";
			picture_link = "default";
			name = "default";
			description = "default";
			InitializeComponent();
		}
		~MultiLoader()
		{
			if (components) delete components;
		}
	protected:
	private: System::Windows::Forms::TextBox^ tag_text;
	private: System::Windows::Forms::Button^ tag_button;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ ML_button;
	private: System::Windows::Forms::CheckBox^ checkBox_yt;
	private: System::Windows::Forms::CheckBox^ checkBox_ya;
	private: System::Windows::Forms::CheckBox^ checkBox_ru;
	private: System::Windows::Forms::CheckBox^ checkBox_vk;
	private: System::Windows::Forms::CheckBox^ checkBox_pl;
	private: System::Windows::Forms::TextBox^ name_text;
	private: System::Windows::Forms::TextBox^ description_text;
	private: System::Windows::Forms::Button^ allOnButton;
	private: System::Windows::Forms::Button^ allOffButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::TextBox^ file_text;
	private: System::Windows::Forms::Button^ file_button;
	private: System::Windows::Forms::Button^ picture_button;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MultiLoader::typeid));
			this->tag_button = (gcnew System::Windows::Forms::Button());
			this->tag_text = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_pl = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_vk = (gcnew System::Windows::Forms::CheckBox());
			this->picture_button = (gcnew System::Windows::Forms::Button());
			this->file_button = (gcnew System::Windows::Forms::Button());
			this->file_text = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox_ru = (gcnew System::Windows::Forms::CheckBox());
			this->allOffButton = (gcnew System::Windows::Forms::Button());
			this->allOnButton = (gcnew System::Windows::Forms::Button());
			this->description_text = (gcnew System::Windows::Forms::TextBox());
			this->name_text = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_ya = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_yt = (gcnew System::Windows::Forms::CheckBox());
			this->ML_button = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tag_button
			// 
			this->tag_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->tag_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tag_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->tag_button->Location = System::Drawing::Point(708, 515);
			this->tag_button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tag_button->Name = L"tag_button";
			this->tag_button->Size = System::Drawing::Size(140, 40);
			this->tag_button->TabIndex = 28;
			this->tag_button->Text = L"Авто-тэг";
			this->tag_button->UseVisualStyleBackColor = false;
			this->tag_button->Click += gcnew System::EventHandler(this, &MultiLoader::tag_button_Click);
			// 
			// tag_text
			// 
			this->tag_text->BackColor = System::Drawing::Color::NavajoWhite;
			this->tag_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tag_text->ForeColor = System::Drawing::SystemColors::GrayText;
			this->tag_text->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->tag_text->Location = System::Drawing::Point(855, 515);
			this->tag_text->MaxLength = 100;
			this->tag_text->Name = L"tag_text";
			this->tag_text->Size = System::Drawing::Size(736, 35);
			this->tag_text->TabIndex = 27;
			this->tag_text->Text = L"Тэги";
			this->tag_text->UseWaitCursor = true;
			this->tag_text->GotFocus += gcnew System::EventHandler(this, &MultiLoader::On_tag_text_GotFocus);
			this->tag_text->LostFocus += gcnew System::EventHandler(this, &MultiLoader::On_tag_text_LostFocus);
			// 
			// checkBox_pl
			// 
			this->checkBox_pl->AutoSize = true;
			this->checkBox_pl->BackColor = System::Drawing::SystemColors::Window;
			this->checkBox_pl->Checked = true;
			this->checkBox_pl->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_pl->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_pl->Location = System::Drawing::Point(150, 449);
			this->checkBox_pl->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_pl->Name = L"checkBox_pl";
			this->checkBox_pl->Size = System::Drawing::Size(166, 36);
			this->checkBox_pl->TabIndex = 26;
			this->checkBox_pl->Tag = L"checkBox";
			this->checkBox_pl->Text = L"Платформа";
			this->checkBox_pl->UseVisualStyleBackColor = false;
			// 
			// checkBox_vk
			// 
			this->checkBox_vk->AutoSize = true;
			this->checkBox_vk->BackColor = System::Drawing::SystemColors::Window;
			this->checkBox_vk->Checked = true;
			this->checkBox_vk->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_vk->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_vk->Location = System::Drawing::Point(150, 403);
			this->checkBox_vk->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_vk->Name = L"checkBox_vk";
			this->checkBox_vk->Size = System::Drawing::Size(152, 36);
			this->checkBox_vk->TabIndex = 25;
			this->checkBox_vk->Tag = L"checkBox";
			this->checkBox_vk->Text = L"VK Видео";
			this->checkBox_vk->UseVisualStyleBackColor = false;
			// 
			// picture_button
			// 
			this->picture_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->picture_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->picture_button->Location = System::Drawing::Point(708, 395);
			this->picture_button->Name = L"picture_button";
			this->picture_button->Size = System::Drawing::Size(250, 112);
			this->picture_button->TabIndex = 24;
			this->picture_button->Text = L"Вставьте изображение";
			this->picture_button->UseVisualStyleBackColor = false;
			this->picture_button->Click += gcnew System::EventHandler(this, &MultiLoader::picture_button_Click);
			// 
			// file_button
			// 
			this->file_button->Location = System::Drawing::Point(1554, 349);
			this->file_button->Name = L"file_button";
			this->file_button->Size = System::Drawing::Size(39, 40);
			this->file_button->TabIndex = 23;
			this->file_button->Text = L"...";
			this->file_button->UseVisualStyleBackColor = true;
			this->file_button->Click += gcnew System::EventHandler(this, &MultiLoader::file_button_Click);
			// 
			// file_text
			// 
			this->file_text->BackColor = System::Drawing::Color::NavajoWhite;
			this->file_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->file_text->Location = System::Drawing::Point(708, 349);
			this->file_text->Name = L"file_text";
			this->file_text->Size = System::Drawing::Size(838, 35);
			this->file_text->TabIndex = 22;
			this->file_text->Text = L"C:\\";
			this->file_text->TextChanged += gcnew System::EventHandler(this, &MultiLoader::file_text_TextChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->InitialDirectory = L"C:\\";
			this->openFileDialog1->Title = L"Выберите файл";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Window;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(705, 149);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(177, 37);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Информация";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Window;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(144, 149);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(161, 37);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Платформы";
			// 
			// checkBox_ru
			// 
			this->checkBox_ru->AutoSize = true;
			this->checkBox_ru->BackColor = System::Drawing::SystemColors::Window;
			this->checkBox_ru->Checked = true;
			this->checkBox_ru->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_ru->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_ru->Location = System::Drawing::Point(150, 357);
			this->checkBox_ru->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_ru->Name = L"checkBox_ru";
			this->checkBox_ru->Size = System::Drawing::Size(124, 36);
			this->checkBox_ru->TabIndex = 14;
			this->checkBox_ru->Tag = L"checkBox";
			this->checkBox_ru->Text = L"RuTube";
			this->checkBox_ru->UseVisualStyleBackColor = false;
			// 
			// allOffButton
			// 
			this->allOffButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->allOffButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->allOffButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->allOffButton->Location = System::Drawing::Point(314, 197);
			this->allOffButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->allOffButton->Name = L"allOffButton";
			this->allOffButton->Size = System::Drawing::Size(160, 52);
			this->allOffButton->TabIndex = 13;
			this->allOffButton->Text = L"Все выкл.";
			this->allOffButton->UseVisualStyleBackColor = false;
			this->allOffButton->Click += gcnew System::EventHandler(this, &MultiLoader::allOffButton_Click);
			// 
			// allOnButton
			// 
			this->allOnButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->allOnButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->allOnButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->allOnButton->Location = System::Drawing::Point(146, 197);
			this->allOnButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->allOnButton->Name = L"allOnButton";
			this->allOnButton->Size = System::Drawing::Size(160, 52);
			this->allOnButton->TabIndex = 12;
			this->allOnButton->Text = L"Все вкл.";
			this->allOnButton->UseVisualStyleBackColor = false;
			this->allOnButton->Click += gcnew System::EventHandler(this, &MultiLoader::allOnButton_Click);
			// 
			// description_text
			// 
			this->description_text->BackColor = System::Drawing::Color::NavajoWhite;
			this->description_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->description_text->ForeColor = System::Drawing::SystemColors::GrayText;
			this->description_text->Location = System::Drawing::Point(708, 248);
			this->description_text->MaxLength = 5000;
			this->description_text->Multiline = true;
			this->description_text->Name = L"description_text";
			this->description_text->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->description_text->Size = System::Drawing::Size(883, 93);
			this->description_text->TabIndex = 19;
			this->description_text->Text = L"Описание";
			this->description_text->UseWaitCursor = true;
			this->description_text->TextChanged += gcnew System::EventHandler(this, &MultiLoader::description_text_TextChanged);
			this->description_text->GotFocus += gcnew System::EventHandler(this, &MultiLoader::On_description_text_GotFocus);
			this->description_text->LostFocus += gcnew System::EventHandler(this, &MultiLoader::On_description_text_LostFocus);
			// 
			// name_text
			// 
			this->name_text->BackColor = System::Drawing::Color::NavajoWhite;
			this->name_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name_text->ForeColor = System::Drawing::SystemColors::GrayText;
			this->name_text->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->name_text->Location = System::Drawing::Point(708, 202);
			this->name_text->MaxLength = 100;
			this->name_text->Name = L"name_text";
			this->name_text->Size = System::Drawing::Size(883, 35);
			this->name_text->TabIndex = 17;
			this->name_text->Text = L"Название";
			this->name_text->UseWaitCursor = true;
			this->name_text->TextChanged += gcnew System::EventHandler(this, &MultiLoader::name_text_TextChanged);
			this->name_text->GotFocus += gcnew System::EventHandler(this, &MultiLoader::On_name_text_GotFocus);
			this->name_text->LostFocus += gcnew System::EventHandler(this, &MultiLoader::On_name_text_LostFocus);
			// 
			// checkBox_ya
			// 
			this->checkBox_ya->AutoSize = true;
			this->checkBox_ya->BackColor = System::Drawing::SystemColors::Window;
			this->checkBox_ya->Checked = true;
			this->checkBox_ya->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_ya->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_ya->Location = System::Drawing::Point(150, 311);
			this->checkBox_ya->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_ya->Name = L"checkBox_ya";
			this->checkBox_ya->Size = System::Drawing::Size(194, 36);
			this->checkBox_ya->TabIndex = 7;
			this->checkBox_ya->Tag = L"checkBox";
			this->checkBox_ya->Text = L"Яндекс Дзен";
			this->checkBox_ya->UseVisualStyleBackColor = false;
			// 
			// checkBox_yt
			// 
			this->checkBox_yt->AutoSize = true;
			this->checkBox_yt->BackColor = System::Drawing::SystemColors::Window;
			this->checkBox_yt->Checked = true;
			this->checkBox_yt->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_yt->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_yt->Location = System::Drawing::Point(150, 265);
			this->checkBox_yt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox_yt->Name = L"checkBox_yt";
			this->checkBox_yt->Size = System::Drawing::Size(138, 36);
			this->checkBox_yt->TabIndex = 4;
			this->checkBox_yt->Tag = L"checkBox";
			this->checkBox_yt->Text = L"YouTube";
			this->checkBox_yt->UseVisualStyleBackColor = false;
			// 
			// ML_button
			// 
			this->ML_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->ML_button->BackColor = System::Drawing::Color::DarkOrange;
			this->ML_button->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ML_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->ML_button->Location = System::Drawing::Point(1673, 688);
			this->ML_button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->ML_button->Name = L"ML_button";
			this->ML_button->Size = System::Drawing::Size(165, 45);
			this->ML_button->TabIndex = 1;
			this->ML_button->Text = L"MultiLoad";
			this->ML_button->UseVisualStyleBackColor = false;
			this->ML_button->Click += gcnew System::EventHandler(this, &MultiLoader::ML_button_Click);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->InitialDirectory = L"C:\\";
			this->openFileDialog2->Title = L"Выберите изображение";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Window;
			this->label3->Location = System::Drawing::Point(12, 733);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 20);
			this->label3->TabIndex = 29;
			this->label3->Text = L"MultiLoader v1.0";
			// 
			// MultiLoader
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1878, 762);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tag_button);
			this->Controls->Add(this->tag_text);
			this->Controls->Add(this->checkBox_pl);
			this->Controls->Add(this->checkBox_vk);
			this->Controls->Add(this->picture_button);
			this->Controls->Add(this->file_button);
			this->Controls->Add(this->file_text);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox_ru);
			this->Controls->Add(this->allOffButton);
			this->Controls->Add(this->allOnButton);
			this->Controls->Add(this->description_text);
			this->Controls->Add(this->name_text);
			this->Controls->Add(this->checkBox_ya);
			this->Controls->Add(this->checkBox_yt);
			this->Controls->Add(this->ML_button);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MultiLoader";
			this->Text = L"MultiLoader";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MultiLoader::MultiLoader_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void SetEnglishLayout()
	{
		for each (InputLanguage^ lang in InputLanguage::InstalledInputLanguages)
		{
			if (lang->Culture->Name->StartsWith("en"))
			{
				InputLanguage::CurrentInputLanguage = lang;
				break;
			}
		}
	}
	
	private: void CopyToClipboard(String^ text) {
		Clipboard::SetText(text);
	}

	/*private: void ShowPopup()
    {
        if (pw == nullptr || pw->IsDisposed)
        {
			pw = gcnew ProgressWindow();
            pw->Show();
        }
        else
        {
            pw->BringToFront();
        }
    }*/

	private: void ytLoad(IUIAutomation *pAutomation) {
		ShellExecute(NULL, TEXT("open"), TEXT("https://studio.youtube.com/"), NULL, NULL, SW_MAXIMIZE);
		IUIAutomationElement* pRoot = nullptr;
		pAutomation->GetRootElement(&pRoot);

		if (WaitForElement(pAutomation, pRoot, L"Создать", 360)) {
			ClickElementByName(pAutomation, pRoot, L"Создать");
		}

		if (WaitForElement(pAutomation, pRoot, L"Добавить видео", 120)) {
			ClickElementByName(pAutomation, pRoot, L"Добавить видео");
		}

		if (WaitForElement(pAutomation, pRoot, L"Выбрать файлы", 120)) {
			ClickElementByName(pAutomation, pRoot, L"Выбрать файлы");
		}

		EmptyClipboard();
		CopyToClipboard(this->file_link);
		WaitForFileDialog(360);
		Sleep(1000);
		pasteText();
		Sleep(200);
		pressEnter();

		if (WaitForElement(pAutomation, pRoot, L"Описание", 360)) {
			if (this->name != "default")
			{
				clearText();
				EmptyClipboard();
				CopyToClipboard(this->name);
				pasteText();
				Sleep(1000);
			}
		}

		if (this->description != "default")
		{
			pressTab();
			pressTab();
			EmptyClipboard();
			CopyToClipboard(this->description);
			pasteText();
			Sleep(1000);
		}

		if (this->picture_link != "default")
		{
			ClickElementByName(pAutomation, pRoot, L"Загрузить файл");
			EmptyClipboard();
			CopyToClipboard(this->picture_link);
			WaitForFileDialog(360);
			Sleep(500);
			pasteText();
			Sleep(200);
			pressEnter();
			Sleep(1000);
		}

		if (!String::IsNullOrWhiteSpace(this->tag_text->Text))
		{
			HWND hwnd = GetForegroundWindow();
			SendMessage(hwnd, WM_KEYDOWN, VK_END, 0);
			ClickElementByName(pAutomation, pRoot, L"Развернуть");
			pressTab();
			pressTab();
			pressTab();
			pressTab();
			pressTab();
			pressTab();
			pressTab();
			pressTab();
			pressTab();
			pressTab();
			pressTab();
			pressTab();
			pressTab();
			EmptyClipboard();
			CopyToClipboard(this->tag_text->Text);
			pasteText();
		}

		ClickElementByName(pAutomation, pRoot, L"Далее");
		Sleep(500);
		ClickElementByName(pAutomation, pRoot, L"Далее");
		Sleep(500);
		ClickElementByName(pAutomation, pRoot, L"Далее");
		Sleep(500);
		ClickElementByName(pAutomation, pRoot, L"Открытый доступ");
		if (WaitForElement(pAutomation, pRoot, L"Опубликовать", 360)) {
			ClickElementByName(pAutomation, pRoot, L"Опубликовать");
		}

		pRoot->Release();
		Sleep(500);
	}

	private: void yaLoad(IUIAutomation* pAutomation)
	{
		ShellExecute(NULL, TEXT("open"), TEXT("https://dzen.ru/profile/editor/create"), NULL, NULL, SW_MAXIMIZE);
		IUIAutomationElement* pRoot = nullptr;
		pAutomation->GetRootElement(&pRoot);

		if (WaitForElement(pAutomation, pRoot, L"Главное", 360)) {
			ClickRelative(0.78, 0.139);
		}
		if (WaitForElement(pAutomation, pRoot, L"Загрузить видео", 60)) {
			ClickElementByName(pAutomation, pRoot, L"Загрузить видео");
		}
		if (WaitForElement(pAutomation, pRoot, L"Выбрать видео", 60)) {
			ClickElementByName(pAutomation, pRoot, L"Выбрать видео");
		}

		EmptyClipboard();
		CopyToClipboard(this->file_link);
		WaitForFileDialog(360);
		Sleep(500);
		pasteText();
		Sleep(200);
		pressEnter();
		Sleep(3000);
		
		if (WaitForElement(pAutomation, pRoot, L"Название", 120)) {
			pressTab();
			pressTab();
			if (this->name != "default")
			{
				clearText();
				EmptyClipboard();
				CopyToClipboard(this->name);
				pasteText();
				Sleep(1000);
			}
		}

		if (this->description != "default")
		{
			pressTab();
			pressTab();
			EmptyClipboard();
			CopyToClipboard(this->description);
			pasteText();
			Sleep(1000);
		}

		if (this->picture_link != "default")
		{
			ClickElementByName(pAutomation, pRoot, L"Добавить обложку");
			EmptyClipboard();
			CopyToClipboard(this->picture_link);
			pressEnter();
			WaitForFileDialog(360);
			Sleep(500);
			pasteText();
			Sleep(200);
			pressEnter();
			Sleep(1000);
		}

		if (WaitForElement(pAutomation, pRoot, L"Опубликовать", 3600)) {
			ClickElementByName(pAutomation, pRoot, L"Опубликовать");
		}
		Sleep(500);
		pRoot->Release();
	}

	private: void ruLoad(IUIAutomation* pAutomation)
	{
		ShellExecute(NULL, TEXT("open"), TEXT("https://studio.rutube.ru/"), NULL, NULL, SW_MAXIMIZE);
		IUIAutomationElement* pRoot = nullptr;
		pAutomation->GetRootElement(&pRoot);

		if (WaitForElement(pAutomation, pRoot, L"Добавить", 360)) {
			ClickElementByName(pAutomation, pRoot, L"Добавить");
		}
		if (WaitForElement(pAutomation, pRoot, L"Загрузить видео", 60)) {
			ClickElementByName(pAutomation, pRoot, L"Загрузить видео");
		}
		if (WaitForElement(pAutomation, pRoot, L"Выбрать файлы", 60)) {
			ClickElementByName(pAutomation, pRoot, L"Выбрать файлы");
		}

		EmptyClipboard();
		CopyToClipboard(this->file_link);
		WaitForFileDialog(360);
		Sleep(500);
		pasteText();
		Sleep(200);
		pressEnter();

		if (WaitForElement(pAutomation, pRoot, L"Название", 360)) {
			Sleep(500);
			pressTab();
			pressTab();
			if (this->name != "default")
			{
				clearText();
				EmptyClipboard();
				CopyToClipboard(this->name);
				pasteText();
				Sleep(1000);
			}
		}

		if (this->description != "default")
		{
			pressTab();
			EmptyClipboard();
			CopyToClipboard(this->description);
			pasteText();
			Sleep(1000);
		}

		if (this->picture_link != "default")
		{
			ClickElementByName(pAutomation, pRoot, L"Загрузить свою");
			EmptyClipboard();
			CopyToClipboard(this->picture_link);
			WaitForFileDialog(360);
			Sleep(1000);
			pasteText();
			Sleep(200);
			pressEnter();
			Sleep(1000);
		}

		if (WaitForElement(pAutomation, pRoot, L"Обложка", 60)) {
			Sleep(2000);
			ClickRelative(0.65, 0.76);
		}

		if (WaitForElement(pAutomation, pRoot, L"Опубликовать", 3600)) {
			ClickElementByName(pAutomation, pRoot, L"Опубликовать");
		}
		
		pRoot->Release();
	}

	private: void vkLoad(IUIAutomation* pAutomation)
	{
		ShellExecute(NULL, TEXT("open"), TEXT("https://vkvideo.ru/my_communities"), NULL, NULL, SW_MAXIMIZE);
		IUIAutomationElement* pRoot = nullptr;
		pAutomation->GetRootElement(&pRoot);

		if (WaitForElement(pAutomation, pRoot, L"Добавить", 360)) {
			ClickElementByName(pAutomation, pRoot, L"Добавить");
		}
		if (WaitForElement(pAutomation, pRoot, L"Добавить видео", 60)) {
			ClickElementByName(pAutomation, pRoot, L"Добавить видео");
		}
		if (WaitForElement(pAutomation, pRoot, L"Выбрать файл", 60)) {
			ClickElementByName(pAutomation, pRoot, L"Выбрать файл");
		}

		EmptyClipboard();
		CopyToClipboard(this->file_link);
		WaitForFileDialog(360);
		Sleep(500);
		pasteText();
		Sleep(200);
		pressEnter();

		if (WaitForElement(pAutomation, pRoot, L"Название", 360)) {
			
			ClickElementByName(pAutomation, pRoot, L"Название");
			if (this->name != "default")
			{
				clearText();
				CopyToClipboard(this->name);
				pasteText();
				Sleep(1000);
			}
		}

		if (this->description != "default")
		{
			pressTab();
			EmptyClipboard();
			CopyToClipboard(this->description);
			pasteText();
			Sleep(1000);
		}

		if (this->picture_link != "default")
		{
			pressTab();
			EmptyClipboard();
			CopyToClipboard(this->picture_link);
			pressEnter();
			WaitForFileDialog(360);
			Sleep(500);
			pasteText();
			Sleep(200);
			pressEnter();
			Sleep(1000);
		}

		ClickElementByName(pAutomation, pRoot, L"Далее");
		Sleep(500);
		ClickElementByName(pAutomation, pRoot, L"Далее");
		Sleep(500);
		if (WaitForElement(pAutomation, pRoot, L"Опубликовать", 3600)) {
			ClickElementByName(pAutomation, pRoot, L"Опубликовать");
		}
		Sleep(500);
		pRoot->Release();
	}

	private: void plLoad(IUIAutomation* pAutomation)
	{
		ShellExecute(NULL, TEXT("open"), TEXT("https://studio.plvideo.ru/"), NULL, NULL, SW_MAXIMIZE);
		IUIAutomationElement* pRoot = nullptr;
		pAutomation->GetRootElement(&pRoot);

		if (WaitForElement(pAutomation, pRoot, L"Загрузить видео", 360)) {
			ClickElementByName(pAutomation, pRoot, L"Загрузить видео");
		}
		if (WaitForElement(pAutomation, pRoot, L"Выбрать файлы", 60)) {
			ClickElementByName(pAutomation, pRoot, L"Выбрать файлы");
		}

		EmptyClipboard();
		CopyToClipboard(this->file_link);
		WaitForFileDialog(360);
		Sleep(500);
		pasteText();
		Sleep(200);
		pressEnter();

		Sleep(5000);
		pressTab();
		clearText();
		EmptyClipboard();
		CopyToClipboard(this->name);
		pasteText();

		/*if (WaitForElement(pAutomation, pRoot, L"Описание", 360)) {
			if (this->name != "default")
			{
				ClickAtPosition(660, 360);
				clearText();
				EmptyClipboard();
				CopyToClipboard(this->name);
				pasteText();
				Sleep(1000);
			}
		}*/

		if (this->description != "default")
		{
			ClickElementByName(pAutomation, pRoot, L"Описание видео");
			EmptyClipboard();
			CopyToClipboard(this->description);
			pasteText();
			Sleep(1000);
		}

		if (this->picture_link != "default")
		{
			ClickElementByName(pAutomation, pRoot, L"Загрузить");
			EmptyClipboard();
			CopyToClipboard(this->picture_link);
			pressEnter();
			WaitForFileDialog(360);
			Sleep(500);
			pasteText();
			Sleep(200);
			pressEnter();
			Sleep(1000);
		}

		ClickElementByName(pAutomation, pRoot, L"Далее");
		Sleep(500);
		ClickElementByName(pAutomation, pRoot, L"Далее");
		Sleep(500);
		ClickElementByName(pAutomation, pRoot, L"Далее");
		Sleep(500);
		if (WaitForElement(pAutomation, pRoot, L"Опубликовать", 3600)) {
			ClickElementByName(pAutomation, pRoot, L"Опубликовать");
		}
		Sleep(500);
		
		pRoot->Release();
	}

	private: System::Void ML_button_Click(System::Object^ sender, System::EventArgs^ e) {
		SetEnglishLayout();
		CoInitialize(NULL);
		IUIAutomation* pAutomation = nullptr;
		HRESULT hr = CoCreateInstance(
			CLSID_CUIAutomation,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_IUIAutomation,
			(void**)&pAutomation
		);
		//ShowPopup();
		if (this->checkBox_yt->Checked == true) ytLoad(pAutomation);
		if (this->checkBox_ya->Checked == true) yaLoad(pAutomation);
		if (this->checkBox_ru->Checked == true) ruLoad(pAutomation);
		if (this->checkBox_pl->Checked == true) plLoad(pAutomation);
		if (this->checkBox_vk->Checked == true) vkLoad(pAutomation);
		

		pAutomation->Release();
		CoUninitialize();
	}

	private: System::Void allOnButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->checkBox_yt->Checked = true;
		this->checkBox_ya->Checked = true;
		this->checkBox_ru->Checked = true;
		this->checkBox_vk->Checked = true;
		this->checkBox_pl->Checked = true;
	}
	private: System::Void allOffButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->checkBox_yt->Checked = false;
		this->checkBox_ya->Checked = false;
		this->checkBox_ru->Checked = false;
		this->checkBox_vk->Checked = false;
		this->checkBox_pl->Checked = false;
	}

	private: System::Void tag_button_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ tags = getTags(this->name);
			this->tag_text->Text = tags;
		}
		catch (System::Exception^ ex) {
			// Обработка управляемых исключений
			System::Windows::Forms::MessageBox::Show(
				ex->Message,
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);

			System::Diagnostics::Debug::WriteLine(ex->Message);
		}
		catch (const std::exception& ex) {
			// Обработка неуправляемых исключений
			System::Windows::Forms::MessageBox::Show(
				gcnew String(ex.what()),
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);

			System::Diagnostics::Debug::WriteLine(gcnew String(ex.what()));
		}
	}

	private: System::Void On_name_text_GotFocus(Object^ sender, EventArgs^ e)
    {
		if (name_text->Text == "Название")
        {
            name_text->Text = "";
            name_text->ForeColor = Color::Black;
        }
    }

	private: System::Void On_name_text_LostFocus(Object^ sender, EventArgs^ e)
    {
        if (String::IsNullOrWhiteSpace(name_text->Text))
        {
            name_text->Text = "Название";
            name_text->ForeColor = Color::Gray;
        }
    }

	private: System::Void On_description_text_GotFocus(Object^ sender, EventArgs^ e)
    {
		if (description_text->Text == "Описание")
        {
			description_text->Text = "";
			description_text->ForeColor = Color::Black;
        }
    }

	private: System::Void On_description_text_LostFocus(Object^ sender, EventArgs^ e)
    {
        if (String::IsNullOrWhiteSpace(description_text->Text))
        {
			description_text->Text = "Описание";
			description_text->ForeColor = Color::Gray;
        }
    }

	private: System::Void On_tag_text_GotFocus(Object^ sender, EventArgs^ e)
    {
		if (tag_text->Text == "Тэги")
        {
            tag_text->Text = "";
            tag_text->ForeColor = Color::Black;
        }
    }

	private: System::Void On_tag_text_LostFocus(Object^ sender, EventArgs^ e)
    {
        if (String::IsNullOrWhiteSpace(tag_text->Text))
        {
			tag_text->Text = "Тэги";
			tag_text->ForeColor = Color::Gray;
        }
    }

	private: System::Void file_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			String^ message = "";
			for each (String ^ file in openFileDialog1->FileNames)
			{
				message += file;
			}
			this->file_link = message;
			this->file_text->Text = this->file_link;
		}
	}
	private: System::Void picture_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog2->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			String^ message = "";
			for each (String ^ file in openFileDialog2->FileNames)
			{
				message += file;
			}
			this->picture_button->Image = Image::FromFile(message);
			this->picture_link = message;
		}
	}
	private: System::Void file_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->file_link = this->file_text->Text;
	}
	private: System::Void name_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->name = this->name_text->Text;
	}
	private: System::Void description_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->description = this->description_text->Text;
	}
private: System::Void MultiLoader_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
