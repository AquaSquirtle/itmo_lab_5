#include "iostream"
#include "lib\Array.h"

int main () {
    int x = 2;
    int y = 2;
    int z = 2;
    Array arr = Array::make_array(x,y,z);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                std::cin >> arr[i][j][k];
            }
        }
    }
    Array arr2 = arr;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                std::cout << arr2[i][j][k] << ' ';
            }
        }
    }
    return 0;
}
