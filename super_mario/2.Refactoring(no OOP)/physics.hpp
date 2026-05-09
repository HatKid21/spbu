#pragma once

#include "object.hpp"

namespace hatkid {

    void horizonMoveMap(
            TObject& mario, 
            TObject* brick, int brickAmount, 
            TObject* moving, int movingAmount, 
            float dx);
    void horizonMoveObject(
            TObject* brick, int brickAmount, 
            TObject* obj);
    
    bool isCollision(TObject o1, TObject o2);
    
    void marioCollision(
            TObject& mario, 
            TObject* &moving, int &movingAmount, 
            int &score, 
            int &level, int maxLevel, 
            TObject* &brick, int &brickAmount, 
            bool &isLeftHold, bool &isRightHold);
    void vertMoveObject(
            TObject& mario, 
            TObject* &brick, int &brickAmount, 
            TObject* obj, 
            int &level, int maxLevel, 
            TObject* &moving, int &movingAmount, 
            int &score, 
            bool &isLeftHold, bool &isRightHold);

}
