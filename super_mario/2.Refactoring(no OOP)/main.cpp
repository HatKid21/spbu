#include <ncurses.h>

#include "gameState.hpp"
#include "level.hpp"
#include "render.hpp"
#include "physics.hpp"

int main(){

    //Инициализация ncurses для фиксирования нажатий на Линуксе
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    nodelay(stdscr,TRUE);

    hatkid::game::GameState state;
    hatkid::level::createLevel(state,state.level);

    int input = 0;
    
    while(true){
        hatkid::render::clearMap(state);
        
        switch (input){
            case ' ':
                if (!state.mario.isFly){
                    state.mario.verticalSpeed = -1;
                }
                break;
            case 'q':
                endwin();
                return 0;
            case KEY_LEFT:
                state.isLeftHold = !state.isLeftHold;
                state.isRightHold = false;
                break;
            case KEY_RIGHT:
                state.isRightHold = !state.isRightHold;
                state.isLeftHold = false;
                break;
        }
        input = getch();

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

        for (int i = 0; i < state.brickAmount;i++){
            hatkid::render::putObjectOnMap(state,state.brick[i]);
        }
        for (int i = 0; i < state.movingAmount; i++){
            hatkid::physics::vertMoveObject(state, state.moving + i);
            hatkid::physics::horizonMoveObject(state,state.moving + i);
            if (state.moving[i].y > hatkid::game::MAP_HEIGHT){
                hatkid::game::deleteMoving(state,i);
                i--;
                continue;
            }
            hatkid::render::putObjectOnMap(state,state.moving[i]);
        }

        hatkid::render::putObjectOnMap(state,state.mario);

        hatkid::render::putScoreOnMap(state);

        hatkid::render::setCursor(0,0);
        hatkid::render::showMap(state);

        napms(16);

    }

    endwin();
}
