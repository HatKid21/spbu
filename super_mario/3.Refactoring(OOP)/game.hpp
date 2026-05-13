#pragma once

#include "gameObject.hpp"
#include "player.hpp"
#include "level.hpp"
#include "renderer.hpp"
#include "keyboard.hpp"

namespace hatkid{

    class Game {
        private:
            Player player;
            Level level;
            Renderer renderer;
            Keyboard keyboard;
            bool isRunning;
        public:
            Game();
            ~Game() = default;

            void run();
            void stop();

        private:
            void inputHandler();

   };

}
