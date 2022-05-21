// By: Gonçalo Leão

#include "exercises.h"

bool sum3(unsigned int T, unsigned int nums[3]) {
    if(T < 3) return false;

    nums[0] = T / 2;
    nums[1] = nums[0] / 2;
    nums[2] = T - nums[0] - nums[1];

    return true;
}

bool sum3_a(unsigned int T, unsigned int nums[3]) {
    int j = 1;
    for(int i = 0; i < 3; i++){
        nums[i] = j;
        if(T < j || i == 2) nums[i] = T;
        else {
            T -= j;
            if (T == 0) return false;
        }
    }
    return true;
}

/// TESTS ///
#include <gtest/gtest.h>

void compareSums(unsigned int selected[3], unsigned int expectedSum) {
    EXPECT_EQ(selected[0] + selected[1] + selected[2], expectedSum);
}

TEST(TP1_Ex1, 3sumExists) {
    unsigned int selected[3];

    unsigned int T = 10;
    EXPECT_EQ(sum3(T,selected), true);
    compareSums(selected,T);

    T = 18;
    EXPECT_EQ(sum3(T,selected), true);
    compareSums(selected,T);
}

TEST(TP1_Ex1, 3sumNotExists) {
    unsigned int selected[3];

    unsigned int T = 1;
    EXPECT_EQ(sum3(T,selected), false);
}