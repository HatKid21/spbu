#include <ncurses.h>

#include "game.hpp"
#include "keyboard.hpp"
#include "player.hpp"
#include "level.hpp"
#include "brick.hpp"
#include "renderer.hpp"
#include "physics.hpp"

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

        hatkid::Physics::playerMoveHorizontal(player, level);
        hatkid::Physics::playerMoveVertical(player, level);
        hatkid::Physics::checkPlayerEnemyCollision(player, level);

        Enemy* enemies = level.getEnemies();
        for (int i = 0; i < level.getEnemyAmount(); i++){
            hatkid::Physics::moveEnemy(enemies[i],level);
        }

        hatkid::Physics::checkPlayerEnemyCollision(player, level);

        renderer.setCameraX((int)player.x());
        
        Brick* bricks = level.getBricks();
        for (int i = 0; i < level.getBrickAmount(); i++){
            renderer.drawObject(bricks[i]);
        }

        for (int i = 0; i < level.getEnemyAmount(); i++){
            if (enemies[i].isAlive()){
                renderer.drawObject(enemies[i]);
            }
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
        isRunning = false;
        return;
    }

    if (keyboard.isPressed(105)) { 
        player.setHorizontalSpeed(-1);
        //hatkid::Physics::playerMoveHorizontal(player,level);
        //player.setX(player.x() - 1);
    }else if (keyboard.isPressed(106)) { 
        player.setHorizontalSpeed(1);
        //hatkid::Physics::playerMoveHorizontal(player,level);
        //player.setX(player.x() + 1);
    }else{
        player.setHorizontalSpeed(0);
    }
}
