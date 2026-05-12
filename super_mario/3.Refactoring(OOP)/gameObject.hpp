#pragma once

#include "objectTypes.hpp"

namespace hatkid{
    class GameObject{

        protected:
            float _x;
            float _y;
            float width;
            float height;
            ObjectType type;

        public:
            GameObject(float width, float height, ObjectType type);
            virtual ~GameObject() = default;

            virtual char getSymbol() const = 0;

            float x() const;
            float y() const;
            float getWidth() const;
            float getHeight() const;
            ObjectType getType() const;

            void setX(float x);
            void setY(float y);
            void setPos(float x, float y);

    };
}
