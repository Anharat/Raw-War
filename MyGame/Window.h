// Window.h

#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include "Window.h"
#include "WindowProc.h"
#include <ShellScalingApi.h>

class Window {
public:
    Window();
    ~Window();

    void Create(const char* title, int width, int height);
    HWND GetWindowHandle() const; 
    RECT GetClientRect() const;

private:
    HWND hwnd;
    WNDCLASS wc;
};

#endif // WINDOW_H
