//
// Created by AAI2002 on 12.11.2021.
//

#include "Array.h"

Array::~Array() = default;

void Array::resize(int new_size) {
    if (data == nullptr) {
        length = new_size;
        data = new Object[length];
        for (int i = 0; i < length; ++i) {
            data[i] = 0;
        }
    }
    if (new_size > length) {
        for (int i = length; i < new_size; ++i) {
            push_back(0);
        }
    }
    else if (new_size < length) {
        auto *newArr = new Object[new_size];
        for (int i = 0; i < new_size; ++i) {
            newArr[i] = data[i];
        }
        delete[] data;
        data = newArr;
        length = new_size;
    }
}

void Array::resizeOnce() {
    if (data == nullptr) {
        data = new Object[++length];
    }
    else {
        data = (Object*) realloc (data, ++length * sizeof(Object));
    }
}

void Array::push_back(Object other) {
    resizeOnce();
    data[length - 1] = other;
}
