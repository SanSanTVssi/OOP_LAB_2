//
// Created by AAI2002 on 20.11.2021.
//

#ifndef LAB22_ARRAYOFSTRING_H
#define LAB22_ARRAYOFSTRING_H

#include "Array.h"
#include "String.h"

class arrayOfstring : public Array{
private:
    String * data;

    void resizeOnce();
public:

    arrayOfstring(): Array(), data(nullptr) {}

    explicit arrayOfstring (String & value);

    void push_back(Boost::Any val) override;

    void push_back(String & value);

    void scans() override;

    void print() const override;

    void printType() const override;

    String operator[](int index);

    void resize(int new_size) override;

    [[nodiscard]] IArray *Clone() const override;

    ~arrayOfstring() override;
};


#endif //LAB22_ARRAYOFSTRING_H
