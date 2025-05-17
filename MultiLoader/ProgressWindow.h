#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

public ref class ProgressWindow : public System::Windows::Forms::Form
{
private:
    System::Windows::Forms::ProgressBar^ progressBar1;

public:
    ProgressWindow()
    {
        InitializeComponent();
        SetupForm();
    }

protected:
    // Переопределение ShowWithoutActivation через override метода
    virtual bool ShowWithoutActivationOverride()
    {
        return true;
    }

    // Переопределение CreateParams как обычного метода
    virtual System::Windows::Forms::CreateParams^ CreateParamsOverride()
    {
        System::Windows::Forms::CreateParams^ cp = System::Windows::Forms::Form::CreateParams;
        cp->ExStyle |= 0x08000000; // WS_EX_NOACTIVATE
        return cp;
    }

private:
    void InitializeComponent()
    {
        this->progressBar1 = gcnew System::Windows::Forms::ProgressBar();
        this->SuspendLayout();
        // 
        // progressBar1
        // 
        this->progressBar1->Location = System::Drawing::Point(-2, 225);
        this->progressBar1->Name = "progressBar1";
        this->progressBar1->Size = System::Drawing::Size(464, 36);
        this->progressBar1->TabIndex = 0;
        // 
        // ProgressWindow
        // 
        this->ClientSize = System::Drawing::Size(464, 262);
        this->Controls->Add(this->progressBar1);
        this->Name = "ProgressWindow";
        this->Text = "Всплывающее окно";
        this->ResumeLayout(false);
    }

    void SetupForm()
    {
        this->TopMost = true;
        this->ShowInTaskbar = false;
    }
};
