#pragma once

#include "movable.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "level.hpp"

namespace hatkid{
    class Physics{
        public:
            static void playerMoveVertical(Player& player, Level& level, int mapHeight);
            static void playerMoveHorizontal(Player& player, Level& level);

            static void moveEnemy(Enemy& enemy, Level& level);

            static void checkPlayerEnemyCollision(Player& player, Level& level);
    };
}
