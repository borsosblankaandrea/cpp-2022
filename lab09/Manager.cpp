//
// Created by ASUS on 2022. 11. 16..
//

#include "Manager.h"

Manager::Manager(const string &firstName, const string &lastName, int birthYear, const string &munkakor) : Alkalmazott(
        firstName, lastName, birthYear, munkakor) {}

void Manager::print(ostream &os) const {
    Alkalmazott::print(os);
}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    beosztottak.emplace_back(alkalmazott);
}

void Manager::deleteAlkalmazott(Alkalmazott *alkalmazott) {
    remove(beosztottak.begin(), beosztottak.end(), alkalmazott);
}

int Manager::beosztottakSzama() {
    return beosztottak.size();
}

