#include <cstdlib>

#include "gameState.hpp"
#include "level.hpp"
#include "object.hpp"
#include "objectTypes.hpp"

using hatkid::getNewBrick;
using hatkid::getNewMoving;
using hatkid::initObject;

void hatkid::createLevel(hatkid::GameState& state,int lvl){

    state.isLeftHold = false;
    state.isRightHold = false;

    state.brickAmount = 0;
    state.brick = (hatkid::TObject*)realloc(state.brick, 0);
    state.movingAmount = 0;
    state.moving = (hatkid::TObject*)realloc(state.moving,0);

    hatkid::initObject(&state.mario,39,10,3,3,hatkid::TYPE_MARIO);
    state.score = 0;

    if (lvl == 1){
        initObject(getNewBrick(state),20,21,40,5,hatkid::TYPE_BRICK);
            initObject(getNewBrick(state),30,10,5,3,hatkid::TYPE_BONUS);
            initObject(getNewBrick(state),50,10,5,3,hatkid::TYPE_BONUS);
        initObject(getNewBrick(state),60,15,40,10,hatkid::TYPE_BRICK);
            initObject(getNewBrick(state),60,5,10,3,hatkid::TYPE_EMPTY_BONUS);
            initObject(getNewBrick(state),70,5,5,3,hatkid::TYPE_BONUS);
            initObject(getNewBrick(state),75,5,5,3,hatkid::TYPE_EMPTY_BONUS);
            initObject(getNewBrick(state),80,5,5,3,hatkid::TYPE_BONUS);
            initObject(getNewBrick(state),85,5,10,3,hatkid::TYPE_EMPTY_BONUS);
        initObject(getNewBrick(state),100,20,20,5,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),120,15,10,10,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),150,20,40,5,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),210,15,10,10,hatkid::TYPE_GOAL);
        
        initObject(getNewMoving(state),25,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),80,10,3,2,hatkid::TYPE_ENEMY);
    }

    if (lvl == 2){

        initObject(getNewBrick(state),20,21,40,5,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),60,15,10,10,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),80,20,20,5,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),120,15,10,10,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),150,20,40,5,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),210,15,10,10,hatkid::TYPE_GOAL);

        initObject(getNewMoving(state),25,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),80,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),65,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),120,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),160,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),175,10,3,2,hatkid::TYPE_ENEMY);
    }
    if (lvl == 3){

        initObject(getNewBrick(state),20,21,40,5,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),80,20,15,5,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),120,15,15,10,hatkid::TYPE_BRICK);
        initObject(getNewBrick(state),160,10,15,15,hatkid::TYPE_GOAL);

        initObject(getNewMoving(state),25,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),50,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),80,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),90,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),120,10,3,2,hatkid::TYPE_ENEMY);
        initObject(getNewMoving(state),130,10,3,2,hatkid::TYPE_ENEMY);
    }

    state.maxLevel = 3;
}
