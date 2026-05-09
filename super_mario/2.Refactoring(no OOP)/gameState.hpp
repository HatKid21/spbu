#pragma once

#include "object.hpp"

namespace hatkid {

    const static int MAP_HEIGHT = 25;
    const static int MAP_WIDTH = 80;

    struct GameState{
        TObject mario;

        TObject *brick = nullptr;
        int brickAmount = 0;

        TObject *moving = nullptr;
        int movingAmount = 0;

        char map[MAP_HEIGHT][MAP_WIDTH+1];

        int level = 1;
        int score;
        int maxLevel;


        bool isLeftHold = false;
        bool isRightHold = false;
        
    };

    void deleteMoving(GameState& state, int i);
    TObject *getNewBrick(GameState& state);
    TObject *getNewMoving(GameState& state);
    bool isPosInMap(GameState& state,int x, int y);

}
