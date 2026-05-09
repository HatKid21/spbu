#include "utils.hpp"

void hatkid::deleteMoving(TObject* &moving, int &movingAmount, int i) {
    movingAmount--;
    moving[i] = moving[movingAmount];

    if (movingAmount == 0) {
        delete[] moving;
        moving = nullptr;
    } else {
        TObject* newArray = new TObject[movingAmount];
        for (int j = 0; j < movingAmount; j++) {
            newArray[j] = moving[j];
        }
        delete[] moving;
        moving = newArray;
    }
}

hatkid::TObject* hatkid::getNewBrick(TObject* &bricks, int &bricksAmount) {
    int oldAmount = bricksAmount;
    bricksAmount++;

    TObject* newBricks = new TObject[bricksAmount];

    if (bricks != nullptr) {
        for (int i = 0; i < oldAmount; i++) {
            newBricks[i] = bricks[i];
        }
        delete[] bricks;
    }

    bricks = newBricks;

    return &bricks[bricksAmount - 1];
}

hatkid::TObject* hatkid::getNewMoving(TObject* &moving, int &movingAmount) {
    int oldAmount = movingAmount;
    movingAmount++;

    TObject* newMoving = new TObject[movingAmount];

    if (moving != nullptr) {
        for (int i = 0; i < oldAmount; i++) {
            newMoving[i] = moving[i];
        }
        delete[] moving;
    }

    moving = newMoving;
    return &moving[movingAmount - 1];
}

bool hatkid::isPosInMap(int x, int y, int MAP_WIDTH, int MAP_HEIGHT) {
    return (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT);
}
