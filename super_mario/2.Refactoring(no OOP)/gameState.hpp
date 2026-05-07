#pragma once

#include "object.hpp"
#include "objectFunctions.hpp"

namespace hatkid {
    namespace game{ 

        static int MAP_HEIGHT = 25;
        static int MAP_WIDTH = 80;

        using objects::TObject;

        struct GameState{
            TObject mario;

            TObject *brick;
            int brickAmount;

            TObject *moving;
            int movingAmount

            char map[MAP_HEIGHT][MAP_WIDTH+1];

            int level;
            int score;
            int maxLevel;
            
        };


        TObject *getNewMoving(GameState& state);
        TObject *getNewBrick(GameState& state);
        void deleteMoving(GameState& state, int i);
        bool isPosInMap(GameState& state,int x, int y){

    }
}
