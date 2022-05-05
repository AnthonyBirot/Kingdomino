#ifndef __DOMINO_HPP__
#define __DOMINO_HPP__

#include <string>

using namespace std;

class Domino {
   public: 
    Domino();
    Domino(string domino_number, string field_1, string crown_1, string field_2, string crown_2);

    string _domino_number;
    string _field_1;
    string _crown_1;
    string _field_2;
    string _crown_2;

    bool _is_selected;
};

#endif