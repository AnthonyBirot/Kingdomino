#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include <memory>

#include "Domino.hpp"
#include "Field.hpp"

enum class Color {red, blue, green, yellow};

class Game;

class Player{
   public:
    Player(Game& game, Color color);

    void select_domino(int choice);

    Color _color;
    pair<string, shared_ptr<Domino>> _domino;
    Field _field;

   protected: 
    Game& _game;
};

#endif