#include "Player.hpp"
#include <vector>
#include <iostream>
using namespace std;
using namespace pandemic;

const int FIVE = 5;

pandemic::Player &pandemic::Player::take_card(City c)
{
    cards.insert(c);
    return *this;
};

pandemic::Player &pandemic::Player::drive(City c)
{
    if (!board.is_connected(current_city, c))
    {
        throw invalid_argument("cities are not connected");
    }
    if (current_city == c)
    {
        throw invalid_argument("you're already in this city");
    }
    current_city = c;
    return *this;
};

pandemic::Player &pandemic::Player::fly_direct(City c)
{
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
    return *this;
};

pandemic::Player &pandemic::Player::fly_charter(City c)
{
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
    return *this;
};

pandemic::Player &pandemic::Player::fly_shuttle(City c)
{
    if (current_city == c)
    {
        throw invalid_argument("you're already in this city");
    }
    if (!board.is_research_station(c) || !board.is_research_station(current_city))
    {
        throw invalid_argument("you need to have research stations in both cities");
    }
    current_city = c;
    return *this;
};

pandemic::Player &pandemic::Player::build()
{
    if (cards.count(current_city) == 0)
    {
        throw invalid_argument("you dont have the right card");
    }
    board.is_research_station(current_city) = true;
    cards.erase(current_city);
    return *this;
};

pandemic::Player &pandemic::Player::discover_cure(Color c)
{
    if (!board.get_cures(c))
    {
        if (!board.is_research_station(current_city))
        {
            throw invalid_argument("no research station in your current city");
        }
        if (cards.size() < FIVE)
        {
            throw invalid_argument("you dont have enough cards");
        }
        vector<City> list;
        for (auto city : cards)
        {
            if (color_by_city.at(city) == c)
            {
                list.push_back(city);
            }
        }
        if (list.size() < FIVE)
        {
            throw invalid_argument("not enough cards in color");
        }
        for (size_t i = 0; i < FIVE; i++)
        {
            cards.erase(list[i]);
        }
        board.get_cures(c) = true;
    }
    return *this;
};

pandemic::Player &pandemic::Player::treat(City c)
{
    if (current_city != c)
    {
        throw invalid_argument("you are not in the given city");
    }
    if (board[c] == 0)
    {
        throw invalid_argument("no infection in this city");
    }
    Color temp = color_by_city.at(c);
    if (board.get_cures(temp))
    {
        board[c] = 0;
    }
    else
    {
        board[c]--;
    }
    return *this;
};

void pandemic::Player::remove_cards()
{
    cards.clear();
}

string pandemic::Player::role()
{
    return "Player";
};