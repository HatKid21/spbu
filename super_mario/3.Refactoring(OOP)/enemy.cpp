#include "enemy.hpp"

using hatkid::Enemy;

Enemy::Enemy() : Movable(0, 0, hatkid::ObjectType::AIR) {
    dead = true;
}

Enemy::Enemy(float x, float y, float width, float height, hatkid::ObjectType type)
    : Movable(width, height, type) {
    setPos(x, y);
    setHorizontalSpeed(0.5);
}

char Enemy::getSymbol() const { 
    return 'o'; 
}

