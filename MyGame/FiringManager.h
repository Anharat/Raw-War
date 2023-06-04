// FiringManager.h

#ifndef FIRINGMANAGER_H
#define FIRINGMANAGER_H

#include "GameObject.h"
#include "FiringPattern.h"
#include "KeyboardHandler.h"
#include <windows.h>
#include "Timer.h"
#include "GameState.h"
#include <cmath>
#include <string>

class FiringManager {
public:
    FiringManager();
    ~FiringManager();

    void UpdateFiringPattern(int id, GameObject& gameObject);
    void SpawnProjectileTowardsNearestPlayer(GameObject& gameObject);  // New method

private:
    void HandleNoFiring(GameObject& gameObject);
    void HandleKeyboardFiring(GameObject& gameObject);
    void HandleSteadyFiring(int id, GameObject& gameObject);

    KeyboardHandler keyboardHandler;
    Timer keyboardTimer;

    std::map<int, Timer> steadyFiringTimers;

    void SpawnProjectile(GameObject& player);
};

#endif // FIRINGMANAGER_H
