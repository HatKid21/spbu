#include "level.hpp"
#include "brick.hpp"
#include "enemy.hpp"

using hatkid::Level;

Level::Level(int level) : currentLevel(level),score(0),goalReached(false),bricks(nullptr),enemies(nullptr),enemyAmount(0),brickAmount(0){
    loadLevel(currentLevel);
}

void Level::loadLevel(int level){
    delete[] bricks;
    delete[] enemies;
    bricks = nullptr;
    enemies = nullptr;
    goalReached = false;

    currentLevel = level;
    int i;

    if (level == 1) {
        brickAmount = 13;
        bricks = new Brick[brickAmount];
        i = 0;
        bricks[i++] = Brick( 20, 21, 40, 5, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 30, 10, 5, 3, hatkid::ObjectType::BONUS);
        bricks[i++] = Brick( 50, 10, 5, 3, hatkid::ObjectType::BONUS);
        bricks[i++] = Brick( 60, 15, 40, 10, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 60, 5, 10, 3, hatkid::ObjectType::EMPTY_BONUS);
        bricks[i++] = Brick( 70, 5, 5, 3, hatkid::ObjectType::BONUS);
        bricks[i++] = Brick( 75, 5, 5, 3, hatkid::ObjectType::EMPTY_BONUS);
        bricks[i++] = Brick( 80, 5, 5, 3, hatkid::ObjectType::BONUS);
        bricks[i++] = Brick( 85, 5, 10, 3, hatkid::ObjectType::EMPTY_BONUS);
        bricks[i++] = Brick( 100, 20, 20, 5, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 120, 15, 10, 10, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 150, 20, 40, 5, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 210, 15, 10, 10, hatkid::ObjectType::GOAL);

        enemyAmount = 2;
        enemies = new Enemy[enemyAmount];
        i = 0;
        enemies[i++] = Enemy(25, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(80, 10, 3, 2, hatkid::ObjectType::ENEMY);
    }

    if (level == 2) {
        brickAmount = 6;
        bricks = new Brick[brickAmount];
        i = 0;
        bricks[i++] = Brick( 20, 21, 40, 5, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 60, 15, 10, 10, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 80, 20, 20, 5, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 120, 15, 10, 10, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 150, 20, 40, 5, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 210, 15, 10, 10, hatkid::ObjectType::GOAL);

        enemyAmount = 6;
        enemies = new Enemy[enemyAmount];
        i = 0;
        enemies[i++] = Enemy(25, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(80, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(65, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(120, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(160, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(175, 10, 3, 2, hatkid::ObjectType::ENEMY);
    }

    if (level == 3) {
        brickAmount = 4;
        bricks = new Brick[brickAmount];
        i = 0;
        bricks[i++] = Brick( 20, 21, 40, 5, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 80, 20, 15, 5, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 120, 15, 15, 10, hatkid::ObjectType::BRICK);
        bricks[i++] = Brick( 160, 10, 15, 15, hatkid::ObjectType::GOAL);

        enemyAmount = 6;
        enemies = new Enemy[enemyAmount];
        i = 0;
        enemies[i++] = Enemy(25, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(50, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(80, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(90, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(120, 10, 3, 2, hatkid::ObjectType::ENEMY);
        enemies[i++] = Enemy(130, 10, 3, 2, hatkid::ObjectType::ENEMY);
    }
}

void Level::reset(){
    score = 0;
    loadLevel(currentLevel);
}

void Level::nextLevel(){
    if (currentLevel < 3){
        currentLevel++;
    } else{
        currentLevel = 1;
    }
    loadLevel(currentLevel);
}

Level::~Level(){
    delete[] enemies;
    delete[] bricks;
}
bool Level::isGoalReached() const{
    return goalReached;
}

void Level::setGoalReached(bool state){
    goalReached = state;
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

int Level::getSpawnX() const{
    return spawnX;
}

int Level::getSpawnY() const{
    return spawnY;
}
