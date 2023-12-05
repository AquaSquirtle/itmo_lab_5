#include <gtest/gtest.h>
#include <lib/Array.h>

TEST(ArrayTest, StaticMethodTest) {
    Array arr = Array::make_array(4,4,4);
    arr[1][1][1] = 100500;
    EXPECT_EQ(arr[1][1][1], 100500);
}

TEST(ArrayTest, ConstructorTest) {
    Array arr(4, 4, 4);
    arr[1][1][1] = 100500;
    EXPECT_EQ(arr[1][1][1], 100500);
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
    EXPECT_EQ(arr, arr3);
}

TEST(ArrayTest, WrongIndexTest) {
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
    EXPECT_EXIT(arr[5][5][5], testing::ExitedWithCode(EXIT_FAILURE), "");
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
    EXPECT_EQ(arr, arr3);
}

TEST(ArrayTest, CopiedArray) {
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
    arr3[3][3][3] = 555;
    EXPECT_FALSE(arr == arr3);
}

TEST(ArrayTest, SumDifferentSizeTest) {
    int x = 4;
    int y = 4;
    int z = 4;
    Array arr = Array::make_array(x, y, z);
    Array arr2 = Array::make_array(x - 1, y - 1, z - 1);
    Array arr3 = Array::make_array(x, y, z);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                arr[i][j][k] = 10;
                arr3[i][j][k] = 15;
            }
        }
    }
    EXPECT_FALSE((arr + arr2) == arr3);
}
TEST(ArrayTest, SubstrDifferentSizeTest) {
    int x = 4;
    int y = 4;
    int z = 4;
    Array arr = Array::make_array(x, y, z);
    Array arr2 = Array::make_array(x - 1, y - 1, z - 1);
    for (int i = 0; i < x - 1; ++i) {
        for (int j = 0; j < y - 1; ++j) {
            for (int k = 0; k < z - 1; ++k) {
                arr2[i][j][k] = 5;
            }
        }
    }
    Array arr3 = Array::make_array(x, y, z);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                arr[i][j][k] = 10;
                arr3[i][j][k] = 5;
            }
        }
    }
    EXPECT_FALSE((arr - arr2) == arr3);
}

TEST(ArrayTest, OverflowTest) {
    int x = 4;
    int y = 4;
    int z = 4;
    Array arr = Array::make_array(x, y, z);
    arr[3][3][3] = 10005000;
    EXPECT_FALSE(arr[3][3][3] == 10005000);
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
    EXPECT_EQ(arr + arr2, arr3);
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
    EXPECT_EQ(arr - arr2, arr3);
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
    EXPECT_EQ(arr * 10, arr3);
}