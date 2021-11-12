//
// Created by AAI2002 on 12.11.2021.
//

#include "Object.h"

double Object::getDecimal() const {
    switch (_type) {
        case 'i': return value._integer;
        case 'f': return value._float;
        case 'd': return value._double;
        case 'c': return value._char;
        case 'b': return value._bool;
        default: return value._double;
    }
}

double Object::getDouble() const {
    if (_type == 'i') return value._double;
    else {
        std::cout << "Type of Object is not double! Function return \\0-symbol by default!" << std::endl;
    }
    return 0;
}

float Object::getFloat() const {
    if (_type == 'i') return value._float;
    else {
        std::cout << "Type of Object is not float! Function return \\0-symbol by default!" << std::endl;
    }
    return 0;
}

int Object::getInteger() const {
    if (_type == 'i') return value._integer;
    else {
        std::cout << "Type of Object is not integer! Function return \\0-symbol by default!" << std::endl;
    }
    return 0;
}

char Object::getCharacter() const {
    if (_type == 'c') return value._char;
    else {
        std::cout << "Type of Object is not bool! Function return \\0-symbol by default!" << std::endl;
    }
    return 0;
}

bool Object::getBoolean() const {
    if (_type == 'b') return value._bool;
    else {
        std::cout << "Type of Object is not bool! Function return false by default!" << std::endl;
    }
    return false;
}

std::string Object::type() const {
    switch (_type) {
        case 'i': return "int";
        case 'f': return "float";
        case 'd': return "double";
        case 'c': return "char";
        case 'b': return "bool";
        default: return "unknown type";
    }
}
