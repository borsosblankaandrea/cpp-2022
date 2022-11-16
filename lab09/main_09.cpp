#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"

int main() {
    Szemely szemely1("Kiss", "Sanyi", 1988);
    Szemely szemely2("Nagy", "Attila", 2004);
    szemely1.print(cout);
    cout << endl << szemely1 << endl << szemely2 << endl;

    Alkalmazott alkalmazott1("Harry", "Potter", 1980, "Diak");
    cout << alkalmazott1;

    Manager manager1("Fekete", "Zoli", 1995, "Tanar");
    cout << manager1 << endl;
    //manager1.addAlkalmazott(&alkalmazott1);

    return 0;
}