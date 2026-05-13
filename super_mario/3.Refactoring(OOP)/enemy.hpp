#pragma once

#include "gameObject.hpp"

namespace hatkid{

    class Enemy : public GameObject {
        private:
            int direction;
            bool alive;

        public:
            Enemy();

            char getSymbol() const override;

            int getDirection() const;
            void setDirection(int dir);

            bool isAlive() const;

    };

}
