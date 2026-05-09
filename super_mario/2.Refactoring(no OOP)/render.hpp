#pragma once
#include "object.hpp"
#include "utils.hpp"

namespace hatkid {
    void clearMap(char map[MAP_HEIGHT][MAP_WIDTH + 1]);
    void putObjectOnMap(char map[MAP_HEIGHT][MAP_WIDTH + 1], TObject obj);
    void putScoreOnMap(char map[MAP_HEIGHT][MAP_WIDTH + 1], int score);
    void renderBricks(char map[MAP_HEIGHT][MAP_WIDTH + 1], TObject* brick, int brickAmount);
    void renderMoving(char map[MAP_HEIGHT][MAP_WIDTH + 1], TObject* &moving, int &movingAmount, TObject* brick, int brickAmount, TObject& mario, int &level, int maxLevel, int &score, bool &isLeftHold, bool &isRightHold);
    void setCursor(int x, int y);
    void showMap(char map[MAP_HEIGHT][MAP_WIDTH + 1]);
}
