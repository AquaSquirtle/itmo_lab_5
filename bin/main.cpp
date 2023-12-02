#include "iostream"
#include "lib\Array.h"

int main () {
    Array arr = Array::make_array(4,4,4);
    arr[1][1][1] = 100500;
    std::cout << arr[1][1][1];
    return 0;
}
