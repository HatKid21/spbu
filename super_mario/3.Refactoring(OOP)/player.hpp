#pragma once

#include "level.hpp"
#include "movable.hpp"

namespace hatkid{

    class Player : public Movable {
        public:
            Player();
            ~Player();

            char getSymbol() const override;

            void onCollision(GameObject& other, Level& level) override;
            void handleInteractions(Level& level);

            void jump();
    };
}
