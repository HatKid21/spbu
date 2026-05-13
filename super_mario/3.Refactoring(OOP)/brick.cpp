#include "brick.hpp"
#include "objectTypes.hpp"

using hatkid::Brick;

Brick::Brick(): GameObject(0,0,hatkid::ObjectType::AIR){};

Brick::Brick(float x, float y, float width, float height,hatkid::ObjectType type)
    : GameObject(width,height,type){
    setPos(x,y);
}

char Brick::getSymbol() const{
    return '#';
}
