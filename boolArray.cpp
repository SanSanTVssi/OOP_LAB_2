//
// Created by AAI2002 on 16.11.2021.
//

#include "boolArray.h"

boolArray::boolArray(Boost::Any value) {
    boolArray::push_back(value);
}

boolArray::boolArray(int size, const bool *array) {
    for (int i = 0; i < size; ++i) {
        boolArray::push_back(array[i]);
    }
}

boolArray::boolArray(int RepeatOfValue, Boost::Any value) {
    for (int i = 0; i < RepeatOfValue; ++i) {
        boolArray::push_back(value);
    }
}

void boolArray::push_back(Boost::Any value) {
    resizeOnce();
    data[length - 1] = Boost::any_cast<bool>(value);
}

void boolArray::resize(int new_size) {
    if (data == nullptr) {
        length = new_size;
        data = new bool[length];
        for (int i = 0; i < length; ++i) {
            data[i] = false;
        }
    }
    if (new_size > length) {
        for (int i = length; i < new_size; ++i) {
            push_back(false);
        }
    }
    else if (new_size < length) {
        auto *newArr = new bool[new_size];
        for (int i = 0; i < new_size; ++i) {
            newArr[i] = data[i];
        }
        delete[] data;
        data = newArr;
        length = new_size;
    }
}

boolArray boolArray::operator+(const boolArray &other) {
    boolArray result = boolArray();

    for (int i = 0; i < std::min(length, other.Length()); ++i) {
        if (data[i] + other[i] != 1) {
            result.push_back(0);
        }
        else {
            result.push_back(1);
        }
    }

    for (int i = 0; i < std::max(length, other.Length()) - std::min(length, other.Length()); ++i) {
        result.push_back(false);
    }
    return result;
}

void boolArray::print() const {
    for (int i = 0; i < length; ++i) {
        std::cout << data[i] << "\t";
    }
    std::cout << std::endl;
}

void boolArray::scans() {
    std::string temp = std::string();
    do {
        std::cin >> temp;
        bool x;
        try {
            x = std::stod(temp);
        }
        catch (std::exception& exception) {
            std::cout << "Exception!" << exception.what() << std::endl;
        }
    } while(std::cin.get() != '\n');
    std::cin.clear();
}

void boolArray::printType() const {
    std::cout  << "bool[" << length << "]" << std::endl;
}

bool boolArray::operator[](int iterator) const {
    return data[iterator];
}

boolArray boolArray::getElementInBoolArr(int index) const {
    return boolArray(data[index]);
}

void boolArray::resizeOnce() {
    if (data == nullptr) {
        data = new bool[++length];
    } else {
        data = (bool *) realloc(data, ++length * sizeof(bool));
    }
}

boolArray &boolArray::operator=(boolArray &other) {
    for (int i = 0; i < other.Length(); ++i) {
        this->push_back(other[i]);
    }
    return *this;
}

boolArray::~boolArray() {
    delete[] data;
}

IArray *boolArray::Clone() const {
    boolArray * temp = new boolArray();
    for (int i = 0; i < length; ++i) {
        temp->push_back(data[i]);
    }
    return temp;
}
