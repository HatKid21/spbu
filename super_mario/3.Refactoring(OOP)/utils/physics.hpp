#pragma once

#include "level.hpp"
#include "movable.hpp"

namespace hatkid{
    class Physics{
        public:
            static void moveHorizontal(Movable& obj, Level& level);
            static void moveVertical(Movable& obj, Level& level, int mapHeight);
    };
}
