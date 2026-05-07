#include <ncurses.h>

#include "render.hpp"
#include "object.hpp"

void clearMap(){
    for (int i = 0; i < mapWidth; i++){
        map[0][i] = ' ';
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

void putObjectOnMap(TObject obj){
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int) round(obj.width);
    int iHeight = (int)round(obj.height);
    for (int i = ix; i < (ix + iWidth);i++){
        for (int j = iy; j < (iy + iHeight);j++){
            if (isPosInMap(i,j)){
                map[j][i] = obj.cType;
            }
        }
    }
}

void setCursor(int x, int y){
    move(y,x);
}

void putScoreOnMap(){
    char c[30];
    sprintf(c,"Score %d",score);
    int len = strlen(c);
    for (int i = 0; i < len;i++){
        map[1][i+5] = c[i];
    }
}
