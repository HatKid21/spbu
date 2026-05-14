#include "player.hpp"

using hatkid::Player;

Player::Player()
    : Movable(3, 3, hatkid::ObjectType::MARIO) {
}

Player::~Player() = default;

char Player::getSymbol() const {
    return '@'; 
}

void Player::jump() {
    if (onGround) {
        verticalSpeed = -1.0f;
        onGround = false;
    }
}
