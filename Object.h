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

        explicit VALUE(int value): _integer(value) { }
        explicit VALUE(float value): _float(value) { }
        explicit VALUE(double value): _double(value) { }
        explicit VALUE(char value): _char(value) { }
        explicit VALUE(bool value): _bool(value) { }
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
    template <typename Type>
    [[nodiscard]] Type get() const {
        switch (_type) {
            case 'i': return value._integer;
            case 'd': return value._float;
            case 'c': return value._char;
            case 'b': return value._bool;
            case 'f': return value._float;
            default: return value._double;
        }
    }
    [[nodiscard]] std::string type() const;
};


#endif //LAB22_OBJECT_H
