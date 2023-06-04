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

void Window::Create(const char* title) {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN); // Get the screen width
    int screenHeight = GetSystemMetrics(SM_CYSCREEN); // Get the screen height

    // Register the window class
    RegisterClass(&wc);

    // Create the window
    hwnd = CreateWindowEx(
        0,                              // Optional window styles
        wc.lpszClassName,               // Window class
        L"My Window",                   // Window text. Change this line
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,  // Window style
        CW_USEDEFAULT, CW_USEDEFAULT,   // Window initial position
        screenWidth, screenHeight,      // Window size
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