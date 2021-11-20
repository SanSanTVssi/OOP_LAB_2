//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_ANY_H
#define LAB22_ANY_H
#include <iostream>
#include <utility>

namespace Boost {
    struct Any {
    protected:
        union VALUE {
            double _double;
            const char * _string;
            float _float;
            bool _bool;
            int _integer;
            char _char;

            explicit VALUE(int value) : _integer(value) {}

            explicit VALUE(float value) : _float(value) {}

            explicit VALUE(double value) : _double(value) {}

            explicit VALUE(char value) : _char(value) {}

            explicit VALUE(bool value) : _bool(value) {}

            explicit VALUE(const char * value) : _string(value) {}

        } value;

        char _type;
    public:
        Any() = delete;

        Any(int val) : value(val), _type('i') {}

        Any(float val) : value(val), _type('f') {}

        Any(double val) : value(val), _type('d') {}

        Any(char val) : value(val), _type('c') {}

        Any(bool val) : value(val), _type('b') {}

        Any (const char *str) : value(str), _type('s') {}

        [[nodiscard]] char type() const {
            return _type;
        }

        [[nodiscard]] char const * getString() const {
            return value._string;
        }

        Any operator=(Any val) {
            switch (val._type) {
                case 'i': value = VALUE(val.value._integer); break;
                case 'd': value = VALUE(val.value._double); break;
                case 'f': value = VALUE(val.value._float); break;
                case 'c': value = VALUE(val.value._char); break;
                case 'b': value = VALUE(val.value._bool); break;
                case 's': value = VALUE(val.value._string); break;
            }
        }

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
            default: return 0;
        }
    }
}

#endif //LAB22_ANY_H
