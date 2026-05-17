#include "coin.hpp"
#include "objectTypes.hpp"

using hatkid::Coin;

Coin::Coin() : Movable(3, 2, hatkid::ObjectType::MONEY),
    value(100){
    dead = true;
}

Coin::Coin(float x, float y) : Movable(3, 2, hatkid::ObjectType::MONEY),
    value(100) {
    setPos(x, y);
}

char Coin::getSymbol() const { 
    return '$'; 
}

int Coin::getVal() const { 
    return value; 
}
