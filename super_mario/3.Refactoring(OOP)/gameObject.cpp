#include "gameObject.hpp"
#include "objectTypes.hpp"

using hatkid::GameObject;

GameObject::GameObject(float width,float height, hatkid::ObjectType type) 
    : width(width), height(height), type(type){
}

float GameObject::x() const {
    return _x;
}

float GameObject::y() const {
    return _y;
}

float GameObject::getWidth() const{
    return width;
}

float GameObject::getHeight() const{
    return height;
}

hatkid::ObjectType GameObject::getType() const{
    return type;
}

void GameObject::setX(float x){
    _x = x;
}

void GameObject::setY(float y){
    _y = y;
}

void GameObject::setPos(float x, float y){
    _x = x;
    _y = y;
}
