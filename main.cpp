#include <iostream>
#include <memory>
#include "Vector.h"


void Foo(Array* arr) {
    int x = 64;
    for (int i = 0; i < 4; ++i) {
        arr->push_back(x++);
    }
    arr->print();
    arr->resize(7);
    std::cout << "=========================" << std::endl;
    arr->print();
}

int main()
{
    float ArrforInstance[2] {1.1, 1.2};
    auto v = Vector();
    auto instance1 = Vector(2, ArrforInstance);
    Foo(&instance1);
    Vector instance2 = Vector(instance1);
    std::cout << "=========================" << std::endl;
    instance1.resize(3);
    instance1.print();
    std::cout << "=========================" << std::endl;
    instance2.print();
}
