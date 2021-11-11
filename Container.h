//
// Created by AAI2002 on 10.11.2021.
//

#ifndef LAB22_CONTAINER_H
#define LAB22_CONTAINER_H

#include <iostream>

template <class Type>
class Container {
protected:
    Type Value;
public:
    virtual std::string getString() { return {}; };
    //Container() = delete;
    //Container(const Container&) = delete;
    virtual std::string getVector() { }
    virtual void printInfo() { }
    virtual void getSize() { }
    virtual void resize(unsigned int size) { }
    virtual void push_back(Type const&) { }
    virtual ~Container() { }
};


#endif //LAB22_CONTAINER_H
