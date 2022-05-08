#include "Map.hpp"

Map::Map() {
    _grid.resize(DIMENSION, vector<Case>(DIMENSION));
}

bool Map::is_occuped(int x, int y) {
    if (x > DIMENSION && y > DIMENSION) {
        cout << "x and y are out of grid" << endl;
        return true; 
    }
    return (_grid[x][y]._occuped);
}

bool Map::pose(int x1, int y1, int x2, int y2, shared_ptr<Domino> domino){
    // Check if there already is a domino on x1y1 or x2y2
    if (is_occuped(x1, y1) || is_occuped(x2, y2)) {
        cout << "There already is a domino in this pose" << endl;
        return false;
    }

    //Find all cases in the grid next to x1y1 and x2y2  
    string orientation;
    if (x1 == x2) {
        orientation = (y1 < y2) ? "y+" : "y-";
    } else {
        orientation = (x1 < x2) ? "x+" : "x-";
    }

    vector<int> possible_x;
    vector<int> possible_y;
    if (orientation == "y+") {
        possible_x.insert(possible_x.end(), {x1-1, x1, x1+1});
        possible_y.insert(possible_y.end(), {y1-1, y1, y2, y2+1});
    } else if (orientation == "y-") {
        possible_x.insert(possible_x.end(), {x1-1, x1, x1+1});
        possible_y.insert(possible_y.end(), {y2-1, y2, y1, y1+1});
    } else if (orientation == "x+") {
        possible_x.insert(possible_x.end(), {x1-1, x1, x2, x2+1});
        possible_y.insert(possible_y.end(), {y1-1, y1, y1+1});        
    } else if (orientation == "x-") {
        possible_x.insert(possible_x.end(), {x2-1, x2, x1, x1+1});
        possible_y.insert(possible_y.end(), {y1-1, y1, y1+1});    
    }

    vector<pair<int, int>> side;
    for (int x : possible_x) {
        //Test if x is in the grid
        if (x >= 0 && x < DIMENSION) {
            for(int y : possible_y) {
                //Test if y is in the grid
                if (y >= 0 && y < DIMENSION) {
                    //Test if (x,y) is one of the domino index
                    if (!((x == x1 && y == y1) || (x == x2 && y == y2))) {
                        // //Delete diagonals couple
                        if (orientation == "y+" || orientation == "y-") {
                            if (y != y1 && y != y2) {
                                if (x==x1) {
                                    side.push_back(make_pair(x, y));
                                }
                            } else {
                                side.push_back(make_pair(x, y));
                            }
                        } else if (orientation == "x+" || orientation == "x-") {
                            if (x != x1 && x != x2) {
                                if (y==y1) {
                                    side.push_back(make_pair(x, y));
                                }
                            } else {
                                side.push_back(make_pair(x, y));
                            }
                        }
                    }
                }
            }            
        }
    }

    // Cases occuped around the domino
    vector<pair<int, int>> side_occuped;
    for (pair<int, int> couple : side) {
        if (_grid[couple.first][couple.second]._occuped) {
            side_occuped.push_back(couple);
        }
    }

    if (side_occuped.size() == 0) {
        cout << "No domino next to yours" << endl;
        return false;
    }

    // Check match between domino's field
    vector<pair<int, int>> side_occuped_same_field;
    for (pair<int, int> couple : side_occuped) {
        string test_field = _grid[couple.first][couple.second]._field;

        if (test_field != "castle") {

            if (orientation == "y+") {

                if (couple.second == y1-1 || couple.second == y1) {
                    if (test_field == domino->_field_1 || test_field == "castle"){
                        side_occuped_same_field.push_back(couple);
                    }
                } else {
                    if (test_field == domino->_field_2){
                        side_occuped_same_field.push_back(couple);
                    }
                }

            } 
            
            else if (orientation == "y-") {

                if (couple.second == y1+1 || couple.second == y1) {
                    if (test_field == domino->_field_1){
                        side_occuped_same_field.push_back(couple);
                    }
                } else {
                    if (test_field == domino->_field_2){
                        side_occuped_same_field.push_back(couple);
                    }
                }   

            } 
            
            else if (orientation == "x+") {

                if (couple.first == x1-1 || couple.first == x1) {
                    if (test_field == domino->_field_1){
                        side_occuped_same_field.push_back(couple);
                    }
                } else {
                    if (test_field == domino->_field_2){
                        side_occuped_same_field.push_back(couple);
                    }
                }   

            } 
            
            else if (orientation == "x-") {

                if (couple.first == x1+1 || couple.first == x1) {
                    if (test_field == domino->_field_1){
                        side_occuped_same_field.push_back(couple);
                    }
                } else {
                    if (test_field == domino->_field_2){
                        side_occuped_same_field.push_back(couple);
                    }
                }   

            }

        } 
        else {
            side_occuped_same_field.push_back(couple);
        }
    }

    if(side_occuped_same_field.size() == 0) {
        cout << "No domino with the good field next to yours" << endl;
        return false;     
    }

    //TO DO : Check the global size of the map (5 fields by line and column max)

    _grid[x1][y1]._field = domino->_field_1;
    _grid[x1][y1]._score = domino->_crown_1;
    _grid[x1][y1]._occuped = true;
    
    _grid[x2][y2]._field = domino->_field_2;
    _grid[x2][y2]._score = domino->_crown_2;
    _grid[x2][y2]._occuped = true;

    return true;
}