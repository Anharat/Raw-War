// RendererManager.h

#ifndef RENDERERMANAGER_H
#define RENDERERMANAGER_H

#include "Renderer.h"
#include "GameState.h"
#include <windows.h>

class RendererManager {
public:
    RendererManager(HWND hwnd, RECT clientRect);  // Add RECT parameter
    ~RendererManager();

    void Initialize();
    void Render();
    void Cleanup();
    RECT GetClientRect() const;  // Add this line
    UINT GetRenderTargetWidth() const;  // Add this line
    UINT GetRenderTargetHeight() const;  // Add this line

private:
    Renderer* renderer;
    RECT clientRect;  // Add this line
};

#endif // RENDERERMANAGER_H
