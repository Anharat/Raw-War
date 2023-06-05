// Color.h

#pragma once  // Preprocessor directive to prevent multiple inclusions of the header file

// Color class declaration
class Color {
public:
    int r; // Red component of the color, range 0-255
    int g; // Green component of the color, range 0-255
    int b; // Blue component of the color, range 0-255
    int a; // Alpha (transparency) component of the color, range 0-255

    // Constructor with default parameter values
    // If no values are provided, it defaults to white color (255, 255, 255) with full opacity (255)
    Color(int r = 255, int g = 255, int b = 255, int a = 255);
};