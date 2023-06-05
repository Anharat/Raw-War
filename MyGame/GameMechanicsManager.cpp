// GameMechanicsManager.cpp

#include "GameMechanicsManager.h"

// Constructor: Initializes a new GameMechanicsManager instance with a given GameState.
GameMechanicsManager::GameMechanicsManager(GameState& gameState)
    : gameState(gameState) {  // The GameState reference is stored for future manipulation.
    // You can put additional initialization code here if needed.
}

// Destructor: Cleans up the GameMechanicsManager instance before it's destroyed.
GameMechanicsManager::~GameMechanicsManager() {
    // You can put cleanup code here if needed.
}

// Initialize: Prepares the game mechanics as needed at the start of the game or level.
void GameMechanicsManager::Initialize() {
    // Place any game or level initialization code here.
}

// Update: Changes the game mechanics according to the passed-in time interval (deltaTime).
// This function updates the firing and movement patterns of all game objects.
void GameMechanicsManager::Update(double deltaTime) {
    // Iterate over all game objects in the current game state.
    for (auto& pair : gameState.GetGameObjects()) {
        int id = pair.first;  // The id of the current game object.
        GameObject& gameObject = gameState.GetModifiableGameObject(id);  // A reference to the current game object.

        // Update the current game object's firing pattern using the FiringManager.
        firingManager.UpdateFiringPattern(id, gameObject);

        // Update the current game object's movement pattern using the MovementManager.
        movementManager.UpdateMovementPattern(id, gameObject, deltaTime);
    }
}
