// CollisionManager.h

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "GameObject.h"  // Include the GameObject class which represents an object in the game (e.g., player, enemy, wall)
#include "KeyboardHandler.h"  // Include the KeyboardHandler class for managing keyboard input
#include "GameState.h"  // Include the GameState class which represents the state of the game at any given instance
#include <iostream>
#include <unordered_map>

// The CollisionManager class provides functionality for detecting and handling collisions between GameObjects
class CollisionManager {
public:
    // Constructor for the CollisionManager class
    CollisionManager();
    // Destructor for the CollisionManager class
    ~CollisionManager();

    // Check if two GameObjects are colliding. It checks the bounding boxes of the GameObjects for overlap.
    bool CheckCollision(const GameObject& object1, const GameObject& object2);

    // Predict the future position of a GameObject based on its current position, speed, direction, and a specified time delta.
    Position PredictFuturePosition(const GameObject& object, double deltaTime);

    // Predict the future left and right positions of a GameObject based on its initial position and a specified time delta.
    Position PredictFutureLeftAndRightPosition(const GameObject& gameObject, double deltaTime);

    // Return a pointer to the GameObject that is colliding with the provided GameObject.
    // If there is no collision, return nullptr.
    const GameObject* GetCollidingObject(const GameObject& object1, const GameObject& object2);

private:
    KeyboardHandler keyboardHandler;  // Instance of the KeyboardHandler for handling keyboard input
};

#endif // COLLISIONMANAGER_H

