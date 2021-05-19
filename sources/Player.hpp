#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

using namespace std;

namespace pandemic {

    class Player {

        protected:
            Board& game;
            map<const City,bool> cards;
            City t;

        public:
            Player(Board& game, const City& town): game(game), t(town){remove_cards();}
            Player& take_card(const City&);
            virtual Player& drive(const City&);
            virtual Player& fly_charter(const City&);
            virtual Player& fly_shuttle(const City&);

            const int NeededAmount = 5;
            
            Player& remove_cards(){
                for(auto& card : cards){card.second = false;}
                return *this;
            
            }
            Player& setCity(const City& town){
                t = town;
                return *this;
            }

            void printCards(){
                for(const auto& ca : cards){
                    if (ca.second)
                    {
                        cout << "\x1B[1;20;30m";
                        cout << Sity::toString(ca.first);
                        cout << "\033[0m" << endl;
                    }
                    
                }
            }

            virtual const string role(){ return "Player";}
            virtual Player& fly_direct(const City&);
            virtual Player& build();
            virtual Player& discover_cure(const Color&);
            virtual Player& treat(const City&);

    };

}