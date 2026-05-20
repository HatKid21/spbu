#include "keyboard.hpp"

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <filesystem>

namespace fs = std::filesystem;

hatkid::Keyboard::Keyboard() : fd(-1) {
    for (int i = 0; i < KEY_MAX; i++) {
        keyStates[i] = false;
    }

    std::string path = findKeyboardPath();

    if (!path.empty()) {
        fd = open(path.c_str(), O_RDONLY | O_NONBLOCK);
        if (fd < 0) {
            std::cerr << "Error: Could not open keyboard device at " << path << std::endl;
        }
    } else {
        std::cerr << "Error: No keyboard device found in /dev/input/by-path/" << std::endl;
    }
}

hatkid::Keyboard::~Keyboard() {
    if (fd > 0) {
        close(fd);
    }
}

std::string hatkid::Keyboard::findKeyboardPath() {
    std::string searchPath = "/dev/input/by-path/";
    try {
        if (!fs::exists(searchPath)) return "";

        for (const auto& entry : fs::directory_iterator(searchPath)) {
            std::string filename = entry.path().filename().string();
            if (filename.find("-event-kbd") != std::string::npos) {
                return entry.path().string();
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }
    return "";
}

void hatkid::Keyboard::update() {
    if (fd < 0) return;

    struct input_event ev;
    while (read(fd, &ev, sizeof(struct input_event)) > 0) {
        if (ev.type == EV_KEY) {
            if (ev.value == 1 || ev.value == 2) {
                keyStates[ev.code] = true;
            } 
            else if (ev.value == 0) {
                keyStates[ev.code] = false;
            }
        }
    }
}

bool hatkid::Keyboard::isPressed(int keyCode) {
    if (keyCode < 0 || keyCode >= KEY_MAX) return false;
    return keyStates[keyCode];
}
