//
// Created by AAI2002 on 20.11.2021.
//

#ifndef LAB22_ARRAYOFVECTOR_H
#define LAB22_ARRAYOFVECTOR_H

#include "Array.h"
#include "Vector.h"

template <typename T>
class arrayOfVector : public Array{
private:
    Vector<T> * data;

    void resizeOnce() {
        if (data == nullptr) {
            data = new Vector<T>[++length];
        }
        else {
            auto * newarr = new Vector<T>[++length];
            for (int i = 0; i < length - 1; ++i) {
                newarr[i] = data[i];
            }
            delete[] data;
            data = newarr;
        }
    }
public:

    explicit arrayOfVector (Vector<T> & value) : data(nullptr) {
        push_back(value);
    }

    void push_back(Boost::Any val) override {
        Vector<T> temp = Vector<T>(val);
        push_back(temp);
    }

    void push_back(Vector<T> & value) {
        resizeOnce();
        data[length - 1] = value;
    }

    void scans() override {
        Vector<T> temp = Vector<T>();
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

    Vector<T> operator[](int index) {
        return data[index];
    }

    void resize(int new_size) override {
        if (data == nullptr) {
            length = new_size;
            data = new Vector<T>[length];
            for (int i = 0; i < length; ++i) {
                Vector<T> temp = Vector<T>('\0');
                data[i] = temp;
            }
        }
        if (new_size > length) {
            for (int i = length; i < new_size; ++i) {
                Vector<T> temp = Vector<T>('\0');
                push_back(temp);
            }
        }
        else if (new_size < length) {
            auto *newArr = new Vector<T>[new_size];
            for (int i = 0; i < new_size; ++i) {
                newArr[i] = data[i];
            }
            delete[] data;
            data = newArr;
            length = new_size;
        }
    }

    ~arrayOfVector() override{
        delete[] data;
    }
};


#endif //LAB22_ARRAYOFVECTOR_H
