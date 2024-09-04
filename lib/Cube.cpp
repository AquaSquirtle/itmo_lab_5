#include "Cube.h"


Cube::Cube(size_t x_, uint17_t& storage_)
    : x(x_)
    , storage(storage_)
{
}

Square Cube::operator[](size_t value) {
    if (storage.CheckY(value)) {
        return {x, value, storage};
    }
    exit(EXIT_FAILURE);
}
