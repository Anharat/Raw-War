// Window.cpp

#include "Window.h"

// Constructor initializes the WNDCLASS structure
Window::Window() {
    // Initialize WNDCLASS structure
    wc = { 0 };
    wc.lpfnWndProc = WindowProc::WndProc;  // Set window procedure to WindowProc::WndProc
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"MyWindowClass";
}

// Destructor cleans up the window class.
Window::~Window() {
    // Cleanup: unregister the window class
    UnregisterClass(wc.lpszClassName, wc.hInstance);
}

// Create a new window with the specified title, width, and height.
void Window::Create(const char* title, int width, int height) {
    // Register the window class
    RegisterClass(&wc);

    // Create the window
    hwnd = CreateWindowEx(
        0,                              // Optional window styles
        wc.lpszClassName,               // Window class
        L"Raw War",                   // Window text
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

// Get the handle to the window
HWND Window::GetWindowHandle() const {
    return hwnd;
}

// Get the client rectangle of the window and scale it according to the DPI of the window
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
