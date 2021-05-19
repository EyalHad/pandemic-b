#include "Researcher.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Researcher& Researcher::discover_cure(Color color){
    // cout << " Researcher->discover_cure( "+ Sity::toString(t)+ " )" << endl;

    if (game.getCure(color)){return *this;}
    int i = 0;
    for(auto& card : cards){
        City town = card.first;
        Color townColor = game.getTown(town).color;
        if (cards[town] && townColor == color){ i++; }
        if (i == Player::NeededAmount){ break; }
    }
    if (i != Player::NeededAmount) {throw invalid_argument ("Need 5 Cards with Same Color !, Cannot dicover_cure()");}
    game.foundCure(color);
    cout << "game cures: " << game.getCure(Color::Black) << game.getCure(Color::Blue) << game.getCure(Color::Red) << game.getCure(Color::Yellow) << endl;
    for(auto& card : cards){
        City town = card.first;
        Color townColor = game.getTown(town).color;
        if (cards[town] && townColor == color){
            cards[town] = false;
            i--;
        }
        if (i == 0){ break; }
    }   
    return *this;
}