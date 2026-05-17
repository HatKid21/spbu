#pragma once

#include "coin.hpp"
#include "movable.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "level.hpp"

namespace hatkid{
    class Physics{
        public:
            static void moveVertical(Movable& player, Level& level, int mapHeight);
            static void moveHorizontal(Movable& player, Level& level);

            static void checkPlayerMovableCollision(Player& player, Level& level);
    };
}
