// CollisionManager.cpp

#include "CollisionManager.h"

// Default constructor for the CollisionManager
CollisionManager::CollisionManager() {
    // No specific initialization logic required
}

// Destructor for the CollisionManager
CollisionManager::~CollisionManager() {
    // No specific clean-up logic required
}

// Method to check if two GameObjects are colliding based on their positions and dimensions
bool CollisionManager::CheckCollision(const GameObject& object1, const GameObject& object2) {
    // Check if the bounding boxes of the two GameObjects overlap (AABB collision detection)
    // If the boxes overlap, it means the two GameObjects are colliding
    if (object1.position.x < object2.position.x + object2.size.width &&
        object1.position.x + object1.size.width > object2.position.x &&
        object1.position.y < object2.position.y + object2.size.height &&
        object1.position.y + object1.size.height > object2.position.y) {
        return true;  // The GameObjects are colliding
    }

    return false;  // The GameObjects are not colliding
}

// Method to predict the future position of a GameObject based on its current state and a time delta
Position CollisionManager::PredictFuturePosition(const GameObject& object, double deltaTime) {
    Position futurePosition = object.position;  // Initialize the future position to the current position

    double framesAhead = 0.5;  // Number of frames to look ahead

    keyboardHandler.Update();  // Update the state of the keyboard handler

    // Adjust the future position based on the current keyboard input and GameObject's speed
    if (keyboardHandler.IsKeyDown('W')) {
        futurePosition.y -= static_cast<float>(object.speed * deltaTime * framesAhead);  // Move up
    }
    if (keyboardHandler.IsKeyDown('S')) {
        futurePosition.y += static_cast<float>(object.speed * deltaTime * framesAhead);  // Move down
    }
    if (keyboardHandler.IsKeyDown('A')) {
        futurePosition.x -= static_cast<float>(object.speed * deltaTime * framesAhead);  // Move left
    }
    if (keyboardHandler.IsKeyDown('D')) {
        futurePosition.x += static_cast<float>(object.speed * deltaTime * framesAhead);  // Move right
    }

    return futurePosition;  // Return the predicted future position
}

// Method to predict the future left and right positions of a GameObject
Position CollisionManager::PredictFutureLeftAndRightPosition(const GameObject& gameObject, double deltaTime) {
    Position futurePosition = gameObject.position;  // Initialize the future position to the current position

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

    // Return the future position. This will either be the same as the original position if no key was pressed,
    // or it will be a new position reflecting the calculated movement.
    return futurePosition;
}

// Method to get the GameObject that is colliding with the provided GameObject
const GameObject* CollisionManager::GetCollidingObject(const GameObject& object1, const GameObject& object2) {
    // Check if the bounding boxes of the two GameObjects overlap using AABB collision detection
    if (object1.position.x < object2.position.x + object2.size.width &&
        object1.position.x + object1.size.width > object2.position.x &&
        object1.position.y < object2.position.y + object2.size.height &&
        object1.position.y + object1.size.height > object2.position.y) {
        // If the bounding boxes overlap, a collision is occurring
        // Return a pointer to the GameObject that is colliding with the provided GameObject
        return &object2;
    }

    // If there was no collision detected, return a nullptr
    return nullptr;
}




