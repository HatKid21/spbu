#include <ncurses.h>

int main(){

    //Инициализация ncurses для фиксирования нажатий на Линуксе
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    nodelay(stdscr,TRUE);

    createLevel(level);

    while(true){
        clearMap();
        int input;
        switch (input){
            case ' ':
                if (!mario.isFly){
                mario.verticalSpeed = -1;
                }
                break;
            case 'q':
                endwin();
                return 0;
            case KEY_LEFT:
                isLeftHold = !isLeftHold;
                isRightHold = false;
                break;
            case KEY_RIGHT:
                isRightHold = !isRightHold;
                isLeftHold = false;
                break;
        }
        input = getch();

        if (isRightHold) horizonMoveMap(-1);
        if (isLeftHold) horizonMoveMap(1);

        if (mario.y > mapHeight) {
            napms(500);
            createLevel(level);
        }
        vertMoveObject(&mario);
        marioCollision();

        for (int i = 0; i < brickLength;i++){
            putObjectOnMap(brick[i]);
        }
        for (int i = 0; i < movingLength;i++){
            vertMoveObject(moving + i);
            horizonMoveObject(moving + i);
            if (moving[i].y > mapHeight){
                deleteMoving(i);
                i--;
                continue;
            }
            putObjectOnMap(moving[i]);
        }

        putObjectOnMap(mario);

        putScoreOnMap();

        setCursor(0,0);
        showMap();

        napms(16);

    }

    endwin();
}
