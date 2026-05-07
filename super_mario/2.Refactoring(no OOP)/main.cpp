#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include <ncurses.h>
#include <math.h>
#include <time.h>

#include "object.hpp"
#include "objectFunctions.hpp"

void clearMap(){
    for (int i = 0; i < mapWidth; i++){
        map[0][i] = ' ';
    }
    map[0][mapWidth] = '\0';
    for (int i = 1; i < mapHeight;i++){
        sprintf(map[i],map[0]);
    }
}

void showMap(){

    map[mapHeight - 1][mapWidth - 1] = '\0';
    for (int i = 0; i < mapHeight; i++){
        printw("%s\n",map[i]);
    }
    refresh();

}

bool isCollision(TObject o1, TObject o2);
void createLevel(int lvl);

TObject *getNewMoving();

void deleteMoving(int i){
    movingLength--;
    moving[i] = moving[movingLength];
    moving = (TObject*)realloc(moving,sizeof(*moving) * movingLength);
}

bool isPosInMap(int x, int y){
    return ( (x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeight) );
}

void putObjectOnMap(TObject obj){
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int) round(obj.width);
    int iHeight = (int)round(obj.height);
    for (int i = ix; i < (ix + iWidth);i++){
        for (int j = iy; j < (iy + iHeight);j++){
            if (isPosInMap(i,j)){
                map[j][i] = obj.cType;
            }
        }
    }
}

void setCursor(int x, int y){
    move(y,x);
}

bool isRightHold = false;
bool isLeftHold = false;

TObject *getNewBrick(){
    brickLength++;
    brick = (TObject*)realloc(brick, sizeof(*brick) * brickLength);
    return brick + brickLength - 1;
}

TObject *getNewMoving(){
    movingLength++;
    moving = (TObject*)realloc(moving, sizeof(*moving) * movingLength);
    return moving + movingLength - 1;
}

void putScoreOnMap(){
    char c[30];
    sprintf(c,"Score %d",score);
    int len = strlen(c);
    for (int i = 0; i < len;i++){
        map[1][i+5] = c[i];
    }
}

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

int main(){

    //Инициализация ncurses для фиксирования нажатий на Линуксе
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    nodelay(stdscr,TRUE);

    createLevel(level);

    while(true){
        clearMap();
        int input;
        switch (input){
            case ' ':
                if (!mario.isFly){
                mario.verticalSpeed = -1;
                }
                break;
            case 'q':
                endwin();
                return 0;
            case KEY_LEFT:
                isLeftHold = !isLeftHold;
                isRightHold = false;
                break;
            case KEY_RIGHT:
                isRightHold = !isRightHold;
                isLeftHold = false;
                break;
        }
        input = getch();

        if (isRightHold) horizonMoveMap(-1);
        if (isLeftHold) horizonMoveMap(1);

        if (mario.y > mapHeight) {
            napms(500);
            createLevel(level);
        }
        vertMoveObject(&mario);
        marioCollision();

        for (int i = 0; i < brickLength;i++){
            putObjectOnMap(brick[i]);
        }
        for (int i = 0; i < movingLength;i++){
            vertMoveObject(moving + i);
            horizonMoveObject(moving + i);
            if (moving[i].y > mapHeight){
                deleteMoving(i);
                i--;
                continue;
            }
            putObjectOnMap(moving[i]);
        }

        putObjectOnMap(mario);

        putScoreOnMap();

        setCursor(0,0);
        showMap();

        napms(16);

    }

    endwin();
}
