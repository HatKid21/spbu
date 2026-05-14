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

void Physics::playerMoveVertical(hatkid::Player& player, hatkid::Level& level){
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
                //TODO create coins
            }

            player.setY(player.y() - player.getVerticalSpeed());
            player.setVerticalSpeed(0);

            if (bricks[i].getType() == hatkid::ObjectType::GOAL){
                //TODO next level logic
            }
            break;

        }
    }

}

void Physics::moveEnemy(hatkid::Enemy& enemy, hatkid::Level& level){
    if (!enemy.isAlive()){
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
        if (player.collisionWith(enemies[i])){
            if (!player.isOnGround() 
                    && player.getVerticalSpeed() > 0 
                    && player.y() + player.getHeight() < enemies[i].y() + enemies[i].getHeight() * 0.5){
                level.addScore(100);
                enemies[i].setAlive(false);
                continue;
            } else{
                //TODO player died level restart
            }
        }
    }
}

//TODO logic for coins
