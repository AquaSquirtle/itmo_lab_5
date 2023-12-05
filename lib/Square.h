#pragma once
#include "uint17_t.h"

class Square {
public:
    Square(size_t x_, size_t y_, uint17_t& storage_);
    uint17_t& operator[] (size_t value);
private:
    size_t x;
    size_t y;
    uint17_t& storage;
};
