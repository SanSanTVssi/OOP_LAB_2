//
// Created by aai2002 on 14.09.2021.
//

#include <sstream>
#include "VECTOR.h"

std::ostream &operator<<(std::ostream &out, const VECTOR &vector) {
    return out << vector.Value;
}

std::string VECTOR::getString() {
    return std::to_string(Value);
}

VECTOR::~VECTOR() {

}
