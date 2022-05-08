#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include <memory>
#include <map>

#include "Domino.hpp"
#include "Map.hpp"

enum class Color {red, blue, green, yellow};

class Game;

class Player{
   public:
    Player(Game& game, Color color);

    void select_domino(int choice);
    void place_domino(int x1, int y1, int x2, int y2, Domino domino);
    void place_castle(int x, int y);
    int score();

    Color _color;
    pair<string, shared_ptr<Domino>> _domino;
    Map _map;

   protected: 
    Game& _game;
};

#endif