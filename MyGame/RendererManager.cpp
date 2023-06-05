// RendererManager.cpp

#include "RendererManager.h"
#include "GameState.h"
#include <d2d1.h>

RendererManager::RendererManager(HWND hwnd, RECT clientRect)  // Add RECT parameter
    : clientRect(clientRect) {  // Initialize clientRect
    // Create a D2D1 factory
    ID2D1Factory* pFactory;
    D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory);

    // Get the DPI for the window
    UINT dpi = GetDpiForWindow(hwnd);

    // Calculate the scaling factor
    float scaleFactor = dpi / 96.0f;  // 96 DPI is the default

    // Scale the dimensions of the client rectangle
    UINT width = static_cast<UINT>((clientRect.right - clientRect.left) * scaleFactor);
    UINT height = static_cast<UINT>((clientRect.bottom - clientRect.top) * scaleFactor);

    // Create a render target
    ID2D1HwndRenderTarget* pRenderTarget;
    pFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(width, height)),  // Use the scaled size
        &pRenderTarget
    );

    // Create a new Renderer
    renderer = new Renderer(pRenderTarget);

    // Release the factory
    pFactory->Release();
}


RendererManager::~RendererManager() {
    // Delete the Renderer
    delete renderer;
}

void RendererManager::Initialize() {
    // Initialization code here
}

void RendererManager::Render() {
    // Begin drawing
    renderer->GetRenderTarget()->BeginDraw();

    // Clear the background
    renderer->RenderBackground();

    // Render each game object
    const auto& gameObjects = GameState::GetInstance().GetGameObjects();
    for (const auto& pair : gameObjects) {
        renderer->RenderGameObject(pair.second);
    }

    // Render the player's health bar
    const auto& playerIter = std::find_if(gameObjects.begin(), gameObjects.end(),
        [](const std::pair<int, GameObject>& pair) {
            return pair.second.objectType == ObjectType::Player;
        });

    if (playerIter != gameObjects.end()) {
        const GameObject& player = playerIter->second;
        renderer->RenderHealthBar(player.health.currentHealth, player.health.maxHealth, 15.0f, clientRect.bottom - 30.0f, 200.0f, 20.0f);
    }

    // Render the enemies' health bars
    float enemyHealthBarY = 10.0f;  // Starting Y position for enemy health bars
    const float enemyHealthBarHeight = 20.0f;  // Height of each enemy health bar
    const float enemyHealthBarSpacing = 5.0f;  // Spacing between enemy health bars

    for (const auto& pair : gameObjects) {
        if (pair.second.objectType == ObjectType::Enemy) {
            const GameObject& enemy = pair.second;
            renderer->RenderHealthBar(enemy.health.currentHealth, enemy.health.maxHealth, clientRect.right - 210.0f, enemyHealthBarY, 200.0f, enemyHealthBarHeight);

            // Move the Y position down for the next health bar
            enemyHealthBarY += enemyHealthBarHeight + enemyHealthBarSpacing;
        }
    }

    // End drawing
    renderer->GetRenderTarget()->EndDraw();
}


void RendererManager::Cleanup() {
    // Cleanup code here
}

RECT RendererManager::GetClientRect() const {
    return clientRect;
}

UINT RendererManager::GetRenderTargetWidth() const {
    return clientRect.right - clientRect.left;
}

UINT RendererManager::GetRenderTargetHeight() const {
    return clientRect.bottom - clientRect.top;
}