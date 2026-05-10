#pragma once

#include "gameObject.hpp"
#include "player.hpp"
#include "renderer.hpp"

namespace hatkid{

    class Game {
        private:
            Player player;
            Level level;
            Renderer renderer;
        public:
            Game();
            ~Game() = default;
    }

}
