// GameObject.cpp

#include "GameObject.h"  // Include the GameObject header file

// Constructor implementation
GameObject::GameObject(
    float x, float y, float width, float height,
    int r, int g, int b, int a,
    ObjectType objectType,
    float dx, float dy,
    MovementPattern movementPattern,
    FiringPattern firingPattern,
    float speed,
    float initialX, float initialY,
    float maxHealth, float currentHealth,
    int targetId
)
    : position(x, y),  // Initialize position with the provided x and y values
    size(width, height),  // Initialize size with the provided width and height values
    color(r, g, b, a),  // Initialize color with the provided r, g, b, and a values
    objectType(objectType),  // Initialize objectType with the provided value
    velocity(dx, dy),  // Initialize velocity with the provided dx and dy values
    movementPattern(movementPattern),  // Initialize movementPattern with the provided value
    firingPattern(firingPattern),  // Initialize firingPattern with the provided value
    speed(speed),  // Initialize speed with the provided value
    initialPosition(initialX, initialY),  // Initialize initialPosition with the provided initialX and initialY values
    health(maxHealth, currentHealth),  // Initialize health with the provided maxHealth and currentHealth values
    targetId(targetId)  // Initialize targetId with the provided value
{
    // No additional code needed here as all properties are already set
}