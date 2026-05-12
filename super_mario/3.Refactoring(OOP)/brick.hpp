#pragma once

#include "gameObject.hpp"

namespace hatkid {
    class Brick : public GameObject {
        public:
            Brick();
            char getSymbol() const override;
    };
}
