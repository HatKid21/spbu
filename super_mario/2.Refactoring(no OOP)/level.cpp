#include "level.hpp"

void createLevel(int lvl){

    isLeftHold = false;
    isRightHold = false;

    brickLength = 0;
    brick = (TObject*)realloc(brick, 0);
    movingLength = 0;
    moving = (TObject*)realloc(moving,0);

    initObject(&mario,39,10,3,3,'@');
    score = 0;

    if (lvl == 1){
        initObject(getNewBrick(),20,21,40,5,'#');
            initObject(getNewBrick(),30,10,5,3,'?');
            initObject(getNewBrick(),50,10,5,3,'?');
        initObject(getNewBrick(),60,15,40,10,'#');
            initObject(getNewBrick(),60,5,10,3,'-');
            initObject(getNewBrick(),70,5,5,3,'?');
            initObject(getNewBrick(),75,5,5,3,'-');
            initObject(getNewBrick(),80,5,5,3,'?');
            initObject(getNewBrick(),85,5,10,3,'-');
        initObject(getNewBrick(),100,20,20,5,'#');
        initObject(getNewBrick(),120,15,10,10,'#');
        initObject(getNewBrick(),150,20,40,5,'#');
        initObject(getNewBrick(),210,15,10,10,'+');
        
        initObject(getNewMoving(),25,10,3,2,'o');
        initObject(getNewMoving(),80,10,3,2,'o');
    }

    if (lvl == 2){

        initObject(getNewBrick(),20,21,40,5,'#');
        initObject(getNewBrick(),60,15,10,10,'#');
        initObject(getNewBrick(),80,20,20,5,'#');
        initObject(getNewBrick(),120,15,10,10,'#');
        initObject(getNewBrick(),150,20,40,5,'#');
        initObject(getNewBrick(),210,15,10,10,'+');

        initObject(getNewMoving(),25,10,3,2,'o');
        initObject(getNewMoving(),80,10,3,2,'o');
        initObject(getNewMoving(),65,10,3,2,'o');
        initObject(getNewMoving(),120,10,3,2,'o');
        initObject(getNewMoving(),160,10,3,2,'o');
        initObject(getNewMoving(),175,10,3,2,'o');
    }
    if (lvl == 3){

        initObject(getNewBrick(),20,21,40,5,'#');
        initObject(getNewBrick(),80,20,15,5,'#');
        initObject(getNewBrick(),120,15,15,10,'#');
        initObject(getNewBrick(),160,10,15,15,'+');

        initObject(getNewMoving(),25,10,3,2,'o');
        initObject(getNewMoving(),50,10,3,2,'o');
        initObject(getNewMoving(),80,10,3,2,'o');
        initObject(getNewMoving(),90,10,3,2,'o');
        initObject(getNewMoving(),120,10,3,2,'o');
        initObject(getNewMoving(),130,10,3,2,'o');
    }

    maxLvl = 3;
}
