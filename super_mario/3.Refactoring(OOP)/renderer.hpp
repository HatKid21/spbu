#pragma once

#icnlude "gameObject.hpp"
#include "utils.hpp"

namespace hatkid{
    class Renderer{
        private:
            char** map;
            int height;
            int width;
        public:
            Renderer(int height,int width);
            ~Renderer();

            void drawObject(GameObject obj);
            void clearMap();
            void showMap();
        private:
            bool isPosInMap(int x, int y);
    };
}
