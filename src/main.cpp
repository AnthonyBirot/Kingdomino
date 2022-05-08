#include <iostream>

#include "Game.hpp"

using namespace std;

int main() {
    Game game;

    vector<Color> colors_players{Color::blue, Color::green, Color::red};
    game.set_players(colors_players);
    cout << "Number of players: " << game._players.size() << endl;

    vector<string> erased_dominos{"5", "9", "8"};
    game.discard_dominos(erased_dominos);
    cout << "Number of dominos: " << game._dominos.size() << endl;

    vector<string> domino_number{"4", "65", "45", "8", "22"};
    game.choose_dominos(domino_number);
    for (auto d : game._selected_dominos) {
        cout << "You choose: " << d.first << endl;
    }

    game._players[Color::green]->select_domino(3);
    cout << "Player green choose the domino: " << game._players[Color::green]->_domino.first << endl;

    game._players[Color::red]->select_domino(2);
    cout << "Player red choose the domino: " << game._players[Color::red]->_domino.first << endl;

    cout << "Player green domino field_1: " << game._players[Color::green]->_domino.second->_field_1 << endl;
    cout << "Player green domino field_2: " << game._players[Color::green]->_domino.second->_field_2 << endl;
    game._players[Color::green]->place_castle(2, 2);
    game._players[Color::green]->place_domino(1, 2, 1, 3, game._players[Color::green]->_domino.second);
    cout << "Grid[x1][y1] field: " << game._players[Color::green]->_map._grid[1][2]._field << endl;
    cout << "Grid[x2][y2] field: " << game._players[Color::green]->_map._grid[1][3]._field << endl;

    return 0;
}