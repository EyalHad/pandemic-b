
#include "GeneSplicer.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

GeneSplicer& GeneSplicer::discover_cure(Color c){
    // cout << " GeneSplicer->discover_cure( "+ Sity::toString(c)+ " )" << endl;
    if(!game.getResearchS(t)){throw invalid_argument{"TTTTTT"};}
    int i = 0;
    for(auto& card : cards){ 
        if (cards[card.first]){i++;}
        if( i == Player::NeededAmount) { break; }
    }
    if( i != Player::NeededAmount){throw invalid_argument{"TTTTTT"};}
    game.foundCure(c);
    for(auto& card : cards){ 
        if (cards[card.first]){
            cards[card.first] = false;
            i--;
        }
        if( i == 0) { break; }
    }
    return *this;
}