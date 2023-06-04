// CollisionManager.cpp

#include "CollisionManager.h"

CollisionManager::CollisionManager() {
    // Constructor implementation
}

CollisionManager::~CollisionManager() {
    // Destructor implementation
}

bool CollisionManager::CheckCollision(const GameObject& object1, const GameObject& object2) {
    // Check if the bounding boxes of the two GameObjects overlap
    // This is a simple AABB collision detection
    if (object1.position.x < object2.position.x + object2.size.width &&
        object1.position.x + object1.size.width > object2.position.x &&
        object1.position.y < object2.position.y + object2.size.height &&
        object1.position.y + object1.size.height > object2.position.y) {
        // The bounding boxes overlap, so there is a collision
        return true;
    }

    
    return false;
}

Position CollisionManager::PredictFuturePosition(const GameObject& object, double deltaTime) {
    Position futurePosition = object.position;

    double framesAhead = 0.5;

    keyboardHandler.Update();

    // Calculate the future position based on the current velocity and direction
    if (keyboardHandler.IsKeyDown('W')) {
        futurePosition.y -= static_cast<float>(object.speed * deltaTime * framesAhead);
    }
    if (keyboardHandler.IsKeyDown('S')) {
        futurePosition.y += static_cast<float>(object.speed * deltaTime * framesAhead);
    }
    if (keyboardHandler.IsKeyDown('A')) {
        futurePosition.x -= static_cast<float>(object.speed * deltaTime * framesAhead);
    }
    if (keyboardHandler.IsKeyDown('D')) {
        futurePosition.x += static_cast<float>(object.speed * deltaTime * framesAhead);
    }


    return futurePosition;
}

// CollisionManager.cpp
Position CollisionManager::PredictFutureLeftAndRightPosition(const GameObject& gameObject, double deltaTime) {
    Position futurePosition = gameObject.position;

    // Calculate the left and right positions based on the initial position
    float leftPosition = gameObject.initialPosition.x - 200.0f;
    float rightPosition = gameObject.initialPosition.x + 200.0f;

    // Define the number of frames ahead to predict
    double framesAhead = 0.5;

    // Calculate the new position based on the speed, direction, deltaTime, and framesAhead
    float newPosition = gameObject.position.x + gameObject.velocity.dx * gameObject.speed * static_cast<float>(deltaTime * framesAhead);

    // Check if the new position has reached or passed the left or right position
    if (newPosition <= leftPosition) {
        // If the new position is at or past the left position, set the future position to the left position
        futurePosition.x = leftPosition;
    }
    else if (newPosition >= rightPosition) {
        // If the new position is at or past the right position, set the future position to the right position
        futurePosition.x = rightPosition;
    }
    else {
        // If the new position is between the left and right positions, update the future position
        futurePosition.x = newPosition;
    }

    return futurePosition;
}

const GameObject* CollisionManager::GetCollidingObject(const GameObject& object1, const GameObject& object2) {
    // Check if the bounding boxes of the two GameObjects overlap
    if (object1.position.x < object2.position.x + object2.size.width &&
        object1.position.x + object1.size.width > object2.position.x &&
        object1.position.y < object2.position.y + object2.size.height &&
        object1.position.y + object1.size.height > object2.position.y) {
        // The bounding boxes overlap, so there is a collision
        return &object2;  // Return a pointer to the colliding GameObject
    }

    return nullptr;  // Return nullptr if no collision was found
}



