#include "Medic.hpp"

pandemic::Player &pandemic::Medic::treat(pandemic::City c)
{
    if (current_city != c)
    {
        throw invalid_argument("you are not in the given city");
    }
    if (board[c] == 0)
    {
        throw invalid_argument("no infection in this city");
    }
    board[c] = 0;
    return *this;
};

pandemic::Player& pandemic::Medic::drive(pandemic::City c) {
    if (!board.is_connected(current_city, c))
    {
        throw invalid_argument("cities are not connected");
    }
    if (current_city == c)
    {
        throw invalid_argument("you're already in this city");
    }
    current_city = c;
    if(board.get_cures(color_by_city.at(current_city))){
        board[current_city]=0;
    }
    return *this;
}

pandemic::Player& pandemic::Medic::fly_direct(pandemic::City c) {
    if (current_city == c)
    {
        throw invalid_argument("you're already in this city");
    }
    if (cards.count(c) == 0)
    {
        throw invalid_argument("relevant card not found");
    }
    current_city = c;
    cards.erase(c);
    if(board[current_city]!=0 && board.get_cures(color_by_city.at(current_city))){
        board[current_city]=0;
    }
    return *this;
}

pandemic::Player& pandemic::Medic::fly_charter(pandemic::City c) {
    if (current_city == c)
    {
        throw invalid_argument("you're already in this city");
    }
    if (cards.count(current_city) == 0)
    {
        throw invalid_argument("relevant card not found");
    }
    cards.erase(current_city);
    current_city = c;
    if(board[current_city]!=0 && board.get_cures(color_by_city.at(current_city))){
        board[current_city]=0;
    }
    return *this;
}

pandemic::Player& pandemic::Medic::fly_shuttle(pandemic::City c) {
    if (current_city == c)
    {
        throw invalid_argument("you're already in this city");
    }
    if (!board.is_research_station(c) || !board.is_research_station(current_city))
    {
        throw invalid_argument("you need to have research stations in both cities");
    }
    current_city = c;
    if(board[current_city]!=0 && board.get_cures(color_by_city.at(current_city))){
        board[current_city]=0;
    }
    return *this;
}

string pandemic::Medic::role(){
    return "Medic";
}