#pragma once

#include "gameObject.hpp"
#include "objectTypes.hpp"

namespace hatkid {
    class Brick : public GameObject {
        public:
            Brick();
            Brick(float x, float y, float width, float height, ObjectType type);
            char getSymbol() const override;
    };
}
