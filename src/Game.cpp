#include "Game.hpp"

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

			_dominos.insert({row[0], make_shared<Domino>(domino)});
		}
	} else {
	    cout<<"Could not open the file\n";
    }
}

void Game::set_players(vector<Color> color_players) {
	_players.clear();

	if (color_players.size() > 1 && color_players.size() < 5) {
		for (int i = 0; i < color_players.size(); i++) {
			_players[color_players[i]] = make_shared<Player>(*this, color_players[i]);
		}
	} else {
		cout << "You need between 2 and 4 players to play at this game" << endl;
	}

}

void Game::discard_dominos(vector<string> domino_numbers) {
	for (int i = 0; i < domino_numbers.size(); i++) {
		_dominos.erase(domino_numbers[i]);
	}
}

void Game::choose_dominos(vector<string> domino_numbers) {
	_selected_dominos.clear();

	for (int i = 0; i < domino_numbers.size(); i++) {
		if (_dominos.find(domino_numbers[i]) != _dominos.end()) {
			_selected_dominos.insert({domino_numbers[i], _dominos[domino_numbers[i]]});
		} else {
			cout << domino_numbers[i] << " is not a valid domino number" << endl;
		}
	}

	//Test if we have a good numbers of dominos
	if ((_players.size() == 3 || _players.size() == 4) && _selected_dominos.size() != 3){
		_selected_dominos.clear();
		cout << "Choose 3 dominos to play with 3 or 4 players" << endl;
		return;
	} else if (_players.size() == 2 && _selected_dominos.size() != 4) {
		_selected_dominos.clear();
		cout << "Choose 4 dominos to play with 2 players" << endl;
		return;
	}
}