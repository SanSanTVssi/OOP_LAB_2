//
// Created by AAI2002 on 20.11.2021.
//

#ifndef LAB22_ARRAYOFBOOLARRAY_H
#define LAB22_ARRAYOFBOOLARRAY_H

#include "Array.h"
#include "boolArray.h"

class arrayOfboolArray : public Array {
private:
    boolArray * data;

    void resizeOnce();
public:

    arrayOfboolArray() : Array(), data(nullptr) { }

    explicit arrayOfboolArray (boolArray & value);

    void push_back(Boost::Any val) override;

    void push_back(boolArray & value);

    void scans() override;

    void print() const override;

    void printType() const override;

    boolArray operator[](int index);

    void resize(int new_size) override;

    [[nodiscard]] IArray *Clone() const override;

    ~arrayOfboolArray() override;
};


#endif //LAB22_ARRAYOFBOOLARRAY_H
