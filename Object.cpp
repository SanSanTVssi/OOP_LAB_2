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
