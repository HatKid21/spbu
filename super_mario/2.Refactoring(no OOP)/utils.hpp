#pragma once

#include "object.hpp"

namespace hatkid {
    void deleteMoving(TObject* &moving, int &movingAmount, int i);
    TObject* getNewBrick(TObject* &bricks, int &bricksAmount);
    TObject* getNewMoving(TObject* &moving, int &movingAmount);
    bool isPosInMap(int x, int y, int MAP_WIDTH, int MAP_HEIGHT);
}
