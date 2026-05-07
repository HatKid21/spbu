#include <cstdlib>

#include "gameState.hpp"
#include "object.hpp"

hatkid::objects::TObject* hatkid::game::getNewMoving(GameState& state){
    state.movingAmount++;
    state.moving = (TObject*)realloc(state.moving, sizeof(TObject) * state.movingAmount);
    return state.moving + state.movingAmount - 1;
}


hatkid::objects::TObject* hatkid::game::getNewBrick(hatkid::game::GameState& state){
    state.brickAmount++;
    state.brick = (TObject*)realloc(state.brick, sizeof(TObject) * state.brickAmount);
    return state.brick + state.brickAmount - 1;
}


void hatkid::game::deleteMoving(hatkid::game::GameState& state, int i){
    state.movingAmount--;
    state.moving[i] = state.moving[state.movingAmount];
    state.moving = (TObject*)realloc(state.moving,sizeof(TObject) * state.movingAmount);
}

bool hatkid::game::isPosInMap(hatkid::game::GameState& state,int x, int y){
    return ( (x >= 0) && (x < hatkid::game::MAP_WIDTH) && (y >= 0) && (y < hatkid::game::MAP_HEIGHT) );
}
