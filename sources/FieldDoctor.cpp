#include "FieldDoctor.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

FieldDoctor& FieldDoctor::treat(City town){
    cout << " FieldDoctor->treat( "+ Sity::toString(town)+ " )" << endl;
    if(game.getTown(t).reachable.find(town) == game.getTown(t).reachable.end()){
        throw invalid_argument("Do not in requested/Neighbor City, City Current: "+Sity::toString(t)
        +"Tried to: "+Sity::toString(town)+" Cannot use treat()");
    }
    else if (game.getCure(game.getTown(town).color)){
        game[town] = 0;
    }else{ game[town]--;}
    
    return *this;
}