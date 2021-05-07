#include <iostream>
#include "Player.hpp"
#include <set>
using namespace std;



namespace pandemic {


    Player& Player::take_card(const City& town) {
        cout << " Player->take_card( "+ Sity::toString(town)+ " )" << endl;
        cards[town] = true;
        return *this;
    }

    Player& Player::discover_cure(const Color& color) {
        cout << " Player->discover_cure( "+ Sity::toString(t)+ " )" << endl;
        if (game.getCure(color)){return *this;}
        else if(!game.getResearchS(t)) 
            {throw invalid_argument ("Need to Build Research Station FIRST !, Cannot dicover_cure()");}
        int i = 0;
        for(auto& card : cards){
            City town = card.first;
            Color townColor = game.getTown(town).color;
            if (cards[town] && townColor == color){ i++; }
            if (i == NeededAmount){ break; }
        }
        if (i != NeededAmount) {throw invalid_argument ("Need 5 Cards with Same Color !, Cannot dicover_cure()");}
        game.foundCure(color);
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
    Player& Player::drive(const City& town) {
        
        cout << Sity::toString(t) << " Player->drive( "+ Sity::toString(town)+ " )" << endl;
        if ((int)t == (int)town){throw invalid_argument("Cannot Drive there !, We Are Already Here"); }
        else if (game.getTown(t).reachable.count(town) > 0){
            setCity(town);
                    cout << "                         After"<< endl;
        cout << Sity::toString(t) << " HEREEEEEE" << endl;
        }else { throw invalid_argument("Cannot Drive there !, Not a Neighbor City");}

        return *this;
    }

    Player& Player::fly_direct(const City& town) {
        cout << " Player->fly_direct( "+ Sity::toString(town)+ " )" << endl;
        if ((int)t == (int)town){throw invalid_argument("Cannot Fly there !, We Are Already Here"); } 
        else if (cards[town]){
            setCity(town);
        }else { throw invalid_argument("We Do not have the Card: " + Sity::toString(town) + " Cannot use fly_direct()");}
        return *this;
    }
    Player& Player::fly_charter(const City& town) {
        cout << " Player->fly_charter( "+ Sity::toString(town)+ " )" << endl; 
        if ((int)t == (int)town){throw invalid_argument("Cannot Fly there !, We Are Already Here"); }
        else if (cards[t]){
            setCity(town);
        }else{ throw invalid_argument("We Do not have the Card: " + Sity::toString(t)+ " Cannot use fly_charter()");}
        
        return *this;
    }
    Player& Player::fly_shuttle(const City& town) {
        cout << " Player->fly_shuttle( "+ Sity::toString(town)+ " )" << endl;
        if ((int)t == (int)town){throw invalid_argument("Cannot Fly there !, We Are Already Here"); } 
        else if (game.getResearchS(t)){
            if (game.getResearchS(town)){
                setCity(town);
            }else{ throw invalid_argument("No Research Station in: " + Sity::toString(town) + " Cannot use fly_shuttle()");}  
        }else{ throw invalid_argument("No Research Station in: " + Sity::toString(t)+ " Cannot use fly_shuttle()");}
        
        return *this;
    }
    Player& Player::build() {
        cout << " Player->build( "+ Sity::toString(t)+ " )" << endl; 
        if (game.getResearchS(t)){ return *this; }
        else{
            if (cards[t]){
                game.getTown(t).Reaserch = true;
            }else{ throw invalid_argument("We Do not have the Card: " + Sity::toString(t) + " Cannot use build()");}
        }
        return *this;
    }


    Player& Player::treat(const City& town) {
        cout << " Player->treat( "+ Sity::toString(town)+ " )" << endl; 
        if ((int)t != (int)town){ throw invalid_argument("Do not in requested, City Current: "+Sity::toString(t)
        +"Tried to: "+Sity::toString(town)+" Cannot use treat()");}
        else if (game[town] <= 0){
            throw invalid_argument("Diease level is ZERO Cannot use treat()");
        }else if(game.getCure(game.getTown(town).color)){ game[town] = 0; }
        else{ game[town]--;}
        return *this;
    }
}; 