// GameLoop.h

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

// GameLoop class declaration
class GameLoop {
public:
    GameLoop(HINSTANCE hInstance, int nCmdShow);  // Constructor
    ~GameLoop();  // Destructor

    void Initialize();  // Initialize the game loop
    void Update(double deltaTime);  // Update the game state
    void Render();  // Render the game state
    void Run();  // Run the game loop
    void Cleanup();  // Cleanup the game loop

private:
    HINSTANCE hInstance;  // Handle to the current instance of the application
    int nCmdShow;  // Controls how the window is to be shown
    Window window;  // Window object
    WindowProc windowProc;  // Window procedure object
    RendererManager* rendererManager;  // Pointer to the RendererManager
    Timer timer;  // Timer object
    GameMechanicsManager* gameMechanicsManager;  // Pointer to the GameMechanicsManager
};

#endif // GAMELOOP_H