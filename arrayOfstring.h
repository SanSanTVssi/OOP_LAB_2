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

    void resizeOnce() {
        if (data == nullptr) {
            data = new String[++length];
        }
        else {
            auto * newarr = new String[++length];
            for (int i = 0; i < length - 1; ++i) {
                newarr[i] = data[i];
            }
            delete[] data;
            data = newarr;
        }
    }
public:

    explicit arrayOfstring (String & value) : data(nullptr) {
        push_back(value);
    }

    void push_back(Boost::Any val) override {
        String temp = String(val);
        push_back(temp);
    }

    void push_back(String & value) {
        resizeOnce();
        data[length - 1] = value;
    }

    void scans() override {
        String temp = String();
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

    String operator[](int index) {
        return data[index];
    }

    void resize(int new_size) override {
        if (data == nullptr) {
            length = new_size;
            data = new String[length];
            for (int i = 0; i < length; ++i) {
                String temp = String('\0');
                data[i] = temp;
            }
        }
        if (new_size > length) {
            for (int i = length; i < new_size; ++i) {
                String temp = String('\0');
                push_back(temp);
            }
        }
        else if (new_size < length) {
            auto *newArr = new String[new_size];
            for (int i = 0; i < new_size; ++i) {
                newArr[i] = data[i];
            }
            delete[] data;
            data = newArr;
            length = new_size;
        }
    }

    ~arrayOfstring() override{
        delete[] data;
    }
};


#endif //LAB22_ARRAYOFSTRING_H
