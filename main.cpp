#include <iostream>
#include <memory>
#include "Vector.h"
#include "String.h"


void Foo(Array* arr) {
    float x = 65;
    for (int i = 0; i < 4; ++i) {
        arr->push_back(x++);
    }
    arr->print();
    arr->resize(7);
    std::cout << "=========================" << std::endl;
    arr->scans();
    arr->print();
    std::cout << arr->Length() << std::endl;
    arr->printType();
}

int main()
{
    float ArrforInstance[2] {1.1, 1.2};
    auto instance1 = Vector(2, ArrforInstance);
    instance1.printType();
    auto instance2 = String("niger");
    Foo(&instance2);
    Foo(&instance1);
    Vector instance3 = Vector(instance1);
    std::cout << "=========================" << std::endl;
    instance1.resize(3);
    instance1.print();
    std::cout << "=========================" << std::endl;
    instance3.print();
}
