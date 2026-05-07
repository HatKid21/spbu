#pragma once

namespace hatkid{

    namespace objects{

        struct TObject {
            float x,y;
            float width, height;
            float verticalSpeed;
            bool isFly;
            char cType;
            float horizontalSpeed;
        };

        void setObjectPos(TObject *obj, float xPos, float yPos);
            
        void initObject(TObject *obj,float xPos, float yPos, float oWidth, float oHeight, char oType);

    }
}
