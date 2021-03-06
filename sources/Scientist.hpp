#pragma once
#include "Player.hpp"

namespace pandemic {

    class Scientist: public Player {
        int n;

        public:
            Scientist(Board& b, City c, int num): Player(b, c), n(num){};
            Player& discover_cure(Color) override;
            string role() override;
    };
}