//
// Created by AAI2002 on 12.11.2021.
//

#ifndef LAB22_STRING_H
#define LAB22_STRING_H

#include "Array.h"

class String : public Array {
private:
    char *data = nullptr;

    void resizeOnce();

public:
    String() : Array() {}

    explicit String(char);

    explicit String(Boost::Any val) {
        String::push_back(val);
    }

    String(const char *);

    String Clone() {
        String temp;
        for (int i = 0; i < length; ++i) {
            temp.push_back(this->data[i]);
        }
        return temp;
    }

    String(int, char);

    String(String const &) = default;

    void push_back(Boost::Any) override;

    void pushString(const std::string &);

    void resize(int new_size) override;

    String operator+(const String &);

    void print() const override;

    void scans() override;

    void printType() const override;

    char operator[](int iterator) const;

    [[nodiscard]] String getElementInString(int) const;

    ~String() override {
        delete[] data;
    }

    String& operator=(String& other) {
        for (int i = 0; i < other.Length(); ++i) {
            this->push_back(other[i]);
        }
        return *this;
    }
};


#endif //LAB22_STRING_H
