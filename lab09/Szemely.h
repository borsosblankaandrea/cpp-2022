//
// Created by ASUS on 2022. 11. 16..
//

#ifndef CPP_2022_SZEMELY_H
#define CPP_2022_SZEMELY_H

#include <ostream>
using namespace std;

class Szemely {
public:
    Szemely(string firstName, string lastName, int birthYear);
    virtual void print(ostream &os) const;

protected:
    string firstName;
    string lastName;
    int birthYear;
};

ostream& operator<<(ostream &os, const Szemely &szemely);

#endif //CPP_2022_SZEMELY_H
