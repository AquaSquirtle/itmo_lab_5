#pragma once
#include "uint17_t.h"
#include "Square.h"

class Cube {
public:
    Cube(size_t x_, uint17_t& storage_);
    Square operator[] (size_t value);
private:
    size_t x;
    uint17_t& storage;
};

