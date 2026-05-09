#pragma once
#include "object.hpp"

namespace hatkid {
    const int MAP_HEIGHT = 25;
    const int MAP_WIDTH = 80;

    void deleteMoving(TObject* &moving, int &movingAmount, int i);
    TObject* getNewBrick(TObject* &bricks, int &bricksAmount);
    TObject* getNewMoving(TObject* &moving, int &movingAmount);
    
    bool isPosInMap(int x, int y);
}
