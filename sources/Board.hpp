#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include <map>
#include <set>
#include <iostream>

using namespace std;

namespace pandemic {
    // struct Node{
    //     Color color;
    //     bool Reaserch = false;
    //     int diseaseCount = 0;
    //     set<City> reachable;    
    // };
    class Board
    {
    private:
    unordered_map<const Color,bool> hasCure;
    // unordered_map<const City,Node> _TownsMap; 
    unordered_map<const City,set<City>> _TownsMap;
    unordered_map<const City, bool> _ResearchStation;
    unordered_map<const City,const Color> _TownsColors;
    unordered_map<const City, unsigned int> _DiseaseLevel;        
    public:
        // ---------- Getters -------------
        bool getCure(const Color c){ return hasCure[c]; }
        bool getResearchS(const City t){ return _ResearchStation[t];}
        // Node& getTown(const City t){ return _TownsMap[t]; }
        Board& foundCure(const Color c){ hasCure[c] = true; return *this; }
        // --------------------------------
        Board();
        bool is_clean() const {
            for(auto& town : this->_TownsMap)
                { if (town.second.diseaseCount != 0)
                    { return false; } }
            return true;
        }
        int& operator[] (const City&);
        friend ostream& operator<< (std::ostream&, const Board& game);
        inline Board& remove_stations(){ for(auto& town: _TownsMap){town.second.Reaserch = false;} return *this; }
        Board& remove_cures(){
            for(auto& Cure: hasCure){ Cure.second = false; }
            return *this;
        }
    };
}