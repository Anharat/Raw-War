// MyGame.cpp

#include <windows.h>
#include "GameLoop.h"
#pragma comment(lib, "Shcore.lib")

#include <windows.h>
#include <ShellScalingApi.h>  // Include this header for SetProcessDpiAwareness function
#include "GameLoop.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Set the process DPI aware
    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);

    GameLoop gameLoop(hInstance, nCmdShow);
    gameLoop.Run();
    return 0;
}
