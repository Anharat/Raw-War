// GameObject.h

#pragma once  // Preprocessor directive to prevent multiple inclusions of the header file

// Include necessary header files
#include "Position.h"
#include "Size.h"
#include "Color.h"
#include "ObjectType.h"
#include "Velocity.h"
#include "MovementPattern.h"
#include "FiringPattern.h"
#include "Speed.h" 
#include "InitialPosition.h"
#include "Health.h"

// GameObject class declaration
class GameObject {
public:
    Position position;  // Current position of the GameObject
    Size size;  // Size of the GameObject
    Color color;  // Color of the GameObject
    ObjectType objectType;  // Type of the GameObject (Player, Wall, Enemy, etc.)
    Velocity velocity;  // Velocity of the GameObject
    MovementPattern movementPattern;  // Movement pattern of the GameObject
    FiringPattern firingPattern;  // Firing pattern of the GameObject
    Speed speed;  // Speed of the GameObject
    InitialPosition initialPosition;  // Initial position of the GameObject
    Health health;  // Health of the GameObject
    int targetId;  // ID of the target GameObject

    // Constructor with default parameter values
    GameObject(
        float x = 0.0f, float y = 0.0f, float width = 0.0f, float height = 0.0f,
        int r = 255, int g = 255, int b = 255, int a = 255,
        ObjectType objectType = ObjectType::Wall,
        float dx = 0.0f, float dy = 0.0f,
        MovementPattern movementPattern = MovementPattern::Stationary,
        FiringPattern firingPattern = FiringPattern::NoFiring,
        float speed = 0.0f,
        float initialX = 0.0f, float initialY = 0.0f,
        float maxHealth = 0.0f, float currentHealth = 0.0f,
        int targetId = -1
    );
};
