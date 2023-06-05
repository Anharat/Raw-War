// Window.h

#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>      // Include the Windows API
#include "WindowProc.h"   // Include the WindowProc class
#include <ShellScalingApi.h>  // API for handling DPI scaling on Windows

// The Window class represents a window in a Windows application.
class Window {
public:
    Window();  // Constructor
    ~Window(); // Destructor

    // Creates a window with the specified title, width, and height.
    void Create(const char* title, int width, int height);

    // Returns the handle to the window (HWND).
    HWND GetWindowHandle() const;

    // Returns the client rectangle of the window.
    RECT GetClientRect() const;

private:
    HWND hwnd;  // Handle to the window
    WNDCLASS wc; // Structure containing the window class information
};

#endif // WINDOW_H
