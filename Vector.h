//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_VECTOR_H
#define LAB22_VECTOR_H

#include "Array.h"

class Vector: public Array {
public:

    Vector() : Array() { }

    template<typename T>
    explicit Vector(T value) : Array() {
        Vector::push_back(static_cast<double>(value));
    }

    template<typename T>
    Vector(int size, T * array) : Array() {
        for (int i = 0; i < size; ++i) {
            Vector::push_back(static_cast<double>(array[i]));
        }
    }

    template<typename T>
    Vector(int RepeatOfValue, T value) : Array() {
        for (int i = 0; i < RepeatOfValue; ++i) {
            Vector::push_back(static_cast<double>(value));
        }
    }

    Vector(Vector const &vector) : Array() {
        for (int i = 0; i < vector.Length(); ++i) {
            Vector::push_back(vector[i]);
        }
    }

    void print() const override;
    void scan() override;
    void scans() override;
    void printType() const override;
    double operator[](int iterator) const;
    [[nodiscard]] Vector getElementInVector(int index) const;
};

#endif //LAB22_VECTOR_H
