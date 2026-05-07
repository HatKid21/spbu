#include "object.hpp"
#include "objectFunctions.hpp"

bool isCollision(TObject o1, TObject o2){
    return ( (o1.x + o1.width) > o2.x ) && (o1.x < (o2.x + o2.width)) &&
        ( (o1.y + o1.height) > o2.y ) && (o1.y < (o2.y + o2.height));
}

void marioCollision(){
    for (int i = 0; i < movingLength;i++){
        if (isCollision(mario,moving[i])){
            if (moving[i].cType == 'o'){
                if (mario.isFly && (mario.verticalSpeed > 0) && (mario.y + mario.height < moving[i].y + moving[i].height * 0.5)){
                    score += 50;
                    deleteMoving(i);
                    i--;
                    continue;
                } else{
                    napms(500);
                    createLevel(level);
                }
            }

            if (moving[i].cType == '$'){
                score += 100;
                deleteMoving(i);
                i--;
                continue;
            }
        }
    }
}


void horizonMoveObject(TObject *obj){
    obj[0].x += obj[0].horizontalSpeed;
    for (int i = 0; i < brickLength;i++){
        if (isCollision(obj[0],brick[i])){
            obj[0].x -= obj[0].horizontalSpeed;
            obj[0].horizontalSpeed = -obj[0].horizontalSpeed;
            return;
        }
    }
    if (obj[0].cType == 'o'){
        TObject temp = *obj;
        vertMoveObject(&temp);
        if (temp.isFly == true){
            obj[0].x -= obj[0].horizontalSpeed;
            obj[0].horizontalSpeed = -obj[0].horizontalSpeed;
        }
    }
}

void horizonMoveMap(float dx){

    mario.x -= dx;
    for (int i = 0; i < brickLength; i++){
        if (isCollision(mario, brick[i])){
            mario.x += dx;
            return;
        }
    }
    mario.x += dx;

    for (int i = 0; i < brickLength; i++){
        brick[i].x += dx;
    }
    for (int i = 0; i < movingLength; i++){
        moving[i].x += dx;
    }
}

void vertMoveObject(TObject *obj){
    (*obj).isFly = true;
    (*obj).verticalSpeed += 0.05;
    setObjectPos(obj,(*obj).x,(*obj).y + (*obj).verticalSpeed);
    for (int i = 0 ; i < brickLength; i++){
        if (isCollision(obj[0],brick[i])){
            if (obj[0].verticalSpeed > 0){
                obj[0].isFly = false;
            }

            if ((brick[i].cType == '?') && (obj[0].verticalSpeed < 0) && (obj == &mario) ){
                brick[i].cType = '-';
                initObject(getNewMoving(),brick[i].x,brick[i].y-3,3,2,'$');
                moving[movingLength-1].verticalSpeed = -0.5;
            }

            (*obj).y -= (*obj).verticalSpeed;
            (*obj).verticalSpeed = 0;
            if (brick[i].cType == '+'){
                level++;
                if (level > maxLvl) level = 1;
                napms(1000);
                createLevel(level);
            }
            break;
        }
    }
}
