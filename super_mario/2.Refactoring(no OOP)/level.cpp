#include <cstdlib>

#include "gameState.hpp"
#include "level.hpp"
#include "object.hpp"

using hatkid::objects::initObject;
using hatkid::game::getNewBrick;
using hatkid::game::getNewMoving;

void hatkid::level::createLevel(hatkid::game::GameState& state,int lvl){

    state.isLeftHold = false;
    state.isRightHold = false;

    state.brickAmount = 0;
    state.brick = (hatkid::objects::TObject*)realloc(state.brick, 0);
    state.movingAmount = 0;
    state.moving = (hatkid::objects::TObject*)realloc(state.moving,0);

    hatkid::objects::initObject(&state.mario,39,10,3,3,'@');
    state.score = 0;

    if (lvl == 1){
        initObject(getNewBrick(state),20,21,40,5,'#');
            initObject(getNewBrick(state),30,10,5,3,'?');
            initObject(getNewBrick(state),50,10,5,3,'?');
        initObject(getNewBrick(state),60,15,40,10,'#');
            initObject(getNewBrick(state),60,5,10,3,'-');
            initObject(getNewBrick(state),70,5,5,3,'?');
            initObject(getNewBrick(state),75,5,5,3,'-');
            initObject(getNewBrick(state),80,5,5,3,'?');
            initObject(getNewBrick(state),85,5,10,3,'-');
        initObject(getNewBrick(state),100,20,20,5,'#');
        initObject(getNewBrick(state),120,15,10,10,'#');
        initObject(getNewBrick(state),150,20,40,5,'#');
        initObject(getNewBrick(state),210,15,10,10,'+');
        
        initObject(getNewMoving(state),25,10,3,2,'o');
        initObject(getNewMoving(state),80,10,3,2,'o');
    }

    if (lvl == 2){

        initObject(getNewBrick(state),20,21,40,5,'#');
        initObject(getNewBrick(state),60,15,10,10,'#');
        initObject(getNewBrick(state),80,20,20,5,'#');
        initObject(getNewBrick(state),120,15,10,10,'#');
        initObject(getNewBrick(state),150,20,40,5,'#');
        initObject(getNewBrick(state),210,15,10,10,'+');

        initObject(getNewMoving(state),25,10,3,2,'o');
        initObject(getNewMoving(state),80,10,3,2,'o');
        initObject(getNewMoving(state),65,10,3,2,'o');
        initObject(getNewMoving(state),120,10,3,2,'o');
        initObject(getNewMoving(state),160,10,3,2,'o');
        initObject(getNewMoving(state),175,10,3,2,'o');
    }
    if (lvl == 3){

        initObject(getNewBrick(state),20,21,40,5,'#');
        initObject(getNewBrick(state),80,20,15,5,'#');
        initObject(getNewBrick(state),120,15,15,10,'#');
        initObject(getNewBrick(state),160,10,15,15,'+');

        initObject(getNewMoving(state),25,10,3,2,'o');
        initObject(getNewMoving(state),50,10,3,2,'o');
        initObject(getNewMoving(state),80,10,3,2,'o');
        initObject(getNewMoving(state),90,10,3,2,'o');
        initObject(getNewMoving(state),120,10,3,2,'o');
        initObject(getNewMoving(state),130,10,3,2,'o');
    }

    state.maxLevel = 3;
}
