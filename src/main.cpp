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
    cout << game._selected_dominos.size() << endl;

    game._players[Color::green]->select_domino(1);
    cout << game._players[Color::green]->_domino.first << endl;

    return 0;
}