#include "enemy.hpp"

using hatkid::Enemy;

Enemy::Enemy()
    : GameObject(3, 2, hatkid::ObjectType::ENEMY), direction(1) {
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
