//
// Created by AAI2002 on 16.11.2021.
//

#ifndef LAB22_BOOLARRAY_H
#define LAB22_BOOLARRAY_H

#include "Array.h"

class boolArray : public Array{
private:
    bool *data = nullptr;

    void resizeOnce();

public:
    boolArray() : Array() {}

    explicit boolArray(Boost::Any);

    boolArray(int, const bool *);

    boolArray(int, Boost::Any);

    boolArray(boolArray const &);

    void push_back(Boost::Any) override;

    void resize(int) override;

    boolArray operator+(const boolArray &);

    void print() const override;

    void scans() override;

    void printType() const override;

    bool operator[](int) const;

    [[nodiscard]] boolArray getElementInBoolArr(int) const;
};


#endif //LAB22_BOOLARRAY_H
