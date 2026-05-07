#pragma once

#include "gameState.hpp"
#include "object.hpp"

namespace hatkid {
    namespace physics {

        bool isCollision(hatkid::objects::TObject o1, hatkid::objects::TObject o2);

        void marioCollision(hatkid::game::GameState& state);
        void horizonMoveObject(hatkid::game::GameState& state, hatkid::objects::TObject* obj);
        void horizonMoveMap(hatkid::game::GameState& state, float dx);
        void vertMoveObject(hatkid::game::GameState& state, hatkid::objects::TObject* obj);

    }
}

