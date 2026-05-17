#include "enemy.hpp"
#include "physics.hpp"

using hatkid::Enemy;

Enemy::Enemy() : Movable(0, 0, hatkid::ObjectType::AIR) {
    dead = true;
}

Enemy::Enemy(float x, float y, float width, float height, hatkid::ObjectType type)
    : Movable(width, height, type) {
    setPos(x, y);
    setHorizontalSpeed(0.5);
}

char Enemy::getSymbol() const { 
    return 'o'; 
}

void Enemy::update(hatkid::Level& level, int mapHeight){
    if (isDead()) return;

    addX(getHorizontalSpeed());

    Brick* bricks = level.getBricks();
    int brickAmount = level.getBrickAmount();

    for (int i = 0; i < brickAmount; i++) {
        if (collisionWith(bricks[i])) {
            addX(-getHorizontalSpeed());
            setHorizontalSpeed(-getHorizontalSpeed());
            break;
        }
    }

    bool groundBelow = false;

    addY(1);
    for (int i = 0; i < brickAmount; i++) {
        if (collisionWith(bricks[i])) {
            groundBelow = true;
            break;
        }
    }
    addY(-1);

    if (!groundBelow) {
        addX(-getHorizontalSpeed());
        setHorizontalSpeed(-getHorizontalSpeed());
    }

    Physics::moveVertical(*this, level, mapHeight);
}
