//
// Created by AAI2002 on 20.11.2021.
//

#ifndef LAB22_ANYARRAY_H
#define LAB22_ANYARRAY_H

#include "Array.h"
#include "String.h"

class anyArray: public Array {
private:
    Array* * data;

    void resizeOnce() {
        if (data == nullptr) {
            data = new Array*[++length];
        }
        else {
            auto * newarr = new Array*[++length];
            for (int i = 0; i < length - 1; ++i) {
                newarr[i] = data[i];
            }
            delete[] data;
            data = newarr;
        }
    }
public:

    anyArray(): Array(), data(nullptr) {}

    explicit anyArray (Array* value): Array(), data(nullptr) {
        push_back(value);
    }

    void push_back(Boost::Any val) override {
        auto * temp = new String('\0');
        push_back(temp);
    }

    void push_back(Array* value) {
        if (value != this) {
            resizeOnce();
            IArray* newArr = value->Clone();
            data[length - 1] = dynamic_cast<Array *>(newArr);
        }
        else {
            std::cout << "Exception! You cannot add add an object to itself!" << std::endl;
        }
    }

    void scans() override {
        auto * temp = new String();
        temp->scans();
        push_back(temp);
    }

    void print() const override {
        Array * temp;
        for (int i = 0; i < length; ++i) {
            temp = data[i];
            if (temp != nullptr) {
                temp->print();
            }
            else {
                std::cout << "nullptr" << std::endl;
            }
        }
    }

    void printType() const override {
        std::cout << "anyArray[" << length << "]" << std::endl;
    }

    Array* operator[](int index) {
        return data[index];
    }

    void resize(int new_size) override {
        if (data == nullptr) {
            length = new_size;
            data = new Array*[length];
            for (int i = 0; i < length; ++i) {
                data[i] = nullptr;
            }
        }
        if (new_size > length) {
            for (int i = length; i < new_size; ++i) {
                push_back(nullptr);
            }
        }
        else if (new_size < length) {
            auto *newArr = new Array*[new_size];
            for (int i = 0; i < new_size; ++i) {
                newArr[i] = data[i];
            }
            delete[] data;
            data = newArr;
            length = new_size;
        }
    }

    [[nodiscard]] IArray *Clone() const override {
        auto * temp = new anyArray();
        for (int i = 0; i < length; ++i) {
            temp->push_back(data[i]);
        }
        return temp;
    }

    ~anyArray() override{
        delete[] data;
    }
};


#endif //LAB22_ANYARRAY_H
