//
// Created by AAI2002 on 12.11.2021.
//

#include "Vector.h"

void Vector::print() const {
    for (int i = 0; i < length; ++i) {
        std::cout << data[i].getDecimal() << "\t" << std::endl;
    }
}

double Vector::operator[](int iterator) const {
    return data[iterator].getDecimal();
}

void Vector::push_back(Object other) {
    resizeOnce();
    data[length - 1] = other;
}

Vector::~Vector() {
    delete[] data;
    length = 0;
}
