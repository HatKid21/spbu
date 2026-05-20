#pragma once

#include <string>
#include <vector>
#include <linux/input.h>

namespace hatkid{
    class Keyboard {
    private:
        int fd;
        bool keyStates[KEY_MAX];

        std::string findKeyboardPath();

    public:
        Keyboard();
        ~Keyboard();

        Keyboard(const Keyboard&) = delete;
        Keyboard& operator=(const Keyboard&) = delete;

        void update();
        bool isPressed(int keyCode);
        bool isValid() const { return fd > 0; }
    };
}
