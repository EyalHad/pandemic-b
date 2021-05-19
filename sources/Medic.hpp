#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class Medic: public Player{
    public:
        Medic(Board& game, City town):Player(game, town){cout<< role() << endl;} 
        Medic& treat(const City&);
        Medic& drive(const City&);
        Medic& fly_direct(const City&);
        Medic& fly_shuttle(const City&);
        Medic& fly_charter(const City&);
        const std::string role() const{
            return "Medic";
        }
    };
}