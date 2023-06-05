// RendererManager.cpp

#include "RendererManager.h"
#include "GameState.h"
#include <d2d1.h>

// Constructor
RendererManager::RendererManager(HWND hwnd, RECT clientRect) : clientRect(clientRect) {
    // Create a Direct2D factory
    ID2D1Factory* pFactory;
    D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory);

    // Get the DPI for the window. DPI stands for Dots Per Inch.
    UINT dpi = GetDpiForWindow(hwnd);

    // Calculate the scaling factor based on the DPI (96 DPI is the default)
    float scaleFactor = dpi / 96.0f;

    // Scale the dimensions of the client rectangle using the scaling factor
    UINT width = static_cast<UINT>((clientRect.right - clientRect.left) * scaleFactor);
    UINT height = static_cast<UINT>((clientRect.bottom - clientRect.top) * scaleFactor);

    // Create a render target using the window handle and the scaled size
    ID2D1HwndRenderTarget* pRenderTarget;
    pFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(width, height)),
        &pRenderTarget
    );

    // Create a new Renderer instance using the render target
    renderer = new Renderer(pRenderTarget);

    // Release the Direct2D factory
    pFactory->Release();
}

// Destructor
RendererManager::~RendererManager() {
    // Delete the Renderer instance
    delete renderer;
}

void RendererManager::Initialize() {
    // Add any initialization code for the RendererManager here
}

// Render function
void RendererManager::Render() {
    // Begin drawing onto the render target
    renderer->GetRenderTarget()->BeginDraw();

    // Clear the background
    renderer->RenderBackground();

    // Render each game object from the game state
    const auto& gameObjects = GameState::GetInstance().GetGameObjects();
    for (const auto& pair : gameObjects) {
        renderer->RenderGameObject(pair.second);
    }

    // Find the player object and render its health bar
    const auto& playerIter = std::find_if(gameObjects.begin(), gameObjects.end(),
        [](const std::pair<int, GameObject>& pair) {
            return pair.second.objectType == ObjectType::Player;
        });

    // Render player's health bar if player exists
    if (playerIter != gameObjects.end()) {
        const GameObject& player = playerIter->second;
        renderer->RenderHealthBar(player.health.currentHealth, player.health.maxHealth, 15.0f, clientRect.bottom - 30.0f, 200.0f, 20.0f);
    }

    // Render the health bars for each enemy object
    float enemyHealthBarY = 10.0f;
    const float enemyHealthBarHeight = 20.0f;
    const float enemyHealthBarSpacing = 5.0f;
    for (const auto& pair : gameObjects) {
        if (pair.second.objectType == ObjectType::Enemy) {
            const GameObject& enemy = pair.second;
            renderer->RenderHealthBar(enemy.health.currentHealth, enemy.health.maxHealth, clientRect.right - 210.0f, enemyHealthBarY, 200.0f, enemyHealthBarHeight);
            enemyHealthBarY += enemyHealthBarHeight + enemyHealthBarSpacing;
        }
    }

    // End drawing onto the render target
    renderer->GetRenderTarget()->EndDraw();
}


void RendererManager::Cleanup() {
    // This function should contain code to clean up resources when the RendererManager is done.
    // For instance, this is where you might release graphics resources or other data used during rendering.
}

// Function to return the client rectangle.
// The client rectangle is the area of the window where the game state is rendered.
RECT RendererManager::GetClientRect() const {
    return clientRect;
}

// Function to get the width of the render target.
// This is calculated as the width of the client rectangle.
// The render target is the area where we draw our game objects.
UINT RendererManager::GetRenderTargetWidth() const {
    return clientRect.right - clientRect.left;
}

// Function to get the height of the render target.
// This is calculated as the height of the client rectangle.
UINT RendererManager::GetRenderTargetHeight() const {
    return clientRect.bottom - clientRect.top;
}