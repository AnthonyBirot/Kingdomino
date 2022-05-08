#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <iostream>
#include <string>
#include <vector>

#include "Domino.hpp"

using namespace std;

const int DIMENSION = 5;

class Case {
   public: 
    bool _occuped;
    string _field;
    string _score;

    Case() : _occuped(false) {};
};

class Map {
   public:
    Map();

    bool is_occuped(int x, int y);
    bool pose(int x1, int y1, int x2, int y2, Domino domino);

    vector<vector<Case>> _grid;
};

#endif