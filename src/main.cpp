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

    return 0;
}