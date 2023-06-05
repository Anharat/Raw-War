// MyGame.cpp

#include <windows.h>  // Windows API
#include "GameLoop.h"  // GameLoop class
#include <ShellScalingApi.h>  // Header for DPI-awareness function (SetProcessDpiAwareness)
#pragma comment(lib, "Shcore.lib")  // Linking Shcore.lib library (for DPI-awareness)


// The entry point of the Windows application
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Set the process DPI aware. This ensures that the application is aware of the DPI (dots per inch) settings 
    // for each monitor, which can be useful if you have high-resolution displays or multiple monitors with 
    // different DPI settings.
    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);

    // Create a GameLoop instance and pass the instance handle (hInstance) and command show option (nCmdShow)
    GameLoop gameLoop(hInstance, nCmdShow);

    // Run the game loop
    gameLoop.Run();

    // Exit the program
    return 0;
}
