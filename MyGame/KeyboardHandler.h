// KeyboardHandler.h

#ifndef KEYBOARDHANDLER_H  // Preprocessor directive to prevent multiple inclusions of the header file
#define KEYBOARDHANDLER_H

#include <windows.h>  // Include the windows.h header file for Windows-specific functions

// KeyboardHandler class declaration
class KeyboardHandler {
public:
    KeyboardHandler();  // Constructor
    ~KeyboardHandler();  // Destructor

    void Update();  // Method to update the keyboard state
    bool IsKeyDown(int virtualKeyCode) const;  // Method to check if a specific key is pressed

private:
    BYTE keyboardState[256];  // Array to store the state of all keys
};

#endif // KEYBOARDHANDLER_H  // End of preprocessor directive


