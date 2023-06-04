// GameState.h

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "IObserver.h"
#include "GameObject.h"  // Include GameObject.h
#include <windows.h>  // Include windows.h for OutputDebugString
#include <map>  // Include map library
#include <iostream>
#include <sstream>

class GameState : public IObserver {
public:
    static GameState& GetInstance() {
        static GameState instance;
        return instance;
    }

    void Update() override;

    void Pause();

    void Resume();

    bool IsPaused() const;

    // Add a GameObject to the map
    void AddGameObject(const GameObject& gameObject);

    // Remove a GameObject from the map
    void RemoveGameObject(int id);

    // Get a GameObject from the map
    GameObject GetGameObject(int id) const;

    // Get the map of GameObjects
    const std::map<int, GameObject>& GetGameObjects() const;

    // Get a non-const reference to a GameObject from the map
    GameObject& GetModifiableGameObject(int id);

    // Get a non-const map of GameObjects
    std::map<int, GameObject>& GetModifiableGameObjects();

    void MarkForRemoval(int id);

private:
    GameState();  // Private constructor

    // Delete copy constructor and assignment operator
    GameState(const GameState&) = delete;
    GameState& operator=(const GameState&) = delete;

    bool paused = false;
    int nextGameObjectId = 0;  // ID for the next GameObject to be added

    // Map of GameObjects
    std::map<int, GameObject> gameObjects;

    std::map<int, bool> objectsToRemove;

};

#endif // GAMESTATE_H
