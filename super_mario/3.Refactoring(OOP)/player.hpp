#pragma once

#include "gameObject.hpp"

namespace hatkid{
    class Player : public GameObject{
        private:
            float verticalSpeed;
            float horizontalSpeed;
            bool onGround;

        public:
            Player();
            ~Player();

            bool isOnGround() const;
            
            void setOnGround(bool val);

    }

};
