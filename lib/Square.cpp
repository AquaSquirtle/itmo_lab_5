#include "Square.h"

Square::Square(size_t x_, size_t y_, uint17_t &storage_)
    : x(x_)
    , y(y_)
    , storage(storage_)

{
}

uint17_t &Square::operator[](size_t value) {
    if (storage.CheckZ(value)) {
        storage.GenerateIndex(x, y, value);
        return storage;
    }
    exit(EXIT_FAILURE);

}

