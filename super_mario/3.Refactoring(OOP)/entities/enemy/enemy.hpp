#pragma once

#include "movable.hpp"

namespace hatkid{
    class Enemy : public Movable {
        private:

        public:
            Enemy();
            Enemy(float x, float y, float width, float height, hatkid::ObjectType type);

            char getSymbol() const override;

            void update(Level& level, int mapHeight) override;

    };
}
