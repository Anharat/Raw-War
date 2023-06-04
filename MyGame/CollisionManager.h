// CollisionManager.h

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "GameObject.h"
#include "KeyboardHandler.h"  // Include KeyboardHandler.h
#include "GameState.h"  // Include GameState.h
#include <iostream>
#include <unordered_map>

class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager();

    bool CheckCollision(const GameObject& object1, const GameObject& object2);
    Position PredictFuturePosition(const GameObject& object, double deltaTime);
    Position PredictFutureLeftAndRightPosition(const GameObject& gameObject, double deltaTime);
    const GameObject* GetCollidingObject(const GameObject& object1, const GameObject& object2);


private:
    KeyboardHandler keyboardHandler;  // Add a KeyboardHandler member
};

#endif // COLLISIONMANAGER_H

