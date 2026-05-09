#include <ncurses.h>

#include "level.hpp"
#include "object.hpp"
#include "objectTypes.hpp"
#include "physics.hpp"
#include "utils.hpp"

void hatkid::horizonMoveMap(
        hatkid::TObject& mario, 
        hatkid::TObject* brick, int brickAmount, 
        hatkid::TObject* moving, int movingAmount, 
        float dx
        ) {
    mario.x -= dx;

    for (int i = 0; i < brickAmount; i++) {
        if (isCollision(mario, brick[i])) {
            mario.x += dx;
            return;
        }
    }
    mario.x += dx;

    for (int i = 0; i < brickAmount; i++) {
        brick[i].x += dx;
    }
    for (int i = 0; i < movingAmount; i++) {
        moving[i].x += dx;
    }
}

void hatkid::horizonMoveObject(
        hatkid::TObject* brick, int brickAmount, 
        hatkid::TObject* obj
        ) {
    obj->x += obj->horizontalSpeed;

    for (int i = 0; i < brickAmount; i++) {
        if (isCollision(*obj, brick[i])) {
            obj->x -= obj->horizontalSpeed;
            obj->horizontalSpeed = -obj->horizontalSpeed;
            return;
        }
    }

    if (obj->cType == hatkid::ObjectType::ENEMY) {
        hatkid::TObject temp = *obj;
        int dummyLevel = 0, dummyMax = 0, dummyScore = 0;
        bool dummyL = false, dummyR = false;
        TObject* dummyMoving = nullptr;
        int dummyMovingAmount = 0;
        TObject dummyMario;
        
        hatkid::vertMoveObject(dummyMario, brick, brickAmount, &temp, dummyLevel, dummyMax, dummyMoving, dummyMovingAmount, dummyScore, dummyL, dummyR);
        if (temp.isFly) {
            obj->x -= obj->horizontalSpeed;
            obj->horizontalSpeed = -obj->horizontalSpeed;
        }
    }
}

bool hatkid::isCollision(hatkid::TObject o1, hatkid::TObject o2) {
    return (o1.x + o1.width > o2.x) && (o1.x < o2.x + o2.width) &&
           (o1.y + o1.height > o2.y) && (o1.y < o2.y + o2.height);
}

void hatkid::marioCollision(
        hatkid::TObject& mario, 
        hatkid::TObject* &moving, int &movingAmount, 
        int &score, 
        int &level, int maxLevel, 
        hatkid::TObject* &brick, int &brickAmount, 
        bool &isLeftHold, bool &isRightHold
        ) {
    for (int i = 0; i < movingAmount; i++) {
        if (isCollision(mario, moving[i])) {
            if (moving[i].cType == hatkid::ObjectType::ENEMY) {
                if (mario.isFly && 
                    mario.verticalSpeed > 0 && 
                    mario.y + mario.height < moving[i].y + moving[i].height * 0.5f) {
                    score += 50;
                    deleteMoving(moving, movingAmount, i);
                    i--;
                    continue;
                } else {
                    napms(500);
                    hatkid::createLevel(mario, brick, brickAmount, moving, movingAmount, score, level, maxLevel, isLeftHold, isRightHold);
                }
            }

            if (moving[i].cType == hatkid::ObjectType::MONEY) {
                score += 100;
                deleteMoving(moving, movingAmount, i);
                i--;
            }
        }
    }
}

void hatkid::vertMoveObject(
        hatkid::TObject& mario, 
        hatkid::TObject* brick, int brickAmount, 
        hatkid::TObject* obj, 
        int &level, int maxLevel, 
        hatkid::TObject* &moving, int &movingAmount, 
        int &score, 
        bool &isLeftHold, bool &isRightHold
        ) {
    obj->isFly = true;
    obj->verticalSpeed += 0.05f;
    hatkid::setObjectPos(obj, obj->x, obj->y + obj->verticalSpeed);

    for (int i = 0; i < brickAmount; i++) {
        if (isCollision(*obj, brick[i])) {
            if (obj->verticalSpeed > 0) {
                obj->isFly = false;
            }

            if (brick[i].cType == hatkid::ObjectType::BONUS && obj->verticalSpeed < 0 && obj == &mario) {
                brick[i].cType = hatkid::ObjectType::EMPTY_BONUS;
                hatkid::TObject* coin = getNewMoving(moving, movingAmount);
                hatkid::initObject(coin, brick[i].x, brick[i].y - 3, 3, 2, hatkid::ObjectType::MONEY);
                coin->verticalSpeed = -0.5f;
            }

            obj->y -= obj->verticalSpeed;
            obj->verticalSpeed = 0;

            if (brick[i].cType == hatkid::ObjectType::GOAL && obj == &mario) {
                level++;
                if (level > maxLevel) {
                    level = 1;
                }
                napms(1000);
                hatkid::createLevel(mario, brick, brickAmount, moving, movingAmount, score, level, maxLevel, isLeftHold, isRightHold);
            }
            break;
        }
    }
}
