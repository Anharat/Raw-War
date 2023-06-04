// WindowProc.h

#ifndef WINDOWPROC_H
#define WINDOWPROC_H

#include <windows.h>
#include <vector>
#include "IObserver.h"
#include "GameState.h"

class WindowProc {
public:
    WindowProc(HWND hwnd);  // Add HWND parameter
    ~WindowProc();

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    void RegisterObserver(IObserver* observer);
    void UnregisterObserver(IObserver* observer);

private:
    HWND hwnd;  // Add this line
    std::vector<IObserver*> observers;

    void NotifyObservers();
};

#endif // WINDOWPROC_H
