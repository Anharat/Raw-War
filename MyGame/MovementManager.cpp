// Implementation of the MovementManager class.

#include "MovementManager.h"

// Default constructor.
MovementManager::MovementManager() {
    // TODO: Initialization code here.
}

// Destructor.
MovementManager::~MovementManager() {
    // TODO: Cleanup code here.
}

// Update the movement pattern of a game object based on its movement type.
void MovementManager::UpdateMovementPattern(int id, GameObject& gameObject, double deltaTime) {
    switch (gameObject.movementPattern) {
        // Handle the case where the movement pattern is Target.
    case MovementPattern::Target:
        HandleTargetMovement(id, gameObject, deltaTime);
        break;
        // Handle the case where the movement pattern is Stationary.
    case MovementPattern::Stationary:
        HandleNoMovement(gameObject);
        break;
        // Handle the case where the movement pattern is Keyboard.
    case MovementPattern::Keyboard:
        HandleKeyboardMovement(id, gameObject, deltaTime);
        break;
        // Handle the case where the movement pattern is LeftAndRight.
    case MovementPattern::LeftAndRight:
        HandleLeftAndRightMovement(id, gameObject, deltaTime);
        break;
    }
}

// Handle case when the game object is not supposed to move.
void MovementManager::HandleNoMovement(GameObject& gameObject) {
    // TODO: Handle stationary movement pattern.
}

// Handle case when the game object's movement is controlled by keyboard inputs.
void MovementManager::HandleKeyboardMovement(int id, GameObject& gameObject, double deltaTime) {
    // Use the CollisionManager to predict possible collisions.
    CollisionManager collisionManager;
    Position futurePosition = collisionManager.PredictFuturePosition(gameObject, deltaTime);

    // Clone the game object to simulate its future state.
    GameObject futureGameObject = gameObject;
    futureGameObject.position = futurePosition;

    // Get all game objects.
    const auto& allGameObjects = GameState::GetInstance().GetGameObjects();

    // Check for collision between the future game object and all other game objects.
    // Skip collision checking with itself and other projectiles.
    for (const auto& pair : allGameObjects) {
        const GameObject& otherGameObject = pair.second;

        if (id == pair.first || otherGameObject.objectType == ObjectType::Projectile) {
            continue;
        }

        // If a collision is detected, the function early returns and the game object doesn't move.
        if (collisionManager.CheckCollision(futureGameObject, otherGameObject)) {
            return;
        }
    }

    // Process the keyboard inputs.
    keyboardHandler.Update();

    // Update the game object's position based on keyboard inputs.
    // WASD keyboard layout for up, down, left, and right, respectively.
    if (keyboardHandler.IsKeyDown('W')) {
        gameObject.position.y -= gameObject.speed * static_cast<float>(deltaTime);
    }
    if (keyboardHandler.IsKeyDown('S')) {
        gameObject.position.y += gameObject.speed * static_cast<float>(deltaTime);
    }
    if (keyboardHandler.IsKeyDown('A')) {
        gameObject.position.x -= gameObject.speed * static_cast<float>(deltaTime);
    }
    if (keyboardHandler.IsKeyDown('D')) {
        gameObject.position.x += gameObject.speed * static_cast<float>(deltaTime);
    }
}

void MovementManager::HandleLeftAndRightMovement(int id, GameObject& gameObject, double deltaTime) {
    
    // Create an instance of CollisionManager
    CollisionManager collisionManager;

    // Predict the future position of the game object
    Position futurePosition = collisionManager.PredictFutureLeftAndRightPosition(gameObject, deltaTime);

    

    // Create a copy of the game object and assign it the future position
    GameObject futureGameObject = gameObject;
    futureGameObject.position = futurePosition;

    // Get all game objects
    const auto& allGameObjects = GameState::GetInstance().GetGameObjects();

    // Check for collision between the future game object and all other game objects
    for (const auto& pair : allGameObjects) {
        const GameObject& otherGameObject = pair.second;

        // Skip checking collision with self
        if (id == pair.first) {
            continue;
        }

        // Skip checking collision with other projectiles
        if (otherGameObject.objectType == ObjectType::Projectile) {
            continue;
        }

        bool isColliding = collisionManager.CheckCollision(futureGameObject, otherGameObject);

        // If the future GameObject is colliding with another game object, don't update the position
        if (isColliding) {
            
            return;
        }
    }
          
    // Calculate the left and right positions based on the initial position
    float leftPosition = gameObject.initialPosition.x - 200.0f;
    float rightPosition = gameObject.initialPosition.x + 200.0f;
    
    // Calculate the new position based on the speed and deltaTime
    float newPosition = gameObject.position.x + gameObject.velocity.dx * gameObject.speed * static_cast<float>(deltaTime);

    // Check if the new position has reached or passed the left or right position
    if (newPosition <= leftPosition) {
        // If the new position is at or past the left position, set the position to the left position and change direction to the right
        gameObject.position.x = leftPosition;
        gameObject.velocity.dx = 1.0f;  // Change direction to the right
    }
    else if (newPosition >= rightPosition) {
        // If the new position is at or past the right position, set the position to the right position and change direction to the left
        gameObject.position.x = rightPosition;
        gameObject.velocity.dx = -1.0f;  // Change direction to the left
    }
    else {
        // If the new position is between the left and right positions, update the position
        gameObject.position.x = newPosition;
    }
}

void MovementManager::HandleTargetMovement(int id, GameObject& gameObject, double deltaTime) {
    // Get the target GameObject
    const GameObject& target = GameState::GetInstance().GetGameObject(gameObject.targetId);

    // Calculate the direction to the target
    float dx = target.position.x - gameObject.position.x;
    float dy = target.position.y - gameObject.position.y;
    float distanceToTarget = std::sqrt(dx * dx + dy * dy);

    // Create an instance of CollisionManager
    CollisionManager collisionManager;

    // Get all game objects
    const auto& allGameObjects = GameState::GetInstance().GetGameObjects();

    // Check for collision between the gameObject and all other game objects
    for (const auto& pair : allGameObjects) {
        const GameObject& otherGameObject = pair.second;

        // Skip checking collision with self
        if (id == pair.first) {
            continue;
        }

        // Skip checking collision with other projectiles
        if (otherGameObject.objectType == ObjectType::Projectile) {
            continue;
        }

        const GameObject* collidingObject = collisionManager.GetCollidingObject(gameObject, otherGameObject);

        // If the GameObject is colliding with another game object, check if it's a player or an enemy
        if (collidingObject != nullptr) {
            auto& modifiableGameObjects = GameState::GetInstance().GetModifiableGameObjects();
            if (collidingObject->objectType == ObjectType::Player || collidingObject->objectType == ObjectType::Enemy) {
                // If the colliding object is a player or an enemy, reduce its health by 10
                modifiableGameObjects[pair.first].health.TakeDamage(10.0f);

                // If the health of the colliding object has reached 0, mark it for removal
                if (modifiableGameObjects[pair.first].health.currentHealth <= 0) {
                    GameState::GetInstance().MarkForRemoval(pair.first);
                }
            }

            // Also, check if the GameObject's health has reached 0 after the collision, and if so mark it for removal
            if (gameObject.health.currentHealth <= 0) {
                GameState::GetInstance().MarkForRemoval(id);
            }
            return;
        }

    }

    float directionX = dx / distanceToTarget;
    float directionY = dy / distanceToTarget;

    // Move the GameObject towards the target
    gameObject.position.x += directionX * gameObject.speed * static_cast<float>(deltaTime);
    gameObject.position.y += directionY * gameObject.speed * static_cast<float>(deltaTime);
}
