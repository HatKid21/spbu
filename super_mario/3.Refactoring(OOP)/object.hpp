#pragma once

namespace hatkid{

    struct TObject {
        float x,y;
        float width, height;
        float verticalSpeed;
        float horizontalSpeed;
        bool isFly;
        char cType;
    };

    void initObject(TObject *obj,float xPos, float yPos, float oWidth, float oHeight, char oType);
    
    void setObjectPos(TObject *obj, float xPos, float yPos);

}
