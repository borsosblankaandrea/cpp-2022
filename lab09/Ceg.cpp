//
// Created by ASUS on 2022. 11. 20..
//

#include "Ceg.h"

Ceg::Ceg(const string &nev) : nev(nev) {}

void Ceg::addBeosztott(Alkalmazott *alkalmazott) {
    this->beosztottak.emplace_back(alkalmazott);
}

void Ceg::addBeosztott(Manager *manager) {
    this->beosztottak.emplace_back(manager);
}

void Ceg::deleteBeosztott(int id) {
    for (int i = 0; i < beosztottak.size(); ++i) {
        if( beosztottak[i]->getID() == id){
            beosztottak.erase(beosztottak.begin()+1);
        }
    }
}

void Ceg::printAll(ostream &os) {
    for( auto b: beosztottak){
        b->print(os);
    }

}

void Ceg::printManager(ostream &os) {
    for( auto m: beosztottak){
        m->print(os);
    }

}

/// Kedves David segitsegevel
void Ceg::addToManager(Manager *to, int id) {
    for(auto m : beosztottak){
        auto *manager = dynamic_cast<Manager*>(m);  //manager
        if((manager != nullptr) && (manager == to)) {
            for(auto e : beosztottak){
                if(e->getID() == id)
                    manager->addAlkalmazott(e);
            }
        }
    }
}

void Ceg::removeFromManager(Manager *from, int id) {
    for(auto m : beosztottak){
        auto *manager = dynamic_cast<Manager*>(m);  //manager
        if((manager != nullptr) && (manager == from)) {
            manager->deleteAlkalmazott(id);
        }
    }
}
