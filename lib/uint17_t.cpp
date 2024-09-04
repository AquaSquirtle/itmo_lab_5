#include "uint17_t.h"

void uint17_t::WriteValue(int value, size_t id) {
    array_of_16bit[id] = value & UINT16_MAX;
    uint8_t temp = (value >> 16);
    temp = temp << id%8;
    array_of_8bit[id/8] |= temp;
}

int uint17_t::GetValue(size_t index_) const {
    return array_of_16bit[index_] + ((array_of_8bit[index_/8] >> index_%8) % 2 * (0x10000));
}

uint17_t::uint17_t(size_t x_, size_t y_, size_t z_)
: x(x_)
, y(y_)
, z(z_)
{
    array_of_16bit = new uint16_t[x * y * z] {};
    array_of_8bit = new uint8_t[(x * y * z + 7) / 8] {};
}

uint16_t uint17_t::GetValueFrom16Bit(size_t index_) const{
    return array_of_16bit[index_];
}

uint8_t uint17_t::GetValueFrom8Bit(size_t index_) const{
    return array_of_8bit[index_];
}

void uint17_t::WriteValueFrom16Bit(size_t index_, uint16_t value) {
    array_of_16bit[index_] = value;
}

void uint17_t::WriteValueFrom8Bit(size_t index_, uint8_t value) {
    array_of_8bit[index_] = value;
}


uint17_t::~uint17_t() {
    delete[] array_of_8bit;
    delete[] array_of_16bit;
}




uint17_t& uint17_t::operator=(int value) {
    WriteValue(value, index);
    return *this;
}



std::ostream &operator<<(std::ostream &stream, const uint17_t &number) {
    stream << number.GetValue(number.index);
    return stream;
}

std::istream &operator>>(std::istream &cin, uint17_t &number) {
    int temp;
    cin >> temp;
    number.WriteValue(temp, number.index);
    return cin;
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

void uint17_t::GenerateIndex(size_t cur_x, size_t cur_y, size_t cur_z) {
    index = cur_x * y * z + cur_y * z + cur_z;
}

bool uint17_t::CheckX(size_t cur_x) const {
    return x > cur_x;
}

bool uint17_t::CheckY(size_t cur_y) const {
    return y > cur_y;
}

bool uint17_t::CheckZ(size_t cur_z) const {
    return z > cur_z;
}
