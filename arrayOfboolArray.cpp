//
// Created by AAI2002 on 20.11.2021.
//

#include "arrayOfboolArray.h"

void arrayOfboolArray::resizeOnce() {
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

arrayOfboolArray::arrayOfboolArray(boolArray &value) : Array(), data(nullptr){
    push_back(value);
}

void arrayOfboolArray::push_back(Boost::Any val) {
    boolArray temp = boolArray(val);
    push_back(temp);
}

void arrayOfboolArray::push_back(boolArray &value) {
    resizeOnce();
    data[length - 1] = value;
}

void arrayOfboolArray::scans() {
    boolArray temp = boolArray();
    temp.scans();
    push_back(temp);
}

void arrayOfboolArray::print() const {
    for (int i = 0; i < length; ++i) {
        data[i].print();
    }
}

void arrayOfboolArray::printType() const {
    std::cout << "boolArray[" << length << "]" << std::endl;
}

void arrayOfboolArray::resize(int new_size) {
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

IArray *arrayOfboolArray::Clone() const {
    arrayOfboolArray * temp = new arrayOfboolArray();
    for (int i = 0; i < length; ++i) {
        temp->push_back(data[i]);
    }
    return temp;
}

arrayOfboolArray::~arrayOfboolArray() {
    delete[] data;
}

boolArray arrayOfboolArray::operator[](int index) {
    return data[index];
}
