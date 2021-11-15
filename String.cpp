//
// Created by AAI2002 on 12.11.2021.
//

#include "String.h"

void String::print() const {
    for (int i = 0; i < length; ++i) {
        std::cout << data[i].get<char>();
    }
    std::cout << std::endl;
}

void String::scan() {
    std::string temp = std::string();
    std::cin >> temp;
    for (char i : temp) {
        push_back(i);
    }
    std::cin.clear();
}

void String::scans() {
    std::string temp = std::string();
    do {
        std::cin >> temp;
        for (char i : temp) {
            push_back(i);
        }
    } while(std::cin.get() != '\n');
    std::cin.clear();
}

void String::printType() const {
    std::cout << "char[" << length << "]" << std::endl;
}

double String::operator[](int iterator) const {
    return data[iterator].get<char>();
}

String::~String() {

}
