#include "Virologist.hpp"

pandemic::Player &pandemic::Virologist::treat(pandemic::City c)
{
    if (board[c] == 0)
    {
        throw invalid_argument("no infection in this city");
    }
    if (c == current_city)
    {
        if (board.get_cures(color_by_city.at(c)))
        {
            board[c] = 0;
        }
        else
        {
            board[c]--;
        }
        return *this;
    }
    if (cards.count(c) == 0)
    {
        throw invalid_argument("not enough cards!!");
    }
    if (board.get_cures(color_by_city.at(c)))
    {
        board[c] = 0;
    }
    else
    {
        board[c]--;
    }
    cards.erase(c);
    return *this;
};

string pandemic::Virologist::role()
{
    return "Virologist";
}