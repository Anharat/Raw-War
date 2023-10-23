/**
 * @file GameLoop.cpp
 * @brief Implements the GameLoop class functions for the Raw-War game.
 *
 * The GameLoop class provides the functionalities to initialize the game, run the main game loop,
 * handle game updates, manage rendering, and perform cleanup operations at the end.
 *
 * This source file provides the actual implementation of the functions declared in the GameLoop header.
 */

#include "GameLoop.h"  // GameLoop class definition

 /**
  * @brief Constructs the GameLoop object.
  *
  * Initializes the game loop variables, sets up the window, and prepares the RendererManager.
  *
  * @param hInstance Handle to the current instance of the application.
  * @param nCmdShow Controls how the main window is displayed.
  */

GameLoop::GameLoop(HINSTANCE hInstance, int nCmdShow)
    : hInstance(hInstance), nCmdShow(nCmdShow), window(), windowProc(window.GetWindowHandle()), timer() {
    // Create the window with specified title and dimensions
    window.Create("Raw War", 1200, 700);

    // Get the client rectangle of the window
    RECT clientRect = window.GetClientRect();

    // Create the RendererManager with the window handle and client rectangle
    rendererManager = new RendererManager(window.GetWindowHandle(), clientRect);
        
}

/**
 * @brief Destructs the GameLoop object.
 *
 * Ensures proper cleanup of dynamically allocated resources.
 */

GameLoop::~GameLoop() {
    // Delete the RendererManager
    delete rendererManager;

    // Delete the GameMechanicsManager
    delete gameMechanicsManager;
}

/**
 * @brief Sets up the initial game state and initializes necessary managers.
 *
 * Prepares the game for the main game loop.
 */

void GameLoop::Initialize() {
    // Get the client rectangle of the window
    RECT clientRect = window.GetClientRect();

    // Setup the game state with the client rectangle
    Setup(clientRect);

    // Create the GameMechanicsManager with the current game state
    gameMechanicsManager = new GameMechanicsManager(GameState::GetInstance());

    // Initialize the RendererManager
    rendererManager->Initialize();

    // Output a debug string to indicate that initialization is complete
    OutputDebugString(L"Initialize\n");
}

/**
 * @brief Sets up the initial game state.
 *
 * @param clientRect The client rectangle of the window.
 */

void GameLoop::Update(double deltaTime) {
    // Skip the update if the game is paused
    if (GameState::GetInstance().IsPaused()) {
        return;
    }

    // Update the GameMechanicsManager with the delta time
    gameMechanicsManager->Update(deltaTime);

    // Update the game state
    GameState::GetInstance().Update();

    // Check the health of the Player and Enemy objects
    auto gameObjects = GameState::GetInstance().GetGameObjects();
    bool playerAlive = false;
    int enemyCount = 0;
    for (const auto& pair : gameObjects) {
        const GameObject& gameObject = pair.second;
        if (gameObject.objectType == ObjectType::Player) {
            playerAlive = gameObject.health.currentHealth > 0;
        }
        else if (gameObject.objectType == ObjectType::Enemy) {
            if (gameObject.health.currentHealth > 0) {
                enemyCount++;
            }
        }
    }

    // The game ends when the health of the Player reaches 0 or all Enemies' health reach 0
    if (!playerAlive || enemyCount == 0) {
        // You can handle this situation as needed for your game
        // For example, you can pause the game and display a game over message
        GameState::GetInstance().Pause();
    }
}

/**
 * @brief Renders the current game state.
 */

void GameLoop::Render() {
    // Call the Render method of RendererManager to render the game state
    rendererManager->Render();
}

/**
 * @brief Sets up the initial game state.
 *
 * @param clientRect The client rectangle of the window.
 */

void GameLoop::Run() {
    // Initialize the game loop
    Initialize();

    // Set the target delta time for 60 FPS
    const double targetDeltaTime = 1.0 / 60.0;
    double accumulator = 0.0;
    double lastTime = timer.GetElapsedTime();

    // Main game loop
    MSG msg = { 0 };
    while (true) {
        // Process Windows messages if there are any
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            // If the message is WM_QUIT, break the loop and end the game
            if (msg.message == WM_QUIT) {
                break;
            }
            // Translate and dispatch the message to the window procedure
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            // If there are no messages to process, update and render the game
            double currentTime = timer.GetElapsedTime();
            double frameTime = currentTime - lastTime;
            lastTime = currentTime;

            // Accumulate the frame time
            accumulator += frameTime;

            // Update game state based on fixed time step
            while (accumulator >= targetDeltaTime) {
                // Update the game state
                Update(targetDeltaTime);
                // Subtract the target delta time from the accumulator
                accumulator -= targetDeltaTime;
            }

            // Render the game state
            Render();
        }
    }

    // Cleanup the game loop after the main loop has ended
    Cleanup();
}

/**
 * @brief Sets up the initial game state.
 *
 * @param clientRect The client rectangle of the window.
 */
void GameLoop::Cleanup() {
    // This method is responsible for cleaning up resources before the game loop ends

    // Call the Cleanup method of the RendererManager to free up its resources
    rendererManager->Cleanup();

    // Output a debug string to indicate that the cleanup process has started
    // This can be useful for debugging purposes to ensure that Cleanup is being called properly
    OutputDebugString(L"Cleanup\n");
}

