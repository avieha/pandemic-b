#include <vector>
#include "Scientist.hpp"

pandemic::Player &pandemic::Scientist::discover_cure(pandemic::Color c)
{
    if (!board.get_cures(c))
    {
        if (!board.is_research_station(current_city))
        {
            throw invalid_argument("no research station in your current city");
        }
        if (cards.size() < n)
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
        if (list.size() < n)
        {
            throw invalid_argument("not enough cards in color");
        }
        for (size_t i = 0; i < n; i++)
        {
            cards.erase(list[i]);
        }
        board.get_cures(c) = true;
    }
    return *this;
};

string pandemic::Scientist::role()
{
    return "Scientist";
}
