//
// Created by aai2002 on 14.09.2021.
//

#ifndef LAB1_COMPLEX_H
#define LAB1_COMPLEX_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include "Container.h"

class VECTOR :public Container<double>  {
public:
    VECTOR()  {Value = 0; }
    VECTOR(double value) {Value = value;}
    VECTOR(VECTOR const &) = default;
    //explicit VECTOR (const std::string&);

    //> Assignment operators
    friend std::ostream& operator<<(std::ostream& out, const VECTOR &);
    VECTOR& operator= (const VECTOR &) = default;

    std::string getString() override;

    ~VECTOR() override;
};



#endif //LAB1_COMPLEX_H
