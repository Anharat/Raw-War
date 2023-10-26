/**
 * @file Setup.h
 * @brief Header file for the initial game setup of the Raw-War game.
 *
 * This header defines the `Setup` function responsible for initializing the game state
 * with various game objects such as boundary walls, enemies, player, and other additional walls.
 * The game state and game objects are represented by the `GameState` and `GameObject` classes, respectively.
 */

#ifndef SETUP_H
#define SETUP_H

 // System includes
#include <cstdlib>  /**< Provides general purpose functions. */
#include <ctime>    /**< Provides time-related functions, used for randomization and time-based events. */

// Local includes
#include "GameState.h"   /**< Represents the overall state of the game at any given moment. */
#include "GameObject.h"  /**< Represents individual entities in the game, e.g., player, enemy, walls, etc. */

/**
 * @brief Initializes the game state and sets up the game environment.
 *
 * This function sets up the boundary walls, enemies, player, and additional walls
 * based on the dimensions provided by the client rectangle of the game window.
 * The created game objects are added to the game state for gameplay.
 *
 * @param clientRect The client rectangle of the game window, used for setting up the game objects in the correct position and dimensions.
 */

void Setup(const RECT& clientRect);

#endif // SETUP_H
