//
// Created by ASUS on 2022. 10. 26..
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree+1;
    this->coefficients = new double[capacity];
    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double [this->capacity];

    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity;
    this->coefficients = that.coefficients;

    that.capacity = 0;
    that.coefficients = nullptr;
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    for (int i = 0; i < what.capacity-1; ++i) {
        out << what.coefficients[i] << "x^" << (what.capacity-1-i) << "+";
    }
    out << what.coefficients[what.capacity - 1] << endl;
    return out;
}

Polynomial::~Polynomial() {
    if(coefficients != nullptr){
        delete[] coefficients;
        capacity = 0;
    }
}

double Polynomial::evaluate(double x) const {
    double P = coefficients[0];
    for (int i = 1; i < capacity; ++i) {
        P = P * x + coefficients[i];
    }
    return P;
}

Polynomial Polynomial::derivative() const {
    double coeffs[this->capacity - 1];
    Polynomial der(this->degree() - 1, coeffs);
    int n = this->degree();
    for (int i = 0; i <= n - 1; ++i) {
        der.coefficients[i] = this->coefficients[i]*(n-i);
    }

    return der;
}


