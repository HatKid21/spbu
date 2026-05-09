#pragma once

#include "gameState.hpp"
#include "object.hpp"

namespace hatkid {

    void horizonMoveMap(GameState& state, float dx);
    void horizonMoveObject(GameState& state, TObject* obj);
    
    bool isCollision(TObject o1, TObject o2);
    
    void marioCollision(GameState& state);
    void vertMoveObject(GameState& state, TObject* obj);

}

