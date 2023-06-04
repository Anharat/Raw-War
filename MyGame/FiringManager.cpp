// FiringManager.cpp

#include "FiringManager.h"

FiringManager::FiringManager() {
    // Constructor implementation
}

FiringManager::~FiringManager() {
    // Destructor implementation
}

void FiringManager::UpdateFiringPattern(int id, GameObject& gameObject) {
    switch (gameObject.firingPattern) {
    case FiringPattern::NoFiring:
        HandleNoFiring(gameObject);
        break;
    case FiringPattern::KeyboardFiring:
        HandleKeyboardFiring(gameObject);
        break;
    case FiringPattern::SteadyFiring:
        HandleSteadyFiring(id, gameObject);
        break;
    }
}

void FiringManager::HandleNoFiring(GameObject& gameObject) {
    // Handle NoFiring pattern
}

void FiringManager::HandleKeyboardFiring(GameObject& gameObject) {
    const double firingInterval = 1.0;  // Set the firing interval to 1 second

    keyboardHandler.Update();  // Update the keyboard state

    if ((keyboardHandler.IsKeyDown(VK_NUMPAD1) || keyboardHandler.IsKeyDown(0x31))
        && keyboardTimer.GetElapsedTime() >= firingInterval) {  // Use keyboardTimer
        OutputDebugString(L"'1' key is pressed\n");  // Add debug output

        SpawnProjectile(gameObject);  // Spawn a projectile

        keyboardTimer.Reset();  // Reset the keyboardTimer
    }
}

void FiringManager::HandleSteadyFiring(int id, GameObject& gameObject) {
    const double firingInterval = 1.0;  // Set the firing interval to 1 second

    // Get or create the timer for this game object
    Timer& steadyFiringTimer = steadyFiringTimers[id];

    if (steadyFiringTimer.GetElapsedTime() >= firingInterval) {  // Use steadyFiringTimer
        OutputDebugString(L"Steady firing\n");  // Add debug output

        SpawnProjectileTowardsNearestPlayer(gameObject);  // Spawn a projectile towards the nearest player

        steadyFiringTimer.Reset();  // Reset the steadyFiringTimer
    }
}


void FiringManager::SpawnProjectile(GameObject& player) {
    // Calculate the distance between the player and all enemies
    // Find the nearest enemy
    // Spawn a projectile with the target set to this enemy

    // Get all game objects
    const auto& gameObjects = GameState::GetInstance().GetGameObjects();

    // Initialize the nearest distance to a large value
    float nearestDistance = (std::numeric_limits<float>::max)();

    int nearestEnemyId = -1;

    // Iterate over all game objects
    for (const auto& pair : gameObjects) {
        const GameObject& gameObject = pair.second;

        // Skip if the game object is not an enemy
        if (gameObject.objectType != ObjectType::Enemy) {
            continue;
        }

        // Calculate the distance between the player and the enemy
        float dx = player.position.x - gameObject.position.x;
        float dy = player.position.y - gameObject.position.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        // Update the nearest enemy if this enemy is nearer
        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearestEnemyId = pair.first;
        }
    }

    // If an enemy was found, spawn a projectile
    if (nearestEnemyId != -1) {
        const GameObject& nearestEnemy = gameObjects.at(nearestEnemyId);

        // Add a variable to control the spawn distance
        const float spawnDistance = 30.0f;  // Set this to the desired distance

        // Calculate the direction to the target
        float dx = nearestEnemy.position.x - player.position.x;
        float dy = nearestEnemy.position.y - player.position.y;
        float distanceToTarget = std::sqrt(dx * dx + dy * dy);
        float directionX = dx / distanceToTarget;
        float directionY = dy / distanceToTarget;

        // Calculate the spawn position
        float spawnPosX = player.position.x + directionX * (player.size.width / 2 + spawnDistance);
        float spawnPosY = player.position.y + directionY * (player.size.height / 2 + spawnDistance);


        GameObject projectile(
            spawnPosX, spawnPosY,  // Position a small distance from the player
            10.0f, 10.0f,  // Size
            255, 255, 255, 255,  // Color
            ObjectType::Projectile,  // Object type
            0.0f, 0.0f,  // Velocity
            MovementPattern::Target,  // Movement pattern
            FiringPattern::NoFiring,  // Firing pattern
            350.0f  // Speed
        );

        projectile.targetId = nearestEnemyId;  // Set the target ID

        OutputDebugString(L"Spawning a projectile\n");

        // Add the projectile to the game state
        GameState::GetInstance().AddGameObject(projectile);
    }
}

void FiringManager::SpawnProjectileTowardsNearestPlayer(GameObject& enemy) {
    // Get all game objects
    const auto& gameObjects = GameState::GetInstance().GetGameObjects();

    // Initialize the nearest distance to a large value
    float nearestDistance = (std::numeric_limits<float>::max)();

    int nearestPlayerId = -1;

    // Iterate over all game objects
    for (const auto& pair : gameObjects) {
        const GameObject& gameObject = pair.second;

        // Skip if the game object is not a player
        if (gameObject.objectType != ObjectType::Player) {
            continue;
        }

        // Calculate the distance between the enemy and the player
        float dx = enemy.position.x - gameObject.position.x;
        float dy = enemy.position.y - gameObject.position.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        // Update the nearest player if this player is nearer
        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearestPlayerId = pair.first;
        }
    }

    // If a player was found, spawn a projectile
    if (nearestPlayerId != -1) {
        const GameObject& nearestPlayer = gameObjects.at(nearestPlayerId);

        // Add a variable to control the spawn distance
        const float spawnDistance = 10.0f;  // Set this to the desired distance

        // Calculate the direction to the target
        float dx = nearestPlayer.position.x - enemy.position.x;
        float dy = nearestPlayer.position.y - enemy.position.y;
        float distanceToTarget = std::sqrt(dx * dx + dy * dy);
        float directionX = dx / distanceToTarget;
        float directionY = dy / distanceToTarget;  // Calculate directionY

        // Calculate the spawn position
        float spawnPosX = enemy.position.x + directionX * (enemy.size.width / 2 + spawnDistance);
        float spawnPosY = enemy.position.y + directionY * (enemy.size.height / 2 + spawnDistance);

        GameObject projectile(
            spawnPosX, spawnPosY,  // Position a small distance from the enemy
            10.0f, 10.0f,  // Size
            255, 255, 255, 255,  // Color
            ObjectType::Projectile,  // Object type
            directionX, directionY,  // Velocity
            MovementPattern::Target,  // Movement pattern
            FiringPattern::NoFiring,  // Firing pattern
            350.0f  // Speed
        );

        projectile.targetId = nearestPlayerId;  // Set the target ID
        
        OutputDebugString(L"Spawning a projectile\n");

        // Add the projectile to the game state
        GameState::GetInstance().AddGameObject(projectile);
    }
}
