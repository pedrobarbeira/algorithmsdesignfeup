#include "exercises.h"

#include <iostream>
bool changeMakingUnlimitedDP(unsigned int C[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {

    auto* minCoins = (unsigned int*) malloc(sizeof(unsigned int) * (T + 1));
    minCoins[0] = 0;
    auto* lastCoin = (unsigned int*) malloc(sizeof(unsigned int) * (T + 1));

    for (int i = 0; i < T + 1; i++) {
        if (i > 0) minCoins[i] = UINT32_MAX;
        lastCoin[i] = UINT32_MAX;
    }
    for (int i = 0; i < n; i++)
        usedCoins[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= T; j++) {
            if (j >= C[i]) {
                if (minCoins[j - C[i]] == 0) {
                    minCoins[j] = 1;
                    lastCoin[j] = i;
                }
                else if (1 + minCoins[j - C[i]] < minCoins[j]){
                    minCoins[j] = 1 + minCoins[j - C[i]];
                    lastCoin[j] = i;
                }
            }
        }
    }

    while(T > 0){
        unsigned int last = lastCoin[T];
        if(last == UINT32_MAX || last < 0) return false;
        usedCoins[last]++;
        T -= C[last];
    }

	return true;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP3_Ex2, hasChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 1);
    EXPECT_EQ(usedCoins[3], 3);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,10,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);
}

TEST(TP3_Ex2, hasChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int n = 3;
    unsigned int usedCoins[3];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,7,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 2);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);
}

TEST(TP3_Ex2, hasNoChange) {
    unsigned int C[] = {5,10};
    unsigned int n = 2;
    unsigned int usedCoins[2];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,1,usedCoins), false);
}