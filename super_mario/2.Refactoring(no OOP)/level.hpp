#pragma once

#include "object.hpp"

namespace hatkid{
    
    void createLevel(TObject& mario, TObject* &bricks, int &brickAmount, 
                         TObject* &moving, int &movingAmount, int &score, 
                         int &level, int &maxLevel, bool &isLeftHold, bool &isRightHold);
}
