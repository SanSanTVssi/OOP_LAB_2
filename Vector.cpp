//
// Created by AAI2002 on 12.11.2021.
//

#include "Vector.h"

void Vector::print() const {
    for (int i = 0; i < length; ++i) {
        std::cout << data[i].getDecimal() << "\t";
    }
    std::cout << std::endl;
}

double Vector::operator[](int iterator) const {
    return data[iterator].getDecimal();
}

Vector::~Vector() {
    delete[] data;
    length = 0;
}

void Vector::scan() {
    std::string temp = std::string();
    std::cin >> temp;
    push_back(stod(temp));
    std::cin.clear();
}

void Vector::printType() const {
    std::string type;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if (data[i].type() != data[j].type()) {
                std::cout << "different[" << length << "]" << std::endl;
                return;
            }
        }
    }
    std::cout << data[0].type() << "[" << length << "]" << std::endl;
}

void Vector::scans() {
    std::string temp = std::string();
    do {
        std::cin >> temp;
        push_back(stod(temp));
    } while(std::cin.get() != '\n');
    std::cin.clear();
}
