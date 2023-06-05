// GameLoop.cpp

#include "GameLoop.h"

GameLoop::GameLoop(HINSTANCE hInstance, int nCmdShow)
    : hInstance(hInstance), nCmdShow(nCmdShow), window(), windowProc(window.GetWindowHandle()), timer() {
    // Create the window
    window.Create("My Window", 1200, 700);

    // Get the client rectangle of the window
    RECT clientRect = window.GetClientRect();

    // Create the RendererManager
    rendererManager = new RendererManager(window.GetWindowHandle(), clientRect);

    // Don't create the GameMechanicsManager here
}

GameLoop::~GameLoop() {
    // Delete the RendererManager
    delete rendererManager;

    // Delete the GameMechanicsManager
    delete gameMechanicsManager;
}

void GameLoop::Initialize() {
    // Initialization code here
    RECT clientRect = window.GetClientRect();
    Setup(clientRect);

    // Create the GameMechanicsManager after the GameState has been initialized
    gameMechanicsManager = new GameMechanicsManager(GameState::GetInstance());

    rendererManager->Initialize();
    OutputDebugString(L"Initialize\n");
}

void GameLoop::Update(double deltaTime) {
    // Skip the update if the game is paused
    if (GameState::GetInstance().IsPaused()) {
        return;
    }

    // Update the GameMechanicsManager
    gameMechanicsManager->Update(deltaTime);

    // Update the GameState
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




void GameLoop::Render() {
    // Rendering code here
    rendererManager->Render();  // Call the Render method of RendererManager
}

void GameLoop::Run() {
    Initialize();

    const double targetDeltaTime = 1.0 / 60.0;  // Target delta time for 60 FPS
    double accumulator = 0.0;
    double lastTime = timer.GetElapsedTime();

    // Main game loop
    MSG msg = { 0 };
    while (true) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            double currentTime = timer.GetElapsedTime();
            double frameTime = currentTime - lastTime;
            lastTime = currentTime;

            accumulator += frameTime;

            // Update game state based on fixed time step
            while (accumulator >= targetDeltaTime) {
                Update(targetDeltaTime);
                accumulator -= targetDeltaTime;
            }

            Render();
        }
    }

    Cleanup();
}

void GameLoop::Cleanup() {
    // Cleanup code here
    rendererManager->Cleanup();  // Cleanup the RendererManager
    OutputDebugString(L"Cleanup\n");
}
