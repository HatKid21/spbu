#pragma once

#include "gameState.hpp"
#include "object.hpp"

namespace hatkid {

    bool isCollision(TObject o1, TObject o2);

    void marioCollision(GameState& state);
    void horizonMoveObject(GameState& state, TObject* obj);
    void horizonMoveMap(GameState& state, float dx);
    void vertMoveObject(GameState& state, TObject* obj);

}

