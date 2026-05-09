#include <cstring>
#include <math.h>
#include <ncurses.h>

#include "gameState.hpp"
#include "object.hpp"
#include "objectTypes.hpp"
#include "physics.hpp"
#include "render.hpp"

void hatkid::clearMap(hatkid::GameState& state){
    for (int i = 0; i < hatkid::MAP_WIDTH; i++){
        state.map[0][i] = hatkid::TYPE_AIR;
    }
    state.map[0][hatkid::MAP_WIDTH] = '\0';
    for (int i = 1; i < hatkid::MAP_HEIGHT;i++){
        sprintf(state.map[i],state.map[0]);
    }
}

void hatkid::putObjectOnMap(hatkid::GameState& state, 
        hatkid::TObject obj){
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int) round(obj.width);
    int iHeight = (int)round(obj.height);
    for (int i = ix; i < (ix + iWidth);i++){
        for (int j = iy; j < (iy + iHeight);j++){
            if (hatkid::isPosInMap(state,i,j)){
                state.map[j][i] = obj.cType;
            }
        }
    }
}

void hatkid::putScoreOnMap(hatkid::GameState& state){
    char c[30];
    sprintf(c,"Score %d",state.score);
    int len = strlen(c);
    for (int i = 0; i < len;i++){
        state.map[1][i+5] = c[i];
    }
}

void hatkid::renderBricks(hatkid::GameState& state){
    for (int i = 0; i < state.brickAmount;i++){
        hatkid::putObjectOnMap(state,state.brick[i]);
    }
}

void hatkid::renderMoving(hatkid::GameState& state){
    for (int i = 0; i < state.movingAmount; i++){
        hatkid::vertMoveObject(state, state.moving + i);
        hatkid::horizonMoveObject(state,state.moving + i);
        if (state.moving[i].y > hatkid::MAP_HEIGHT){
            hatkid::deleteMoving(state,i);
            i--;
            continue;
        }
        hatkid::putObjectOnMap(state,state.moving[i]);
    }
}

void hatkid::setCursor(int x, int y){
    move(y,x);
}

void hatkid::showMap(hatkid::GameState& state){

    state.map[hatkid::MAP_HEIGHT - 1][hatkid::MAP_WIDTH - 1] = '\0';
    for (int i = 0; i < hatkid::MAP_HEIGHT; i++){
        printw("%s\n",state.map[i]);
    }
    refresh();

}
