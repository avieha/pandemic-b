#pragma once
#include <map>
#include <set>
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic
{
    class Board
    {
    private:
        map<City, int> color_cubes;
        map<City, set<City>> connections {
            {Algiers, {Madrid, Paris, Istanbul, Cairo}},
            {Atlanta, {Chicago, Miami, Washington}},
            {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
            {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
            {Beijing, {Shanghai, Seoul}},
            {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
            {BuenosAires, {Bogota, SaoPaulo}},
            {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
            {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
            {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
            {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
            {Essen, {London, Paris, Milan, StPetersburg}},
            {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
            {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
            {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
            {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
            {Johannesburg, {Kinshasa, Khartoum}},
            {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
            {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
            {Kinshasa, {Lagos, Khartoum, Johannesburg}},
            {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
            {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
            {Lima, {MexicoCity, Bogota, Santiago}},
            {London, {NewYork, Madrid, Essen, Paris}},
            {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
            {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
            {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
            {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
            {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
            {Milan, {Essen, Paris, Istanbul}},
            {Montreal, {Chicago, Washington, NewYork}},
            {Moscow, {StPetersburg, Istanbul, Tehran}},
            {Mumbai, {Karachi, Delhi, Chennai}},
            {NewYork, {Montreal, Washington, London, Madrid}},
            {Osaka, {Taipei, Tokyo}},
            {Paris, {Algiers, Essen, Madrid, Milan, London}},
            {Riyadh, {Baghdad, Cairo, Karachi}},
            {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
            {Santiago, {Lima}},
            {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
            {Seoul, {Beijing, Shanghai, Tokyo}},
            {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
            {StPetersburg, {Essen, Istanbul, Moscow}},
            {Sydney, {Jakarta, Manila, LosAngeles}},
            {Taipei, {Shanghai, HongKong, Osaka, Manila}},
            {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
            {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
            {Washington, {Atlanta, NewYork, Montreal, Miami}}};
        map<City,bool> research_stations;
        map<Color,bool> cures;

    public:
        // constructor
        Board();
        int &operator[](City c);
        void remove_cures();
        void remove_stations();
        bool is_connected(City c1, City c2);
        bool& is_research_station(City c);
        bool& get_cures(Color c);
        friend ostream &operator<<(ostream &os, Board &b);
        bool is_clean();
    };
}