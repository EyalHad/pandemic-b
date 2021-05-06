#include "Medic.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Medic& Medic::treat(City town){
    cout << " Medic->treat( "+ Sity::toString(town)+ " )" << endl;
    Player::treat(town);
    game[town] = 0;
    return *this;
}
Medic& Medic::fly_charter(City town){
    cout << " Medic->fly_charter( "+ Sity::toString(town)+ " )" << endl;
    Player::fly_charter(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}
Medic& Medic::fly_direct(City town){
    cout << " Medic->fly_direct( "+ Sity::toString(town)+ " )" << endl;
    Player::fly_direct(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}
Medic& Medic::fly_shuttle(City town){
    cout << " Medic->fly_shuttle( "+ Sity::toString(town)+ " )" << endl;
    Player::fly_shuttle(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}
Medic& Medic::drive(City town){
    cout << " Medic->fly_drive( "+ Sity::toString(town)+ " )" << endl;
    Player::drive(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}