#include <cstring>
#include <math.h>
#include <ncurses.h>

#include "object.hpp"
#include "objectTypes.hpp"
#include "physics.hpp"
#include "render.hpp"
#include "utils.hpp"

void hatkid::clearMap(char map[25][81], int MAP_WIDTH, int MAP_HEIGHT){
    for (int i = 0; i < MAP_WIDTH; i++){
        map[0][i] = hatkid::TYPE_AIR;
    }
    map[0][MAP_WIDTH] = '\0';
    for (int i = 1; i < MAP_HEIGHT;i++){
        sprintf(map[i], map[0]);
    }
}

void hatkid::putObjectOnMap(char map[25][81], hatkid::TObject obj, int MAP_WIDTH, int MAP_HEIGHT){
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int) round(obj.width);
    int iHeight = (int)round(obj.height);
    for (int i = ix; i < (ix + iWidth);i++){
        for (int j = iy; j < (iy + iHeight);j++){
            if (hatkid::isPosInMap(i, j, MAP_WIDTH, MAP_HEIGHT)){
                map[j][i] = obj.cType;
            }
        }
    }
}

void hatkid::putScoreOnMap(char map[25][81], int score){
    char c[30];
    sprintf(c,"Score %d", score);
    int len = strlen(c);
    for (int i = 0; i < len;i++){
        map[1][i+5] = c[i];
    }
}

void hatkid::renderBricks(char map[25][81], hatkid::TObject* brick, int brickAmount, int MAP_WIDTH, int MAP_HEIGHT){
    for (int i = 0; i < brickAmount;i++){
        hatkid::putObjectOnMap(map, brick[i], MAP_WIDTH, MAP_HEIGHT);
    }
}

void hatkid::renderMoving(char map[25][81], hatkid::TObject* &moving, int &movingAmount, hatkid::TObject* brick, int brickAmount, int MAP_WIDTH, int MAP_HEIGHT, hatkid::TObject& mario, int &level, int maxLevel, int &score, bool &isLeftHold, bool &isRightHold){
    for (int i = 0; i < movingAmount; i++){
        hatkid::vertMoveObject(mario, brick, brickAmount, moving + i, level, maxLevel, moving, movingAmount, score, isLeftHold, isRightHold);
        hatkid::horizonMoveObject(brick, brickAmount, moving + i);
        if (moving[i].y > MAP_HEIGHT){
            hatkid::deleteMoving(moving, movingAmount, i);
            i--;
            continue;
        }
        hatkid::putObjectOnMap(map, moving[i], MAP_WIDTH, MAP_HEIGHT);
    }
}

void hatkid::setCursor(int x, int y){
    move(y,x);
}

void hatkid::showMap(char map[25][81], int MAP_WIDTH, int MAP_HEIGHT){
    map[MAP_HEIGHT - 1][MAP_WIDTH - 1] = '\0';
    for (int i = 0; i < MAP_HEIGHT; i++){
        printw("%s\n", map[i]);
    }
    refresh();
}
