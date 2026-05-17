#include "level.hpp"
#include "physics.hpp"

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
}

void Physics::moveVertical(hatkid::Movable& obj, hatkid::Level& level,int mapHeight){
    if (obj.isDead()){
        return;
    }

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

            obj.onCollision(bricks[i],level);

            obj.addY(-obj.getVerticalSpeed());
            obj.setVerticalSpeed(0);

            break;
        }
    }
    if (obj.y() > mapHeight){
        obj.setDead(true);
    }
}

