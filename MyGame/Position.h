// Position.h

#pragma once  // Preprocessor directive to prevent multiple inclusions of the header file

// Position class declaration
class Position {
public:
    float x; // X-coordinate of the position
    float y; // Y-coordinate of the position

    // Constructor with default parameter values
    // If no values are provided, it defaults to position (0,0)
    Position(float x = 0.0f, float y = 0.0f);
};
