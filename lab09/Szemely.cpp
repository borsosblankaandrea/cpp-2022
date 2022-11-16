//
// Created by ASUS on 2022. 11. 16..
//

#include "Szemely.h"

Szemely::Szemely(string firstName, string lastName, int birthYear) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->birthYear = birthYear;
}

void Szemely::print(ostream &os) const {
    os << this->firstName << " " << this->lastName << " " << this->birthYear;
}

ostream &operator<<(ostream &os, const Szemely &szemely) {
    szemely.print(os);
    return os;
}
