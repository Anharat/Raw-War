// Renderer.cpp

#include "Renderer.h"

Renderer::Renderer(ID2D1HwndRenderTarget* pRenderTarget)
    : pRenderTarget(pRenderTarget) {
    // Create a brush for drawing
    pRenderTarget->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::Black),
        &pBrush
    );
}

Renderer::~Renderer() {
    // Release the brush
    if (pBrush) {
        pBrush->Release();
        pBrush = nullptr;
    }
}

void Renderer::RenderBackground() {
    // Clear the background with a black color
    pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
}

void Renderer::RenderGameObject(const GameObject& gameObject) {
    // Set the brush color based on the game object's color
    pBrush->SetColor(D2D1::ColorF(gameObject.color.r / 255.0f, gameObject.color.g / 255.0f, gameObject.color.b / 255.0f, gameObject.color.a / 255.0f));

    // Draw the game object as a rectangle
    pRenderTarget->FillRectangle(
        D2D1::RectF(gameObject.position.x, gameObject.position.y, gameObject.position.x + gameObject.size.width, gameObject.position.y + gameObject.size.height),
        pBrush
    );
}

void Renderer::RenderHealthBar(float currentHealth, float maxHealth, float x, float y, float width, float height) {
    // Draw the max health bar
    pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::Green));
    pRenderTarget->FillRectangle(
        D2D1::RectF(x, y, x + width, y + height),
        pBrush
    );

    // Draw the current health bar
    pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::White));
    pRenderTarget->FillRectangle(
        D2D1::RectF(x, y, x + (width * currentHealth / maxHealth), y + height),
        pBrush
    );
}

