//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_VECTOR_H
#define LAB22_VECTOR_H

#include "Array.h"

class Vector: public Array{
public:

    Vector() {
        length = 0;
        data = nullptr;
    }

    template<typename T>
    explicit Vector(T value);

    template<typename T>
    Vector(int size, T * array);

    template<typename T>
    Vector(int RepeatOfValue, T value) ;

    Vector(Vector const &vector);

    void print() const override;
    double operator[](int iterator) const;
    void push_back(Object other) override;
    ~Vector() override;
};

#endif //LAB22_VECTOR_H
