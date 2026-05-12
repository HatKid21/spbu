#pragma once

#include "gameObject.hpp"

namespace hatkid{
    class Player : public GameObject{
        private:
            float verticalSpeed;
            float horizontalSpeed;
            bool onGround;

        public:
            Player();
            ~Player();

            char getSymbol() const override;

            bool isOnGround() const;
            void setOnGround(bool val);
            void jump();

            float getVerticalSpeed() const;
            void setVerticalSpeed(float speed);

    };

}
