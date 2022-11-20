//
// Created by ASUS on 2022. 11. 16..
//

#include "Alkalmazott.h"

int Alkalmazott::counter{1};

Alkalmazott::Alkalmazott(const string &firstName, const string &lastName, int birthYear, const string &munkakor)
        : Szemely(firstName, lastName, birthYear), munkakor(munkakor) {
    this->id = counter;
    counter++;
}

void Alkalmazott::print(ostream &os) const {
    os << this->id << ".: ";
    Szemely::print(os);
    os << " " << this->munkakor << endl;
}


int Alkalmazott::getID() const {
    return this->id;
}

const string &Alkalmazott::getMunkakor() const {
    return this->munkakor;
}




