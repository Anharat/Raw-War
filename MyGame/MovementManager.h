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

// The MovementManager class is responsible for controlling the movement of game objects. 
// It uses different handlers depending on the type of movement the game object is supposed to make. 
class MovementManager {
public:
    // Default constructor for the MovementManager class.
    MovementManager();

    // Destructor for the MovementManager class.
    ~MovementManager();

    // Update the movement pattern of a game object. Takes in the game object's ID, 
    // a reference to the game object itself, and a delta time which represents the elapsed time.
    void UpdateMovementPattern(int id, GameObject& gameObject, double deltaTime);

private:
    // Handle no movement. Called when the game object is supposed to be stationary.
    void HandleNoMovement(GameObject& gameObject);

    // Handle keyboard movement. Called when the game object's movement is controlled by keyboard inputs.
    void HandleKeyboardMovement(int id, GameObject& gameObject, double deltaTime);

    // Handle left and right movement. Called when the game object's movement is supposed to be back and forth in a straight line.
    void HandleLeftAndRightMovement(int id, GameObject& gameObject, double deltaTime);

    // Handle target movement. Called when the game object's movement is supposed to be towards a target game object.
    void HandleTargetMovement(int id, GameObject& gameObject, double deltaTime);

    // An instance of the Timer class used for managing time-related aspects of game object movement.
    Timer timer;

    // An instance of the KeyboardHandler class used for handling keyboard inputs that control game object movement.
    KeyboardHandler keyboardHandler;
};

#endif // MOVEMENTMANAGER_H
