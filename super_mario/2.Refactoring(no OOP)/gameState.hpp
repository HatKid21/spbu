#pragma once

#include "object.hpp"
#include "objectFunctions.hpp"

namespace hatkid {
    namespace game{ 

        using objects::TObject;

        struct GameState{
            TObject mario;

            TObject *brick;
            int brickAmount;

            TObject *moving;
            int movingAmount;

            char map[25][81];

            int level;
            int score;
            int maxLevel;
            
        };

    }
}
