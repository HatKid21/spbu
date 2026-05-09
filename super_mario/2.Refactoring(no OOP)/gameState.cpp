#include "gameState.hpp"
#include <cstdlib>

void hatkid::deleteMoving(TObject* &moving, int &movingAmount, int i) {
    movingAmount--;
    moving[i] = moving[movingAmount];
    moving = (TObject*)realloc(moving, sizeof(TObject) * movingAmount);
}

hatkid::TObject* hatkid::getNewBrick(TObject* &bricks, int &bricksAmount) {
    bricksAmount++;
    bricks = (TObject*)realloc(bricks, sizeof(TObject) * bricksAmount);
    return bricks + bricksAmount - 1;
}

hatkid::TObject* hatkid::getNewMoving(TObject* &moving, int &movingAmount) {
    movingAmount++;
    moving = (TObject*)realloc(moving, sizeof(TObject) * movingAmount);
    return moving + movingAmount - 1;
}

bool hatkid::isPosInMap(int x, int y, int MAP_WIDTH, int MAP_HEIGHT) {
    return (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT);
}
