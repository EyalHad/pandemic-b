#include "Dispatcher.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

Dispatcher& Dispatcher::fly_direct(City town){
    cout << " Dispatcher->fly_direct( "+ Sity::toString(town)+ " )" << endl;
    if(game.getResearchS(this->town)){this->town = town;}
    else{Player::fly_direct(town);}
    return *this;
}