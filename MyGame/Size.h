// Size.h

#pragma once  // Preprocessor directive to prevent multiple inclusions of the header file

// Size class declaration
class Size {
public:
    float width; // Width value of the size
    float height; // Height value of the size

    // Constructor with default parameter values
    // If no values are provided, it defaults to size (0,0)
    Size(float width = 0.0f, float height = 0.0f);
};