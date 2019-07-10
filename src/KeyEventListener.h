#pragma once

#include "settings.h"

class KeyEventListener
{
    private:
        KeyCode lastPressedKeyCode;

    public:
        void update();

        KeyCode getPressedKeyCode();

        bool hasPressedKeyCode(KeyCode);
        bool hasPressedKeyEsc();
        bool hasPressedKeyUp();
        bool hasPressedKeyDown();
        bool hasPressedKeyLeft();
        bool hasPressedKeyRight();
        bool hasPressedKeyE();
        bool hasPressedKeySpace();
};
