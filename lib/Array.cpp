#include "Array.h"

Array::Array(size_t x_, size_t y_, size_t z_) {
    x = x_;
    y = y_;
    z = z_;

    size_of_array = x * y * z;

    array_of_16bit = new uint16_t[size_of_array] {};
    array_of_8bit = new uint8_t[(size_of_array + 7)/8] {};
}

Array::Array(const Array &other): x(other.x), y(other.y), z(other.z), size_of_array(other.size_of_array){
    delete[] array_of_8bit;
    delete[] array_of_16bit;
    array_of_16bit = new uint16_t[size_of_array]{};
    array_of_8bit = new uint8_t[(size_of_array + 7)/8]{};
        for (int i = 0; i < size_of_array; ++i) {
            array_of_16bit[i] = other.array_of_16bit[i];
        }
        for (int i = 0; i < (size_of_array + 7)/8; ++i) {
            array_of_8bit[i] = other.array_of_8bit[i];
        }
}

int Array::GetValue(size_t index_) const {
    return array_of_16bit[index_] + ((array_of_8bit[index_/8] >> index%8) % 2 * (0x10000));
}

void Array::WriteValue(int value, size_t id) {
    array_of_16bit[id] = value & UINT16_MAX;
    uint8_t temp = (value >> 16);
    temp = temp << id%8;
    array_of_8bit[id/8] |= temp;
}

Array Array::make_array(size_t x, size_t y, size_t z) {
    return {x,y,z};
}

Array &Array::operator[](int value) {
    switch (counter) {
        case 0: {
            index = 0;
            index += y * z * value;
            break;
        }
        case 1: {
            index += z * value;
            break;
        }
        case 2: {
            index += value;
            counter = 0;
            return *this;
        }
    }
    ++counter;
    return *this;
}

Array &Array::operator=(int value) {
    WriteValue(value, index);
    return *this;
}

Array Array::operator*(int number) {
    int temp;
    Array result(*this);
    for (int i = 0; i < size_of_array; ++i) {
        temp = result.GetValue(i) * number;
        result.WriteValue(temp, i);
    }
    return result;
}

Array Array::operator+(const Array &other) {
    int temp;
    Array result(*this);
    for (int i = 0; i < size_of_array; ++i) {
        temp = result.GetValue(i) + other.GetValue(i);
        result.WriteValue(temp, i);
    }
    return result;
}

Array Array::operator-(const Array &other) {
    int temp;
    Array result(*this);
    for (int i = 0; i < size_of_array; ++i) {
        temp = result.GetValue(i) - other.GetValue(i);
        result.WriteValue(temp, i);
    }
    return result;
}

std::ostream &operator<<(std::ostream &stream, const Array &array) {
    stream << array.GetValue(array.index);
    return stream;
}

std::istream &operator>>(std::istream &cin, Array &array) {
    int temp;
    cin >> temp;
    array.WriteValue(temp, array.index);
    return cin;
}

Array &Array::operator=(const Array &other) {
    if (this != &other) {
        size_of_array = other.size_of_array;
        x = other.x;
        y = other.y;
        z = other.z;

        auto* new_array_of_16bit = new uint16_t[size_of_array];
        auto* new_array_of_8bit = new uint8_t[(size_of_array + 7)/8];

        for (int i = 0; i < size_of_array; ++i) {
            new_array_of_16bit[i] = other.array_of_16bit[i];
        }
        for (int i = 0; i < (size_of_array + 7)/8; ++i) {
            new_array_of_8bit[i] = other.array_of_8bit[i];
        }

        delete[] array_of_16bit;
        delete[] array_of_8bit;

        array_of_16bit = new_array_of_16bit;
        array_of_8bit = new_array_of_8bit;

    }
    return *this;
}

size_t Array::GetIndex() const {
    return index;
}

bool Array::operator==(const Array &other) {
    if (x != other.x || y != other.y || z != other.z) {
        return false;
    }
    for (int i = 0; i < size_of_array; ++i) {
        if (array_of_16bit[i] != other.array_of_16bit[i]) {
            return false;
        }
    }
    for (int i = 0; i < (size_of_array + 7)/8; ++i) {
        if (array_of_8bit[i] != other.array_of_8bit[i]) {
            return false;
        }
    }
    return true;
}


Array::~Array() = default;



