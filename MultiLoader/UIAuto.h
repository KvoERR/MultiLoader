#pragma once
#include <windows.h>
#include <uiautomation.h>
#include <shlobj.h>
#include <exdisp.h> 
#include <atlbase.h> 
#include <atlcom.h> 
#include <vcclr.h>

void ClickAtPosition(int x, int y) {
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    Sleep(50);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}

void ClickRelative(double x_percent, double y_percent) {
    // Получаем размер экрана
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Рассчитываем абсолютные координаты
    int x = static_cast<int>(screenWidth * x_percent);
    int y = static_cast<int>(screenHeight * y_percent);

    // Перемещаем курсор
    SetCursorPos(x, y);

    // Имитация клика мышью
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    Sleep(50); // небольшая задержка
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}

void pasteText()
{
    INPUT inputs[4] = { 0 };

    // Ctrl down
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_CONTROL;

    // V down
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 'V';

    // V up
    inputs[2] = inputs[1];
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    // Ctrl up
    inputs[3] = inputs[0];
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(4, inputs, sizeof(INPUT));
}

void pressEnter()
{
    INPUT input[2] = { 0 };

    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = VK_RETURN;

    input[1] = input[0];
    input[1].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(2, input, sizeof(INPUT));
}

void pressTab()
{
    INPUT input[2] = { 0 };

    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = VK_TAB;

    input[1] = input[0];
    input[1].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(2, input, sizeof(INPUT));
}

void clearText()
{
    INPUT inputs[6] = { 0 };

    // Ctrl down
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_CONTROL;
    
    // A down
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 'A';

    // Delete down
    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = VK_DELETE;

    // Delete up
    inputs[3] = inputs[2];
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    // A up
    inputs[4] = inputs[1];
    inputs[4].ki.dwFlags = KEYEVENTF_KEYUP;

    // Ctrl up
    inputs[5] = inputs[0];
    inputs[5].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(6, inputs, sizeof(INPUT));
}

bool ClickElementByName(IUIAutomation* pAutomation, IUIAutomationElement* pParent, const wchar_t* name)
{
    if (!pAutomation || !pParent || !name) return false;

    bool result = false;
    IUIAutomationCondition* pCondition = nullptr;
    IUIAutomationElement* pElement = nullptr;
    IUIAutomationInvokePattern* pInvoke = nullptr;

    HRESULT hr = pAutomation->CreatePropertyCondition(UIA_NamePropertyId, CComVariant(name), &pCondition);
    if (FAILED(hr)) goto cleanup;

    hr = pParent->FindFirst(TreeScope_Descendants, pCondition, &pElement);
    if (FAILED(hr) || !pElement) goto cleanup;

    hr = pElement->GetCurrentPattern(UIA_InvokePatternId, (IUnknown**)&pInvoke);
    if (SUCCEEDED(hr) && pInvoke)
    {
        hr = pInvoke->Invoke();
        result = SUCCEEDED(hr);
    }

cleanup:
    if (pInvoke) pInvoke->Release();
    if (pElement) pElement->Release();
    if (pCondition) pCondition->Release();

    return result;
}

HWND WaitForBrowserWindow(DWORD timeoutMs = 30000)
{
    const wchar_t* browserClasses[] = {
        L"Chrome_WidgetWin_1",  // Google Chrome
        L"MozillaWindowClass",   // Firefox
        L"Edge_WidgetWin_1",     // Microsoft Edge
        L"IEFrame"              // Internet Explorer
    };

    DWORD start = GetTickCount();
    while (GetTickCount() - start < timeoutMs)
    {
        for (const wchar_t* cls : browserClasses)
        {
            HWND hWnd = FindWindow(cls, NULL);
            if (hWnd && IsWindowVisible(hWnd))
            {
                return hWnd;
            }
        }
        Sleep(500);
    }
    return NULL;
}

bool IsElementVisible(IUIAutomationElement* pElement)
{
    if (!pElement) return false;

    VARIANT varIsOffscreen = { VT_EMPTY };
    HRESULT hr = pElement->GetCurrentPropertyValue(UIA_IsOffscreenPropertyId, &varIsOffscreen);

    if (SUCCEEDED(hr))
    {
        bool isVisible = (varIsOffscreen.vt == VT_BOOL && !varIsOffscreen.boolVal);
        VariantClear(&varIsOffscreen);
        return isVisible;
    }

    return false;
}

bool WaitForElement(IUIAutomation* pAutomation, IUIAutomationElement* pParent,
    LPCWSTR elementName, int timeoutSeconds)
{
    if (!pAutomation || !pParent || !elementName || timeoutSeconds <= 0)
        return false;

    DWORD startTime = GetTickCount();
    DWORD timeoutMs = timeoutSeconds * 1000;

    while ((GetTickCount() - startTime) < timeoutMs)
    {
        CComVariant varName(elementName);
        IUIAutomationCondition* pCondition = nullptr;

        HRESULT hr = pAutomation->CreatePropertyCondition(UIA_NamePropertyId, varName, &pCondition);
        if (FAILED(hr)) continue;

        IUIAutomationElement* pElement = nullptr;
        hr = pParent->FindFirst(TreeScope_Descendants, pCondition, &pElement);
        pCondition->Release();

        if (SUCCEEDED(hr) && pElement)
        {
            bool isVisible = IsElementVisible(pElement);
            pElement->Release();

            if (isVisible)
            {
                return true;
            }
        }

        Sleep(500);
    }

    return false;
}

bool WaitForFileDialog(int timeoutSec)
{
    if (timeoutSec <= 0) return false;

    DWORD startTime = GetTickCount();
    DWORD timeoutMs = timeoutSec * 1000;

    while ((GetTickCount() - startTime) < timeoutMs)
    {
        HWND hWnd = GetForegroundWindow();
        if (!hWnd) continue;

        wchar_t className[256] = { 0 };
        if (GetClassName(hWnd, className, _countof(className))
            && wcscmp(className, L"#32770") == 0)
        {
            return true;
        }

        Sleep(500);
    }

    return false;
}

void startAuto()
{
    CoInitialize(NULL);
    IUIAutomation* pAutomation = nullptr;
    HRESULT hr = CoCreateInstance(
        CLSID_CUIAutomation,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IUIAutomation,
        (void**)&pAutomation
    );
}