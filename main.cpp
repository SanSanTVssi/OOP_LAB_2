#include <iostream>
#include "Vector.h"
#include "String.h"

void Foo(Array* arr) {
    int x = 65;
    for (int i = 0; i < 4; ++i) {
        arr->push_back(x++);
    }
    arr->push_back("string");
    arr->print();
    arr->resize(26);
    std::cout << "=========================" << std::endl;
    arr->scans();
    arr->print();
    std::cout << arr->Length() << std::endl;
    arr->printType();
}

int main()
{
    double ArrforInstance[2] {1.1, 1.2};
    auto instance1 = Vector(2, ArrforInstance);
    instance1.printType();
    auto instance2 = String("in");
//    auto instance3 = boolArray(false);
    Foo(&instance1);
    Foo(&instance2);
//    Foo(&instance3);
    Vector instance4 = Vector(instance1);
    std::cout << "Cloning Array" << std::endl;
    std::cout << "=========================" << std::endl;
    instance1.resize(7);
    instance1.print();
    std::cout << "=========================" << std::endl;
    instance4.print();
    std::cout << "=========================" << std::endl;
    (instance1 + instance4).print();
}
