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

    void push_back(Boost::Any value) override;

    void pushString(const std::string& string);

    void resize(int new_size) override;

    void print() const override;
    void scans() override;
    void printType() const override;
    char operator[](int iterator) const;
    [[nodiscard]] String getElementInString(int index) const;
};


#endif //LAB22_STRING_H
