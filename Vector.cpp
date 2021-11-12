//
// Created by AAI2002 on 12.11.2021.
//

#include "Vector.h"

template<typename T>
Vector::Vector(T value) {
    Vector::push_back(static_cast<double>(value));
}

template<typename T>
Vector::Vector(int size, T *array) {
    for (int i = 0; i < size; ++i) {
        Vector::push_back(static_cast<double>(array[i]));
    }
}

template<typename T>
Vector::Vector(int RepeatOfValue, T value) {
    for (int i = 0; i < RepeatOfValue; ++i) {
        Vector::push_back(static_cast<double>(value));
    }
}

Vector::Vector(const Vector &vector) {
    for (int i = 0; i < vector.Length(); ++i) {
        Vector::push_back(vector[i]);
    }
}

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
