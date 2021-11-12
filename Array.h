//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_ARRAY_H
#define LAB22_ARRAY_H
#include "Object.h"

class Array {
protected:
    Object * data = nullptr;
    int length = 0;
    void resizeOnce();
public:
    virtual void push_back(Object other) = 0;
    virtual void print() const = 0;
    void resize(int new_size);
    [[nodiscard]] int Length() const;
    virtual ~Array() = 0;
};

#endif //LAB22_ARRAY_H
