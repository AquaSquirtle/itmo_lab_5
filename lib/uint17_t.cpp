#include "uint17_t.h"

void uint17_t::WriteValue(int value, size_t id) {
    array_of_16bit[id] = value & UINT16_MAX;
    uint8_t temp = (value >> 16);
    temp = temp << id%8;
    array_of_8bit[id/8] |= temp;
}

int uint17_t::GetValue(size_t index) const {
    return array_of_16bit[index] + ((array_of_8bit[index/8] >> index%8) % 2 * (0x10000));
}

uint17_t::uint17_t(size_t x_, size_t y_, size_t z_)
: x(x_)
, y(y_)
, z(z_)
{
    array_of_16bit = new uint16_t[x * y * z] {};
    array_of_8bit = new uint8_t[(x * y * z + 7) / 8] {};
}

uint16_t uint17_t::GetValueFrom16Bit(size_t index) const{
    return array_of_16bit[index];
}

uint8_t uint17_t::GetValueFrom8Bit(size_t index) const{
    return array_of_8bit[index];
}

void uint17_t::WriteValueFrom16Bit(size_t index, uint16_t value) {
    array_of_16bit[index] = value;
}

void uint17_t::WriteValueFrom8Bit(size_t index, uint8_t value) {
    array_of_8bit[index] = value;
}


uint17_t::~uint17_t() {
    delete[] array_of_8bit;
    delete[] array_of_16bit;
}

void uint17_t::GenerateIndex(size_t index_) {
    index = y * z * index_;
}



uint17_t& uint17_t::operator[](int index_) {
    switch (count) {
        case 0: {
            if (y > index_) {
                is_y = true;
                index += index_ * z;
                ++count;
                break;
            }
            exit(EXIT_FAILURE);
        }
        case 1: {
            if (z > index_) {
                is_z = true;
                index += index_;
                count = 0;
                break;
            }
            exit(EXIT_FAILURE);
        }
    }
    return *this;
}


uint17_t& uint17_t::operator=(int value) {
    if (is_y && is_z) {
        is_y = false;
        is_z = false;
        WriteValue(value, index);
        return *this;
    }
    exit(EXIT_FAILURE);
}



std::ostream &operator<<(std::ostream &stream, uint17_t &number) {
    if (number.is_y && number.is_z) {
        number.is_y = false;
        number.is_z = false;
        stream << number.GetValue(number.index);
        return stream;
    }
    exit(EXIT_FAILURE);
}

std::istream &operator>>(std::istream &cin, uint17_t &number) {
    if (number.is_y && number.is_z) {
        number.is_y = false;
        number.is_z = false;
        int temp;
        cin >> temp;
        number.WriteValue(temp, number.index);
        return cin;
    }
    exit(EXIT_FAILURE);
}

bool uint17_t::operator==(int value) const{
    if (GetValue(index) == value) {
        return true;
    }
    return false;
}

bool uint17_t::operator==(uint17_t &other) const {
    if (GetValue(index) == other.GetValue(other.index)) {
        return true;
    }
    return false;
}

