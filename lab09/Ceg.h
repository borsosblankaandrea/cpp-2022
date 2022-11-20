//
// Created by ASUS on 2022. 11. 20..
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H

#include <vector>
#include "Alkalmazott.h"
#include "Manager.h"

using namespace std;

class Ceg{
public:
    Ceg(const string &nev);
    void addBeosztott(Alkalmazott *alkalmazott);
    void deleteBeosztott(int id);
    void addBeosztott(Manager *manager);

    void addToManager(Manager *from, int id);
    void removeFromManager(Manager *from, int id);

    void printAll(ostream &os);
    void printManager(ostream &os);

private:
    string nev;
    vector<Alkalmazott*> beosztottak;
};


#endif //CPP_2022_CEG_H
