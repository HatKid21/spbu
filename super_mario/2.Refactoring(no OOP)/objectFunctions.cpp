#pragma once

#include "object.hpp"
#include "objectFunctions.hpp"

namespace hatkid::objects{
    void setObjectPos(TObject *obj,
            float xPos, float yPos){
        obj->x = xPos;
        obj->y = yPos;
    }

    void initObject(
            TObject *obj,
            float xPos, float yPos,
            float oWidth, float oHeight, char oType){
        setObjectPos(obj,xPos,yPos);
        obj->width = oWidth;
        obj->height = oHeight;
        obj->verticalSpeed = 0;
        obj->cType = oType;
        obj->horizontalSpeed = 0.5;
    }
}
