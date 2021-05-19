#include "FieldDoctor.hpp"

pandemic::Player &pandemic::FieldDoctor::treat(pandemic::City c)
{
    if (board[c] == 0)
    {
        throw invalid_argument("no infection in this city");
    }
    if (current_city == c)
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
    if (!board.is_connected(current_city, c))
    {
        throw invalid_argument("cities are not connected");
    }
    if (board.get_cures(color_by_city.at(c)))
    {
        board[c] = 0;
    }
    else
    {
        board[c]--;
    }
    return *this;
};

string pandemic::FieldDoctor::role()
{
    return "FieldDoctor";
}