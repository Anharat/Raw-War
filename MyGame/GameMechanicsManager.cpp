// GameMechanicsManager.cpp

#include "GameMechanicsManager.h"

GameMechanicsManager::GameMechanicsManager(GameState& gameState)
    : gameState(gameState) {
    // Constructor implementation
}

GameMechanicsManager::~GameMechanicsManager() {
    // Destructor implementation
}

void GameMechanicsManager::Initialize() {
    // Initialization code here
}

void GameMechanicsManager::Update(double deltaTime) {
    // Update game mechanics here
    // Update FiringManager and MovementManager
    // Iterate over all game objects and update their firing pattern and movement pattern
    for (auto& pair : gameState.GetGameObjects()) {
        int id = pair.first;
        GameObject& gameObject = gameState.GetModifiableGameObject(id);
        firingManager.UpdateFiringPattern(id, gameObject);
        movementManager.UpdateMovementPattern(id, gameObject, deltaTime);
    }

}
