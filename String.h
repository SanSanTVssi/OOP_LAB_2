//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_STRING_H
#define LAB22_STRING_H

#include "Array.h"

class String: public Array {
private:
    char * data = nullptr;
    void resizeOnce() {
        if (data == nullptr) {
            data = new char[++length];
        }
        else {
            data = (char*) realloc (data, ++length * sizeof(char));
        }
    }
public:
    String() : Array() { }

    explicit String(char value) : Array() {
        String::push_back(value);
    }

    explicit String(const char * array) : Array() {
        for (int i = 0;array[i] != 0; ++i) {
            char c = array[i];
            String::push_back(c);
        }
    }

    String(int RepeatOfValue, char value) : Array() {
        for (int i = 0; i < RepeatOfValue; ++i) {
            String::push_back(value);
        }
    }

    String(String const &vector) : Array() {
        for (int i = 0; i < vector.Length(); ++i) {
            String::push_back(vector[i]);
        }
    }

    void push_back(Boost::Any value) override {
         if (value.type() != 's') {
             resizeOnce();
             data[length - 1] = Boost::any_cast<char>(value);
         }
         else {
             resizeOnce();
             data[length - 1] = ' ';
             pushString(value.getString());
         }
    }

    void pushString(const std::string& string) {
        for (char c: string) {
            resizeOnce();
            data[length - 1] = c;
        }
    }

    void resize(int new_size) override {
        if (data == nullptr) {
            length = new_size;
            data = new char[length];
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
            auto *newArr = new char[new_size];
            for (int i = 0; i < new_size; ++i) {
                newArr[i] = data[i];
            }
            delete[] data;
            data = newArr;
            length = new_size;
        }
    }

    void print() const override;
    void scans() override;
    void printType() const override;
    char operator[](int iterator) const;
    //[[nodiscard]] String getElementInString(int index) const;
};


#endif //LAB22_STRING_H
