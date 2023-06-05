// Setup.cpp

#include "Setup.h"

// Implement the Setup function defined in Setup.h
void Setup(const RECT& clientRect) {

    // Define the gap between the game area and the boundary walls
    const float BoundaryGap = 10.0f;
    // Define the gap between the boundary walls and the edge of the window
    const float EdgeGap = 0.0f;

    // Define the wall properties
    float wallThickness = 5.0f; // Thickness of the wall
    int wallColorR = 0;  // Red component of the wall color
    int wallColorG = 0;  // Green component of the wall color
    int wallColorB = 255;  // Blue component of the wall color
    int wallColorA = 255;  // Alpha component of the wall color (transparency)

    // Calculate positions and sizes for the boundary walls
    // For top and bottom walls
    float topWallY = EdgeGap; // Y position for the top wall
    float topWallHeight = wallThickness; // Height of the top wall (equal to thickness)
    float bottomWallY = static_cast<float>(clientRect.bottom - wallThickness - EdgeGap); // Y position for the bottom wall
    float bottomWallHeight = wallThickness; // Height of the bottom wall (equal to thickness)

    // For left and right walls
    float leftWallX = EdgeGap; // X position for the left wall
    float leftWallWidth = wallThickness; // Width of the left wall (equal to thickness)
    float rightWallX = static_cast<float>(clientRect.right - wallThickness - EdgeGap); // X position for the right wall
    float rightWallWidth = wallThickness; // Width of the right wall (equal to thickness)

    // Calculate the widths and heights for the boundary walls
    float horizontalWallWidth = static_cast<float>(clientRect.right - 2 * BoundaryGap); // Width of the horizontal walls
    float verticalWallHeight = static_cast<float>(clientRect.bottom - 2 * BoundaryGap); // Height of the vertical walls

    // Create GameObject instances for each of the boundary walls
    // Use the calculated positions, sizes, and colors for each wall
    // All wall objects have ObjectType::Wall, move pattern of Stationary, and no firing pattern
    // Add the wall objects to the game state
    // The same process is repeated for each boundary wall (top, bottom, left, right)

    // Similarly, create and add other GameObject instances (enemies, player, and additional walls) to the game state
    // The parameters for each GameObject instance represent their initial properties such as position, size, color, movement and firing patterns

    // Create wall objects for the border with the new thickness and color
    GameObject topWall(BoundaryGap, topWallY, horizontalWallWidth, topWallHeight, wallColorR, wallColorG, wallColorB, wallColorA, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);
    GameObject bottomWall(BoundaryGap, bottomWallY, horizontalWallWidth, bottomWallHeight, wallColorR, wallColorG, wallColorB, wallColorA, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);
    GameObject leftWall(leftWallX, BoundaryGap, leftWallWidth, verticalWallHeight, wallColorR, wallColorG, wallColorB, wallColorA, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);
    GameObject rightWall(rightWallX, BoundaryGap, rightWallWidth, verticalWallHeight, wallColorR, wallColorG, wallColorB, wallColorA, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);


    // Add the wall objects to the game state
    GameState::GetInstance().AddGameObject(topWall);
    GameState::GetInstance().AddGameObject(bottomWall);
    GameState::GetInstance().AddGameObject(leftWall);
    GameState::GetInstance().AddGameObject(rightWall);

    // Similarly, create and add other GameObject instances (enemies, player, and additional walls) to the game state
    // The parameters for each GameObject instance represent their initial properties such as position, size, color, movement and firing patterns

    // Add initial position to the enemy GameObject
    GameObject enemy1(600.0f, 200.0f, 50.0f, 50.0f, 255, 0, 0, 255, ObjectType::Enemy, 200.0f, 0.0f, MovementPattern::LeftAndRight, FiringPattern::SteadyFiring, 200.0f, 600.0f, 200.0f, 200.0f, 100.0f);
    GameState::GetInstance().AddGameObject(enemy1);

    // Add initial position to the enemy GameObject
    GameObject enemy2(600.0f, 500.0f, 50.0f, 50.0f, 255, 0, 0, 255, ObjectType::Enemy, 200.0f, 0.0f, MovementPattern::LeftAndRight, FiringPattern::SteadyFiring, 200.0f, 600.0f, 200.0f, 200.0f, 100.0f);
    GameState::GetInstance().AddGameObject(enemy2);

    GameObject player(50.0f, 50.0f, 50.0f, 50.0f, 255, 255, 255, 255, ObjectType::Player, 200.0f, 0.0f, MovementPattern::Keyboard, FiringPattern::KeyboardFiring, 200.0f, 200.0f, 200.0f, 200.0f, 100.f);
    GameState::GetInstance().AddGameObject(player);

    GameObject wall(250.0f, 60.0f, 50.0f, 50.0f, 0, 255, 0, 255, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);
    GameState::GetInstance().AddGameObject(wall);

    GameObject wall1(600.0f, 100.0f, 50.0f, 50.0f, 0, 255, 0, 255, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);
    GameState::GetInstance().AddGameObject(wall1);

    GameObject wall2(550.0f, 400.0f, 50.0f, 50.0f, 0, 255, 0, 255, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);
    GameState::GetInstance().AddGameObject(wall2);

    
    GameObject wall3(350.0f, 300.0f, 50.0f, 50.0f, 0, 255, 0, 255, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);
    GameState::GetInstance().AddGameObject(wall3);

    
    GameObject wall4(450.0f, 400.0f, 50.0f, 50.0f, 0, 255, 0, 255, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);
    GameState::GetInstance().AddGameObject(wall4);


    // Output a debug string indicating that the Setup function has completed
    OutputDebugString(L"Setup\n");
}