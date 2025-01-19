#pragma once

class Array {
private:
    int* data;
    size_t size;
    size_t capacity;

    void clear();
public:
    Array();
    Array(size_t n);
    Array(size_t n, int min, int max);
    Array(size_t n, int x);
    Array(const Array& other);
    ~Array();

    void display() const;
    void fillRandom(int min, int max);
    void resize(size_t newSize);
    void sort();
    int getMin() const;
    int getMax() const;

    size_t getSize() const;
    size_t getCapacity() const;
    void append(int value);
    void erase(size_t index);
    void clearAll();
    void reserve(size_t extraCapacity);
    void shrink();
};
