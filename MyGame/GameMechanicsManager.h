// GameMechanicsManager.h

#ifndef GAMEMECHANICSMANAGER_H
#define GAMEMECHANICSMANAGER_H

#include "GameState.h"
#include "FiringManager.h"
#include "MovementManager.h"  // Include MovementManager.h

class GameMechanicsManager {
public:
    GameMechanicsManager(GameState& gameState);
    ~GameMechanicsManager();

    void Initialize();
    void Update(double deltaTime);

private:
    GameState& gameState;
    FiringManager firingManager;
    MovementManager movementManager;  // Add MovementManager as a member variable
};

#endif // GAMEMECHANICSMANAGER_H
