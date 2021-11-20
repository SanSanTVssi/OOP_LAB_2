#include <iostream>
#include "Vector.h"
#include "String.h"
#include "boolArray.h"
#include "arrayOfarrays.h"

void Foo(Array* arr) {
//    int x = 65;
//    for (int i = 0; i < 4; ++i) {
//        arr->push_back(x++);
//    }
//    arr->push_back("string");
//    arr->push_back(true);
    arr->resize(7);
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
    auto instance3 = boolArray(true);

    auto instance11 = arrayOfarrays(instance1);
    auto instance12 = arrayOfarrays(instance2);
    auto instance13 = arrayOfarrays(instance3);

    std::cout << "VectorArray" << std::endl;
    std::cout << "=========================" << std::endl;
    Foo(&instance11);
    std::cout << "StringArray" << std::endl;
    std::cout << "=========================" << std::endl;
    Foo(&instance12);
    std::cout << "boolArrayArray" << std::endl;
    std::cout << "=========================" << std::endl;
    Foo(&instance13);

    std::cout << "Vector" << std::endl;
    std::cout << "=========================" << std::endl;
    Foo(&instance1);
    std::cout << "String" << std::endl;
    std::cout << "=========================" << std::endl;
    Foo(&instance2);
    std::cout << "boolArray" << std::endl;
    std::cout << "=========================" << std::endl;
    Foo(&instance3);

//    Vector instance4 = instance1.Clone();
//    std::cout << "Cloning Array" << std::endl;
//    std::cout << "=========================" << std::endl;
//    instance1.resize(7);
//    instance1.print();
//    std::cout << "=========================" << std::endl;
//    instance4.print();
//    std::cout << "=========================" << std::endl;
//    (instance1 + instance4).print();
//    (instance2 + "string2").print();
//    boolArray instance5 = instance3;
//    instance5.resize(3);
//    instance3.push_back(true);
//    instance3.push_back(true);
//    instance5.push_back(false);
//    instance3.print();
//    (instance3 + instance5).print();


    return 0;
}
