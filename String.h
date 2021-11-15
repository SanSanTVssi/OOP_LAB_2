//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_STRING_H
#define LAB22_STRING_H

#include "Array.h"

class String: public Array {
public:
    String() : Array() { }

    explicit String(char value) : Array() {
        String::push_back(value);
    }

    explicit String(const char * array) : Array() {
        for (int i = 0;array[i] != 0; ++i) {
            String::push_back(array[i]);
        }
    }

    String(int RepeatOfValue, char value) : Array() {
        for (int i = 0; i < RepeatOfValue; ++i) {
            String::push_back(value);
        }
    }

    String(String const &vector) : Array() {
        for (int i = 0; i < vector.Length(); ++i) {
            String::push_back(vector[i]);
        }
    }

    void print() const override;
    void scan() override;
    void scans() override;
    void printType() const override;
    double operator[](int iterator) const;
    ~String() override;
};


#endif //LAB22_STRING_H
