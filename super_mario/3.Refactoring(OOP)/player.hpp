#pragma once

#include "gameObject.hpp"
#include "level.hpp"

namespace hatkid{
    class Player : public GameObject{
        private:
            float verticalSpeed;
            float horizontalSpeed;
            bool onGround;
            bool dead;

        public:
            Player();
            ~Player();

            char getSymbol() const override;

            bool isOnGround() const;
            void setOnGround(bool val);
            void jump();

            float getVerticalSpeed() const;
            void addVerticalSpeed(float ds);
            void setVerticalSpeed(float speed);

            float getHorizontalSpeed() const;
            void addHorizontalSpeed(float ds);
            void setHorizontalSpeed(float speed);

            void setDead(bool state);
            bool isDead() const;

    };

}
