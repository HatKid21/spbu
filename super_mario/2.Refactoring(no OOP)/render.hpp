#pragma once

#include "gameState.hpp"
#include "object.hpp"

namespace hatkid{
    void clearMap(GameState& state);
    void showMap(GameState& state);
    void putObjectOnMap(GameState& state, TObject obj);
    void setCursor(int x, int y);
    void putScoreOnMap(GameState& state);
    void renderBricks(GameState& state);
    void renderMoving(GameState& state);
}
