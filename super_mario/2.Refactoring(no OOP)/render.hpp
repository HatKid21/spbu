#pragma once

#include "object.hpp"

namespace hatkid{
    namespace render{

        using objects::TObject;
        
        void clearMap();
        void showMap();
        void putObjectOnMap(TObject obj);
        void setCursor(int x, int y);
        void putScoreOnMap();

    }
}
