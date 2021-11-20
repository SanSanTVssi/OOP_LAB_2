#include <iostream>
#include "Vector.h"
#include "String.h"
#include "boolArray.h"
#include "arrayOfstring.h"
#include "arrayOfboolArray.h"
#include "arrayOfVector.h"
#include "anyArray.h"

void demoIO(IInputOutput * io) {
    io->scans();
    io->print();
    io->printType();
}

void demoIArr(IArray * array) {
    int x = 65;
    for (int i = 0; i < 10; ++i) {
        array->push_back(x++);
    }
    array->push_back("string");
    array->push_back(true);
    array->resize(10);
}

void CloningDemo(Array * instance) {
    IArray *newIArray;
    newIArray = instance->Clone();
    auto * newArray = dynamic_cast<Array *>(newIArray);
    std::cout << "Incoming array:" << std::endl;
    dynamic_cast<Array *>(instance)->print();
    std::cout << "Copy of array:" << std::endl;
    newArray->print();
    newArray->resize(2);
    std::cout << "Resized array:" << std::endl;
    newArray->print();
}

void demo(Array* arr) {
    demoIArr(arr);
    demoIO(arr);
    CloningDemo(arr);
}

int main()
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~ Start ~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    double ArrforInstance[2] {1.1, 1.2};

    auto instance1 = Vector(2, ArrforInstance);
    auto instance2 = String("in");
    auto instance3 = boolArray(true);

    auto instance21 = arrayOfVector(instance1);
    auto instance22 = arrayOfstring(instance2);
    auto instance23 = arrayOfboolArray(instance3);

    std::cout << "============Vector============" << std::endl;
    demo(&instance1);
    std::cout << "============String============" << std::endl;
    demo(&instance2);
    std::cout << "============boolArray============" << std::endl;
    demo(&instance3);

    std::cout << "============VectorArray============" << std::endl;
    demo(&instance21);
    std::cout << "============StringArray============" << std::endl;
    demo(&instance22);
    std::cout << "============boolArrayArray============" << std::endl;
    demo(&instance23);

    std::cout << "============AnyVector============" << std::endl;
    auto instance31 = anyArray(&instance1);
    auto instance32 = anyArray(&instance1);
    instance31.push_back(&instance2);
    instance31.push_back(&instance3);
    instance31.push_back(&instance21);
    instance31.push_back(&instance22);
    instance31.push_back(&instance23);
    instance31.push_back(&instance31);
    instance31.push_back(&instance32);
    demo(&instance31);

    std::cout << "============Other Functional============" << std::endl;
    (instance2 + "string2").print();
    boolArray instance5 = *dynamic_cast<boolArray *>(instance3.Clone());
    instance5.resize(3);
    instance3.push_back(true);
    instance3.push_back(true);
    instance5.push_back(false);
    instance3.print();
    (instance3 + instance5).print();

    std::cout << "~~~~~~~~~~~~~~~~~~~~~  End  ~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    int x;
    std::cin >> x;
    return 0;
}
