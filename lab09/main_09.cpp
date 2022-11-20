#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

int main() {
//    Szemely szemely1("Kiss", "Sanyi", 1988);
//    Szemely szemely2("Nagy", "Attila", 2004);
//    szemely1.print(cout);
//    cout << endl << szemely1 << endl << szemely2 << endl;
//
//    Alkalmazott alkalmazott1("Harry", "Potter", 1980, "Diak");
//    cout << alkalmazott1;
//
 //   Manager manager1("Fekete", "Zoli", 1995, "Tanar");
//    cout << manager1 << endl;
//    //manager1.addAlkalmazott(&alkalmazott1);

    Ceg company("Company");
    Manager m1("Manager", "Peti", 1978, "Elado");
    Alkalmazott a1("Nagy", "Attila", 1966, "valami");
    Alkalmazott a2("Kiss", "Sany", 1984, "valami");

    Manager m2("Manager", "Kati", 1981, "valami");
    Alkalmazott a3("Szabo", "Janos", 1965, "valami");
    Alkalmazott a4("Kovacs", "Iren", 1994, "valami");

    company.addBeosztott(&m1);
    company.addBeosztott(&a1);
    company.addBeosztott(&a2);
    company.addBeosztott(&m2);
    company.addBeosztott(&a3);
    company.addBeosztott(&a4);

    //company.printAll(cout);

    m1.addAlkalmazott(&a1);
    m1.addAlkalmazott(&a2);
    m2.addAlkalmazott(&a1);
    m2.addAlkalmazott(&a2);

    //company.printManager(cout);

    company.removeFromManager(&m1, 2);
    company.addToManager(&m2, 2);

    company.printManager(cout);
    return 0;
}