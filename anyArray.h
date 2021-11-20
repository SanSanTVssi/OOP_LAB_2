//
// Created by AAI2002 on 20.11.2021.
//

#ifndef LAB22_ANYARRAY_H
#define LAB22_ANYARRAY_H

#include "Array.h"
#include "String.h"

class anyArray : public Array {
private:
    Array **data;

    void resizeOnce();

public:

    anyArray() : Array(), data(nullptr) {}

    explicit anyArray(Array *value);

    void push_back(Boost::Any val) override;

    void push_back(Array *value);

    void scans() override;

    void print() const override;

    void printType() const override;

    Array *operator[](int index);

    void resize(int new_size) override;

    [[nodiscard]] IArray *Clone() const override;

    ~anyArray() override;
};


#endif //LAB22_ANYARRAY_H
