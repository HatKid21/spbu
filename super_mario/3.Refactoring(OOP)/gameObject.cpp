#include "gameObject.hpp"
#include "objectType.hpp"

using hatkid::GameObject;

GameObject::GameObject(float width,float height, hatkid::ObjectType type) 
    : width(width), height(height), type(type){
}

GameObject::~GameObject() = default;

float GameObject::x() const {
    return x;
}

float GameObject::y() const {
    return y;
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
    this.x = x;
}

void GameObject::setY(float y){
    this.y = y;
}

void GameObject::setPos(float x, float y){
    this.x = x;
    this.y = y;
}
