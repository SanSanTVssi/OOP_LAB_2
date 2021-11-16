//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_ANY_H
#define LAB22_ANY_H
#include <iostream>

namespace Boost {
    union Any {
    protected:
        double _double;
        float _float;
        bool _bool;
        int _integer;
        char _char;

    public:
        Any(int value) : _integer(value) {}

        Any(float value) : _float(value) {}

        Any(double value) : _double(value) {}

        Any(char value) : _char(value) {}

        Any(bool value) : _bool(value) {}

        template<typename T>
        friend T any_cast(Any val);
    };

    template<typename T>
    T any_cast(Any val) {
        switch (typeid(T).name()[0]) {
            case 'i': return static_cast<T>(val._integer);
            case 'f': return static_cast<T>(val._float);
            case 'd': return static_cast<T>(val._double);
            case 'c': return static_cast<T>(val._char);
            case 'b': return static_cast<T>(val._bool);
            default: return static_cast<T>(val._double);
        }
    }
}





#endif //LAB22_ANY_H
