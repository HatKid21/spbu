#include <stdio.h>
#include <stdlib.h>

#define mapWidth 80
#define mapHeight 25

char map[mapHeight][mapWidth+1];

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
        printf("%s\n",map[i]);
    }

}

int main(){

    clearMap();
    showMap();

}
