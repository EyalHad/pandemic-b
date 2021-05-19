#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Dispatcher: public Player{
    public:
        Dispatcher(Board& game, City town):Player(game, town){ role();} 
        Dispatcher& fly_direct(const City& );
        const std::string role() const{
            return "Dispatcher";
        }
    };
}