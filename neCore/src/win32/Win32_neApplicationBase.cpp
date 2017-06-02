#include "neApplicationBase.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <memory>

namespace neEngineSDK
{
  const String szWindowClass = "NEKOENGINE_MAIN_WINDOW_CLASS";
  const double MICROSEC_TO_SEC = 1.0 / 1000000.0;
  const float MS_PER_FRAME = 1.0f / 60.0f;

  LRESULT
    CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_DESTROY:
    {
      PostQuitMessage(0);
    }
    break;
    default:
    {
      return DefWindowProc(hWnd, message, wParam, lParam);
    }
    }
    return 0;
  }
  CApplicationBase::CApplicationBase() : m_iScrWidth(0),
                                         m_iScrHeight(0),
                                         m_szTitle("Base App Window"),
                                         m_screenHandle(0)
  {}

  CApplicationBase::~CApplicationBase() {}

  int
  CApplicationBase::run()
  {
    //Regster a window class
    HINSTANCE hInstance = GetModuleHandle(0);
    WNDCLASSEXA wcex;

    memset(&wcex, 0, sizeof(WNDCLASSEXA));
    wcex.cbSize = sizeof(WNDCLASSEXA);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = wndProc;
    wcex.hInstance = hInstance;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.lpszClassName = szWindowClass.c_str();

    if (!RegisterClassExA(&wcex)) {
      return GetLastError();
    }

    HWND hWnd = CreateWindowA(szWindowClass.c_str(),
                              m_szTitle.c_str(),
                              WS_OVERLAPPEDWINDOW,
                              CW_USEDEFAULT,
                              CW_USEDEFAULT,
                              m_iScrWidth,
                              m_iScrHeight,
                              nullptr,
                              nullptr,
                              hInstance,
                              nullptr);

    if (!hWnd) {
      return 0;
    }

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    //Reinterprest the hWnd as the screen handler and saves it locally
    m_screenHandle = reinterpret_cast<int>(hWnd);

    //Starts the application loop
    MSG msg;
    memset(&msg, 0, sizeof(msg));
    msg.message = WM_NULL;

    while (msg.message != WM_QUIT) {
      //Process messaged
      if (PeekMessageA(&msg, nullptr, 0U, 0U, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }
    }
    return static_cast<int>(msg.wParam);
  }
}