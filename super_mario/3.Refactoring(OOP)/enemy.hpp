#pragma once

#include "movable.hpp"

namespace hatkid{
    class Enemy : public Movable {
        private:
            int direction;

        public:
            Enemy();
            Enemy(float x, float y, float width, float height, hatkid::ObjectType type);

            char getSymbol() const override;

            int getDirection() const;
            void setDirection(int dir);
            void changeDirection();
    };
}
