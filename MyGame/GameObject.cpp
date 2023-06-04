// GameObject.cpp

#include "GameObject.h"

GameObject::GameObject(
    float x, float y, float width, float height,
    int r, int g, int b, int a,
    ObjectType objectType,
    float dx, float dy,
    MovementPattern movementPattern,
    FiringPattern firingPattern, // Add firingPattern to constructor
    float speed,
    float initialX, float initialY,  // Add initialPosition to constructor
    float maxHealth, float currentHealth,
    int targetId  // Add targetId to constructor
    
)
    : position(x, y),
    size(width, height),
    color(r, g, b, a),
    objectType(objectType),
    velocity(dx, dy),
    movementPattern(movementPattern),
    firingPattern(firingPattern), // Initialize firingPattern
    speed(speed),
    initialPosition(initialX, initialY),  // Initialize initialPosition
    health(maxHealth, currentHealth),
    targetId(targetId)  // Initialize targetId
    
{
    // Constructor implementation
}