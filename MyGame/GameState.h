// GameState.h

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "IObserver.h"
#include "GameObject.h"  
#include <windows.h>  // Include windows.h for OutputDebugString
#include <map>  // Include map library to manage GameObjects
#include <iostream>
#include <sstream>

// The GameState class is a singleton class that manages the state of the game.
// It handles adding, removing and getting GameObjects.
// It also has methods to pause, resume, and check if the game is paused.
// The class inherits from IObserver, so it can receive notifications about changes in game objects.
class GameState : public IObserver {
public:
    // Get the single instance of the GameState class.
    static GameState& GetInstance() {
        static GameState instance;
        return instance;
    }

    // Update the game state, called every frame.
    void Update() override;

    // Pause the game.
    void Pause();

    // Resume the game.
    void Resume();

    // Check if the game is paused.
    bool IsPaused() const;

    // Add a new GameObject to the map.
    void AddGameObject(const GameObject& gameObject);

    // Remove a GameObject from the map by its ID.
    void RemoveGameObject(int id);

    // Get a GameObject from the map by its ID.
    GameObject GetGameObject(int id) const;

    // Get a constant reference to the map of GameObjects.
    const std::map<int, GameObject>& GetGameObjects() const;

    // Get a non-constant reference to a GameObject from the map by its ID.
    GameObject& GetModifiableGameObject(int id);

    // Get a non-constant reference to the map of GameObjects.
    std::map<int, GameObject>& GetModifiableGameObjects();

    // Mark a GameObject for removal by its ID.
    void MarkForRemoval(int id);

private:
    GameState();  // Private constructor for the Singleton pattern

    // Delete copy constructor and assignment operator to prevent duplication of the Singleton
    GameState(const GameState&) = delete;
    GameState& operator=(const GameState&) = delete;

    // Boolean to keep track if the game is paused or not.
    bool paused = false;

    // ID for the next GameObject to be added. Incremented after adding a GameObject.
    int nextGameObjectId = 0;

    // Map of GameObjects, keyed by their IDs.
    std::map<int, GameObject> gameObjects;

    // Map of GameObjects marked for removal, keyed by their IDs.
    std::map<int, bool> objectsToRemove;
};

#endif // GAMESTATE_H

