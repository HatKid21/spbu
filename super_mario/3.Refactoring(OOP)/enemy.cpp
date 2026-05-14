#include "enemy.hpp"
#include "objectTypes.hpp"

using hatkid::Enemy;

Enemy::Enemy() : GameObject(0,0,hatkid::ObjectType::AIR){};

Enemy::Enemy(float x, float y,float width, float height, hatkid::ObjectType type)
    : GameObject(width, height, type), direction(1),alive(true),onGround(false) {
        setPos(x,y);
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

void Enemy::changeDirection(){
    direction *= -1;
}

void Enemy::setAlive(bool st){
    alive = st;
}

bool Enemy::isAlive() const{
    return alive;
}

void Enemy::setOnGround(bool val){
    onGround = val;
}

bool Enemy::isOnGround() const{
    return onGround;
}
