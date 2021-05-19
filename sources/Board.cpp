#include "Board.hpp"
#include <iostream>
using namespace std;

namespace pandemic
{
    // constructor
    Board::Board(){};

    int &Board::operator[](pandemic::City c)
    {
        return color_cubes[c];
    }

    void Board::remove_cures()
    {
        cures.clear();
    };

    bool &Board::is_research_station(pandemic::City c)
    {
        return research_stations[c];
    }

    bool &Board::get_cures(pandemic::Color c)
    {
        return cures[c];
    }

    void Board::remove_stations()
    {
        for (auto &station : research_stations)
        {
            station.second = false;
        }
    }

    bool Board::is_connected(pandemic::City c1, pandemic::City c2)
    {
        return connections[c1].count(c2) == 1;
    }

    ostream &operator<<(ostream &os, pandemic::Board &b)
    {
        return os;
    };

    bool Board::is_clean()
    {
        for (auto &city : color_cubes)
        {
            if (city.second != 0)
            {
                return false;
            }
        }
        return true;
    };
}