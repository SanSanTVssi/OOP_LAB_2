//
// Created by AAI2002 on 19.11.2021.
//

#ifndef LAB22_INTRERFACES_H
#define LAB22_INTRERFACES_H

#include "Any.h"
#include <iostream>

class IArray {
public:
    virtual void push_back(Boost::Any other) = 0;
    virtual void resize(int) = 0;
    [[nodiscard]] virtual int Length() const = 0;
    virtual ~IArray() = 0;
};

class IInputOutput {
public:
    virtual void print() const = 0;
    virtual void scans() = 0;
    virtual void printType() const = 0;
    virtual ~IInputOutput() = 0;
};

class ICloning{
public:
    [[nodiscard]] virtual IArray *Clone() const = 0;
    virtual ~ICloning() = 0;
};

#endif //LAB22_INTRERFACES_H
