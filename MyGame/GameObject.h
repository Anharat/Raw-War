// GameObject.h

#pragma once

#include "Position.h"
#include "Size.h"
#include "Color.h"
#include "ObjectType.h"
#include "Velocity.h"
#include "MovementPattern.h"
#include "FiringPattern.h" // Include the FiringPattern header
#include "Speed.h" 
#include "InitialPosition.h" // Include the InitialPosition header
#include "Health.h"

class GameObject {
public:
    Position position;
    Size size;
    Color color;
    ObjectType objectType;
    Velocity velocity;
    MovementPattern movementPattern;
    FiringPattern firingPattern; // Add FiringPattern to GameObject
    Speed speed;
    InitialPosition initialPosition;  // InitialPosition as a value
    Health health;
    int targetId;  // ID of the target GameObject
    

    GameObject(
        float x = 0.0f, float y = 0.0f, float width = 0.0f, float height = 0.0f,
        int r = 255, int g = 255, int b = 255, int a = 255,
        ObjectType objectType = ObjectType::Wall,
        float dx = 0.0f, float dy = 0.0f,
        MovementPattern movementPattern = MovementPattern::Stationary,
        FiringPattern firingPattern = FiringPattern::NoFiring, // Add firingPattern to constructor
        float speed = 0.0f,
        float initialX = 0.0f, float initialY = 0.0f,  // Add initialPosition to constructor
        float maxHealth = 0.0f, float currentHealth = 0.0f,
        int targetId = -1  // Add targetId to constructor
        
    );
};