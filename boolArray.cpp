//
// Created by AAI2002 on 15.11.2021.
//

#include "boolArray.h"

boolArray boolArray::getElementInVector(int index) const {
    return boolArray(data[index].get<bool>());
}

void boolArray::print() const {
    for (int i = 0; i < length; ++i) {
        std::cout << data[i].get<bool>() << "\t";
    }
    std::cout << std::endl;
}

void boolArray::scan() {
    std::string temp = std::string();
    std::cin >> temp;
    push_back(static_cast<bool>(stod(temp)));
    std::cin.clear();
}

void boolArray::scans() {
    std::string temp = std::string();
    do {
        std::cin >> temp;
        push_back(static_cast<bool>(stod(temp)));
    } while(std::cin.get() != '\n');
    std::cin.clear();
}

void boolArray::printType() const {
    std::cout << "bool[" << length << "]" << std::endl;
}

bool boolArray::operator[](int iterator) const {
    return data[iterator].get<bool>();
}
