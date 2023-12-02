#pragma once
#include "cstdint"
#include "iostream"

class Array {
private:
    int counter = 0;
    size_t index = 0;

    uint16_t* array_of_16bit{};
    uint8_t* array_of_8bit{};
    size_t size_of_array{};

    size_t x{};
    size_t y{};
    size_t z{};
public:
    Array(size_t x_, size_t y_, size_t z_);
    Array (const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    void WriteValue(int value_, size_t id);
    int GetValue(size_t index_) const;
    size_t GetIndex() const;

    static Array make_array(size_t x, size_t y, size_t z);

    Array& operator[](int value);
    Array& operator=(int value);
    Array operator*(int number);
    Array operator+(const Array& other);
    Array operator-(const Array& other);
    bool operator==(const Array& other);

    friend std::ostream& operator<<(std::ostream& stream, const Array& array);
    friend std::istream& operator>>(std::istream& cin, Array& array);
};
