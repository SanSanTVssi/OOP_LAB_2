//
// Created by AAI2002 on 12.11.2021.
//

#include "String.h"

void String::print() const {
    for (int i = 0; i < length; ++i) {
        std::cout << data[i];
    }
    std::cout << std::endl;
}

void String::scans() {
    std::string temp = std::string();
    do {
        std::cin >> temp;
        for (char i : temp) {
            push_back(i);
        }
        push_back(' ');
    } while(std::cin.get() != '\n');
    std::cin.clear();
}

void String::printType() const {
    std::cout << "char[" << length << "]" << std::endl;
}

char String::operator[](int iterator) const {
    return data[iterator];
}

String String::getElementInString(int index) const {
    return String(data[index]);
}
void String::push_back(Boost::Any value) {
    switch (value.type()) {
        case 'c':
        {
            resizeOnce();
            data[length - 1] = Boost::any_cast<char>(value);
        } break;
        case 'd':
        {
            auto temp = Boost::any_cast<double>(value);
            std::string tempstr = std::to_string(temp);
            pushString(tempstr);
        } break;
        case 'i':
        {
            auto temp = Boost::any_cast<int>(value);
            std::string tempstr = std::to_string(temp);
            pushString(tempstr);
        } break;
        case 'f':
        {
            auto temp = Boost::any_cast<float>(value);
            std::string tempstr = std::to_string(temp);
            pushString(tempstr);
        } break;
        case 'b':
        {
            auto temp = Boost::any_cast<bool>(value);
            std::string tempstr = (temp) ? "true": "false";
            pushString(tempstr);
        } break;
        case 's':
        {
            pushString(value.getString());
        } break;

    }
}

void String::pushString(const std::string &string) {
    for (char c: string) {
        resizeOnce();
        data[length - 1] = c;
    }
}

void String::resize(int new_size) {
    if (data == nullptr) {
        length = new_size;
        data = new char[length];
        for (int i = 0; i < length; ++i) {
            data[i] = '\0';
        }
    }
    if (new_size > length) {
        for (int i = length; i < new_size; ++i) {
            push_back('\0');
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

String String::operator+(const String &other) {
    String string = String();
    for (int i = 0; i < Length(); ++i) {
        string.push_back(data[i]);
    }
    for (int i = 0; i < other.Length(); ++i) {
        string.push_back(other[i]);
    }
    return string;
}

String::String(char value) : Array() {
    String::push_back(value);
}

String::String(const char *array) : Array() {
    for (int i = 0;array[i] != 0; ++i) {
        char c = array[i];
        String::push_back(c);
    }
}

String::String(const String &vector) : Array() {
    for (int i = 0; i < vector.Length(); ++i) {
        String::push_back(vector[i]);
    }
}

String::String(int RepeatOfValue, char value) : Array() {
    for (int i = 0; i < RepeatOfValue; ++i) {
        String::push_back(value);
    }
}

void String::resizeOnce() {
    if (data == nullptr) {
        data = new char[++length];
    } else {
        data = (char *) realloc(data, ++length * sizeof(char));
    }
}
