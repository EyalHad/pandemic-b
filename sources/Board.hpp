#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include <map>
#include <set>
#include <iostream>

using namespace std;

namespace pandemic {

    class Board
    {
    private:
            struct Node{
                Color color;
                bool Reaserch;
                int diseaseCount;
                set<City> reachable;    
            };
    unordered_map<const Color, bool> hasCure;
    map<City, Node> _TownsMap; 
    // unordered_map<const City,set<City>> _TownsMap;
    // unordered_map<const City, bool> _ResearchStation;
    // unordered_map<const City,const Color> _TownsColors;
    // unordered_map<const City, unsigned int> _DiseaseLevel;        
    public:
    
        // ---------- Getters -------------
        bool getCure(const Color& c){ return hasCure[c]; }
        bool getResearchS(const City& t){ return _TownsMap[t].Reaserch;}
        const Node& getTown(const City& t){ return _TownsMap[t]; }
        void foundCure(const Color& c){ hasCure[c] = true;}
        // --------------------------------
        Board();
        bool is_clean() const {
            for(auto& town : this->_TownsMap)
                { if (town.second.diseaseCount != 0)
                    { return false; } }
            return true;
        }
        int& operator[] (const City&);
        void set_station(const City& town){_TownsMap[town].Reaserch = true;}

        friend ostream& operator<< (std::ostream&, const Board& game);
        inline Board& remove_stations(){ for(auto& town: _TownsMap){town.second.Reaserch = false;} return *this; }
        Board& remove_cures(){
            for(auto& Cure: hasCure){ Cure.second = false; }
            return *this;
        }
    };
}