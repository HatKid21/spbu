#pragma once

namespace hatkid{

    class Enemy : public GameObject{
        private:
            int direction;

        public:
            Enemy();

            char getSymbol const override;

            int getDirection() const;
            void setDirection(int dir);

    };

}
