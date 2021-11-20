//
// Created by AAI2002 on 20.11.2021.
//

#include "anyArray.h"

void anyArray::resizeOnce() {
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

anyArray::anyArray(Array *value) : Array(), data(nullptr) {
    anyArray::push_back(value);
}

void anyArray::push_back(Boost::Any val) {
    auto * temp = new String('\0');
    push_back(temp);
}

void anyArray::push_back(Array *value) {
    if (value != this) {
        resizeOnce();
        IArray* newArr = value->Clone();
        data[length - 1] = dynamic_cast<Array *>(newArr);
    }
    else {
        std::cout << "Exception! You cannot add add an object to itself!" << std::endl;
    }
}

void anyArray::scans() {
    auto * temp = new String();
    temp->scans();
    push_back(temp);
}

void anyArray::print() const {
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

void anyArray::printType() const {
    std::cout << "anyArray[" << length << "]" << std::endl;
}

Array *anyArray::operator[](int index) {
    return data[index];
}

void anyArray::resize(int new_size) {
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

IArray *anyArray::Clone() const {
    auto * temp = new anyArray();
    for (int i = 0; i < length; ++i) {
        temp->push_back(data[i]);
    }
    return temp;
}

anyArray::~anyArray() {
    delete[] data;
}
