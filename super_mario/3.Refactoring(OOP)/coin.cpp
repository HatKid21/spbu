#include "coin.hpp"
#include "objectTypes.hpp"

using hatkid::Coin;

Coin::Coin() : Movable(3, 2, hatkid::ObjectType::MONEY), value(100), direction(1) {
    dead = true;
}

Coin::Coin(float x, float y) : Movable(3, 2, hatkid::ObjectType::MONEY), value(100), direction(1) {
    setPos(x, y);
}

char Coin::getSymbol() const { 
    return '$'; 
}
int Coin::getVal() const { 
    return value; 
}
int Coin::getDirection() const { 
    return direction; 
}
void Coin::changeDirection() { 
    direction *= -1; 
}
