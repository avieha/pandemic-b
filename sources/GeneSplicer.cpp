#include <vector>
#include "GeneSplicer.hpp"

const int FIVE = 5;

pandemic::Player &pandemic::GeneSplicer::discover_cure(pandemic::Color c)
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
            list.push_back(city);
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

string pandemic::GeneSplicer::role()
{
    return "GeneSplicer";
}