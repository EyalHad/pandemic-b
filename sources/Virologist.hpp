#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class Virologist: public Player{
    public:
        Virologist(Board& game, City town): Player(game, town){ cout<< role() << endl;}
        Virologist& treat(const City&);
        const std::string role() const{return "Virologist";}
    };
}