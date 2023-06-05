// Renderer.cpp

#include "Renderer.h"

// Constructor implementation. Takes a pointer to an ID2D1HwndRenderTarget as an argument.
// Initializes member variables and creates a solid color brush for rendering.
Renderer::Renderer(ID2D1HwndRenderTarget* pRenderTarget)
    : pRenderTarget(pRenderTarget) {
    // Create a solid color brush, initially set to black color, for drawing on the render target.
    pRenderTarget->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::Black),
        &pBrush
    );
}

// Destructor implementation. Releases any resources used by the class.
Renderer::~Renderer() {
    // If the brush exists, release it and set the pointer to nullptr.
    if (pBrush) {
        pBrush->Release();
        pBrush = nullptr;
    }
}

// Renders the game background by clearing the render target to a black color.
void Renderer::RenderBackground() {
    // Clear the render target with a black color.
    pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
}

// Renders a given GameObject onto the render target.
void Renderer::RenderGameObject(const GameObject& gameObject) {
    // Set the brush color to the color of the GameObject.
    pBrush->SetColor(D2D1::ColorF(gameObject.color.r / 255.0f, gameObject.color.g / 255.0f, gameObject.color.b / 255.0f, gameObject.color.a / 255.0f));

    // Draw the GameObject as a rectangle using the brush.
    pRenderTarget->FillRectangle(
        D2D1::RectF(gameObject.position.x, gameObject.position.y, gameObject.position.x + gameObject.size.width, gameObject.position.y + gameObject.size.height),
        pBrush
    );
}

// Renders a health bar at a specified location, representing the current and maximum health of a GameObject.
void Renderer::RenderHealthBar(float currentHealth, float maxHealth, float x, float y, float width, float height) {
    // Set the brush color to green and draw the max health bar.
    pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::Green));
    pRenderTarget->FillRectangle(
        D2D1::RectF(x, y, x + width, y + height),
        pBrush
    );

    // Set the brush color to white and draw the current health bar over the max health bar.
    // The length of the current health bar represents the ratio of current health to max health.
    pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::White));
    pRenderTarget->FillRectangle(
        D2D1::RectF(x, y, x + (width * currentHealth / maxHealth), y + height),
        pBrush
    );
}

