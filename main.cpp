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
    using namespace std;
    IArray *newIArray;
    newIArray = instance->Clone();
    auto * newArray = dynamic_cast<Array *>(newIArray);
    cout << "Incoming array:" << endl;
    dynamic_cast<Array *>(instance)->print();
    cout << "Copy of array:" << endl;
    newArray->print();
    newArray->resize(2);
    cout << "Resized array:" << endl;
    newArray->print();
}

void demo(Array* arr) {
    demoIArr(arr);
    demoIO(arr);
    CloningDemo(arr);
}

int main()
{
    using namespace std;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~ Start ~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    double ArrforInstance[2] {1.1, 1.2};

    auto instance1 = Vector(2, ArrforInstance);
    auto instance2 = String("in");
    auto instance3 = boolArray(true);

    auto instance21 = arrayOfVector(instance1);
    auto instance22 = arrayOfstring(instance2);
    auto instance23 = arrayOfboolArray(instance3);

    cout << "============Vector============" << endl;
    demo(&instance1);
    cout << "============String============" << endl;
    demo(&instance2);
    cout << "============boolArray============" << endl;
    demo(&instance3);

    cout << "============VectorArray============" << endl;
    demo(&instance21);
    cout << "============StringArray============" << endl;
    demo(&instance22);
    cout << "============boolArrayArray============" << endl;
    demo(&instance23);

    cout << "============AnyVector============" << endl;
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

    cout << "============Other Functional============" << endl;
    (instance2 + "string2").print();
    boolArray instance5 = *dynamic_cast<boolArray *>(instance3.Clone());
    instance5.resize(3);
    instance3.push_back(true);
    instance3.push_back(true);
    instance5.push_back(false);
    instance3.print();
    (instance3 + instance5).print();

    cout << "~~~~~~~~~~~~~~~~~~~~~  End  ~~~~~~~~~~~~~~~~~~~~~" << endl;
    int x;
    cin >> x;
    return 0;
}
