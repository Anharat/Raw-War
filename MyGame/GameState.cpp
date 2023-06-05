// GameState.cpp

#include "GameState.h"

// Updates the game state.
void GameState::Update() {
    // Skip the update if the game is paused
    if (IsPaused()) {
        return;
    }

    // Update each game object in the game
    for (auto& pair : gameObjects) {
        GameObject& gameObject = pair.second;
        // Implement code to update the game object here
    }

    // Remove any game objects that have been marked for removal
    for (auto& pair : objectsToRemove) {
        if (pair.second) {
            gameObjects.erase(pair.first);
        }
    }
    // Clear the list of objects to remove for the next frame
    objectsToRemove.clear();
}


// Pauses the game state and logs the action
void GameState::Pause() {
    paused = true;
    OutputDebugString(L"Game paused\n");
}

// Resumes the game state and logs the action
void GameState::Resume() {
    paused = false;
    OutputDebugString(L"Game resumed\n");
}

// Checks if the game is paused
bool GameState::IsPaused() const {
    return paused;
}

// Adds a game object to the game state
void GameState::AddGameObject(const GameObject& gameObject) {
    gameObjects[nextGameObjectId] = gameObject;
    nextGameObjectId++;
}

// Removes a game object from the game state
void GameState::RemoveGameObject(int id) {
    gameObjects.erase(id);
}

// Gets a game object from the game state by its ID
GameObject GameState::GetGameObject(int id) const {
    auto it = gameObjects.find(id);
    if (it != gameObjects.end()) {
        return it->second;
    }
    // If the GameObject with the given id is not found, return a default GameObject
    return GameObject();
}

// Gets a constant reference to the map of game objects
const std::map<int, GameObject>& GameState::GetGameObjects() const {
    return gameObjects;
}

// Constructor for GameState
GameState::GameState() {
    // Initialize game state here
}

// Gets a non-constant reference to a game object from the game state by its ID
GameObject& GameState::GetModifiableGameObject(int id) {
    return gameObjects[id];
}

// Marks a game object for removal from the game state by its ID
void GameState::MarkForRemoval(int id) {
    objectsToRemove[id] = true;
}

// Gets a non-constant reference to the map of game objects
std::map<int, GameObject>& GameState::GetModifiableGameObjects() {
    return gameObjects;
}
