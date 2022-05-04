#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <unordered_map>

#include "Player.hpp"

using namespace std;

const int NBR_DOMINOS = 48;

class Domino {
   public: 
    string _domino_number;
    string _field_1;
    string _crown_1;
    string _field_2;
    string _crown_2;

    Domino();
    Domino(string domino_number, string field_1, string crown_1, string field_2, string crown_2);
};

class Game {
   public:
    Game();

    void setup_dominos();
    void set_players(vector<Color> color_players);
    void discard_dominos(vector<string> domino_numbers);
    void start();

    unordered_map<string, Domino> _dominos;
    unordered_map<Color, Player> _players;
};

#endif