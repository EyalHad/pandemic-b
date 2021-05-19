#include "FieldDoctor.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

FieldDoctor& FieldDoctor::treat(const City& town){
    // cout << " FieldDoctor->treat( "+ Sity::toString(town)+ " )" << endl;


    if (game.getTown(t).reachable.count(town) > 0 || t == town){
                City dummy = t;
    try {

        setCity(town);
        Player::treat(town);
        setCity(dummy);
    } catch( const exception& e) {setCity(dummy); throw e;}
    }else{
        throw invalid_argument{"kasbdklbas"};
    }


    
    return *this;
}