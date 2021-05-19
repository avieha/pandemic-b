#include "OperationsExpert.hpp"

pandemic::Player &pandemic::OperationsExpert::build()
{
    board.is_research_station(current_city) = true;
    return *this;
};

string pandemic::OperationsExpert::role(){
    return "OperationsExpert";
}