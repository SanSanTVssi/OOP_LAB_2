//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_ARRAY_H
#define LAB22_ARRAY_H
#include "Any.h"
#include "intrerfaces.h"

class Array: IArray, IOutput, IInput, IType{
protected:
    int length;
public:
    Array(): length(0) {}
    void push_back(Boost::Any other) override = 0;
    void print() const override = 0;
    void scans() override = 0;
    void printType() const override = 0;
    void resize(int) override = 0;
    [[nodiscard]] int Length() const override {return length;};
    ~Array() override = 0;
};


#endif //LAB22_ARRAY_H
