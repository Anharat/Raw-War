// Setup.cpp

#include "Setup.h"

void Setup(const RECT& clientRect) {

    const float BoundaryGap = 10.0f;
    const float EdgeGap = 0.0f;  // Adjust this value to set the distance of the boundary walls from the edge of the screen

    // Create wall objects for the border
    // Define the new thickness and color for the boundary walls
    float wallThickness = 5.0f;  // Adjust this value to change the thickness of the walls
    int wallColorR = 0;  // Red component of the wall color
    int wallColorG = 0;  // Green component of the wall color
    int wallColorB = 255;  // Blue component of the wall color
    int wallColorA = 255;  // Alpha component of the wall color

    // Calculate the adjusted positions and sizes for the boundary walls
    float topWallY = EdgeGap;
    float topWallHeight = wallThickness;
    float bottomWallY = static_cast<float>(clientRect.bottom - wallThickness - EdgeGap);
    float bottomWallHeight = wallThickness;
    float leftWallX = EdgeGap;
    float leftWallWidth = wallThickness;
    float rightWallX = static_cast<float>(clientRect.right - wallThickness - EdgeGap);
    float rightWallWidth = wallThickness;

    // Calculate the adjusted widths and heights for the boundary walls
    float horizontalWallWidth = static_cast<float>(clientRect.right - 2 * BoundaryGap);
    float verticalWallHeight = static_cast<float>(clientRect.bottom - 2 * BoundaryGap);

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

    // Add a second wall
    GameObject wall3(350.0f, 300.0f, 50.0f, 50.0f, 0, 255, 0, 255, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);
    GameState::GetInstance().AddGameObject(wall3);

    // Add a third wall
    GameObject wall4(100.0f, 400.0f, 50.0f, 50.0f, 0, 255, 0, 255, ObjectType::Wall, 0.0f, 0.0f, MovementPattern::Stationary, FiringPattern::NoFiring, 0.0f);
    GameState::GetInstance().AddGameObject(wall4);


    OutputDebugString(L"Setup\n");
}