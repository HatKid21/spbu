#include "physics.hpp"
#include "player.hpp"
#include "level.hpp"

using hatkid::Physics;

void Physics::playerMoveHorizontal(hatkid::Player& player, hatkid::Level& level){
    player.setX(player.x() + player.getHorizontalSpeed());

    hatkid::Brick* bricks = level.getBricks();
    int brickAmount = level.getBrickAmount();

    for (int i = 0; i < brickAmount; i++){
        if (player.collisionWith(bricks[i])){
            player.setX(player.x() - player.getHorizontalSpeed());
            player.setHorizontalSpeed(-player.getHorizontalSpeed());
            return;
        }
    }

}

void Physics::playerMoveVertical(hatkid::Player& player, hatkid::Level& level,int mapHeight){
    player.setOnGround(false);
    player.addVerticalSpeed(0.05);
    player.setY(player.y() + player.getVerticalSpeed());

    hatkid::Brick* bricks = level.getBricks();
    int brickAmount = level.getBrickAmount();

    for (int i = 0; i < brickAmount; i++){
        if (player.collisionWith(bricks[i])){
            if (player.getVerticalSpeed() > 0){
                player.setOnGround(true);
            }
            if (bricks[i].getType() == hatkid::ObjectType::BONUS && player.getVerticalSpeed() < 0){
                bricks[i].setType(hatkid::ObjectType::EMPTY_BONUS);
                level.addCoin(bricks[i].x(),bricks[i].y()-2);
            }

            player.setY(player.y() - player.getVerticalSpeed());
            player.setVerticalSpeed(0);

            if (bricks[i].getType() == hatkid::ObjectType::GOAL){
                level.setGoalReached(true);
            }
            break;

        }
    }

    if (player.y() > mapHeight){
        player.setDead(true);
    }

}

void Physics::moveEnemy(hatkid::Enemy& enemy, hatkid::Level& level){
    if (enemy.isDead()){
        return;
    }

    hatkid::Brick* bricks = level.getBricks();
    int brickAmount = level.getBrickAmount();

    float oldX = enemy.x();
    float oldY = enemy.y();
    bool wasOnGround = enemy.isOnGround();

    float speed = 0.5f * enemy.getDirection();
    enemy.setX(enemy.x() + speed);

    for (int i = 0; i < brickAmount; i++){
        if (enemy.collisionWith(bricks[i])){
            enemy.setX(enemy.x() - speed);
            enemy.changeDirection();
            break;
        }
    }
    enemy.setOnGround(false);
    enemy.setY(enemy.y() + 0.5);

    for (int i = 0; i < brickAmount; i++){
        if (enemy.collisionWith(bricks[i])){
            enemy.setY(enemy.y() - 0.5);
            enemy.setOnGround(true);
            break;
        }
    }

    if (wasOnGround && !enemy.isOnGround()){
            enemy.setX(oldX);
            enemy.setY(oldY);
            enemy.setOnGround(true);
            enemy.changeDirection();
    }
}

void Physics::checkPlayerEnemyCollision(hatkid::Player& player, hatkid::Level& level){
    hatkid::Enemy* enemies = level.getEnemies();
    int enemyAmount = level.getEnemyAmount();
    for (int i = 0; i < enemyAmount; i++){
        if (player.collisionWith(enemies[i]) && !enemies[i].isDead()){
            if (!player.isOnGround() 
                    && player.getVerticalSpeed() > 0 
                    && player.y() + player.getHeight() < enemies[i].y() + enemies[i].getHeight() * 0.5){
                level.addScore(250);
                enemies[i].setDead(true);
                continue;
            } else{
                player.setDead(true);
            }
        }
    }
}

void Physics::moveCoin(hatkid::Coin& coin, hatkid::Level& level){
    if (coin.isDead()) {
        return;
    }

    hatkid::Brick* bricks = level.getBricks();
    int brickAmount = level.getBrickAmount();

    float speed = 0.5f * coin.getDirection();
    coin.setX(coin.x() + speed);

    for (int i = 0; i < brickAmount; i++){
        if (coin.collisionWith(bricks[i])){
            coin.setX(coin.x() - speed);
            coin.changeDirection();
            break;
        }
    }

    coin.setOnGround(false);
    coin.addVerticalSpeed(0.05f);
    coin.setY(coin.y() + coin.getVerticalSpeed());

    for (int i = 0; i < brickAmount; i++){
        if (coin.collisionWith(bricks[i])){
            if (coin.getVerticalSpeed() > 0){
                coin.setOnGround(true);
            }
            coin.setY(coin.y() - coin.getVerticalSpeed());
            coin.setVerticalSpeed(0);
            break;
        }
    }
}
            

void Physics::checkPlayerCoinCollision(hatkid::Player& player, hatkid::Level& level){
    hatkid::Coin* coins = level.getCoins();
    int coinAmount = level.getCoinAmount();
    for (int i = 0; i < coinAmount; i++){
        if (player.collisionWith(coins[i]) && !coins[i].isDead()){
            level.addScore(coins[i].getVal());
            coins[i].setDead(true);
        }
    }
}

