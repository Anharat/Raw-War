// MovementManager.h

#ifndef MOVEMENTMANAGER_H
#define MOVEMENTMANAGER_H

#include "GameObject.h"
#include "GameState.h"
#include "CollisionManager.h"
#include "KeyboardHandler.h"
#include <cmath>
#include <iostream>
#include "Timer.h"
#include <locale>
#include <codecvt>

class MovementManager {
public:
    MovementManager();
    ~MovementManager();

    void UpdateMovementPattern(int id, GameObject& gameObject, double deltaTime);

private:
    void HandleNoMovement(GameObject& gameObject);
    void HandleKeyboardMovement(int id, GameObject& gameObject, double deltaTime);
    void HandleLeftAndRightMovement(int id, GameObject& gameObject, double deltaTime);
    void HandleTargetMovement(int id, GameObject& gameObject, double deltaTime);

    Timer timer;

    KeyboardHandler keyboardHandler;
};

#endif // MOVEMENTMANAGER_H
