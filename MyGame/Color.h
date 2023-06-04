// Color.h
#pragma once

class Color {
public:
    int r; // Red component of the color
    int g; // Green component of the color
    int b; // Blue component of the color
    int a; // Alpha (transparency) component of the color

    Color(int r = 255, int g = 255, int b = 255, int a = 255); // Constructor with default parameter values
};
