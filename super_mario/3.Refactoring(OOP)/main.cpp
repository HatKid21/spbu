#include <cstdlib>
#include <ncurses.h>

#include "keyboard.hpp"
#include "level.hpp"
#include "physics.hpp"
#include "render.hpp"
#include "utils.hpp"

void inputHandler(
        hatkid::Keyboard& kbd,
        hatkid::TObject& mario, 
        hatkid::TObject* &brick, int brickAmount,
        hatkid::TObject* &moving,int movingAmount,
        bool &isLeftHold, bool &isRightHold, 
        int input);
void ncursesInit();

int main() {
    ncursesInit();

    hatkid::Keyboard kbd;
    
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
        kbd.update();

        hatkid::clearMap(map);
        int input = getch();
        inputHandler(kbd,mario, brick,brickAmount,moving,movingAmount, isLeftHold, isRightHold, input);

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

void inputHandler(
        hatkid::Keyboard& kbd,
        hatkid::TObject& mario, 
        hatkid::TObject* &brick, int brickAmount,
        hatkid::TObject* &moving,int movingAmount,
        bool &isLeftHold, bool &isRightHold, 
        int input) {
    if (kbd.isPressed(57) && !mario.isFly) { 
        mario.verticalSpeed = -1;
    }

    if (kbd.isPressed(16)) {
        endwin();
        return;
    }

    if (kbd.isPressed(105)) { 
        hatkid::horizonMoveMap(mario, brick, brickAmount,moving, movingAmount,1);
    } 
    if (kbd.isPressed(106)) { 
        hatkid::horizonMoveMap(mario,brick,brickAmount,moving,movingAmount,-1);
    }
}
