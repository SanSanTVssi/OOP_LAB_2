//
// Created by AAI2002 on 20.11.2021.
//

#include "arrayOfstring.h"

void arrayOfstring::resizeOnce() {
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

arrayOfstring::arrayOfstring(String &value) : Array(), data(nullptr){
    push_back(value);
}

void arrayOfstring::push_back(Boost::Any val) {
    String temp = String(val);
    push_back(temp);
}

void arrayOfstring::push_back(String &value) {
    resizeOnce();
    data[length - 1] = value;
}

void arrayOfstring::scans() {
    String temp = String();
    temp.scans();
    push_back(temp);
}

void arrayOfstring::print() const {
    for (int i = 0; i < length; ++i) {
        data[i].print();
    }
}

void arrayOfstring::printType() const {
    std::cout << "String[" << length << "]" << std::endl;
}

String arrayOfstring::operator[](int index) {
    return data[index];
}

void arrayOfstring::resize(int new_size) {
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

IArray *arrayOfstring::Clone() const {
    arrayOfstring *temp = new arrayOfstring();
    for (int i = 0; i < length; ++i) {
        temp->push_back(data[i]);
    }
    return temp;
}

arrayOfstring::~arrayOfstring() {
    delete[] data;
}
