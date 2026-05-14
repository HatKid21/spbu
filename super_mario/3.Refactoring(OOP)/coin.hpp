#pragma once

#include "movable.hpp"

namespace hatkid{
    class Coin : public Movable{
        private:
            int value;
            int direction;
        public:
            Coin();
            Coin(float x, float y);

            int getVal() const;
            char getSymbol() const override;

            int getDirection() const;
            void changeDirection();
    };
}
