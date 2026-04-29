#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <math.h>
#include <time.h>

#define mapWidth 80
#define mapHeight 25

#define KEY_ESC 27

typedef struct SObject {
    float x,y;
    float width, height;
    float vertSpeed;
    bool isFly;
    char cType;
} TObject;

char map[mapHeight][mapWidth+1];
TObject mario;
TObject *brick = NULL;
int brickLength;
int level = 1;

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

void setObjectPos(TObject *obj,float xPos, float yPos){
    (*obj).x = xPos;
    (*obj).y = yPos;
}

void initObject(TObject *obj,float xPos, float yPos, float oWidth, float oHeight, char oType){
    setObjectPos(obj,xPos,yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
    (*obj).vertSpeed = 0;
    (*obj).cType = oType;
}

bool isCollision(TObject o1, TObject o2);
void createLevel(int lvl);

void vertMoveObject(TObject *obj){
    (*obj).isFly = true;
    (*obj).vertSpeed += 0.05;
    setObjectPos(obj,(*obj).x,(*obj).y + (*obj).vertSpeed);
    for (int i = 0 ; i < brickLength; i++){
        if (isCollision(*obj,brick[i])){
            (*obj).y -= (*obj).vertSpeed;
            (*obj).vertSpeed = 0;
            (*obj).isFly = false;
            if (brick[i].cType == '+'){
                level++;
                if (level > 2) level = 1;
                createLevel(level);
                napms(500);
            }
            break;
        }
    }
}

bool isPosInMap(int x, int y){
    return ( (x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeight) );
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

void setCur(int x, int y){
    move(y,x);
}

void horizonMoveMap(float dx){

    mario.x -= dx;
    for (int i = 0; i < brickLength; i++){
        if (isCollision(mario, brick[i])){
            mario.x += dx;
            return;
        }
    }
    mario.x += dx;

    for (int i = 0; i < brickLength; i++){
        brick[i].x += dx;
    }
}

bool isCollision(TObject o1, TObject o2){
    return ( (o1.x + o1.width) > o2.x ) && (o1.x < (o2.x + o2.width)) &&
        ( (o1.y + o1.height) > o2.y ) && (o1.y < (o2.y + o2.height));
}

bool isRightHold = false;
bool isLeftHold = false;

void createLevel(int lvl){

    isLeftHold = false;
    isRightHold = false;

    initObject(&mario,39,10,3,3,'@');

    if (lvl == 1){

        brickLength = 6;
        brick = (TObject*)realloc(brick,sizeof(TObject) * brickLength);
        initObject(brick+0,20,21,40,5,'#');
        initObject(brick+1,60,15,10,10,'#');
        initObject(brick+2,80,20,20,5,'#');
        initObject(brick+3,120,15,10,10,'#');
        initObject(brick+4,150,20,40,5,'#');
        initObject(brick+5,210,15,10,10,'+');
    }
    if (lvl == 2){

        brickLength = 4;
        brick = (TObject*)realloc(brick,sizeof(TObject) * brickLength);
        initObject(brick+0,20,21,40,5,'#');
        initObject(brick+1,80,20,15,5,'#');
        initObject(brick+2,120,15,15,10,'#');
        initObject(brick+3,160,10,15,15,'+');
    }
}

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
        int ch;
        switch (ch){
            case ' ':
                if (!mario.isFly){
                mario.vertSpeed = -1;
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
        ch = getch();

        if (isRightHold) horizonMoveMap(-1);
        if (isLeftHold) horizonMoveMap(1);

        if (mario.y > mapHeight) createLevel(level);

        vertMoveObject(&mario);
        for (int i = 0; i < brickLength;i++){
            putObjectOnMap(brick[i]);
        }
        putObjectOnMap(mario);

        setCur(0,0);
        showMap();

        napms(33);

    }

    endwin();
}
