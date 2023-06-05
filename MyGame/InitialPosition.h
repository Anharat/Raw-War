// InitialPosition.h

#pragma once  // Preprocessor directive to prevent multiple inclusions of the header file

// InitialPosition class declaration
class InitialPosition {
public:
    float x; // X-coordinate of the initial position
    float y; // Y-coordinate of the initial position

    // Constructor with default parameter values
    // If no values are provided, it defaults to position (0,0)
    InitialPosition(float x = 0.0f, float y = 0.0f);
};