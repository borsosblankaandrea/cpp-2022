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

double Polynomial::operator[](int index) const {
    if (index > capacity) {
        throw out_of_range("Index out of range");
    }
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    for (int i = 0; i < a.capacity; ++i) {
        a.coefficients[i] *= -1;
    }
    Polynomial temp(a.capacity - 1, a.coefficients);
    return temp;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    double degree, *array;
    if (a.capacity > b.capacity) {
        array = a.coefficients;
        degree = a.degree();

        for (int i = 0; i < b.capacity; ++i) {
            array[b.capacity - i] += b.coefficients[b.capacity - i - 1];
        }
    }
    else {
        array = b.coefficients;
        degree = b.degree();

        for (int i = 0; i < a.capacity; ++i) {
            array[a.capacity - i] += a.coefficients[a.capacity - i - 1];
        }
    }
    Polynomial temp(degree, array);
    return temp;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    double degree, *array;
    if (a.capacity > b.capacity) {
        array = a.coefficients;
        degree = a.degree();
        for (int i = 0; i < b.capacity; ++i) {
            array[b.capacity - i] -= b.coefficients[b.capacity - i - 1];
        }
    }
    else {
        array = b.coefficients;
        degree = b.degree();

        for (int i = 0; i < a.capacity; ++i) {
            array[a.capacity - i] -= a.coefficients[a.capacity - i - 1];
        }
    }
    Polynomial temp(degree, array);
    return temp;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int capacity = a.capacity + b.capacity - 1;
    double *array = new double[capacity]{0};
    for (int i = a.capacity; i > 0; --i) {
        for (int j = b.capacity; j > 0; --j) {
            array[i + j - 2] = array[i + j - 2] + a.coefficients[i - 1] * b.coefficients[j - 1];
        }
    }
    Polynomial temp(capacity - 1, array);
    return temp;
}



