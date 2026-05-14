#include "enemy.hpp"

using hatkid::Enemy;

Enemy::Enemy() : Movable(0, 0, hatkid::ObjectType::AIR), direction(1) {
    dead = true;
}

Enemy::Enemy(float x, float y, float width, float height, hatkid::ObjectType type)
    : Movable(width, height, type), direction(1) {
    setPos(x, y);
}

char Enemy::getSymbol() const { 
    return 'o'; 
}

int Enemy::getDirection() const { 
    return direction; 
}
void Enemy::setDirection(int dir) { 
    direction = dir; 
}
void Enemy::changeDirection() {
    direction *= -1; 
}
