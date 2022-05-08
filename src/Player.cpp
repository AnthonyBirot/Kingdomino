#include "Game.hpp"
#include "Player.hpp"

Player::Player(Game& game, Color color) : _game(game), _color(color) {}

void Player::select_domino(int choice) {
    if (choice < 1 || choice > 3) { 
        cout << "Choose one of the 3 dominos (1, 2 or 3))" << endl;
    } else {
        map<string, shared_ptr<Domino>>::iterator it = _game._selected_dominos.begin();
        advance(it, choice - 1);
        _domino.first = it->first;
        _domino.second = it->second;
        _domino.second->_is_selected = true;
    }
}

void Player::place_castle(int x, int y) {
    _map._grid.at(x).at(y)._occuped = true;
    _map._grid.at(x).at(y)._field = "castle";
}

void Player::place_domino(int x1, int y1, int x2, int y2, Domino domino) {
    _map.pose(x1, y1, x2, y2, domino);
}

int Player::score() {
    return 0;
}