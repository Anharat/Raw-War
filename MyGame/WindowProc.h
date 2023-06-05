// WindowProc.h

#ifndef WINDOWPROC_H
#define WINDOWPROC_H

#include <windows.h>  // Windows API
#include <vector>  // Standard C++ library: vector
#include "IObserver.h"  // IObserver class (for observer pattern)
#include "GameState.h"  // GameState class

// WindowProc class handles window procedures and manages observers.
class WindowProc {
public:
    // Constructor takes a window handle (HWND)
    WindowProc(HWND hwnd);

    // Destructor to clean up any allocated resources.
    ~WindowProc();

    // Static window procedure callback function.
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    // Register an observer.
    void RegisterObserver(IObserver* observer);

    // Unregister an observer.
    void UnregisterObserver(IObserver* observer);

private:
    HWND hwnd;  // Handle to the window
    std::vector<IObserver*> observers;  // List of observers

    // Notify all registered observers.
    void NotifyObservers();
};

#endif // WINDOWPROC_H
