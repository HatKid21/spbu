#pragma once

namespace hatkid{
    class GameObject{

        protected:
            float x;
            float y;
            float width;
            float height;
            ObjectType type;

        public:
            GameObject(float width, float height, float ObjectType type);
            virtual ~GameObject() = default;

            virtual char getSymbol() const = 0;

            float x() const;
            float y() const;
            float getWidth() const;
            float getHeight() const;
            ObjectType getType() const;

            void setX(float x);
            void setY(flaot y);
            void setPos(float x, float y);

    };
}
