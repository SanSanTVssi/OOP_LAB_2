//
// Created by AAI2002 on 15.11.2021.
//

#ifndef LAB22_BOOLARRAY_H
#define LAB22_BOOLARRAY_H

#include "Array.h"

class boolArray: public Array{
    boolArray() : Array() { }

    explicit boolArray(bool value) : Array() {
        boolArray::push_back(static_cast<double>(value));
    }

    boolArray(int size, const bool * array) : Array() {
        for (int i = 0; i < size; ++i) {
            boolArray::push_back(static_cast<double>(array[i]));
        }
    }

    boolArray(int RepeatOfValue, bool value) : Array() {
        for (int i = 0; i < RepeatOfValue; ++i) {
            boolArray::push_back(static_cast<double>(value));
        }
    }

    boolArray(boolArray const &boolArray) : Array() {
        for (int i = 0; i < boolArray.Length(); ++i) {
            boolArray::push_back(boolArray[i]);
        }
    }

    void print() const override;
    void scan() override;
    void scans() override;
    void printType() const override;
    bool operator[](int iterator) const;
    [[nodiscard]] boolArray getElementInVector(int index) const;
};


#endif //LAB22_BOOLARRAY_H
