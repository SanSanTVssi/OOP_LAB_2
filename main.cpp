#include <iostream>
#include "Vector.h"
#include "String.h"
#include "boolArray.h"

void Foo(Array* arr) {
    int x = 65;
    for (int i = 0; i < 4; ++i) {
        arr->push_back(x++);
    }
    arr->push_back("string");
    arr->push_back(true);
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
    auto instance2 = String("in");
    auto instance3 = boolArray(false);
    std::cout << "Vector" << std::endl;
    Foo(&instance1);
    std::cout << "String" << std::endl;
    Foo(&instance2);
    std::cout << "Bool Array" << std::endl;
    Foo(&instance3);
    Vector instance4 = Vector(instance1);
    std::cout << "Cloning Array" << std::endl;
    std::cout << "=========================" << std::endl;
    instance1.resize(7);
    instance1.print();
    std::cout << "=========================" << std::endl;
    instance4.print();
    std::cout << "=========================" << std::endl;
    (instance1 + instance4).print();
    (instance2 + "string2").print();
    boolArray instance5 = instance3;
    instance5.resize(3);
    instance3.push_back(true);
    instance3.push_back(true);
    instance5.push_back(false);

    instance3.print();
    (instance3 + instance5).print();
    return 0;
}
