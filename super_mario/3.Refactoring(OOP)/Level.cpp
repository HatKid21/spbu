#include "Level.hpp"
#include "brick.hpp"
#include "enemy.hpp"

using hatkid::Level;

Level::Level(int level)
    : currentLevel(level), score(0),
      bricks(nullptr), brickAmount(0),
      enemies(nullptr), enemyAmount(0) {
}

Level::~Level(){
    delete[] enemies;
    delete[] bricks;
}

int Level::getScore() const{
    return score;
}

void Level::addScore(int points){
    score += points;
}

int Level::getCurrentLevel() const {
    return currentLevel;
}

hatkid::Brick* Level::getBricks(){
    return bricks;
}

hatkid::Enemy* Level::getEnemies(){
    return enemies;
}

int Level::getBrickAmount(){
    return brickAmount;
}

int Level::getEnemyAmount(){
    return enemyAmount;
}

