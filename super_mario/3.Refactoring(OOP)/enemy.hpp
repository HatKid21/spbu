#pragma once

#include "gameObject.hpp"

namespace hatkid{

    class Enemy : public GameObject {
        private:
            int direction;
            bool alive;
            bool onGround;

        public:
            Enemy();
            Enemy(float x, float y,float width, float height, hatkid::ObjectType type);

            char getSymbol() const override;

            int getDirection() const;
            void setDirection(int dir);
            void changeDirection();

            void setAlive(bool st);

            bool isAlive() const;

            void setOnGround(bool val);
            bool isOnGround() const;

    };

}
