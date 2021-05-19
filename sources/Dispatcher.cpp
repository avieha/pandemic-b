#include "Dispatcher.hpp"

pandemic::Player &pandemic::Dispatcher::fly_direct(pandemic::City c)
{
    if (c==current_city)
    {
        throw invalid_argument("same city");
    }
    if (board.is_research_station(current_city))
    {
        current_city=c;
        return *this;
    }
    if(cards.count(c)==0){
        throw invalid_argument("no card found");
    }
    cards.erase(c);
    current_city=c;
    return *this;
};

string pandemic::Dispatcher::role(){
    return "Dispatcher";
}