#pragma once
#include <set>
#include "Board.hpp"
using namespace std;

namespace pandemic
{
    class Player
    {

    protected:
        Board& board;
        City current_city;
        set<City> cards;

    public:
        Player(Board &b, City c): board(b), current_city(c){}
        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        Player &take_card(City c);
        void remove_cards();
        virtual string role();
    };

}