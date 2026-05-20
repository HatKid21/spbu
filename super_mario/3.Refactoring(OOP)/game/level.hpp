#pragma once

#include "brick.hpp"
#include "coin.hpp"
#include "enemy.hpp"

namespace hatkid{
    class Level{
        private:
            Brick* bricks;
            Enemy* enemies;
            Coin* coins;

            int brickAmount;
            int enemyAmount;
            int coinAmount;

            int currentLevel;
            int score;
            int spawnX = 39;
            int spawnY = 10;

            bool goalReached;
        public:
            Level(int level);
            ~Level();
            
            void loadLevel();
            void reset();
            void nextLevel();

            int getScore() const;
            void addScore(int points);
            
            int getCurrentLevel() const;
            bool isGoalReached() const;
            void setGoalReached(bool state);

            int getSpawnX() const;
            int getSpawnY() const;

            Brick* getBricks();
            int getBrickAmount();

            Enemy* getEnemies();
            int getEnemyAmount();

            Coin* getCoins();
            int getCoinAmount();

            void addCoin(float x, float y);


    };
}
