// Renderer.h

#ifndef RENDERER_H
#define RENDERER_H

#include <d2d1.h>        // Include Direct2D library
#include "GameObject.h"  // Include the GameObject class
#include <sstream>
#include <iostream>

// The Renderer class handles the rendering of GameObjects and the game background.
// It uses the Direct2D library to draw onto a window.
class Renderer {
public:
    // Constructor takes a pointer to an ID2D1HwndRenderTarget, which represents the area where rendering occurs.
    Renderer(ID2D1HwndRenderTarget* pRenderTarget);

    // Destructor to clean up any allocated resources.
    ~Renderer();

    // Returns a pointer to the ID2D1HwndRenderTarget.
    ID2D1HwndRenderTarget* GetRenderTarget() const { return pRenderTarget; }

    // Renders the game background.
    void RenderBackground();

    // Renders a given GameObject.
    void RenderGameObject(const GameObject& gameObject);

    // Renders a health bar at the given position with the given dimensions.
    // The health bar represents the current health and the maximum health.
    void RenderHealthBar(float currentHealth, float maxHealth, float x, float y, float width, float height);

private:
    ID2D1HwndRenderTarget* pRenderTarget;  // Pointer to the render target, where the rendering happens.
    ID2D1SolidColorBrush* pBrush;          // Pointer to the brush, which defines the color for drawing.
};

#endif // RENDERER_H
