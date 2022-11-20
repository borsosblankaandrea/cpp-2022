//
// Created by ASUS on 2022. 11. 16..
//

#include "Manager.h"

Manager::Manager(const string &firstName, const string &lastName, int birthYear, const string &munkakor) : Alkalmazott(
        firstName, lastName, birthYear, munkakor) {}

void Manager::print(ostream &os) const {
    //os << MANAGER_MUNKAKOR << ' ';
    Alkalmazott::print(os);
    os << "\tAlkalmazottak: \n";
    for( auto b: beosztottak){
        os << '\t';
        b->print(os);
    }
}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    beosztottak.emplace_back(alkalmazott);
}

void Manager::deleteAlkalmazott(int id) {
    for (int i = 0; i < beosztottakSzama(); ++i) {
        if( beosztottak[i]->getID() == id){
            beosztottak.erase(beosztottak.begin()+1);
        }
    }
}

int Manager::beosztottakSzama() const{
    return beosztottak.size();
}

