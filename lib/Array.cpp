#include "Array.h"

Array::Array(size_t x_, size_t y_, size_t z_)
    : x(x_)
    , y(y_)
    , z(z_)
    , size_of_array(x_ * y_ * z_)
{
    storage = new uint17_t(x_, y_, z_);
}

Array::Array(const Array &other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
    , size_of_array(other.size_of_array)
{
    storage = new uint17_t(other.x, other.y, other.z);
    for (int i = 0; i < size_of_array; ++i) {
        storage->WriteValueFrom16Bit(i, other.storage->GetValueFrom16Bit(i));
    }
    for (int i = 0; i < (size_of_array + 7) / 8; ++i) {
        storage->WriteValueFrom8Bit(i, other.storage->GetValueFrom8Bit(i));
    }
}

Array::~Array() {
    delete storage;
};

Array Array::make_array(size_t x, size_t y, size_t z) {
    return {x, y, z};
}

uint17_t& Array::operator[](int value) {
    if (x > value) {
        storage->GenerateIndex(value);
        return *storage;
    }
    exit(EXIT_FAILURE);

}

Array Array::operator*(int number) {
    int temp;
    Array result(*this);
    for (int i = 0; i < size_of_array; ++i) {
        temp = result.storage->GetValue(i) * number;
        result.storage->WriteValue(temp, i);
    }
    return result;
}

Array Array::operator+(const Array &other) {
    if (x == other.x && y == other.y && z == other.z) {
        int temp;
        Array result(*this);
        for (int i = 0; i < size_of_array; ++i) {
            temp = result.storage->GetValue(i) + other.storage->GetValue(i);
            result.storage->WriteValue(temp, i);
        }
        return result;
    }
    return *this;
}

Array Array::operator-(const Array &other) {
    if (x == other.x && y == other.y && z == other.z) {
        int temp;
        Array result(*this);
        for (int i = 0; i < size_of_array; ++i) {
            temp = result.storage->GetValue(i) - other.storage->GetValue(i);
            result.storage->WriteValue(temp, i);
        }
        return result;
    }
    return *this;
}

Array &Array::operator=(const Array &other){
    if (this != &other) {
        size_of_array = other.size_of_array;
        x = other.x;
        y = other.y;
        z = other.z;

        delete storage;
        storage = new uint17_t(other.x, other.y, other.z);

        for (int i = 0; i < size_of_array; ++i) {
            storage->WriteValueFrom16Bit(i, other.storage->GetValueFrom16Bit(i));
        }
        for (int i = 0; i < (size_of_array + 7) / 8; ++i) {
            storage->WriteValueFrom8Bit(i, other.storage->GetValueFrom8Bit(i));
        }
    }
    return *this;
}

bool Array::operator==(const Array &other) const{
    if (x != other.x || y != other.y || z != other.z) {
        return false;
    }
    for (int i = 0; i < size_of_array; ++i) {
        if (storage->GetValueFrom16Bit(i) != other.storage->GetValueFrom16Bit(i)) {
            return false;
        }
    }
    for (int i = 0; i < (size_of_array + 7)/8; ++i) {
        if (storage->GetValueFrom8Bit(i) != other.storage->GetValueFrom8Bit(i)) {
            return false;
        }
    }
    return true;
}





