// GameState.cpp

#include "GameState.h"

void GameState::Update() {
    // Skip the update if the game is paused
    if (IsPaused()) {
        return;
    }

    // Update game state here
    for (auto& pair : gameObjects) {
        GameObject& gameObject = pair.second;
        // Update the game object here
    }

    

    // Remove marked objects
    for (auto& pair : objectsToRemove) {
        if (pair.second) {
            gameObjects.erase(pair.first);
            
        }
    }
    objectsToRemove.clear();

    
}


void GameState::Pause() {
    paused = true;
    OutputDebugString(L"Game paused\n");  // Add debug output
}

void GameState::Resume() {
    paused = false;
    OutputDebugString(L"Game resumed\n");  // Add debug output
}

bool GameState::IsPaused() const {
    return paused;
}

void GameState::AddGameObject(const GameObject& gameObject) {
    gameObjects[nextGameObjectId] = gameObject;
    nextGameObjectId++;
}

void GameState::RemoveGameObject(int id) {
    gameObjects.erase(id);
}

GameObject GameState::GetGameObject(int id) const {
    auto it = gameObjects.find(id);
    if (it != gameObjects.end()) {
        return it->second;
    }
    // If the GameObject with the given id is not found, return a default GameObject
    return GameObject();
}

const std::map<int, GameObject>& GameState::GetGameObjects() const {
    return gameObjects;
}

GameState::GameState() {
    // Constructor implementation
}

GameObject& GameState::GetModifiableGameObject(int id) {
    return gameObjects[id];
}

void GameState::MarkForRemoval(int id) {
    objectsToRemove[id] = true;
    
}

std::map<int, GameObject>& GameState::GetModifiableGameObjects() {
    return gameObjects;
}