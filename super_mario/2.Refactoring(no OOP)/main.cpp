#include <cstdlib>
#include <ncurses.h>

#include "level.hpp"
#include "physics.hpp"
#include "render.hpp"
#include "utils.hpp"

void inputHandler(hatkid::TObject& mario, bool &isLeftHold, bool &isRightHold, int input);
void ncursesInit();

int main() {
    ncursesInit();
    
    const int MAP_HEIGHT = 25;
    const int MAP_WIDTH = 80;

    hatkid::TObject mario;
    hatkid::TObject *brick = nullptr;
    int brickAmount = 0;
    hatkid::TObject *moving = nullptr;
    int movingAmount = 0;
    char map[MAP_HEIGHT][MAP_WIDTH+1]; 
    int level = 1;
    int score = 0;
    int maxLevel = 3;
    bool isLeftHold = false;
    bool isRightHold = false;

    hatkid::createLevel(mario, brick, brickAmount, moving, movingAmount, score, level, maxLevel, isLeftHold, isRightHold);

    while(true) {
        hatkid::clearMap(map, MAP_WIDTH, MAP_HEIGHT);
        
        int input = getch();
        inputHandler(mario, isLeftHold, isRightHold, input);

        if (isRightHold) hatkid::horizonMoveMap(mario, brick, brickAmount, moving, movingAmount, -1);
        if (isLeftHold)  hatkid::horizonMoveMap(mario, brick, brickAmount, moving, movingAmount, 1);
        
        if (mario.y > MAP_HEIGHT) {
            napms(500);
            hatkid::createLevel(mario, brick, brickAmount, moving, movingAmount, score, level, maxLevel, isLeftHold, isRightHold);
        }

        hatkid::vertMoveObject(mario, brick, brickAmount, &mario, level, maxLevel, moving, movingAmount, score, isLeftHold, isRightHold);
        hatkid::marioCollision(mario, moving, movingAmount, score, level, maxLevel, brick, brickAmount, isLeftHold, isRightHold);

        hatkid::renderBricks(map, brick, brickAmount, MAP_WIDTH, MAP_HEIGHT);
        hatkid::renderMoving(map, moving, movingAmount, brick, brickAmount, MAP_WIDTH, MAP_HEIGHT, mario, level, maxLevel, score, isLeftHold, isRightHold); 
        hatkid::putObjectOnMap(map, mario, MAP_WIDTH, MAP_HEIGHT);
        hatkid::putScoreOnMap(map, score);

        hatkid::setCursor(0, 0);
        hatkid::showMap(map, MAP_WIDTH, MAP_HEIGHT);
        napms(16);
    }
    
    endwin();
    return 0;
}

void inputHandler(hatkid::TObject& mario, bool &isLeftHold, bool &isRightHold, int input){
    switch (input){
    case ' ':
        if (!mario.isFly){
            mario.verticalSpeed = -1;
        }
        break;
    case 'q':
        endwin();
        exit(0);
    case KEY_LEFT:
        isLeftHold = !isLeftHold;
        isRightHold = false;
        break;
    case KEY_RIGHT:
        isRightHold = !isRightHold;
        isLeftHold = false;
        break;
    }
}

void ncursesInit(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    nodelay(stdscr,TRUE);
}
