#pragma once

#include "movable.hpp"

namespace hatkid{
    class Player : public Movable {
        public:
            Player();
            ~Player();

            char getSymbol() const override;
            void jump();
    };
}
