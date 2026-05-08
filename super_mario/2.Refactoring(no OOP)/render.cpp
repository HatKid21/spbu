#include <cstring>
#include <math.h>
#include <ncurses.h>

#include "gameState.hpp"
#include "object.hpp"
#include "physics.hpp"
#include "render.hpp"

void hatkid::render::clearMap(hatkid::game::GameState& state){
    for (int i = 0; i < hatkid::game::MAP_WIDTH; i++){
        state.map[0][i] = ' ';
    }
    state.map[0][hatkid::game::MAP_WIDTH] = '\0';
    for (int i = 1; i < hatkid::game::MAP_HEIGHT;i++){
        sprintf(state.map[i],state.map[0]);
    }
}

void hatkid::render::showMap(hatkid::game::GameState& state){

    state.map[hatkid::game::MAP_HEIGHT - 1][hatkid::game::MAP_WIDTH - 1] = '\0';
    for (int i = 0; i < hatkid::game::MAP_HEIGHT; i++){
        printw("%s\n",state.map[i]);
    }
    refresh();

}

void hatkid::render::putObjectOnMap(hatkid::game::GameState& state, 
        hatkid::objects::TObject obj){
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int) round(obj.width);
    int iHeight = (int)round(obj.height);
    for (int i = ix; i < (ix + iWidth);i++){
        for (int j = iy; j < (iy + iHeight);j++){
            if (hatkid::game::isPosInMap(state,i,j)){
                state.map[j][i] = obj.cType;
            }
        }
    }
}

void hatkid::render::setCursor(int x, int y){
    move(y,x);
}

void hatkid::render::putScoreOnMap(hatkid::game::GameState& state){
    char c[30];
    sprintf(c,"Score %d",state.score);
    int len = strlen(c);
    for (int i = 0; i < len;i++){
        state.map[1][i+5] = c[i];
    }
}

void hatkid::render::renderBricks(hatkid::game::GameState& state){
    for (int i = 0; i < state.brickAmount;i++){
        hatkid::render::putObjectOnMap(state,state.brick[i]);
    }
}

void hatkid::render::renderMoving(hatkid::game::GameState& state){
    for (int i = 0; i < state.movingAmount; i++){
        hatkid::physics::vertMoveObject(state, state.moving + i);
        hatkid::physics::horizonMoveObject(state,state.moving + i);
        if (state.moving[i].y > hatkid::game::MAP_HEIGHT){
            hatkid::game::deleteMoving(state,i);
            i--;
            continue;
        }
        hatkid::render::putObjectOnMap(state,state.moving[i]);
    }
}

