#include <cstring>
#include <cstdio>
#include <ncurses.h>
#include <cmath>
#include "render.hpp"
#include "objectTypes.hpp"
#include "physics.hpp"
#include "utils.hpp"

void hatkid::clearMap(char map[MAP_HEIGHT][MAP_WIDTH + 1]) {
    for (int i = 0; i < MAP_WIDTH; i++) {
        map[0][i] = hatkid::ObjectType::AIR;
    }
    map[0][MAP_WIDTH] = '\0';
    for (int i = 1; i < MAP_HEIGHT; i++) {
        std::strcpy(map[i], map[0]);
    }
}

void hatkid::putObjectOnMap(char map[MAP_HEIGHT][MAP_WIDTH + 1], TObject obj) {
    int ix = (int)std::round(obj.x);
    int iy = (int)std::round(obj.y);
    for (int i = ix; i < (ix + (int)obj.width); i++) {
        for (int j = iy; j < (iy + (int)obj.height); j++) {
            if (isPosInMap(i, j)) {
                map[j][i] = obj.cType;
            }
        }
    }
}

void hatkid::putScoreOnMap(char map[MAP_HEIGHT][MAP_WIDTH + 1], int score) {
    char c[30];
    std::sprintf(c, "Score %d", score);
    int len = std::strlen(c);
    for (int i = 0; i < len; i++) {
        map[1][i + 5] = c[i];
    }
}

void hatkid::renderBricks(char map[MAP_HEIGHT][MAP_WIDTH + 1], TObject* brick, int brickAmount) {
    for (int i = 0; i < brickAmount; i++) {
        putObjectOnMap(map, brick[i]);
    }
}

void hatkid::renderMoving(
        char map[MAP_HEIGHT][MAP_WIDTH + 1], 
        TObject* &moving, int &movingAmount, 
        TObject* brick, int brickAmount, 
        TObject& mario, 
        int &level, int maxLevel, 
        int &score, 
        bool &isLeftHold, bool &isRightHold
        ) {
    for (int i = 0; i < movingAmount; i++) {
        vertMoveObject(mario, brick, brickAmount, moving + i, level, maxLevel, moving, movingAmount, score, isLeftHold, isRightHold);
        horizonMoveObject(brick, brickAmount, moving + i);
        if (moving[i].y > MAP_HEIGHT) {
            deleteMoving(moving, movingAmount, i);
            i--;
            continue;
        }
        putObjectOnMap(map, moving[i]);
    }
}

void hatkid::setCursor(int x, int y) {
    move(y, x);
}

void hatkid::showMap(char map[MAP_HEIGHT][MAP_WIDTH + 1]) {
    map[MAP_HEIGHT - 1][MAP_WIDTH - 1] = '\0';
    for (int i = 0; i < MAP_HEIGHT; i++) {
        printw("%s\n", map[i]);
    }
    refresh();
}
