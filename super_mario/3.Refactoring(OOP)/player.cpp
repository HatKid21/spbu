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

void Player::handleInteractions(Level& level){
    Enemy* enemies = level.getEnemies();
    int enemyAmount = level.getEnemyAmount();

    for (int i = 0; i < enemyAmount; i++) {

        if (collisionWith(enemies[i]) && !enemies[i].isDead()) {

            if (!isOnGround()
                && getVerticalSpeed() > 0
                && y() + getHeight() < enemies[i].y() + enemies[i].getHeight() * 0.5) {

                level.addScore(250);
                enemies[i].setDead(true);

            } else {
                setDead(true);
            }
        }
    }

    Coin* coins = level.getCoins();
    int coinAmount = level.getCoinAmount();

    for (int i = 0; i < coinAmount; i++) {

        if (collisionWith(coins[i]) && !coins[i].isDead()) {

            level.addScore(coins[i].getVal());
            coins[i].setDead(true);
        }
    }
}
