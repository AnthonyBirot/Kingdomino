#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

#include "Domino.hpp"
#include "Player.hpp"

using namespace std;

class Game {
   public:
    Game();

    //Init the game
    void setup_dominos();
    void set_players(vector<Color> color_players);
    void discard_dominos(vector<string> domino_numbers);

    //Handle dominos
    void choose_dominos(vector<string> domino_numbers);

    map<string, Domino> _dominos;
    map<Color, Player> _players;

    map<string, Domino> _selected_dominos;
};

#endif