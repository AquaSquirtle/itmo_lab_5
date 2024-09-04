#pragma once
#include "cstdint"
#include "iostream"
class uint17_t {
public:
    explicit uint17_t(size_t x_, size_t y_, size_t z_);
    ~uint17_t();

    void WriteValue(int value_, size_t id);
    int GetValue(size_t index_) const;

    void GenerateIndex(size_t cur_x, size_t cur_y, size_t cur_z);

    uint17_t& operator=(int value);

    bool operator==(int value) const;
    bool operator==(uint17_t& other) const;
    friend std::ostream& operator<<(std::ostream &stream, const uint17_t& number);
    friend std::istream& operator>>(std::istream& cin, uint17_t& number);

    uint16_t GetValueFrom16Bit(size_t index) const;
    uint8_t GetValueFrom8Bit (size_t index) const;

    bool CheckX(size_t cur_x) const;
    bool CheckY(size_t cur_y) const;
    bool CheckZ(size_t cur_z) const;


    void WriteValueFrom16Bit(size_t index, uint16_t value);
    void WriteValueFrom8Bit (size_t index, uint8_t value);


private:
    uint16_t* array_of_16bit{};
    uint8_t* array_of_8bit{};

    size_t index {};
    size_t x {};
    size_t y {};
    size_t z {};
};
