#include "Domino.hpp"

Domino::Domino() {}

Domino::Domino(string domino_number, string field_1, string crown_1, string field_2, string crown_2) : _is_selected(false) {
	_domino_number = domino_number;
	_field_1 = field_1;
	_crown_1 = crown_1;
	_field_2 = field_2;
	_crown_2 = crown_2;
}