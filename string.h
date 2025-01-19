#pragma once

class String {
private:
    char* str;
    size_t size;
    size_t capacity;

    void ensureCapacity(size_t requiredCapacity);
public:
    String();
    String(size_t customSize);
    String(const char* input);
    String(const String& other);
    ~String();

    void input();
    void output() const;
    size_t length() const;
    size_t getCapacity() const;
    size_t getSize() const;

    void append(char c);
    void append(const String& other);
    void clear();
    void reserve(size_t extraCapacity);
    void shrink();
};
