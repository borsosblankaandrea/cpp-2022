#include <iostream>
#include "Polynomial.h"
int main() {
    double coef[]{1,2,1};
    Polynomial p1(2,coef);
    cout <<"p1: " << p1;

    cout << "Degree(p1): " << p1.degree() << endl;

    cout << "Evaluate(p1): " <<p1.evaluate(1) << endl;


    cout << "Derivate(p1): " << p1.derivative();
    return 0;
}