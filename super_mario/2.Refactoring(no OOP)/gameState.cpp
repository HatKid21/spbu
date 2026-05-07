#include "gameState.hpp"
#include "object.hpp"

hatkid::object::TObject* hatkid::state::getNewMoving(GameState& state){
    state.movingLength++;
    state.moving = (TObject*)realloc(state.moving, sizeof(TObject) * state.movingLength);
    return state.moving + movingLength - 1;
}


hatkid::objects::TObject* hatkid::state::getNewBrick(GameState& state){
    state.brickLength++;
    state.brick = (TObject*)realloc(state.brick, sizeof(TObject) * state.brickLength);
    return state.brick + brickLength - 1;
}


void hatkid::state::deleteMoving(GameState& state, int i){
    state.movingLength--;
    state.moving[i] = state.moving[movingLength];
    state.moving = (TObject*)realloc(state.moving,sizeof(TObject) * state.movingLength);
}

bool hatkid::state::isPosInMap(GameState& state,int x, int y){
    return ( (x >= 0) && (x < state.MAP_WIDTH) && (y >= 0) && (y < state.MAP_HEIGHT) );
}
