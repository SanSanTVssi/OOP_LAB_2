//
// Created by AAI2002 on 19.11.2021.
//

#ifndef LAB22_ARRAYARRAY_H
#define LAB22_ARRAYARRAY_H

#include "Array.h"

class ArrayArray : Array {
private:
    Array * data;

public:
    ArrayArray (Array * data) :Array() {

    }

    void push_back(Boost::Any other) override {

    }

    void push_back(Array * data) {

    }

};


#endif //LAB22_ARRAYARRAY_H
