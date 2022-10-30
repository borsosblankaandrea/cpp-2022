#include <iostream>
#include "Polynomial.h"
int main() {
//    double coef[]{1,2,1};
//    Polynomial p1(2,coef);
//    cout <<"p1: " << p1;
//
//    cout << "Degree(p1): " << p1.degree() << endl;
//
//    cout << "Evaluate(p1): " <<p1.evaluate(1) << endl;
//
//
//    cout << "Derivate(p1): " << p1.derivative();
//

    double c[] = {1, 2, 3, 4, 5, 6};
    Polynomial p(5, c);

    double c2[] = {5, 4, 3, 2, 1};
    Polynomial q(4, c2);

    cout << "p(x)=" << p;
    cout << "q(x)=" << q << endl;
    cout << "p(x)'=" << p.derivative();
    cout << "-p(x) = " << -p;
    cout << "p(x) + q(x) " << p + q;
    cout << "p(x) - q(x) = " << p - q;
    cout << "p(x) * q(x) = " << p * q;

    return 0;
}