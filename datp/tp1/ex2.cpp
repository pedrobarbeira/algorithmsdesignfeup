// By: Gonçalo Leão

#include "exercises.h"
#include <limits.h>

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum = -INT_MAX, sum = 0;

    for(int l = 1; l <= n; l++) {
        for (int a0 = 0; a0 + l < n; a0++) {
            for (int k = a0; k < a0 + l; k++) {
                sum += A[k];
            }
            if(sum > maxSum){
                maxSum = sum;
                i = a0;
                j = a0+l-1;
            }
            sum = 0;
        }
    }

    return maxSum;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}