#pragma once

#include "gameObject.hpp"

namespace hatkid{
    class Renderer{
        private:
            char** map;
            int height;
            int width;
            int offset;
        public:
            Renderer(int height,int width);
            ~Renderer();

            void drawObject(GameObject& obj);
            void clearMap();
            void showMap();

            void drawScore(int score);
            void addOffset(int dx);
            void setCameraX(int camX);
        private:
            bool isPosInMap(int x, int y);
    };
}
