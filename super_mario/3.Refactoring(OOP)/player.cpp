#include "player.hpp"
#include "level.hpp"

using hatkid::Player;

Player::Player()
    : Movable(3, 3, hatkid::ObjectType::MARIO) {
}

Player::~Player() = default;

char Player::getSymbol() const {
    return '@'; 
}

void Player::onCollision(GameObject& other, Level& level) {

    if (other.getType() == ObjectType::BONUS && getVerticalSpeed() < 0) {
        other.setType(ObjectType::EMPTY_BONUS);
        level.addCoin(other.x(), other.y() - 2);
    }

    if (other.getType() == ObjectType::GOAL) {
        level.setGoalReached(true);
    }
}

void Player::jump() {
    if (onGround) {
        verticalSpeed = -1.0f;
        onGround = false;
    }
}
