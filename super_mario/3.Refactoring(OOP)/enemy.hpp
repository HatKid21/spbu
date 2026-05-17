#pragma once

#include "movable.hpp"

namespace hatkid{
    class Enemy : public Movable {
        private:

        public:
            Enemy();
            Enemy(float x, float y, float width, float height, hatkid::ObjectType type);

            void update(Level& level, int mapHeight);
            void onCollision(GameObject& other, Level& level);

            char getSymbol() const override;


    };
}
