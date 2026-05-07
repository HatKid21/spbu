#pragma once

#include "gameState.hpp"
#include "object.hpp"

namespace hatkid{
    namespace render{

        void clearMap(hatkid::game::GameState& state);
        void showMap(hatkid::game::GameState& state);
        void putObjectOnMap(hatkid::game::GameState& state,hatkid::objects::TObject obj);
        void setCursor(int x, int y);
        void putScoreOnMap(hatkid::game::GameState& state);

    }
}
