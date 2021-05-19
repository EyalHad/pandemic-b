#include "Medic.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Medic& Medic::treat(const City& town){
    cout << " Medic->treat( "+ Sity::toString(town)+ " )" << endl;
    Player::treat(town);
    game[town] = 0;
    return *this;
}
Medic& Medic::fly_charter(const City& town){
    cout << " Medic->fly_charter( "+ Sity::toString(town)+ " )" << endl;
    Player::fly_charter(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}
Medic& Medic::fly_direct(const City& town){
    cout << " Medic->fly_direct( "+ Sity::toString(town)+ " )" << endl;
    Player::fly_direct(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}
Medic& Medic::fly_shuttle(const City& town){
    cout << " Medic->fly_shuttle( "+ Sity::toString(town)+ " )" << endl;
    Player::fly_shuttle(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}
Medic& Medic::drive(const City& town){
    cout << " Medic->drive( "+ Sity::toString(town)+ " )" << endl;
    Player::drive(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}