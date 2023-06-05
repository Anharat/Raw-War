// Window.cpp

#include "Window.h"

Window::Window() {
    // Initialize WNDCLASS structure
    wc = { 0 };
    wc.lpfnWndProc = WindowProc::WndProc;  // Set window procedure to WindowProc::WndProc
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"MyWindowClass";
}

Window::~Window() {
    // Cleanup
    UnregisterClass(wc.lpszClassName, wc.hInstance);
}

void Window::Create(const char* title, int width, int height) {

    RECT windowRect = { 0, 0, width, height };
    AdjustWindowRect(&windowRect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE);
    int adjustedWidth = windowRect.right - windowRect.left;
    int adjustedHeight = windowRect.bottom - windowRect.top;


    // Register the window class
    RegisterClass(&wc);

    // Create the window
    hwnd = CreateWindowEx(
        0,                              // Optional window styles
        wc.lpszClassName,               // Window class
        L"My Window",                   // Window text
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,  // Window style
        CW_USEDEFAULT, CW_USEDEFAULT,   // Window initial position
        adjustedWidth, adjustedHeight,  // Window size
        NULL,                           // Parent window
        NULL,                           // Menu
        wc.hInstance,                   // Instance handle
        NULL                            // Additional application data
    );

    // Show the window
    ShowWindow(hwnd, SW_SHOW);
}

HWND Window::GetWindowHandle() const {
    return hwnd;
}

RECT Window::GetClientRect() const {
    RECT rect;
    ::GetClientRect(hwnd, &rect);
    return rect;
}