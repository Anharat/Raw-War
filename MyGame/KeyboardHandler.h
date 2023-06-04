// KeyboardHandler.h

#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include <windows.h>

class KeyboardHandler {
public:
    KeyboardHandler();
    ~KeyboardHandler();

    void Update();
    bool IsKeyDown(int virtualKeyCode) const;

private:
    BYTE keyboardState[256];
};

#endif // KEYBOARDHANDLER_H
