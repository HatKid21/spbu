#include <ncurses.h>
#include <math.h>
#include <cstring>

#include "gameState.hpp"
#include "render.hpp"
#include "object.hpp"

void hatkid::render::clearMap(hatkid::game::GameState& state){
    for (int i = 0; i < state.MAP_WIDTH; i++){
        state.map[0][i] = ' ';
    }
    state.map[0][state.MAP_WIDTH] = '\0';
    for (int i = 1; i < state.MAP_HEIGHT;i++){
        sprintf(map[i],map[0]);
    }
}

void hatkid::render::showMap(hatkid::game::GameState& state){

    state.map[state.MAP_HEIGHT - 1][state.MAP.WIDTH - 1] = '\0';
    for (int i = 0; i < state.MAP_HEIGHT; i++){
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
            if (hatkid::game::isPosInMap(i,j)){
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
    sprintf(c,"Score %d",score);
    int len = strlen(c);
    for (int i = 0; i < len;i++){
        state.map[1][i+5] = c[i];
    }
}
