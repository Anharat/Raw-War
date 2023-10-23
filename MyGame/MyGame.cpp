/**
 * @file MyGame.cpp
 * @brief Main entry point for the Raw-War game.
 *
 * This file initializes the game environment, ensuring optimal display settings and then enters the game loop.
 *
 * Dependencies:
 *  - Windows API: Provides core Windows functionalities.
 *  - GameLoop: Custom class that manages the game's main loop.
 *  - ShellScalingApi: Enables the game to be DPI-aware, ensuring sharp visuals on high-resolution displays.
 *
 * Libraries:
 *  - Shcore.lib: Library linked for DPI-awareness functionalities.
 */

#include <windows.h>          // Core Windows functionalities.
#include "GameLoop.h"         // Handles the game's main loop.
#include <ShellScalingApi.h>  // Functions related to DPI-awareness.
#pragma comment(lib, "Shcore.lib")  // Linking required library for DPI-awareness.

 /**
  * @brief The main entry point for the Raw-War game on Windows.
  *
  * @param hInstance Handle to the current instance of the application.
  * @param hPrevInstance Handle to the previous instance of the application (always NULL in modern Windows).
  * @param lpCmdLine Command line arguments as a single string, excluding the program name.
  * @param nCmdShow Specifies how the window is to be shown (e.g., minimized, maximized).
  *
  * @return int Returns 0 upon successful execution.
  */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    // Make the game aware of monitor DPI settings. Essential for high-res displays or multi-monitor setups.
    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);

    // Initialize the game environment.
    GameLoop gameLoop(hInstance, nCmdShow);

    // Enter the main game loop.
    gameLoop.Run();

    // Exit the game.
    return 0;
}
