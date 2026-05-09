#include <cstdlib>
#include <ncurses.h>

#include "gameState.hpp"
#include "level.hpp"
#include "physics.hpp"
#include "render.hpp"

void inputHandler(hatkid::GameState& state, int input);
void ncursesInit();

int main(){

    ncursesInit();

    hatkid::GameState state;
    hatkid::createLevel(state,state.level);

    int input = 0;
    
    while(true){
        hatkid::clearMap(state);
        
        input = getch();
        
        inputHandler(state, input);

        if (state.isRightHold){ 
            hatkid::horizonMoveMap(state,-1);
        }
        
        if (state.isLeftHold) {
            hatkid::horizonMoveMap(state,1);
        }
        
        if (state.mario.y > hatkid::MAP_HEIGHT) {
            napms(500);
            hatkid::createLevel(state,state.level);
        }

        hatkid::vertMoveObject(state,&state.mario);
        hatkid::marioCollision(state);

        hatkid::renderBricks(state);
        hatkid::renderMoving(state);

        hatkid::putObjectOnMap(state,state.mario);

        hatkid::putScoreOnMap(state);

        hatkid::setCursor(0,0);
        hatkid::showMap(state);

        napms(16);

    }

    endwin();
}

void inputHandler(hatkid::GameState& state, int input){
    switch (input){
    case ' ':
        if (!state.mario.isFly){
            state.mario.verticalSpeed = -1;
        }
        break;
    case 'q':
        endwin();
        exit(0);
    case KEY_LEFT:
        state.isLeftHold = !state.isLeftHold;
        state.isRightHold = false;
        break;
    case KEY_RIGHT:
        state.isRightHold = !state.isRightHold;
        state.isLeftHold = false;
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

