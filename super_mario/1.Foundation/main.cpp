#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <math.h>

#define mapWidth 80
#define mapHeight 25

#define KEY_ESC 27

typedef struct SObject {
    float x,y;
    float width, height;
} TObject;

char map[mapHeight][mapWidth+1];
TObject mario;

void clearMap(){
    for (int i = 0; i < mapWidth; i++){
        map[0][i] = '.';
    }
    map[0][mapWidth] = '\0';
    for (int i = 1; i < mapHeight;i++){
        sprintf(map[i],map[0]);
    }
}

void showMap(){

    map[mapHeight - 1][mapWidth - 1] = '\0';
    for (int i = 0; i < mapHeight; i++){
        printw("%s\n",map[i]);
    }
    refresh();

}

void setObjectPos(TObject *obj,float xPos, float yPos){
    (*obj).x = xPos;
    (*obj).y = yPos;
}

void initObject(TObject *obj,float xPos, float yPos, float oWidth, float oHeight){
    setObjectPos(obj,xPos,yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
}

void putObjectOnMap(TObject obj){
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int) round(obj.width);
    int iHeight = (int)round(obj.height);
    for (int i = ix; i < (ix + iWidth);i++){
        for (int j = iy; j < (iy + iHeight);j++){
            map[j][i] = '@';
        }
    }
}

void setCur(int x, int y){
    move(y,x);
}

int main(){
    //Инициализация ncurses для фиксирования нажатий на Линуксе
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);

    initObject(&mario,39,10,3,3);
    do{
        clearMap();
        putObjectOnMap(mario);

        setCur(0,0);
        showMap();
    } while (getch() != KEY_ESC);

    endwin();
}
