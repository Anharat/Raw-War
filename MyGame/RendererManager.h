// RendererManager.h

#ifndef RENDERERMANAGER_H
#define RENDERERMANAGER_H

#include "Renderer.h" // Include the Renderer class
#include "GameState.h" // Include the GameState class for accessing game data
#include <windows.h> // Include the Windows API

// The RendererManager class manages a Renderer and handles the rendering of the game state.
class RendererManager {
public:
    // Constructor takes a window handle (HWND) and a RECT for the client area of the window.
    RendererManager(HWND hwnd, RECT clientRect);

    // Destructor to clean up any allocated resources.
    ~RendererManager();

    // Initialize the RendererManager, typically called once at the start of the game.
    void Initialize();

    // Render the current game state.
    void Render();

    // Cleanup the RendererManager, typically called once at the end of the game.
    void Cleanup();

    // Get the client rectangle of the window.
    RECT GetClientRect() const;

    // Get the width of the render target (in pixels).
    UINT GetRenderTargetWidth() const;

    // Get the height of the render target (in pixels).
    UINT GetRenderTargetHeight() const;

private:
    Renderer* renderer;  // Pointer to the Renderer instance used for drawing the game state.
    RECT clientRect;  // The client area of the window where the game state is rendered.
};

#endif // RENDERERMANAGER_H

