#include "Array.h"
#include <iostream>

const size_t DEFAULT_CAPACITY = 10;

void Array::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

Array::Array() : size(0), capacity(DEFAULT_CAPACITY) {
    data = new int[capacity] {0};
}

Array::Array(size_t n) : size(n), capacity(n) {
    data = new int[capacity] {0};
}

Array::Array(size_t n, int min, int max) : size(n), capacity(n) {
    data = new int[capacity];
    fillRandom(min, max);
}

Array::Array(size_t n, int x) : size(n), capacity(n) {
    data = new int[capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = x;
    }
}

Array::Array(const Array& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Array::~Array() {
    clear();
}

void Array::display() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void Array::fillRandom(int min, int max) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = rand() % (max - min + 1) + min;
    }
}

size_t Array::getSize() const {
    return size;
}

size_t Array::getCapacity() const {
    return capacity;
}

void Array::append(int value) {
    if (size == capacity) {
        reserve(capacity * 2);
    }
    data[size++] = value;
}

void Array::erase(size_t index) {
    if (index >= size) {
        return;
    }
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}


void Array::clearAll() {
    size = 0;
}

void Array::reserve(size_t extraCapacity) {
    if (extraCapacity > capacity) {
        int* newData = new int[extraCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = extraCapacity;
    }
}


void Array::shrink() {
    if (capacity > size) {
        int* newData = new int[size];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = size;
    }
}


void Array::resize(size_t newSize) {
    if (newSize > capacity) {
        reserve(newSize);
    }
    for (size_t i = size; i < newSize; ++i) {
        data[i] = 0;
    }
    size = newSize;
}

void Array::sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int Array::getMin() const {
    int minValue = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] < minValue) {
            minValue = data[i];
        }
    }
    return minValue;
}

int Array::getMax() const {
    int maxValue = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }
    return maxValue;
}
