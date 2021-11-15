//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_ARRAY_H
#define LAB22_ARRAY_H
#include "Object.h"
#define interface class

interface IArray {
    virtual void push_back(Object other) = 0;
    virtual void print() const = 0;
    virtual void resize(int) = 0;
    [[nodiscard]] virtual int Length() const = 0;
};

interface IConsoleIO {
    virtual void print() const = 0;
    virtual void scan() = 0;
    virtual void scans() = 0;
    virtual void printType() const = 0;
};

class Array: IArray, IConsoleIO {
protected:
    Object * data;
    int length;
    void resizeOnce();
public:
    Array(): data(nullptr), length(0) {}
    void push_back(Object other) override;
    void print() const override = 0;
    void scan() override = 0;
    void scans() override = 0;
    void printType() const override = 0;
    void resize(int) override;
    [[nodiscard]] int Length() const override {return length;};
    virtual ~Array() = 0;
};

#endif //LAB22_ARRAY_H
