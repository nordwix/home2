#include "String.h"
#include <iostream>
#include <cstring>

const size_t DEFAULT_CAPACITY = 10;

void String::ensureCapacity(size_t requiredCapacity) {
    if (requiredCapacity > capacity) {
        size_t newCapacity = requiredCapacity;
        char* newStr = new char[newCapacity];
        strcpy_s(newStr, newCapacity, str);
        delete[] str;
        str = newStr;
        capacity = newCapacity;
    }
}


String::String() : size(0), capacity(DEFAULT_CAPACITY) {
    str = new char[capacity];
    str[0] = '\0';
}

String::String(size_t customSize) : size(0), capacity(customSize + 1) {
    str = new char[capacity];
    str[0] = '\0';
}

String::String(const char* input) : size(strlen(input)), capacity(strlen(input) + 1) {
    str = new char[capacity];
    strcpy_s(str, capacity, input);
}

String::String(const String& other) : size(other.size), capacity(other.capacity) {
    str = new char[capacity];
    strcpy_s(str, capacity, other.str);
}

String::~String() {
    delete[] str;
}

void String::input() {
    std::cout << "Enter a String: ";
    char buffer[DEFAULT_CAPACITY];
    std::cin.getline(buffer, DEFAULT_CAPACITY);
    size_t inputLength = strlen(buffer);
    ensureCapacity(inputLength + 1);
    strcpy_s(str, capacity, buffer);
    size = inputLength;
}

void String::output() const {
    std::cout << "String: " << str << std::endl;
}

size_t String::length() const {
    return size;
}

size_t String::getCapacity() const {
    return capacity;
}

size_t String::getSize() const {
    return size;
}

void String::append(char c) {
    ensureCapacity(size + 2);
    str[size] = c;
    str[size + 1] = '\0';
    ++size;
}

void String::append(const String& other) {
    ensureCapacity(size + other.size + 1);
    strcat_s(str, capacity, other.str);
    size += other.size;
}


void String::clear() {
    size = 0;
    str[0] = '\0';
}

void String::reserve(size_t extraCapacity) {
    if (extraCapacity > capacity) {
        ensureCapacity(extraCapacity);
    }
}


void String::shrink() {
    if (capacity > size + 1) {
        char* newStr = new char[size + 1];
        strcpy_s(newStr, size + 1, str);
        delete[] str;
        str = newStr;
        capacity = size + 1;
    }
}
