#include <ncurses.h>

#include "gameState.hpp"
#include "level.hpp"
#include "object.hpp"
#include "objectTypes.hpp"
#include "physics.hpp"

bool hatkid::isCollision(hatkid::TObject o1, hatkid::TObject o2) {
    return (o1.x + o1.width > o2.x) && (o1.x < o2.x + o2.width) &&
           (o1.y + o1.height > o2.y) && (o1.y < o2.y + o2.height);
}

void hatkid::marioCollision(hatkid::GameState& state) {
    for (int i = 0; i < state.movingAmount; i++) {
        if (isCollision(state.mario, state.moving[i])) {
            if (state.moving[i].cType == hatkid::TYPE_ENEMY) {
                if (state.mario.isFly && 
                    state.mario.verticalSpeed > 0 && 
                    state.mario.y + state.mario.height < state.moving[i].y + state.moving[i].height * 0.5f) {
                    state.score += 50;
                    deleteMoving(state, i);
                    i--;
                    continue;
                } else {
                    napms(500);
                    hatkid::createLevel(state,state.level);
                }
            }

            if (state.moving[i].cType == hatkid::TYPE_MONEY) {
                state.score += 100;
                deleteMoving(state, i);
                i--;
            }
        }
    }
}

void hatkid::horizonMoveObject(hatkid::GameState& state, hatkid::TObject* obj) {
    obj->x += obj->horizontalSpeed;

    for (int i = 0; i < state.brickAmount; i++) {
        if (isCollision(*obj, state.brick[i])) {
            obj->x -= obj->horizontalSpeed;
            obj->horizontalSpeed = -obj->horizontalSpeed;
            return;
        }
    }

    if (obj->cType == hatkid::TYPE_ENEMY) {
        hatkid::TObject temp = *obj;
        hatkid::vertMoveObject(state, &temp);
        if (temp.isFly) {
            obj->x -= obj->horizontalSpeed;
            obj->horizontalSpeed = -obj->horizontalSpeed;
        }
    }
}

void hatkid::horizonMoveMap(hatkid::GameState& state, float dx) {
    state.mario.x -= dx;

    for (int i = 0; i < state.brickAmount; i++) {
        if (isCollision(state.mario, state.brick[i])) {
            state.mario.x += dx;
            return;
        }
    }
    state.mario.x += dx;

    for (int i = 0; i < state.brickAmount; i++) {
        state.brick[i].x += dx;
    }
    for (int i = 0; i < state.movingAmount; i++) {
        state.moving[i].x += dx;
    }
}

void hatkid::vertMoveObject(hatkid::GameState& state, hatkid::TObject* obj) {
    obj->isFly = true;
    obj->verticalSpeed += 0.05f;
    hatkid::setObjectPos(obj, obj->x, obj->y + obj->verticalSpeed);

    for (int i = 0; i < state.brickAmount; i++) {
        if (isCollision(*obj, state.brick[i])) {
            if (obj->verticalSpeed > 0) {
                obj->isFly = false;
            }

            if (state.brick[i].cType == hatkid::TYPE_BONUS && obj->verticalSpeed < 0 && obj == &state.mario) {
                state.brick[i].cType = hatkid::TYPE_EMPTY_BONUS;
                hatkid::TObject* coin = getNewMoving(state);
                hatkid::initObject(coin, state.brick[i].x, state.brick[i].y - 3, 3, 2, hatkid::TYPE_MONEY);
                coin->verticalSpeed = -0.5f;
            }

            obj->y -= obj->verticalSpeed;
            obj->verticalSpeed = 0;

            if (state.brick[i].cType == hatkid::TYPE_GOAL) {
                state.level++;
                if (state.level > state.maxLevel) {
                    state.level = 1;
                }
                napms(1000);
                hatkid::createLevel(state,state.level);
            }
            break;
        }
    }
}

