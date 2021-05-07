
#include "Virologist.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

Virologist& Virologist::treat(City town){
    cout << " Virologist->treat( "+ Sity::toString(town)+ " )" << endl;
    if ((int)t == (int)town && game.getCure(game.getTown(town).color) ){ game[town] = 0; }
    else if (game.getCure(game.getTown(town).color) && cards[town]){
        cards[town] = false;
        game[town] = 0;
    }
    else{ throw invalid_argument("We Do Not Own & IS Current City: "+Sity::toString(town) ); }
    return *this;
}