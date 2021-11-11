#include <iostream>
#include <memory>

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

    [[nodiscard]] double getDecimal() const {
        switch (_type) {
            case 'i': return _integer;
            case 'f': return _float;
            case 'd': return _double;
            case 'c': return _char;
            case 'b': return _bool;
            default: return _double;
        }
    }

    [[nodiscard]] double getDouble() const {
        if (_type == 'i') return _double;
        else {
            std::cout << "Type of Object is not double! Function return \\0-symbol by default!" << std::endl;
        }
        return 0;
    }

    [[nodiscard]] float getFloat() const {
        if (_type == 'i') return _float;
        else {
            std::cout << "Type of Object is not float! Function return \\0-symbol by default!" << std::endl;
        }
        return 0;
    }

    [[nodiscard]] int getInteger() const {
        if (_type == 'i') return _integer;
        else {
            std::cout << "Type of Object is not integer! Function return \\0-symbol by default!" << std::endl;
        }
        return 0;
    }

    [[nodiscard]] char getChar() const {
        if (_type == 'c') return _char;
        else {
            std::cout << "Type of Object is not bool! Function return \\0-symbol by default!" << std::endl;
        }
        return 0;
    }

    [[nodiscard]] bool getBoolean() const {
        if (_type == 'b') return _bool;
        else {
            std::cout << "Type of Object is not bool! Function return false by default!" << std::endl;
        }
        return false;
    }

    [[nodiscard]] std::string type() const {
        switch (_type) {
            case 'i': return "int";
            case 'f': return "float";
            case 'd': return "double";
            case 'c': return "char";
            case 'b': return "bool";
            default: return "unknown type";
        }
    }
};


class Array {
protected:
    Object * data = nullptr;
    int length = 0;
    void resizeOnce() {
        if (data == nullptr) {
            data = new Object[++length];
        }
        else {
            data = (Object*) realloc (data, ++length * sizeof(Object));
        }
    };
public:
    virtual void push_back(Object other) = 0;

    virtual void print() const = 0;

    void resize(int new_size) {
        if (data == nullptr) {
            length = new_size;
            data = new Object[length];
            for (int i = 0; i < length; ++i) {
                data[i] = 0;
            }
        }
        if (new_size > length) {
            for (int i = length; i < new_size; ++i) {
                push_back(0);
            }
        }
        else if (new_size < length) {
            auto *newArr = new Object[new_size];
            for (int i = 0; i < new_size; ++i) {
                newArr[i] = data[i];
            }
            delete[] data;
            data = newArr;
            length = new_size;
        }
    };

    [[nodiscard]] int Length() const {
        return length;
    };

    virtual ~Array() = 0;
};

Array::~Array() = default;

class Vector: public Array{
public:

    Vector() {
        length = 0;
        data = nullptr;
    }

    template<typename T>
    explicit Vector(T value) {
        Vector::push_back(static_cast<double>(value));
    }

    template<typename T>
    Vector(int size, T * array) {
        for (int i = 0; i < size; ++i) {
            Vector::push_back(static_cast<double>(array[i]));
        }
    }

    template<typename T>
    Vector(int RepeatOfValue, T value) {
        for (int i = 0; i < RepeatOfValue; ++i) {
            Vector::push_back(static_cast<double>(value));
        }
    }

    Vector(Vector const &vector) {
        for (int i = 0; i < vector.Length(); ++i) {
            Vector::push_back(vector[i]);
        }
    }

    void print() const override{
        for (int i = 0; i < length; ++i) {
            std::cout << data[i].getDecimal() << "\t" << std::endl;
        }
    }

    double operator[](int iterator) const{
        return data[iterator].getDecimal();
    }

    void push_back(Object other) override{
        resizeOnce();
        data[length - 1] = other;
    }

    ~Vector() override {
        delete[] data;
        length = 0;
    }
};

void Foo(Array* arr) {
    int x = 64;
    for (int i = 0; i < 4; ++i) {
        arr->push_back(x++);
    }
    arr->print();
    arr->resize(7);
    std::cout << "=========================" << std::endl;
    arr->print();
}

int main()
{
    float ArrforInstance[2] {1.1, 1.2};
    auto instance1 = Vector(2, ArrforInstance);
    Foo(&instance1);
    Vector instance2 = Vector(instance1);
    std::cout << "=========================" << std::endl;
    instance1.resize(3);
    instance1.print();
    std::cout << "=========================" << std::endl;
    instance2.print();
}
