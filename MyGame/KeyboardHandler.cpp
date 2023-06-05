// KeyboardHandler.cpp

#include "KeyboardHandler.h"  // Include the KeyboardHandler header file

// Constructor
KeyboardHandler::KeyboardHandler() {
    ZeroMemory(keyboardState, sizeof(keyboardState));  // Initialize all elements of keyboardState to zero
}

// Destructor
KeyboardHandler::~KeyboardHandler() {
    // Destructor code here
}

// Update method
void KeyboardHandler::Update() {
    GetKeyboardState(keyboardState);  // Get the current state of all keys and store it in keyboardState
}

// IsKeyDown method
bool KeyboardHandler::IsKeyDown(int virtualKeyCode) const {
    // Check if the specified key is pressed
    // The bitwise AND operation with 0x80 checks the high-order bit, which is set if the key is down
    return (keyboardState[virtualKeyCode] & 0x80) != 0;
}