#include "player.hpp"

using hatkid::Player;

Player::Player()
    : GameObject(3, 3, hatkid::ObjectType::MARIO),
      verticalSpeed(0), horizontalSpeed(0), onGround(false) {
}

Player::~Player() = default;

char Player::getSymbol() const {
    return '@';
}

bool Player::isOnGround() const {
    return onGround;
}

void Player::setOnGround(bool val) {
    onGround = val;
}

void Player::jump() {
    if (onGround) {
        verticalSpeed = -1.0f;
        onGround = false;
    }
}

float Player::getVerticalSpeed() const {
    return verticalSpeed;
}
void Player::addVerticalSpeed(float ds){
    verticalSpeed += ds;
}

void Player::setVerticalSpeed(float speed) {
    verticalSpeed = speed;
}

float Player::getHorizontalSpeed() const {
    return horizontalSpeed;
}
void Player::addHorizontalSpeed(float ds){
    horizontalSpeed += ds;
}

void Player::setHorizontalSpeed(float speed) {
    horizontalSpeed = speed;
}

void Player::setDead(bool state){
    dead = state;
}

bool Player::isDead() const{
    return dead;
}
