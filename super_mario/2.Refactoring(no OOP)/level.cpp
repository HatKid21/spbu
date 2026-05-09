#include "level.hpp"
#include "object.hpp"
#include "objectTypes.hpp"
#include "utils.hpp"

using hatkid::getNewBrick;
using hatkid::getNewMoving;
using hatkid::initObject;

void hatkid::createLevel(hatkid::TObject& mario, hatkid::TObject* &bricks, int &brickAmount, 
                         hatkid::TObject* &moving, int &movingAmount, int &score, 
                         int &level, int &maxLevel, bool &isLeftHold, bool &isRightHold) {

    isLeftHold = false;
    isRightHold = false;

    if (bricks != nullptr) {
        delete[] bricks;
        bricks = nullptr;
    }
    brickAmount = 0;

    if (moving != nullptr) {
        delete[] moving;
        moving = nullptr;
    }
    movingAmount = 0;

    hatkid::initObject(&mario, 39, 10, 3, 3, hatkid::TYPE_MARIO);
    score = 0;

    if (level == 1) {
        initObject(getNewBrick(bricks, brickAmount), 20, 21, 40, 5, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 30, 10, 5, 3, hatkid::TYPE_BONUS);
        initObject(getNewBrick(bricks, brickAmount), 50, 10, 5, 3, hatkid::TYPE_BONUS);
        initObject(getNewBrick(bricks, brickAmount), 60, 15, 40, 10, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 60, 5, 10, 3, hatkid::TYPE_EMPTY_BONUS);
        initObject(getNewBrick(bricks, brickAmount), 70, 5, 5, 3, hatkid::TYPE_BONUS);
        initObject(getNewBrick(bricks, brickAmount), 75, 5, 5, 3, hatkid::TYPE_EMPTY_BONUS);
        initObject(getNewBrick(bricks, brickAmount), 80, 5, 5, 3, hatkid::TYPE_BONUS);
        initObject(getNewBrick(bricks, brickAmount), 85, 5, 10, 3, hatkid::TYPE_EMPTY_BONUS);
        initObject(getNewBrick(bricks, brickAmount), 100, 20, 20, 5, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 120, 15, 10, 10, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 150, 20, 40, 5, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 210, 15, 10, 10, hatkid::TYPE_GOAL);
        
        initObject(getNewMoving(moving, movingAmount), 25, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 80, 10, 3, 2, hatkid::TYPE_ENEMY);
    }

    if (level == 2) {
        initObject(getNewBrick(bricks, brickAmount), 20, 21, 40, 5, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 60, 15, 10, 10, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 80, 20, 20, 5, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 120, 15, 10, 10, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 150, 20, 40, 5, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 210, 15, 10, 10, hatkid::TYPE_GOAL);

        initObject(getNewMoving(moving, movingAmount), 25, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 80, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 65, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 120, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 160, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 175, 10, 3, 2, hatkid::TYPE_ENEMY);
    }

    if (level == 3) {
        initObject(getNewBrick(bricks, brickAmount), 20, 21, 40, 5, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 80, 20, 15, 5, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 120, 15, 15, 10, hatkid::TYPE_BRICK);
        initObject(getNewBrick(bricks, brickAmount), 160, 10, 15, 15, hatkid::TYPE_GOAL);

        initObject(getNewMoving(moving, movingAmount), 25, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 50, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 80, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 90, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 120, 10, 3, 2, hatkid::TYPE_ENEMY);
        initObject(getNewMoving(moving, movingAmount), 130, 10, 3, 2, hatkid::TYPE_ENEMY);
    }

    maxLevel = 3;
}
