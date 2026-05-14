#pragma once

#include "brick.hpp"
#include "enemy.hpp"

namespace hatkid{
    class Level{
        private:
            int currentLevel;
            int score;

            int spawnX = 39;
            int spawnY = 10;

            bool goalReached;

            Brick* bricks;
            int brickAmount;
            Enemy* enemies;
            int enemyAmount;

        public:
            Level(int level);
            ~Level();

            int getScore() const;
            void addScore(int points);
            int getCurrentLevel() const;

            Brick* getBricks();
            Enemy* getEnemies();
            int getBrickAmount();
            int getEnemyAmount();

            void reset();
            void nextLevel();
            void loadLevel(int level);

            bool isGoalReached() const;
            void setGoalReached(bool state);

            int getSpawnX() const;
            int getSpawnY() const;

    };
}
