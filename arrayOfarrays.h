//
// Created by AAI2002 on 19.11.2021.
//

#ifndef LAB22_ARRAYOFARRAYS_H
#define LAB22_ARRAYOFARRAYS_H

#include "Array.h"
#include "Vector.h"
#include "String.h"
#include "boolArray.h"

template<typename TypeArray>
class arrayOfarrays : public Array {
private:
    TypeArray * data;

    void resizeOnce() {
        if (data == nullptr) {
            data = (TypeArray*) malloc(++length * sizeof(TypeArray));
        }
        else {
            data = (TypeArray*) realloc (data, ++length * sizeof(TypeArray));
        }
    }

public:
    explicit arrayOfarrays (TypeArray & value) : data(nullptr), Array()  {
       push_back(value);
    }

    void push_back(Boost::Any val) override {
        resizeOnce();
        data[length - 1] = TypeArray(val);
    }

    void push_back(TypeArray & value) {
        resizeOnce();
        data[length - 1] = value;
    }

    void scans() override {
        TypeArray temp = TypeArray();
        temp.scans();
        push_back(temp);
    }
    void print() const override {
        TypeArray temp;
        for (int i = 0; i < length; ++i) {
            temp = data[i];
            temp.print();
        }
    }
    void printType() const override {

    }

    TypeArray operator[](int index) {
        return data[index];
    }

    void resize(int new_size) override {
//        if (data == nullptr) {
//            resizeOnce();
//        }
//        if (new_size > length) {
//            for (int i = length; i < new_size; ++i) {
//            }
//        }
//        else if (new_size < length) {
////            auto *newArr = new TypeArray[new_size];
////            for (int i = 0; i < new_size; ++i) {
////                newArr[i] = data[i];
////            }
////            delete[] data;
////            data = newArr;
////            length = new_size;
//        }
    }

//    ~arrayOfarrays() override {
//        delete[] data;
//    }
};




#endif //LAB22_ARRAYOFARRAYS_H
