//
// Created by ASUS on 2022. 10. 19..
//

#ifndef CPP_2022_MATRIX_H
#define CPP_2022_MATRIX_H

#include <iostream>
#include <stdexcept>

using namespace std;
class Matrix {
public:
//Methods
    Matrix( int mRows = 10, int mCols =10);
    Matrix(const Matrix& what); // copy constructor
    Matrix( Matrix&& what ); // move constructor
    ~Matrix();
    void fillMatrix(double value);
    void printMatrix(ostream& os = cout) const;
    void randomMatrix(int a, int b);

    bool isSquare() const;
    int getRows() const;
    int getCols() const;

    friend Matrix operator+(const Matrix& x, const Matrix& y);
    friend Matrix operator*(const Matrix& x, const Matrix& y);

private:
//Data
    double ** mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};


#endif //CPP_2022_MATRIX_H
