#include "movable.hpp"

using hatkid::Movable;

Movable::Movable(float width, float height, ObjectType type)
    : GameObject(width, height, type),
      verticalSpeed(0), horizontalSpeed(0),
      onGround(false), dead(false) {
}

float Movable::getVerticalSpeed() const { return verticalSpeed; }
void Movable::addVerticalSpeed(float ds) { verticalSpeed += ds; }
void Movable::setVerticalSpeed(float speed) { verticalSpeed = speed; }

float Movable::getHorizontalSpeed() const { return horizontalSpeed; }
void Movable::addHorizontalSpeed(float ds) { horizontalSpeed += ds; }
void Movable::setHorizontalSpeed(float speed) { horizontalSpeed = speed; }

bool Movable::isOnGround() const { return onGround; }
void Movable::setOnGround(bool val) { onGround = val; }

bool Movable::isDead() const { return dead; }
void Movable::setDead(bool val) { dead = val; }
