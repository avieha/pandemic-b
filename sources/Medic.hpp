#pragma once
#include "Player.hpp"

namespace pandemic
{

    class Medic : public Player
    {

    public:
        Medic(Board &b, City c) : Player(b, c){};
        Player &treat(City c) override;
        Player &drive(City c) override;
        Player &fly_direct(City c) override;
        Player &fly_charter(City c) override;
        Player &fly_shuttle(City c) override;
        void medic_treat();
        string role() override;
    };
}