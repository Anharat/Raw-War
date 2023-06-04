// GameLoop.h

#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "WindowProc.h"
#include "Window.h"
#include "Setup.h"
#include "RendererManager.h"
#include "Timer.h"
#include "GameMechanicsManager.h"
#include <windows.h>
#include <sstream>

class GameLoop {
public:
    GameLoop(HINSTANCE hInstance, int nCmdShow);
    ~GameLoop();

    void Initialize();
    void Update(double deltaTime);
    void Render();
    void Run();
    void Cleanup();

private:
    HINSTANCE hInstance;
    int nCmdShow;
    Window window;
    WindowProc windowProc;
    RendererManager* rendererManager;
    Timer timer;
    GameMechanicsManager* gameMechanicsManager;
};

#endif // GAMELOOP_H