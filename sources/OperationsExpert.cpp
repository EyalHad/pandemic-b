#include "OperationsExpert.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

OperationsExpert& OperationsExpert::build(){
    game.set_station(t);
    return *this;
}