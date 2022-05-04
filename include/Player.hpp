#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>

#include "Field.hpp"

enum class Color {red, blue, green, yellow};

class Player{
   public:
    Player(Color color);

    Color _color;
    Field _field;
};

#endif