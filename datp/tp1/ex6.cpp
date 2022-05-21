// By: Gonçalo Leão

#include "exercises.h"
#include <algorithm>

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::operator<(const Activity &a2) const {
    return finish < a2.finish;
}

std::vector<Activity> earliestFinishScheduling(std::vector<Activity> A) {
    std::vector<Activity> res;

    sort(A.begin(), A.end());

    for(auto a : A){
        if(res.empty()) res.push_back(a);
        else if (res[0].start > a.start)
            res[0] = a;
        else if (res[0].start == a.start){
            if (a < res[0]) res[0] = a;
        }
    }

    int resCounter = 0;

    while(res[res.size()-1].finish != A[A.size()-1].finish){
        for(int i = 0; i < A.size(); i++){
            if(A[i].start > res[resCounter].finish){
                res.push_back(A[i]);
                resCounter++;
            }
        }
    }

    return res;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP1_Ex6, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = earliestFinishScheduling(A);
    EXPECT_EQ(V.size(), 3 );
    ASSERT_THAT(earliestFinishScheduling(A),  ::testing::ElementsAre(Activity(5, 15), Activity(30, 35), Activity(40, 50)));
}