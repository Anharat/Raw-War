//** 
// @file Setup.h
// @brief Declares the Setup function for the Raw-War game.
// * The Setup function initializes the game state with the initial game objects.
// *

#ifndef SETUP_H
#define SETUP_H

// Include necessary header files

#include "GameState.h" // Include the GameState class which represents the state of the game at any given instance
#include "GameObject.h" // Include the GameObject class which represents an object in the game (e.g., player, enemy, wall)
#include <cstdlib> // Include the cstdlib library for general purpose functions
#include <ctime> // Include the ctime library for time related functions

// This function initializes the game by setting up the game objects and their initial states
// It takes a reference to a RECT structure that represents the client area of the window as a parameter
// RECT is a structure that defines a rectangle by the coordinates of its upper-left and lower-right corners
void Setup(const RECT& clientRect);

#endif // SETUP_H
