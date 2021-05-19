#include "Dispatcher.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

Dispatcher& Dispatcher::fly_direct(const City& town){
    // cout << " Dispatcher->fly_direct( "+ Sity::toString(town)+ " )" << endl;
    if(t == town) {throw invalid_argument("Cannot fly from city to itself!");}
    if(game.getResearchS(t)){setCity(town);}
    else{Player::fly_direct(town);}
    return *this;
}