//
// Created by ASUS on 2022. 11. 16..
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H

#include <ostream>
#include "Szemely.h"

using namespace std;


class Alkalmazott: public Szemely{
public:
    Alkalmazott(const string &firstName, const string &lastName, int birthYear, const string &munkakor);
    virtual void print(ostream &os) const;
    int getID() const;

    const string &getMunkakor() const;

protected:
    string munkakor;
    int id;
    static int counter;
};

#endif //CPP_2022_ALKALMAZOTT_H
