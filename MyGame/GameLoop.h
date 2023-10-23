/**
 * @file GameLoop.h
 * @brief Provides the main game loop and related functionalities for the Raw-War game.
 *
 * The GameLoop class is responsible for initializing the game, running the main game loop,
 * updating the game state, rendering the game objects, and cleaning up resources.
 *
 * Dependencies:
 *  - WindowProc: Manages the window procedure functionalities.
 *  - Window: Represents the main game window.
 *  - Setup: Used for setting up the initial game state.
 *  - RendererManager: Handles rendering of game objects.
 *  - Timer: Provides timing functionalities for the game loop.
 *  - GameMechanicsManager: Manages game mechanics and interactions.
 *  - Windows API: Utilized for core Windows functionalities.
 *  - sstream: Used for string stream operations.
 *
 * Key Components:
 *  - Game Loop: The core loop that keeps the game running, updating, and rendering.
 *  - Initialization & Cleanup: Prepares the game environment and cleans up resources at the end.
 *
 * @note The class makes extensive use of pointers for managing game mechanics and rendering. Ensure proper memory management.
 */

#ifndef GAMELOOP_H  // Preprocessor directive to prevent multiple inclusions of the header file
#define GAMELOOP_H

 // Include necessary header files
#include "WindowProc.h"
#include "Window.h"
#include "Setup.h"
#include "RendererManager.h"
#include "Timer.h"
#include "GameMechanicsManager.h"
#include <windows.h>
#include <sstream>

/**
 * @class GameLoop
 * @brief Manages the main game loop and related functionalities.
 *
 * This class initializes the game, runs the main loop, updates game state,
 * renders game objects, and ensures resource cleanup at the end.
 */
class GameLoop {
public:
    /**
     * @brief Constructor to initialize game loop variables.
     *
     * @param hInstance Handle to the current instance of the application.
     * @param nCmdShow Controls how the main window is displayed.
     */
    GameLoop(HINSTANCE hInstance, int nCmdShow);

    /**
     * @brief Destructor to ensure proper cleanup of resources.
     */
    ~GameLoop();

    /**
     * @brief Initializes the game environment.
     */
    void Initialize();

    /**
     * @brief Updates the game state based on a fixed time step.
     *
     * @param deltaTime Time since the last update.
     */
    void Update(double deltaTime);

    /**
     * @brief Renders the current game state.
     */
    void Render();

    /**
     * @brief Main game loop that keeps the game running.
     */
    void Run();

    /**
     * @brief Cleans up resources and prepares the game for exit.
     */
    void Cleanup();

private:
    HINSTANCE hInstance;  // Current instance handle of the application
    int nCmdShow;  // Display option for the main window
    Window window;  // Represents the main game window
    WindowProc windowProc;  // Handles window procedure functionalities
    RendererManager* rendererManager;  // Manages game rendering
    Timer timer;  // Provides timing functionalities
    GameMechanicsManager* gameMechanicsManager;  // Manages core game mechanics
};

#endif // GAMELOOP_H
