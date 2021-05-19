#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace Sity;

#include <iostream>
#include <unordered_map>
#include <map>
#include <set>

#include <fstream>

using namespace std;
using namespace pandemic;



namespace pandemic{

    Board::Board(){
        ifstream file{"cities_map.txt"};

        string line;
        string town;

        while (getline(file,line))
        {
            Node city;
            int i = 0;
            string dummy; 
            string space = " "; // For tidy :)
            unsigned long pos = 0;
            while (pos != string::npos)
            {
                pos = line.find(space);
                dummy = line.substr(0,pos);
                if (i == 0)
                {
                    town = dummy;
                    _TownsMap[Sity::toCity(town)];
                    _TownsMap[Sity::toCity(town)].diseaseCount = 0;
                    _TownsMap[Sity::toCity(town)].Reaserch = false;
                }else if (i ==1){
                    _TownsMap[Sity::toCity(town)].color = Sity::toColor(dummy);
                }else{
                    _TownsMap[Sity::toCity(town)].reachable.insert(Sity::toCity(dummy));
                }
                line.erase(0,pos+1);
                i++;   
            }

            _TownsMap[Sity::toCity(town)].reachable.insert(Sity::toCity(line));
            
            
        }

           
    }

    int& Board::operator[] (const City& town){
        return _TownsMap[town].diseaseCount;
    }


    ostream& operator<< (ostream& os, const Board& game) {
        for (auto& Town: game._TownsMap)
        {   
            if (Town.second.diseaseCount != 0)
            {
                cout << "Has Disease" << "Name: \x1B[36m\033[32m[" << Sity::toString( Town.first) << "]" 
                << " ===>" << Town.second.diseaseCount  << endl;
            }
            
            os <<  "[";
            switch (Town.second.color)
            {
            case Color::Blue:
                os << "\x1B[36m Blue \033[0m";
                break;
            case Color::Red:
                os << "\x1B[31m Red \033[0m";
                break;
            case Color::Yellow:
                os << "\x1B[93m Yellow \033[0m";
                break;
            
            default:
                os << "\x1B[1;20;30m Black \033[0m";
                break;
            }
            os << "] "<< "Name: [" << Sity::toString( Town.first) << "] <->" << "\t{ ";
            int i = 0;
            for(const City& Neighbor : Town.second.reachable){
                os << "(" << i << ") " << Sity::toString(Neighbor) << ", ";
                i++;
            }
            os << "}\n";
        }

        
        return os;
    }

};