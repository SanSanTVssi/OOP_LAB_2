//
// Created by AAI2002 on 20.11.2021.
//

#ifndef LAB22_ARRAYOFBOOLARRAY_H
#define LAB22_ARRAYOFBOOLARRAY_H

#include "Array.h"
#include "boolArray.h"

class arrayOfboolArray : public Array {
private:
    boolArray * data;

    void resizeOnce() {
        if (data == nullptr) {
            data = new boolArray[++length];
        }
        else {
            auto * newarr = new boolArray[++length];
            for (int i = 0; i < length - 1; ++i) {
                newarr[i] = data[i];
            }
            delete[] data;
            data = newarr;
        }
    }
public:

    explicit arrayOfboolArray (boolArray & value) : data(nullptr) {
        push_back(value);
    }

    void push_back(Boost::Any val) override {
        boolArray temp = boolArray(val);
        push_back(temp);
    }

    void push_back(boolArray & value) {
        resizeOnce();
        data[length - 1] = value;
    }

    void scans() override {
        boolArray temp = boolArray();
        temp.scans();
        push_back(temp);
    }

    void print() const override {
        for (int i = 0; i < length; ++i) {
            data[i].print();
        }
    }
    void printType() const override {
        std::cout << "String[" << length << "]" << std::endl;
    }

    boolArray operator[](int index) {
        return data[index];
    }

    void resize(int new_size) override {
        if (data == nullptr) {
            length = new_size;
            data = new boolArray[length];
            for (int i = 0; i < length; ++i) {
                boolArray temp = boolArray('\0');
                data[i] = temp;
            }
        }
        if (new_size > length) {
            for (int i = length; i < new_size; ++i) {
                boolArray temp = boolArray('\0');
                push_back(temp);
            }
        }
        else if (new_size < length) {
            auto *newArr = new boolArray[new_size];
            for (int i = 0; i < new_size; ++i) {
                newArr[i] = data[i];
            }
            delete[] data;
            data = newArr;
            length = new_size;
        }
    }

    ~arrayOfboolArray() override{
        delete[] data;
    }
};


#endif //LAB22_ARRAYOFBOOLARRAY_H
