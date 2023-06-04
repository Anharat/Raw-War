// MyGame.cpp

#include <windows.h>
#include "GameLoop.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    GameLoop gameLoop(hInstance, nCmdShow);
    gameLoop.Run();
    return 0;
}