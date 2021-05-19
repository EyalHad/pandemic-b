
#include "Virologist.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

Virologist& Virologist::treat(const City& town){
    // cout << " Virologist->treat( "+ Sity::toString(town)+ " )" << endl;
    // if(t == town) {
    //     if(game.getCure(game.getTown(town).color)) {
    //         game[t] = 0;
    //     } else {
    //         game[t]--;
    //     }
    // } else if(cards[town]) {
    //     if(game.getCure(game.getTown(town).color)) {
    //         game[t] = 0;
    //     } else {
    //         game[t]--;
    //     }
    //     cards[town] = false;
    // }
    // return *this;
    if (t == town && game.getCure(game.getTown(town).color) ){ game[town] = 0; }
    else if(t == town && !(game.getCure(game.getTown(town).color)) ){ game[town]--; }
    else if (game.getCure(game.getTown(town).color) && cards[town]){
        cards[town] = false;
        game[town] = 0;
    }else if(cards[town]){
        cards[town] = false;
        game[town]--;
    }
    else{ throw invalid_argument("We Do Not Own & IS Current City: "+Sity::toString(town) ); }
    return *this;
}