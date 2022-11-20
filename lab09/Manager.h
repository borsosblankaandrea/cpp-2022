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
    //static const string MANAGER_MUNKAKOR;
    Manager(const string &firstName, const string &lastName, int birthYear, const string &munkakor);
    void addAlkalmazott(Alkalmazott *alkalmazott);
    void deleteAlkalmazott(int id);
    int beosztottakSzama() const;
    void print(ostream &os) const override;

private:
    vector<Alkalmazott*> beosztottak;
};

#endif //CPP_2022_MANAGER_H
