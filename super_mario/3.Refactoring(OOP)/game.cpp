#include <ncurses.h>

#include "game.hpp"
#include "keyboard.hpp"
#include "player.hpp"
#include "level.hpp"
#include "brick.hpp"
#include "renderer.hpp"

using hatkid::Game;

Game::Game() : renderer(25,80), player(),level(1),keyboard(),isRunning(false){
    player.setPos(39,10);
}

void Game::run(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    isRunning = true;
    while (isRunning){
        renderer.clearMap();
        inputHandler();
        
        Brick* bricks = level.getBricks();
        for (int i = 0; i < level.getBrickAmount(); i++){
            renderer.drawObject(bricks[i]);
        }

        Enemy* enemies = level.getEnemies();
        for (int i = 0; i < level.getEnemyAmount(); i++){
            renderer.drawObject(enemies[i]);
        }

        renderer.drawObject(player);
        renderer.drawScore(level.getScore());

        renderer.showMap();
        napms(16);
    }
    endwin();
}

void Game::stop(){
    isRunning = false;
}

void Game::inputHandler(){
    keyboard.update();
    if (keyboard.isPressed(57)) { 
        player.jump();
    }

    if (keyboard.isPressed(16)) {
        endwin();
        return;
    }

    if (keyboard.isPressed(105)) { 
        //TODO
    } 
    if (keyboard.isPressed(106)) { 
        //TODO
    }
}
