// WindowProc.cpp

#include "WindowProc.h"

WindowProc::WindowProc(HWND hwnd) : hwnd(hwnd) {  // Use colon instead of comma
    // Constructor code here
    RegisterObserver(&GameState::GetInstance());  // Register GameState as an observer
}

WindowProc::~WindowProc() {
    // Destructor code here
    UnregisterObserver(&GameState::GetInstance());  // Unregister GameState as an observer
}

LRESULT CALLBACK WindowProc::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    // Handle window messages here

    static bool isPaused = false;  // Add this line

    switch (uMsg) {
    case WM_ACTIVATE:
        // The window is being activated or deactivated.
        if (LOWORD(wParam) == WA_INACTIVE) {
            // The window is being deactivated.
            GameState::GetInstance().Pause();
        }
        else {
            // The window is being activated.
            GameState::GetInstance().Resume();
        }
        return 0;

    case WM_NCLBUTTONDOWN:
        // The left mouse button is pressed in the non-client area.
        if (wParam == HTCAPTION) {  // Check if the user clicked on the title bar
            GameState::GetInstance().Pause();
            isPaused = true;  // Add this line
            OutputDebugString(L"Left mouse button pressed in non-client area, game paused\n");  // Add debug output
        }
        break;  // Let the default window procedure handle the message

    case WM_NCMOUSEMOVE:
        // The mouse is moved in the non-client area.
        if (isPaused) {  // Check if the game is paused
            GameState::GetInstance().Resume();
            isPaused = false;  // Add this line
            OutputDebugString(L"Mouse moved in non-client area, game resumed\n");  // Add debug output
        }
        break;  // Let the default window procedure handle the message

    case WM_CLOSE:
        // The window is being closed.
        PostQuitMessage(0);  // Post a WM_QUIT message to the message queue
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}






void WindowProc::RegisterObserver(IObserver* observer) {
    observers.push_back(observer);
}

void WindowProc::UnregisterObserver(IObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void WindowProc::NotifyObservers() {
    for (IObserver* observer : observers) {
        observer->Update();
    }
}
