//
// Created by ASUS on 2022. 10. 19..
//

#include <random>
#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols): mRows(mRows), mCols(mCols) {
    mElements = new double*[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what) { /// ?
    this->mRows = what.mRows;
    this->mCols = what.mCols;

    this->mElements = new double*[this->mRows];
    for (int i = 0; i < this->mRows; ++i) {
        this->mElements[i] = new double[this->mCols];
    }

    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) { /// ?
    this->mRows = what.mRows;
    this->mCols = what.mCols;

    for (int i = 0; i < this->mRows; ++i) {
            this->mElements[i] = what.mElements[i];
            what.mElements[i] = nullptr;
    }
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << ' ';
        }
        os << endl;
    }
}

void Matrix::randomMatrix(int a, int b) {

    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(a, b);
    //uniform_real_distribution<double> distrib(a, b);

    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = distrib(gen);
        }
    }
}


bool Matrix::isSquare() const {
    if(this->mRows == this->mCols) return 1;
    return 0;
}

int Matrix::getRows() const {
    return this->mRows;
}

int Matrix::getCols() const {
    return this->mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.getRows() != y.getRows() || x.getCols() != y.getCols()) {
        throw out_of_range("Out of range!");
    }

    Matrix temp(x.getRows(), x.getCols());
    for (int i = 0; i < temp.mRows; ++i) {
        for (int j = 0; j < temp.mCols; ++j) {
            temp.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return temp;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if(x.getRows() != y.getCols() || x.getCols() != y.getRows()){
        throw out_of_range("Out of range!");
    }

    Matrix temp(x.getRows(), x.getCols());
    for (int i = 0; i < temp.mRows; ++i) {
        for (int j = 0; j < temp.mCols; ++j) {
            for (int k = 0; k < x.mRows; ++k) {
                temp.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }
    return temp;
}

// 1 2 3   4 1 2 1
// 5 6 1   2 1 3 2
// 3 2 4   1 2 2 1
// 1 3 2

Matrix::~Matrix() {
    for (int i = 0; i < this->mRows; ++i) {
        delete[] this->mElements[i];
    }
    delete[] this->mElements;
    this->mElements = nullptr;
    this->mCols = 0;
    this->mRows = 0;
}





