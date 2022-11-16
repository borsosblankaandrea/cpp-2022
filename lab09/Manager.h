//
// Created by ASUS on 2022. 11. 16..
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H

#include <ostream>
#include <vector>
#include "Alkalmazott.h"

using namespace std;

class Manager: public Alkalmazott{
public:
    Manager(const string &firstName, const string &lastName, int birthYear, const string &munkakor);
    void addAlkalmazott(Alkalmazott *alkalmazott);
    void deleteAlkalmazott(Alkalmazott *alkalmazott);
    int beosztottakSzama();
    virtual void print(ostream &os) const;

private:
    vector<Alkalmazott*> beosztottak;
};

#endif //CPP_2022_MANAGER_H
