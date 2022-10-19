#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix m1(3,3);
    m1.fillMatrix(10);
    m1.printMatrix();

    cout << endl;

    Matrix m2(3,3);
    m2.randomMatrix(1,10);
    m2.printMatrix();

    if(m2.isSquare() == 1) cout << "It is a square!" << endl;
    else cout << "It is not a square!" << endl;
    cout << "Rows: " << m2.getRows() << endl;
    cout << "Columns: " << m2.getCols() << endl << endl;

    try {
        cout << "Matrix m3 = m1 + m2: " << endl;
        Matrix m3 = (m1 + m2);
        cout << "m3 = " << endl;
        m3.printMatrix();
        cout << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}