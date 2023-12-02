#include <gtest/gtest.h>
#include <lib/Array.h>

TEST(ArrayTest, StaticMethodTest) {
    Array arr = Array::make_array(4,4,4);
    arr[1][1][1] = 100500;
    ASSERT_EQ(arr[1][1][1].GetValue(arr.GetIndex()), 100500);
}

TEST(ArrayTest, ConstructorTest) {
    Array arr(4, 4, 4);
    arr[1][1][1] = 100500;
    ASSERT_EQ(arr[1][1][1].GetValue(arr.GetIndex()), 100500);
}

TEST(ArrayTest, CopyConstructorTest) {
    int x = 4;
    int y = 4;
    int z = 4;
    Array arr = Array::make_array(x, y, z);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                arr[i][j][k] = 10;
            }
        }
    }
    Array arr3(arr);
    ASSERT_TRUE(arr == arr3);
}

TEST(ArrayTest, CopyAssigmentOperatorTest) {
    int x = 4;
    int y = 4;
    int z = 4;
    Array arr = Array::make_array(x, y, z);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                arr[i][j][k] = 10;
            }
        }
    }
    Array arr3 = arr;
    ASSERT_TRUE(arr == arr3);
}

TEST(ArrayTest, SumTest) {
    int x = 4;
    int y = 4;
    int z = 4;
    Array arr = Array::make_array(x, y, z);
    Array arr2 = Array::make_array(x, y, z);
    Array arr3 = Array::make_array(x, y, z);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                arr[i][j][k] = 10;
                arr2[i][j][k] = 5;
                arr3[i][j][k] = 15;
            }
        }
    }
    ASSERT_TRUE((arr + arr2) == arr3);
}

TEST(ArrayTest, SubstTest) {
    int x = 4;
    int y = 4;
    int z = 4;
    Array arr = Array::make_array(x, y, z);
    Array arr2 = Array::make_array(x, y, z);
    Array arr3 = Array::make_array(x, y, z);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                arr[i][j][k] = 1000;
                arr2[i][j][k] = 7;
                arr3[i][j][k] = 993;
            }
        }
    }
    ASSERT_TRUE((arr - arr2) == arr3);
}

TEST(ArrayTest, MultTest) {
    int x = 4;
    int y = 4;
    int z = 4;
    Array arr = Array::make_array(x, y, z);
    Array arr3 = Array::make_array(x, y, z);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                arr[i][j][k] = 999;
                arr3[i][j][k] = 9990;
            }
        }
    }
    ASSERT_TRUE((arr * 10) == arr3);
}