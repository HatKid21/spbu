#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ncurses.h>

#include "objectTypes.hpp"
#include "renderer.hpp"

using hatkid::Renderer;

Renderer::Renderer(int height, int width){
    this->height = height;
    this->width = width;
    map = new char*[height];
    for (int y = 0; y < height; y++){
        map[y] = new char[width+1];
        for (int x = 0; x < width; x++){
            map[y][x] = hatkid::ObjectType::AIR;
        }
        map[y][width] = '\0';
    }
}

Renderer::~Renderer(){
    for (int i = 0; i < height;i++){
        delete[] map[i];
    }
    delete[] map;
}

void Renderer::drawScore(int score){
    char c[30];
    std::sprintf(c, "Score %d", score);
    int len = std::strlen(c);
    for (int i = 0; i < len; i++) {
        map[1][i + 5] = c[i];
    }
}

void Renderer::drawObject(hatkid::GameObject& obj){
    int ix = (int)std::round(obj.x());
    int iy = (int)std::round(obj.y());
    for (int i = ix; i < (ix + (int)obj.getWidth()); i++) {
        for (int j = iy; j < (iy + (int)obj.getHeight()); j++) {
            if (isPosInMap(i, j)) {
                map[j][i] = obj.getSymbol();
            }
        }
    }
}


void Renderer::clearMap() {
    for (int i = 0; i < width; i++) {
        map[0][i] = hatkid::ObjectType::AIR;
    }
    map[0][width] = '\0';
    for (int i = 1; i < height; i++) {
        std::strcpy(map[i], map[0]);
    }
}

void Renderer::showMap(){
    for (int i = 0; i < height; i++) {
        printw("%s\n", map[i]);
    }
    refresh();
    move(0,0);
}

bool Renderer::isPosInMap(int x, int y){
    return (x >= 0 && x < width && y >= 0 && y < height);
}
