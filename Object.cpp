//
// Created by AAI2002 on 12.11.2021.
//

#include "Object.h"

double Object::getDecimal() const {
    switch (_type) {
        case 'i': return _integer;
        case 'f': return _float;
        case 'd': return _double;
        case 'c': return _char;
        case 'b': return _bool;
        default: return _double;
    }
}

double Object::getDouble() const {
    if (_type == 'i') return _double;
    else {
        std::cout << "Type of Object is not double! Function return \\0-symbol by default!" << std::endl;
    }
    return 0;
}

float Object::getFloat() const {
    if (_type == 'i') return _float;
    else {
        std::cout << "Type of Object is not float! Function return \\0-symbol by default!" << std::endl;
    }
    return 0;
}

int Object::getInteger() const {
    if (_type == 'i') return _integer;
    else {
        std::cout << "Type of Object is not integer! Function return \\0-symbol by default!" << std::endl;
    }
    return 0;
}

char Object::getChar() const {
    if (_type == 'c') return _char;
    else {
        std::cout << "Type of Object is not bool! Function return \\0-symbol by default!" << std::endl;
    }
    return 0;
}

bool Object::getBoolean() const {
    if (_type == 'b') return _bool;
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
