#pragma once
#include "cstdint"
#include "iostream"
#include "uint17_t.h"
#include "Cube.h"

class Array {
public:
    Array(size_t x_, size_t y_, size_t z_);
    Array (const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    static Array make_array(size_t x, size_t y, size_t z);

    Cube operator[](size_t value);
    Array operator*(int number);
    Array operator+(const Array& other);
    Array operator-(const Array& other);
    bool operator==(const Array& other) const;

private:

    uint17_t* storage;

    size_t size_of_array{};
    size_t x{};
    size_t y{};
    size_t z{};

};



