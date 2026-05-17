#include "physics.hpp"
#include "player.hpp"
#include "level.hpp"

using hatkid::Physics;

void Physics::moveHorizontal(hatkid::Movable& obj, hatkid::Level& level){
    if (obj.isDead()){
        return;
    }

    obj.addX(obj.getHorizontalSpeed());

    hatkid::Brick* bricks = level.getBricks();
    int brickAmount = level.getBrickAmount();

    for (int i = 0; i < brickAmount; i++){
        if (obj.collisionWith(bricks[i])){
            obj.addX(-obj.getHorizontalSpeed());
            obj.setHorizontalSpeed(-obj.getHorizontalSpeed());
            return;
        }
    }

    if (Enemy* enemy = dynamic_cast<Enemy*>(&obj)){
        bool groundBelow = false;
        enemy->addY(1);
        for (int i = 0; i < brickAmount; i++){
            if (enemy->collisionWith(bricks[i])){
                groundBelow = true;
                break;
            }
        }
        enemy->addY(-1);
        if (!groundBelow){
            obj.addX(-obj.getHorizontalSpeed());
            obj.setHorizontalSpeed(-obj.getHorizontalSpeed());
        }
    }


}

void Physics::moveVertical(hatkid::Movable& obj, hatkid::Level& level,int mapHeight){
    if (obj.isDead()){
        return;
    }

    float oldY = obj.y();
    bool wasOnGround = obj.isOnGround();

    obj.setOnGround(false);
    obj.addVerticalSpeed(0.05);
    obj.addY(obj.getVerticalSpeed());

    hatkid::Brick* bricks = level.getBricks();
    int brickAmount = level.getBrickAmount();

    for (int i = 0; i < brickAmount; i++){
        if (obj.collisionWith(bricks[i])){
            if (obj.getVerticalSpeed() > 0){
                obj.setOnGround(true);
            }
            if (Player* player = dynamic_cast<Player*>(&obj)){
                if (bricks[i].getType() == hatkid::ObjectType::BONUS && player->getVerticalSpeed() < 0){
                    bricks[i].setType(hatkid::ObjectType::EMPTY_BONUS);
                    level.addCoin(bricks[i].x(),bricks[i].y()-2);
                }
                if (bricks[i].getType() == hatkid::ObjectType::GOAL){
                    level.setGoalReached(true);
                }
            }
            obj.addY(-obj.getVerticalSpeed());
            obj.setVerticalSpeed(0);

            break;
        }
    }

    if (obj.y() > mapHeight){
        obj.setDead(true);
    }

}

void Physics::checkPlayerMovableCollision(hatkid::Player& player, hatkid::Level& level){
    hatkid::Enemy* enemies = level.getEnemies();
    int enemyAmount = level.getEnemyAmount();
    for (int i = 0; i < enemyAmount;i++){
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
    hatkid::Coin* coins = level.getCoins();
    int coinAmount = level.getCoinAmount();
    for (int i = 0; i < coinAmount; i++){
        if (player.collisionWith(coins[i]) && !coins[i].isDead()){
            level.addScore(coins[i].getVal());
            coins[i].setDead(true);
        }
    }
}

