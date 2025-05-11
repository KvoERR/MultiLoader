#pragma once
#include <windows.h>
#include <uiautomation.h>
#include <shlobj.h>
#include <exdisp.h> 
#include <atlbase.h> 
#include <atlcom.h> 
#include <vcclr.h>
#include <string>
#include <iostream>

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


	private: System::Windows::Forms::TextBox^ tag_text;
	private: System::Windows::Forms::Button^ tag_button;
		   String^ description;

	public:
		MultiLoader(void)
		{
			InitializeComponent();
			file_link= "C:\\";
			picture_link= "default";
			name= "default";
			description= "default";
		}
		~MultiLoader()
		{
			if (components) delete components;
		}
	protected:

	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
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
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(-2, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(941, 512);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->tag_button);
			this->tabPage1->Controls->Add(this->tag_text);
			this->tabPage1->Controls->Add(this->checkBox_pl);
			this->tabPage1->Controls->Add(this->checkBox_vk);
			this->tabPage1->Controls->Add(this->picture_button);
			this->tabPage1->Controls->Add(this->file_button);
			this->tabPage1->Controls->Add(this->file_text);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->checkBox_ru);
			this->tabPage1->Controls->Add(this->allOffButton);
			this->tabPage1->Controls->Add(this->allOnButton);
			this->tabPage1->Controls->Add(this->description_text);
			this->tabPage1->Controls->Add(this->name_text);
			this->tabPage1->Controls->Add(this->checkBox_ya);
			this->tabPage1->Controls->Add(this->checkBox_yt);
			this->tabPage1->Controls->Add(this->ML_button);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(933, 486);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Основные";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MultiLoader::tabPage1_Click);
			// 
			// tag_button
			// 
			this->tag_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->tag_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tag_button->Location = System::Drawing::Point(325, 287);
			this->tag_button->Name = L"tag_button";
			this->tag_button->Size = System::Drawing::Size(93, 36);
			this->tag_button->TabIndex = 28;
			this->tag_button->Text = L"Auto-tag";
			this->tag_button->UseVisualStyleBackColor = true;
			this->tag_button->Click += gcnew System::EventHandler(this, &MultiLoader::button1_Click);
			// 
			// tag_text
			// 
			this->tag_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tag_text->ForeColor = System::Drawing::SystemColors::GrayText;
			this->tag_text->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->tag_text->Location = System::Drawing::Point(423, 292);
			this->tag_text->Margin = System::Windows::Forms::Padding(2);
			this->tag_text->MaxLength = 100;
			this->tag_text->Name = L"tag_text";
			this->tag_text->Size = System::Drawing::Size(378, 26);
			this->tag_text->TabIndex = 27;
			this->tag_text->Text = L"Тэги";
			this->tag_text->UseWaitCursor = true;
			// 
			// checkBox_pl
			// 
			this->checkBox_pl->AutoSize = true;
			this->checkBox_pl->Checked = true;
			this->checkBox_pl->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_pl->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_pl->Location = System::Drawing::Point(48, 245);
			this->checkBox_pl->Name = L"checkBox_pl";
			this->checkBox_pl->Size = System::Drawing::Size(110, 25);
			this->checkBox_pl->TabIndex = 26;
			this->checkBox_pl->Tag = L"checkBox";
			this->checkBox_pl->Text = L"Платформа";
			this->checkBox_pl->UseVisualStyleBackColor = true;
			// 
			// checkBox_vk
			// 
			this->checkBox_vk->AutoSize = true;
			this->checkBox_vk->Checked = true;
			this->checkBox_vk->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_vk->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_vk->Location = System::Drawing::Point(48, 215);
			this->checkBox_vk->Name = L"checkBox_vk";
			this->checkBox_vk->Size = System::Drawing::Size(101, 25);
			this->checkBox_vk->TabIndex = 25;
			this->checkBox_vk->Tag = L"checkBox";
			this->checkBox_vk->Text = L"VK Видео";
			this->checkBox_vk->UseVisualStyleBackColor = true;
			// 
			// picture_button
			// 
			this->picture_button->Location = System::Drawing::Point(325, 209);
			this->picture_button->Margin = System::Windows::Forms::Padding(2);
			this->picture_button->Name = L"picture_button";
			this->picture_button->Size = System::Drawing::Size(167, 73);
			this->picture_button->TabIndex = 24;
			this->picture_button->UseVisualStyleBackColor = true;
			this->picture_button->Click += gcnew System::EventHandler(this, &MultiLoader::picture_button_Click);
			// 
			// file_button
			// 
			this->file_button->Location = System::Drawing::Point(778, 179);
			this->file_button->Margin = System::Windows::Forms::Padding(2);
			this->file_button->Name = L"file_button";
			this->file_button->Size = System::Drawing::Size(23, 26);
			this->file_button->TabIndex = 23;
			this->file_button->Text = L"...";
			this->file_button->UseVisualStyleBackColor = true;
			this->file_button->Click += gcnew System::EventHandler(this, &MultiLoader::file_button_Click);
			// 
			// file_text
			// 
			this->file_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->file_text->Location = System::Drawing::Point(325, 179);
			this->file_text->Margin = System::Windows::Forms::Padding(2);
			this->file_text->Name = L"file_text";
			this->file_text->Size = System::Drawing::Size(449, 26);
			this->file_text->TabIndex = 22;
			this->file_text->Text = this->openFileDialog1->InitialDirectory;
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
			this->label2->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(323, 50);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 25);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Информация";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(44, 50);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 25);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Платформы";
			// 
			// checkBox_ru
			// 
			this->checkBox_ru->AutoSize = true;
			this->checkBox_ru->Checked = true;
			this->checkBox_ru->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_ru->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_ru->Location = System::Drawing::Point(48, 185);
			this->checkBox_ru->Name = L"checkBox_ru";
			this->checkBox_ru->Size = System::Drawing::Size(83, 25);
			this->checkBox_ru->TabIndex = 14;
			this->checkBox_ru->Tag = L"checkBox";
			this->checkBox_ru->Text = L"RuTube";
			this->checkBox_ru->UseVisualStyleBackColor = true;
			// 
			// allOffButton
			// 
			this->allOffButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->allOffButton->Location = System::Drawing::Point(157, 81);
			this->allOffButton->Name = L"allOffButton";
			this->allOffButton->Size = System::Drawing::Size(107, 34);
			this->allOffButton->TabIndex = 13;
			this->allOffButton->Text = L"Все выкл.";
			this->allOffButton->UseVisualStyleBackColor = true;
			this->allOffButton->Click += gcnew System::EventHandler(this, &MultiLoader::allOffButton_Click);
			// 
			// allOnButton
			// 
			this->allOnButton->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->allOnButton->Location = System::Drawing::Point(45, 81);
			this->allOnButton->Name = L"allOnButton";
			this->allOnButton->Size = System::Drawing::Size(107, 34);
			this->allOnButton->TabIndex = 12;
			this->allOnButton->Text = L"Все вкл.";
			this->allOnButton->UseVisualStyleBackColor = true;
			this->allOnButton->Click += gcnew System::EventHandler(this, &MultiLoader::allOnButton_Click);
			// 
			// description_text
			// 
			this->description_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->description_text->ForeColor = System::Drawing::SystemColors::GrayText;
			this->description_text->Location = System::Drawing::Point(325, 114);
			this->description_text->Margin = System::Windows::Forms::Padding(2);
			this->description_text->MaxLength = 5000;
			this->description_text->Multiline = true;
			this->description_text->Name = L"description_text";
			this->description_text->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->description_text->Size = System::Drawing::Size(476, 62);
			this->description_text->TabIndex = 19;
			this->description_text->Text = L"Описание";
			this->description_text->UseWaitCursor = true;
			this->description_text->TextChanged += gcnew System::EventHandler(this, &MultiLoader::description_text_TextChanged);
			this->description_text->GotFocus += gcnew System::EventHandler(this, &MultiLoader::On_description_text_GotFocus);
			this->description_text->LostFocus += gcnew System::EventHandler(this, &MultiLoader::On_description_text_LostFocus);
			// 
			// name_text
			// 
			this->name_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name_text->ForeColor = System::Drawing::SystemColors::GrayText;
			this->name_text->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->name_text->Location = System::Drawing::Point(325, 84);
			this->name_text->Margin = System::Windows::Forms::Padding(2);
			this->name_text->MaxLength = 100;
			this->name_text->Name = L"name_text";
			this->name_text->Size = System::Drawing::Size(476, 26);
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
			this->checkBox_ya->Checked = true;
			this->checkBox_ya->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_ya->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_ya->Location = System::Drawing::Point(48, 155);
			this->checkBox_ya->Name = L"checkBox_ya";
			this->checkBox_ya->Size = System::Drawing::Size(128, 25);
			this->checkBox_ya->TabIndex = 7;
			this->checkBox_ya->Tag = L"checkBox";
			this->checkBox_ya->Text = L"Яндекс Дзен";
			this->checkBox_ya->UseVisualStyleBackColor = true;
			// 
			// checkBox_yt
			// 
			this->checkBox_yt->AutoSize = true;
			this->checkBox_yt->Checked = true;
			this->checkBox_yt->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_yt->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_yt->Location = System::Drawing::Point(48, 125);
			this->checkBox_yt->Name = L"checkBox_yt";
			this->checkBox_yt->Size = System::Drawing::Size(92, 25);
			this->checkBox_yt->TabIndex = 4;
			this->checkBox_yt->Tag = L"checkBox";
			this->checkBox_yt->Text = L"YouTube";
			this->checkBox_yt->UseVisualStyleBackColor = true;
			// 
			// ML_button
			// 
			this->ML_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->ML_button->Font = (gcnew System::Drawing::Font(L"Cascadia Mono Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ML_button->Location = System::Drawing::Point(796, 432);
			this->ML_button->Name = L"ML_button";
			this->ML_button->Size = System::Drawing::Size(110, 29);
			this->ML_button->TabIndex = 1;
			this->ML_button->Text = L"MultiLoad";
			this->ML_button->UseVisualStyleBackColor = true;
			this->ML_button->Click += gcnew System::EventHandler(this, &MultiLoader::ML_button_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(933, 486);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Дополнительно";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->InitialDirectory = L"C:\\";
			this->openFileDialog2->Title = L"Выберите изображение";
			// 
			// MultiLoader
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(939, 510);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MultiLoader";
			this->Text = L"MultiLoader";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	void ClickAtPosition(int x, int y) {
		SetCursorPos(x, y);
		mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
		Sleep(50);  
		mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
	}
	private: void CopyToClipboard(String^ text) {
		Clipboard::SetText(text);
	}

	private: void pasteText() {
		keybd_event(VK_CONTROL, 0, 0, 0);       // Нажать Ctrl
		keybd_event('V', 0, 0, 0);              // Нажать V
		keybd_event('V', 0, KEYEVENTF_KEYUP, 0); // Отпустить V
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
	}

	private: void pressEnter() {
		keybd_event(VK_RETURN, 0, 0, 0);
		keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
	}

	private: void pressTab() {
		keybd_event(VK_TAB, 0, 0, 0);       // Нажатие Tab
		keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);  // Отпускание Tab
	}

	private: void clearText() {
		keybd_event(VK_CONTROL, 0, 0, 0);      // Ctrl down
		keybd_event('A', 0, 0, 0);             // A down
		keybd_event(VK_DELETE, 0, 0, 0);       // Delete down

		// Отпускаем в обратном порядке
		keybd_event(VK_DELETE, 0, KEYEVENTF_KEYUP, 0);
		keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
	}
	private: void ClickElementByName(IUIAutomation* pAutomation, IUIAutomationElement* pParent, const wchar_t* name) {
		IUIAutomationCondition* pCondition = nullptr;
		pAutomation->CreatePropertyCondition(UIA_NamePropertyId, CComVariant(name), &pCondition);

		IUIAutomationElement* pElement = nullptr;
		pParent->FindFirst(TreeScope_Descendants, pCondition, &pElement);

		if (pElement) {
			IUIAutomationInvokePattern* pInvoke = nullptr;
			pElement->GetCurrentPattern(UIA_InvokePatternId, (IUnknown**)&pInvoke);
			if (pInvoke) {
				pInvoke->Invoke();
				pInvoke->Release();
			}
			pElement->Release();
		}
		if (pCondition) pCondition->Release();
	}

	private: HWND WaitForBrowserWindow() {
		const wchar_t* browserClasses[] = {
			L"Chrome_WidgetWin_1",  // Google Chrome
			L"MozillaWindowClass",   // Firefox
			L"Edge_WidgetWin_1"     // Microsoft Edge
		};

		DWORD timeout = 30000;
		DWORD start = GetTickCount64();
		while (GetTickCount64() - start < timeout) {
			for (const wchar_t* cls : browserClasses) {
				HWND hWnd = FindWindow(cls, NULL);
				if (hWnd) return hWnd;
			}
			Sleep(500);
		}
		return NULL;
	}



	private: bool IsElementVisible(IUIAutomationElement* pElement) {
		if (!pElement) return false;

		VARIANT varIsOffscreen;
		HRESULT hr = pElement->GetCurrentPropertyValue(UIA_IsOffscreenPropertyId, &varIsOffscreen);

		if (SUCCEEDED(hr) && varIsOffscreen.vt == VT_BOOL) {
			bool isVisible = !varIsOffscreen.boolVal;
			VariantClear(&varIsOffscreen);
			return isVisible;
		}

		return false;
	}

	private: bool WaitForElement(IUIAutomation* pAutomation, IUIAutomationElement* pParent,
		LPCWSTR elementName, int timeoutSeconds)
	{
		DWORD startTime = GetTickCount();

		while ((GetTickCount() - startTime) < (DWORD)(timeoutSeconds * 1000)) {
			VARIANT varName;
			varName.vt = VT_BSTR;
			varName.bstrVal = SysAllocString(elementName);

			IUIAutomationCondition* pCondition = nullptr;
			pAutomation->CreatePropertyCondition(UIA_NamePropertyId, varName, &pCondition);
			VariantClear(&varName);

			IUIAutomationElement* pElement = nullptr;
			pParent->FindFirst(TreeScope_Descendants, pCondition, &pElement);
			pCondition->Release();

			if (pElement) {
				bool isVisible = IsElementVisible(pElement);
				pElement->Release();

				if (isVisible) {
					return true;
				}
			}

			Sleep(500);
		}

		return false;
	}

	// Функция для периодической проверки
	bool WaitForFileDialog(int timeoutSec)
	{
		DWORD startTime = GetTickCount();

		while (true)
		{
			HWND hWnd = GetForegroundWindow();
			wchar_t className[256];
			GetClassName(hWnd, className, 256);

			if (wcscmp(className, L"#32770") == 0)
			{
				return true;  
			}

			if ((GetTickCount() - startTime) >= (DWORD)timeoutSec)
			{
				return false;  
			}

			Sleep(500);
		}
	}
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
		Sleep(500);
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
			pressTab();
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
			ClickAtPosition(1505, 150);
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
			pressEnter();
			WaitForFileDialog(360);
			Sleep(500);
			pasteText();
			Sleep(200);
			pressEnter();
			Sleep(1000);
		}

		ClickElementByName(pAutomation, pRoot, L"Добавить");

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

		if (WaitForElement(pAutomation, pRoot, L"Описание", 360)) {
			if (this->name != "default")
			{
				ClickAtPosition(660, 360);
				clearText();
				EmptyClipboard();
				CopyToClipboard(this->name);
				pasteText();
				Sleep(1000);
			}
		}

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
		
		CoInitialize(NULL);
		IUIAutomation* pAutomation = nullptr;
		HRESULT hr = CoCreateInstance(
			CLSID_CUIAutomation,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_IUIAutomation,
			(void**)&pAutomation
		);

		if (this->checkBox_yt->Checked == true) ytLoad(pAutomation);
		if (this->checkBox_ya->Checked == true) yaLoad(pAutomation);
		if (this->checkBox_ru->Checked == true) ruLoad(pAutomation);
		if (this->checkBox_vk->Checked == true) vkLoad(pAutomation);
		if (this->checkBox_pl->Checked == true) plLoad(pAutomation);


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
	private: System::Void file_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			String^ message = "";
			for each (String ^ file in openFileDialog1->FileNames)
			{
				message += file;
			}
			this->file_link = message;
			this->file_text->Text = file_link;
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

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
