#pragma once

#include "gameObject.hpp"

namespace hatkid{

    class Level;

    class Movable : public GameObject {
        protected:
            float verticalSpeed;
            float horizontalSpeed;
            bool onGround;
            bool dead;

        public:
            Movable(float width, float height, ObjectType type);
            virtual ~Movable() = default;

            virtual void update(Level& level, int mapHeight);
            virtual void onCollision(GameObject& other, Level& level);

            float getVerticalSpeed() const;
            void addVerticalSpeed(float ds);
            void setVerticalSpeed(float speed);

            float getHorizontalSpeed() const;
            void addHorizontalSpeed(float ds);
            void setHorizontalSpeed(float speed);

            bool isOnGround() const;
            void setOnGround(bool val);

            bool isDead() const;
            void setDead(bool val);
    };
}
