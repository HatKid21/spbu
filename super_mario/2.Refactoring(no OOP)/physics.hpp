#pragma once

#include "objects.hpp"

namespace hatkid{
    namespace physics{

        using objects::TObject;
        
        bool isCollision(TObject o1, TObject o2);
        void marioCollision();
        void horizonMoveObject(TObject *obj);
        void horizonMoveMap(float dx);
        void vertMoveObject(TObject *obj);
    }
}
