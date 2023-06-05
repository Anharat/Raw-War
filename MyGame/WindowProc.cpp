// WindowProc.cpp

#include "WindowProc.h"

// Constructor: initializes hwnd and registers GameState as an observer.
WindowProc::WindowProc(HWND hwnd) : hwnd(hwnd) {
    RegisterObserver(&GameState::GetInstance());
}

// Destructor: unregister GameState as an observer.
WindowProc::~WindowProc() {
    UnregisterObserver(&GameState::GetInstance());
}

// Handle window messages and control game state.
LRESULT CALLBACK WindowProc::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    // Static variable for keeping track of the paused state
    static bool isPaused = false;

    switch (uMsg) {
    case WM_ACTIVATE:
        // Handle window activation and deactivation
        if (LOWORD(wParam) == WA_INACTIVE) {
            GameState::GetInstance().Pause();
        }
        else {
            GameState::GetInstance().Resume();
        }
        return 0;

    case WM_NCLBUTTONDOWN:
        // Handle left mouse button pressed in the non-client area (title bar)
        if (wParam == HTCAPTION) {
            GameState::GetInstance().Pause();
            isPaused = true;
        }
        break;

    case WM_NCMOUSEMOVE:
        // Handle mouse movement in the non-client area
        if (isPaused) {
            GameState::GetInstance().Resume();
            isPaused = false;
        }
        break;

    case WM_CLOSE:
        // Handle window closing
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Register an observer in the observer list.
void WindowProc::RegisterObserver(IObserver* observer) {
    observers.push_back(observer);
}

// Remove an observer from the observer list.
void WindowProc::UnregisterObserver(IObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

// Notify all observers by calling their Update method.
void WindowProc::NotifyObservers() {
    for (IObserver* observer : observers) {
        observer->Update();
    }
}
