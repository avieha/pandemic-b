#include <vector>
#include "Researcher.hpp"

const int FIVE = 5;

pandemic::Player &pandemic::Researcher::discover_cure(pandemic::Color c)
{
    if (!board.get_cures(c))
    {
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

string pandemic::Researcher::role()
{
    return "Researcher";
}