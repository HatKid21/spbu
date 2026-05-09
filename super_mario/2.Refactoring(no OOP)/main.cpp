#include <cstdlib>
#include <ncurses.h>

#include "level.hpp"
#include "physics.hpp"
#include "render.hpp"
#include "utils.hpp"

void inputHandler(
        hatkid::TObject& mario,
        bool &isLeftHold, bool &isRightHold,
        int input);
void ncursesInit();

int main() {
    ncursesInit();
    
    hatkid::TObject mario;
    hatkid::TObject *brick = nullptr;
    int brickAmount = 0;
    hatkid::TObject *moving = nullptr;
    int movingAmount = 0;
    
    char map[hatkid::MAP_HEIGHT][hatkid::MAP_WIDTH + 1]; 
    
    int level = 1, score = 0, maxLevel = 3;
    bool isLeftHold = false, isRightHold = false;

    hatkid::createLevel(mario, 
            brick, brickAmount, 
            moving, movingAmount, 
            score, level, maxLevel, 
            isLeftHold, isRightHold);

    while(true) {
        hatkid::clearMap(map);
        int input = getch();
        inputHandler(mario, isLeftHold, isRightHold, input);

        if (isRightHold) hatkid::horizonMoveMap(mario, 
                brick, brickAmount, 
                moving, movingAmount, 
                -1);
        if (isLeftHold)  hatkid::horizonMoveMap(mario, 
                brick, brickAmount, 
                moving, movingAmount, 
                1);
        
        if (mario.y > hatkid::MAP_HEIGHT) {
            napms(500);
            hatkid::createLevel(mario, 
                    brick, brickAmount,
                    moving, movingAmount,
                    score, level, maxLevel,
                    isLeftHold, isRightHold);
        }

        hatkid::vertMoveObject(mario, 
                brick, brickAmount, 
                &mario, 
                level, maxLevel, 
                moving, movingAmount, 
                score, 
                isLeftHold, isRightHold);
        hatkid::marioCollision(mario, 
                moving, movingAmount, 
                score, level, maxLevel, 
                brick, brickAmount, 
                isLeftHold, isRightHold);

        hatkid::renderBricks(map, brick, brickAmount);
        hatkid::renderMoving(map, 
                moving, movingAmount, 
                brick, brickAmount, 
                mario, 
                level, maxLevel, score, 
                isLeftHold, isRightHold); 
        hatkid::putObjectOnMap(map, mario);
        hatkid::putScoreOnMap(map, score);

        hatkid::setCursor(0, 0);
        hatkid::showMap(map);
        napms(16);
    }
    return 0;
}

void ncursesInit() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

void inputHandler(hatkid::TObject& mario, bool &isLeftHold, bool &isRightHold, int input) {
    switch (input) {
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
