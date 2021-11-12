//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_OBJECT_H
#define LAB22_OBJECT_H
#include <iostream>

struct Object {
private:
    union VALUE{
        double _double;
        float _float;
        bool _bool;
        int _integer;
        char _char;

        VALUE(int value): _integer(value) { }
        VALUE(float value): _float(value) { }
        VALUE(double value): _double(value) { }
        VALUE(char value): _char(value) { }
        VALUE(bool value): _bool(value) { }
    } value;
    char _type;
public:
    Object(): value(0) {}
    Object(int value): value(value), _type('i') { }
    Object(float value): value(value), _type('f') { }
    Object(double value): value(value), _type('d') { }
    Object(char value): value(value), _type('c') { }
    Object(bool value): value(value), _type('b') { }

    [[nodiscard]] double getDecimal() const;
    [[nodiscard]] double getDouble() const;
    [[nodiscard]] float getFloat() const;
    [[nodiscard]] int getInteger() const;
    [[nodiscard]] char getChar() const;
    [[nodiscard]] bool getBoolean() const;
    [[nodiscard]] std::string type() const;
};


#endif //LAB22_OBJECT_H
