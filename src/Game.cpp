#include "Game.hpp"

Domino::Domino() {}

Domino::Domino(string domino_number, string field_1, string crown_1, string field_2, string crown_2) {
	_domino_number = domino_number;
	_field_1 = field_1;
	_crown_1 = crown_1;
	_field_2 = field_2;
	_crown_2 = crown_2;
}

Game::Game() {
    setup_dominos();
}

void Game::setup_dominos() {
	_dominos.clear();

	// Convert CSV file to dominos list
	vector<string> row;
	string line, word;
 
	fstream file ("/home/anthony/Workspace/Kingdomino/dominos.csv", ios::in);
	if(file.is_open()) {
		while(getline(file, line)) {
			row.clear();

			stringstream str(line);
 
			while(getline(str, word, ',')) {
				row.push_back(word);
			}

			Domino domino;
			domino._domino_number = row[0];
			domino._field_1 = row[1];
			domino._crown_1 = row[2];
			domino._field_2 = row[3];
			domino._crown_2 = row[4];

			_dominos.insert({row[0], domino});
		}
	}
	else {
	    cout<<"Could not open the file\n";
    }
}

void Game::set_players(vector<Color> color_players) {
	for (int i = 0; i < color_players.size(); i++) {
		_players.insert({color_players[i], Player(color_players[i])});
	}
}

void Game::discard_dominos(vector<string> domino_numbers) {
	for (int i = 0; i < domino_numbers.size(); i++) {
		_dominos.erase(domino_numbers[i]);
	}
}