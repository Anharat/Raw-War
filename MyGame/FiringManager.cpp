// FiringManager.cpp

#include "FiringManager.h"

FiringManager::FiringManager() {
    // The constructor currently does nothing.
    // Add initialization logic here if necessary.
}

FiringManager::~FiringManager() {
    // The destructor currently does nothing.
    // Add cleanup logic here if necessary.
}

// The UpdateFiringPattern function decides which firing pattern to follow based on the passed game object's firing pattern.
void FiringManager::UpdateFiringPattern(int id, GameObject& gameObject) {
    switch (gameObject.firingPattern) {
    case FiringPattern::NoFiring:
        // If the game object is not supposed to fire, handle it.
        HandleNoFiring(gameObject);
        break;
    case FiringPattern::KeyboardFiring:
        // If the game object fires based on keyboard input, handle it.
        HandleKeyboardFiring(id, gameObject);  // Now correctly passing in the id as well.
        break;
    case FiringPattern::SteadyFiring:
        // If the game object fires steadily, handle it.
        HandleSteadyFiring(id, gameObject);
        break;
    }
}

// The HandleNoFiring function handles the case where the game object is not supposed to fire.
// Currently it does nothing. Modify this if you need to handle this case differently.
void FiringManager::HandleNoFiring(GameObject& gameObject) {
    // No action needed for NoFiring
}

void FiringManager::HandleKeyboardFiring(int id, GameObject& gameObject) {
    const double firingInterval = 1.0;  // Set the firing interval to 1 second

    keyboardHandler.Update();  // Update the keyboard state

    // If '1' key is pressed and it has been at least 'firingInterval' seconds since last firing, fire a projectile
    if ((keyboardHandler.IsKeyDown(VK_NUMPAD1) || keyboardHandler.IsKeyDown(0x31))
        && keyboardTimer.GetElapsedTime() >= firingInterval) {
        OutputDebugString(L"'1' key is pressed\n");  // Add debug output

        // Get the id of the nearest enemy
        int nearestEnemyId = GetNearestObjectId(ObjectType::Enemy, gameObject);

        // If an enemy is found, spawn a projectile towards it
        if (nearestEnemyId != -1) {
            SpawnProjectileTowardsTarget(id, nearestEnemyId);  // Spawn a projectile towards the nearest enemy
        }

        keyboardTimer.Reset();  // Reset the keyboardTimer
    }
}


void FiringManager::HandleSteadyFiring(int id, GameObject& gameObject) {
    const double firingInterval = 0.5;  // Set the firing interval to 1 second

    // Get or create the timer for this game object
    Timer& steadyFiringTimer = steadyFiringTimers[id];

    // If it has been at least 'firingInterval' seconds since last firing, fire a projectile towards the nearest player
    if (steadyFiringTimer.GetElapsedTime() >= firingInterval) {
        OutputDebugString(L"Steady firing\n");  // Add debug output

        // Get the id of the nearest player
        int nearestPlayerId = GetNearestObjectId(ObjectType::Player, gameObject);

        // If a player is found, spawn a projectile towards it
        if (nearestPlayerId != -1) {
            SpawnProjectileTowardsTarget(id, nearestPlayerId);  // Spawn a projectile towards the nearest player
        }

        steadyFiringTimer.Reset();  // Reset the steadyFiringTimer
    }
}


void FiringManager::SpawnProjectileTowardsTarget(int originId, int targetId) {
    // Access all game objects currently in the GameState
    const auto& gameObjects = GameState::GetInstance().GetGameObjects();

    // Validate that both origin and target game objects exist
    if (gameObjects.find(originId) == gameObjects.end() || gameObjects.find(targetId) == gameObjects.end()) {
        return;
    }

    // References to the origin and target game objects
    const GameObject& origin = gameObjects.at(originId);
    const GameObject& target = gameObjects.at(targetId);

    // Define the spawn distance from the origin
    const float spawnDistance = 10.0f;  // Change this value as necessary

    // Calculate the spawn position and direction
    auto [spawnPosX, spawnPosY, directionX, directionY] = CalculateSpawnPosition(origin, target, spawnDistance);

    // Create a new projectile GameObject targeting the nearest player
    GameObject projectile(
        spawnPosX, spawnPosY,
        10.0f, 10.0f,
        255, 255, 255, 255,
        ObjectType::Projectile,
        directionX, directionY,
        MovementPattern::Target,
        FiringPattern::NoFiring,
        350.0f
    );

    // Set the target of the projectile to be the targetId
    projectile.targetId = targetId;

    // Output a debug message to indicate that a projectile has been spawned
    OutputDebugString(L"Spawning a projectile\n");

    // Add the new projectile to the GameState's collection of game objects
    GameState::GetInstance().AddGameObject(projectile);
}

int FiringManager::GetNearestObjectId(ObjectType type, GameObject& gameObject) {
    // Access all game objects currently in the GameState
    const auto& gameObjects = GameState::GetInstance().GetGameObjects();

    // Initialize nearestDistance to the largest possible float value
    float nearestDistance = (std::numeric_limits<float>::max)();

    int nearestObjectId = -1;  // Initialize ID of the nearest object to -1, indicating none has been found yet

    // Iterate over all game objects in the game state
    for (const auto& pair : gameObjects) {
        const GameObject& other = pair.second;

        // If the game object is not of the desired type, skip the rest of this loop iteration
        if (other.objectType != type) {
            continue;
        }

        // Calculate the distance between the gameObject and the other game object
        float dx = gameObject.position.x - other.position.x;
        float dy = gameObject.position.y - other.position.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        // If the current object is closer than the current nearest object, update nearestDistance and nearestObjectId
        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearestObjectId = pair.first;
        }
    }

    return nearestObjectId;
}

std::tuple<float, float, float, float> FiringManager::CalculateSpawnPosition(const GameObject& origin, const GameObject& target, float spawnDistance) {
    // Calculate the direction to the target
    float dx = target.position.x - origin.position.x;
    float dy = target.position.y - origin.position.y;
    float distanceToTarget = std::sqrt(dx * dx + dy * dy);
    float directionX = dx / distanceToTarget;
    float directionY = dy / distanceToTarget;

    // Calculate the spawn position
    float spawnPosX = origin.position.x + directionX * spawnDistance;
    float spawnPosY = origin.position.y + directionY * spawnDistance;

    // If the target is to the right of the origin, spawn the projectile from the right side of the origin
    if (directionX > 0) {
        spawnPosX += origin.size.width;
    }
    else {
        // If the target is to the left of the origin, spawn the projectile from the left side of the origin
        // As the position is on the left already, no need for any addition or subtraction
    }

    // If the target is below the origin, spawn the projectile from the bottom side of the origin
    if (directionY > 0) {
        spawnPosY += origin.size.height;
    }
    else {
        // If the target is above the origin, spawn the projectile from the top side of the origin
        // As the position is on the top already, no need for any addition or subtraction
    }

    // Adjust spawn position to account for the origin's size (center of the edge)
    spawnPosX += origin.size.width / 2 * directionX;
    spawnPosY += origin.size.height / 2 * directionY;

    return { spawnPosX, spawnPosY, directionX, directionY };
}




