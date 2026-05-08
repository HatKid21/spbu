#include <cstdlib>
#include <ncurses.h>

#include "gameState.hpp"
#include "level.hpp"
#include "physics.hpp"
#include "render.hpp"

void ncursesInit();
void inputHandler(hatkid::game::GameState& state, int input);

int main(){

    ncursesInit();

    hatkid::game::GameState state;
    hatkid::level::createLevel(state,state.level);

    int input = 0;
    
    while(true){
        hatkid::render::clearMap(state);
        
        input = getch();
        
        inputHandler(state, input);

        if (state.isRightHold){ 
            hatkid::physics::horizonMoveMap(state,-1);
        }
        
        if (state.isLeftHold) {
            hatkid::physics::horizonMoveMap(state,1);
        }
        
        if (state.mario.y > hatkid::game::MAP_HEIGHT) {
            napms(500);
            hatkid::level::createLevel(state,state.level);
        }

        hatkid::physics::vertMoveObject(state,&state.mario);
        hatkid::physics::marioCollision(state);

        hatkid::render::renderBricks(state);
        hatkid::render::renderMoving(state);

        hatkid::render::putObjectOnMap(state,state.mario);

        hatkid::render::putScoreOnMap(state);

        hatkid::render::setCursor(0,0);
        hatkid::render::showMap(state);

        napms(16);

    }

    endwin();
}

void ncursesInit(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    nodelay(stdscr,TRUE);
}

void inputHandler(hatkid::game::GameState& state, int input){
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
