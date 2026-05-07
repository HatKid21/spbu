#include "object.hpp"

void hatkid::objects::setObjectPos(hatkid::objects::TObject *obj,
        float xPos, float yPos){
    obj->x = xPos;
    obj->y = yPos;
}

void hatkid::objects::initObject(
        hatkid::objects::TObject *obj,
        float xPos, float yPos,
        float oWidth, float oHeight, char oType){
    hatkid::objects::setObjectPos(obj,xPos,yPos);
    obj->width = oWidth;
    obj->height = oHeight;
    obj->verticalSpeed = 0;
    obj->cType = oType;
    obj->horizontalSpeed = 0.5;
}
