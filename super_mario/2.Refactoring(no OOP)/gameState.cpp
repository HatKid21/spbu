#include <cstdlib>

#include "gameState.hpp"
#include "object.hpp"

hatkid::TObject* hatkid::getNewMoving(GameState& state){
    state.movingAmount++;
    state.moving = (TObject*)realloc(state.moving, sizeof(TObject) * state.movingAmount);
    return state.moving + state.movingAmount - 1;
}


hatkid::TObject* hatkid::getNewBrick(hatkid::GameState& state){
    state.brickAmount++;
    state.brick = (TObject*)realloc(state.brick, sizeof(TObject) * state.brickAmount);
    return state.brick + state.brickAmount - 1;
}


void hatkid::deleteMoving(hatkid::GameState& state, int i){
    state.movingAmount--;
    state.moving[i] = state.moving[state.movingAmount];
    state.moving = (TObject*)realloc(state.moving,sizeof(TObject) * state.movingAmount);
}

bool hatkid::isPosInMap(hatkid::GameState& state,int x, int y){
    return ( (x >= 0) && (x < hatkid::MAP_WIDTH) && (y >= 0) && (y < hatkid::MAP_HEIGHT) );
}
