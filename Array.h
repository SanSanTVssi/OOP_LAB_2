//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_ARRAY_H
#define LAB22_ARRAY_H
#include "Any.h"

class IArray {
public:
    virtual void push_back(Boost::Any other) = 0;
    virtual Boost::Any getAny(int iterator) const = 0;
    virtual void resize(int) = 0;
    [[nodiscard]] virtual int Length() const = 0;
    virtual ~IArray() = 0;
};

class IInput {
public:
    virtual void print() const = 0;
};

class IOutput {
public:
    virtual void scans() = 0;
};

class IType {
    virtual void printType() const = 0;
};

class Array: Boost::Any, IArray, IOutput, IInput, IType{
protected:
    int length;
public:
    Array(): length(0) {}
    void push_back(Boost::Any other) override = 0;
    [[nodiscard]] Boost::Any getAny(int iterator) const override = 0;
    void print() const override = 0;
    void scans() override = 0;
    void printType() const override = 0;
    void resize(int) override = 0;
    [[nodiscard]] int Length() const override {return length;};
    ~Array() override = 0;
};


#endif //LAB22_ARRAY_H
