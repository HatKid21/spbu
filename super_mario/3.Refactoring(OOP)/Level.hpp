#pragma once

#include "brick.hpp"
#include "enemy.hpp"

namespace hatkid{
    class Level{
        private:
            int currentLevel;
            int score;

            Brick* bricks;
            int brickAmount;
            Enemy* enemies;
            int enemyAmount;

        public:
            Level(int level);
            ~Level();

            void reset();

            int getScore() const;
            void addScore(int points);
            int getCurrentLevel() const;

            Brick* getBricks();
            Enemy* getEnemies();
            int getBrickAmount();
            int getEnemyAmount();

    };
}
