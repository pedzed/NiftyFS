#include <iostream>
#include "KeyEventListener.h"

void KeyEventListener::update()
{
    system("stty raw");
    KeyCode input = std::cin.get();
    system("stty cooked");

    lastPressedKeyCode = input;
}

KeyCode KeyEventListener::getPressedKeyCode()
{
    return lastPressedKeyCode;
}

bool KeyEventListener::hasPressedKeyCode(KeyCode keyCode)
{
    return (getPressedKeyCode() == keyCode);
}

bool KeyEventListener::hasPressedKeyEsc()
{
    return (hasPressedKeyCode(keyCodeEsc));
}

bool KeyEventListener::hasPressedKeyUp()
{
    return (hasPressedKeyCode(keyCodeUp));
}

bool KeyEventListener::hasPressedKeyDown()
{
    return (hasPressedKeyCode(keyCodeDown));
}

bool KeyEventListener::hasPressedKeyLeft()
{
    return (hasPressedKeyCode(keyCodeLeft));
}

bool KeyEventListener::hasPressedKeyRight()
{
    return (hasPressedKeyCode(keyCodeRight));
}
