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

//    boolArray Clone() {
//        boolArray temp;
//        for (int i = 0; i < length; ++i) {
//            temp.push_back(this->data[i]);
//        }
//        return temp;
//    }
    [[nodiscard]] IArray *Clone() const override {
        boolArray * temp = new boolArray();
        for (int i = 0; i < length; ++i) {
            temp->push_back(data[i]);
        }
        return temp;
    }

    boolArray(int, const bool *);

    boolArray(int, Boost::Any);

    boolArray(boolArray const &) = default;

    void push_back(Boost::Any) override;

    void resize(int) override;

    boolArray operator+(const boolArray &);

    void print() const override;

    void scans() override;

    void printType() const override;

    bool operator[](int) const;

    [[nodiscard]] boolArray getElementInBoolArr(int) const;

    boolArray& operator=(boolArray& other) {
        for (int i = 0; i < other.Length(); ++i) {
            this->push_back(other[i]);
        }
        return *this;
    }

    ~boolArray() override {
        delete[] data;
    }
};


#endif //LAB22_BOOLARRAY_H
