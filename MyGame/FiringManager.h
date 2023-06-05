// FiringManager.h

#ifndef FIRINGMANAGER_H
#define FIRINGMANAGER_H

#include "GameObject.h"
#include "FiringPattern.h"
#include "KeyboardHandler.h"
#include "Timer.h"
#include "GameState.h"
#include <cmath>
#include <map>
#include <utility>  // Needed for std::pair

// The FiringManager class is responsible for managing firing patterns for GameObjects.
// It handles different firing patterns and spawns projectiles accordingly.
class FiringManager {
public:
    FiringManager();  // Constructor
    ~FiringManager();  // Destructor

    // Updates the firing pattern of a GameObject based on its ID.
    void UpdateFiringPattern(int id, GameObject& gameObject);

private:
    // Spawns a projectile from a GameObject towards a target GameObject.
    void SpawnProjectileTowardsTarget(int id, int targetId);

    // Handles the case where a GameObject is not firing.
    void HandleNoFiring(GameObject& gameObject);

    // Handles the firing based on keyboard input.
    void HandleKeyboardFiring(int id, GameObject& gameObject);

    // Handles steady firing for a GameObject.
    void HandleSteadyFiring(int id, GameObject& gameObject);

    // Returns the ID of the nearest object of a given type to a given game object.
    int GetNearestObjectId(ObjectType type, GameObject& gameObject);

    // Calculates the spawn position for a projectile given the origin and target GameObjects and spawn distance.
    std::tuple<float, float, float, float> CalculateSpawnPosition(const GameObject& origin, const GameObject& target, float spawnDistance);

    KeyboardHandler keyboardHandler;  // Handles keyboard inputs.
    Timer keyboardTimer;  // Timer for keyboard inputs.

    // Map that stores timers for steady firing, where each GameObject ID corresponds to a unique timer.
    std::map<int, Timer> steadyFiringTimers;
};

#endif // FIRINGMANAGER_H
