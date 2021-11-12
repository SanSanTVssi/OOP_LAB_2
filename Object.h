//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_OBJECT_H
#define LAB22_OBJECT_H
#include <iostream>

struct Object {
private:
    double _double;
    float _float;
    bool _bool;
    int _integer;
    char _char;
    char _type;
public:
    Object(): _double(0), _integer(0) {}
    Object(int value): _integer(value), _type('i') { }
    Object(float value): _float(value), _type('f') { }
    Object(double value): _double(value), _type('d') { }
    Object(char value): _char(value), _type('c') { }
    Object(bool value): _bool(value), _type('b') { }

    [[nodiscard]] double getDecimal() const;
    [[nodiscard]] double getDouble() const;
    [[nodiscard]] float getFloat() const;
    [[nodiscard]] int getInteger() const;
    [[nodiscard]] char getChar() const;
    [[nodiscard]] bool getBoolean() const;
    [[nodiscard]] std::string type() const;
};


#endif //LAB22_OBJECT_H
