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
    // Register the window class
    RegisterClass(&wc);

    // Create the window
    hwnd = CreateWindowEx(
        0,                              // Optional window styles
        wc.lpszClassName,               // Window class
        L"My Window",                   // Window text. Change this line
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,  // Window style
        CW_USEDEFAULT, CW_USEDEFAULT,   // Window initial position
        width, height,                  // Window size
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

    // Get the DPI for the window
    UINT dpi = GetDpiForWindow(hwnd);

    // Calculate the scaling factor
    float scaleFactor = dpi / 96.0f;  // 96 DPI is the default

    // Scale the client rectangle
    rect.right = static_cast<LONG>(rect.right * scaleFactor);
    rect.bottom = static_cast<LONG>(rect.bottom * scaleFactor);

    return rect;
}