#include "player.hpp"

using hatkid::Player;

Player::Player() : GameObject(3,3, hatkid::ObjectType::MARIO){
    onGround = false;
    verticalSpeed = 0;
    horizontalSpeed = 0; 
}

Player::~Player() = default;

void Player::getSymbol const {
    return '@';
}

bool Player::isOnGround() const {
    return onGround;
}

bool Player::setOnGround(bool val){
    this.onGround = val;
}
