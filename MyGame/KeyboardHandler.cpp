// KeyboardHandler.cpp

#include "KeyboardHandler.h"

KeyboardHandler::KeyboardHandler() {
    ZeroMemory(keyboardState, sizeof(keyboardState));
}

KeyboardHandler::~KeyboardHandler() {
    // Destructor code here
}

void KeyboardHandler::Update() {
    GetKeyboardState(keyboardState);
}

bool KeyboardHandler::IsKeyDown(int virtualKeyCode) const {
    return (keyboardState[virtualKeyCode] & 0x80) != 0;
}


