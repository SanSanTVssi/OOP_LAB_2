//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_VECTOR_H
#define LAB22_VECTOR_H

#include "Array.h"

template <typename T>
class Vector: public Array{
private:
    T * data = nullptr;

    void resizeOnce() {
        if (data == nullptr) {
            data = new T[++length];
        }
        else {
            data = (T*) realloc (data, ++length * sizeof(T));
        }
    }
public:

    Vector() : Array() { }

    explicit Vector(Boost::Any value) : Array() {
        Vector::push_back(value);
    }

    Vector(int size, T * array) : Array() {
        for (int i = 0; i < size; ++i) {
            Vector::push_back(array[i]);
        }
    }

    Vector(int RepeatOfValue, Boost::Any value) : Array() {
        for (int i = 0; i < RepeatOfValue; ++i) {
            Vector::push_back(value);
        }
    }

    Vector(Vector const &vector) = default;

    void print() const override {
        for (int i = 0; i < length; ++i) {
            std::cout << data[i] << "\t";
        }
        std::cout << std::endl;
    }

    void scans() override {
        std::string temp = std::string();
        do {
            std::cin >> temp;
            push_back(stod(temp));
        } while(std::cin.get() != '\n');
        std::cin.clear();
    }

    [[nodiscard]] IArray *Clone() const override {
        Vector * temp = new Vector();
        for (int i = 0; i < length; ++i) {
            temp->push_back(this->data[i]);
        }
        return temp;
    }

    void resize(int new_size) override {
        if (data == nullptr) {
            length = new_size;
            data = new T[length];
            for (int i = 0; i < length; ++i) {
                data[i] = 0.0;
            }
        }
        if (new_size > length) {
            for (int i = length; i < new_size; ++i) {
                push_back(0.0);
            }
        }
        else if (new_size < length) {
            auto *newArr = new T[new_size];
            for (int i = 0; i < new_size; ++i) {
                newArr[i] = data[i];
            }
            delete[] data;
            data = newArr;
            length = new_size;
        }
    }

    void printType() const override {
        std::cout << typeid(T).name() << "[" << length << "]" << std::endl;
    }

    void push_back(Boost::Any other) override{
        resizeOnce();
        data[length - 1] = Boost::any_cast<T>(other);
    }

    T operator[](int iterator) const {
        return data[iterator];
    }

    [[nodiscard]] Vector getElementInVector(int index) const {
        return Vector(data[index]);
    }

    Vector operator+ (Vector other) {
        auto temp = Vector();
        for (int i = 0; i < std::min(other.Length(), length); ++i) {
            temp.push_back(data[i] + other[i]);
        }
        return temp;
    }

    Vector& operator=(Vector& other) {
        for (int i = 0; i < other.Length(); ++i) {
            this->push_back(other[i]);
        }
        return *this;
    }

    ~Vector() override{
        delete[] data;
    }
};

#endif //LAB22_VECTOR_H
