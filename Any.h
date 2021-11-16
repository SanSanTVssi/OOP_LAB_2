//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_ANY_H
#define LAB22_ANY_H
#include <iostream>

namespace Boost {
    struct Any {
    protected:
        union VALUE {
            double _double;
            float _float;
            bool _bool;
            int _integer;
            char _char;

            explicit VALUE(int value) : _integer(value) {}

            explicit VALUE(float value) : _float(value) {}

            explicit VALUE(double value) : _double(value) {}

            explicit VALUE(char value) : _char(value) {}

            explicit VALUE(bool value) : _bool(value) {}
        } value;

        char _type;
    public:
        Any() : value(0) {}

        Any(int value) : value(value), _type('i') {}

        Any(float value) : value(value), _type('f') {}

        Any(double value) : value(value), _type('d') {}

        Any(char value) : value(value), _type('c') {}

        Any(bool value) : value(value), _type('b') {}

        [[nodiscard]]double get() const;

        template<typename T>
        friend T any_cast(Any val);

    };

    template<typename T>
    T any_cast(Any val) {
        switch (val._type) {
            case 'i': return static_cast<T>(val.value._integer);
            case 'f': return static_cast<T>(val.value._float);
            case 'd': return static_cast<T>(val.value._double);
            case 'c': return static_cast<T>(val.value._char);
            case 'b': return static_cast<T>(val.value._bool);
            default: return static_cast<T>(val.value._double);
        }
    }
}





#endif //LAB22_ANY_H
