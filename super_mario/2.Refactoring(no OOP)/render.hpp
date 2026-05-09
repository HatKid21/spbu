#pragma once

#include "object.hpp"

namespace hatkid{
    void clearMap(char map[25][81], int MAP_WIDTH, int MAP_HEIGHT);
    void putObjectOnMap(char map[25][81], TObject obj, int MAP_WIDTH, int MAP_HEIGHT);
    void putScoreOnMap(char map[25][81], int score);
    void renderBricks(char map[25][81], TObject* brick, int brickAmount, int MAP_WIDTH, int MAP_HEIGHT);
    void renderMoving(char map[25][81], TObject* &moving, int &movingAmount, TObject* brick, int brickAmount, int MAP_WIDTH, int MAP_HEIGHT, TObject& mario, int &level, int maxLevel, int &score, bool &isLeftHold, bool &isRightHold);
    void setCursor(int x, int y);
    void showMap(char map[25][81], int MAP_WIDTH, int MAP_HEIGHT);
}
