#include "object.hpp"

void hatkid::initObject(
        hatkid::TObject *obj,
        float xPos, float yPos,
        float oWidth, float oHeight, char oType){
    hatkid::setObjectPos(obj,xPos,yPos);
    obj->width = oWidth;
    obj->height = oHeight;
    obj->verticalSpeed = 0;
    obj->cType = oType;
    obj->horizontalSpeed = 0.5;
}

void hatkid::setObjectPos(hatkid::TObject *obj,
        float xPos, float yPos){
    obj->x = xPos;
    obj->y = yPos;
}
