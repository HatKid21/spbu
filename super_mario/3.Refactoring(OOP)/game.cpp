#include <ncurses.h>

#include "brick.hpp"
#include "game.hpp"
#include "keyboard.hpp"
#include "level.hpp"
#include "physics.hpp"
#include "player.hpp"
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

        player.update(level, renderer.getMapHeight());

        Enemy* enemies = level.getEnemies();
        for (int i = 0; i < level.getEnemyAmount(); i++){
            enemies[i].update(level, renderer.getMapHeight());
        }
        Coin* coins = level.getCoins();
        for (int i = 0; i < level.getCoinAmount();i++){
            coins[i].update(level, renderer.getMapHeight());
        }

        player.handleInteractions(level);

        if (player.isDead()){
            level.reset();
            player.setPos(level.getSpawnX(),level.getSpawnY());
            player.setHorizontalSpeed(0);
            player.setVerticalSpeed(0);
            player.setOnGround(false);
            player.setDead(false);
            renderer.resetOffset();
            napms(1000);
            continue;
        }

        if (level.isGoalReached()){
            level.nextLevel();
            player.setPos(level.getSpawnX(),level.getSpawnY());
            player.setHorizontalSpeed(0);
            player.setVerticalSpeed(0);
            player.setOnGround(false);
            renderer.resetOffset();
            napms(1000);
            continue;
        }

        renderer.setCameraX((int)player.x());
        
        Brick* bricks = level.getBricks();
        for (int i = 0; i < level.getBrickAmount(); i++){
            renderer.drawObject(bricks[i]);
        }

        for (int i = 0; i < level.getEnemyAmount(); i++){
            if (!enemies[i].isDead()){
                renderer.drawObject(enemies[i]);
            }
        }

        for (int i = 0; i < level.getCoinAmount(); i++){
            if (!coins[i].isDead()){
                renderer.drawObject(coins[i]);
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
    }else if (keyboard.isPressed(106)) { 
        player.setHorizontalSpeed(1);
    }else{
        player.setHorizontalSpeed(0);
    }
}
