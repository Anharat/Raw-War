// Velocity.h

#pragma once

class Velocity {
public:
    float dx; // Velocity along the x-axis
    float dy; // Velocity along the y-axis

    Velocity(float dx = 0.0f, float dy = 0.0f)
        : dx(dx), dy(dy) { }
};
