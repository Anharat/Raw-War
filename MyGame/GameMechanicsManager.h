// GameMechanicsManager.h

#ifndef GAMEMECHANICSMANAGER_H
#define GAMEMECHANICSMANAGER_H

#include "GameState.h"          // GameState class used for storing and manipulating game data
#include "FiringManager.h"      // FiringManager class used for managing game objects' firing patterns
#include "MovementManager.h"    // MovementManager class used for managing game objects' movement patterns

// The GameMechanicsManager class is responsible for managing the game's mechanics.
// It operates by continuously updating the game's state, firing patterns, and movement patterns.
class GameMechanicsManager {
public:
    // Constructor: initializes a GameMechanicsManager object with a given game state.
    // The GameState reference is used to manipulate the game's data.
    GameMechanicsManager(GameState& gameState);

    // Destructor: cleans up the GameMechanicsManager object before it is destroyed.
    ~GameMechanicsManager();

    // Initialize: sets up the game mechanics as needed at the start of the game or level.
    void Initialize();

    // Update: updates the game mechanics according to the given time interval (deltaTime).
    // This method updates the firing and movement patterns of all game objects.
    void Update(double deltaTime);

private:
    // A reference to the game's current state, which allows the game's data to be manipulated.
    GameState& gameState;

    // The FiringManager, which manages the firing patterns of game objects.
    FiringManager firingManager;

    // The MovementManager, which manages the movement patterns of game objects.
    MovementManager movementManager;
};

#endif // GAMEMECHANICSMANAGER_H
