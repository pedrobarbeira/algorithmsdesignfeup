//
// Created by pbarbeira on 22-05-2022.
//

#include "exercises.h"

std::pair<int,int>sociology(std::vector<std::vector<int>> data){
    Graph<int> graph;
    for(auto v : data){
        graph.addNode(v[0]);
        for (int i=1;i<data.size();i++){
            graph.addNode(v[i]);
            graph.addEdge(v[0], v[i]);
        }
    }
    std::stack<int> stacc = graph.getStackDFS();
    data = graph.kosaraju(stacc);
    int groups = 0, foreverAlones = 0;
    for(auto v : data){
        if(v.size() >= 4) groups++;
        else foreverAlones++;
    }
    std::pair<int,int> ret(groups, foreverAlones);
    return ret;
}

std::vector<std::pair<int, int>> ex2(){
    std::vector<std::pair<int, int>> ret;
    std::ifstream infile("files/ex2.txt");
    if(!infile.is_open()){
        cout << "error opening ex2.txt\n";
        return ret;
    }
    int i, n;
    infile >> i;
    std::vector<std::vector<int>> data;
    while(i>0){
        std::vector<int> dataEntry;
        infile >> n;
        while(n>0){
            int st, fNum, f;
            infile >> st;
            dataEntry.push_back(st);
            infile >> fNum;
            while(fNum>0){
                infile >> f;
                dataEntry.push_back(f);
                fNum--;
            }
            data.push_back(dataEntry);
            dataEntry.clear();
            n--;
        }
        std::pair<int, int> result = sociology(data);
        ret.push_back(result);
        for(auto v : data)
            v.clear();
        data.clear();
        i--;
    }
}



/// TESTS ///
#include <gtest/gtest.h>

TEST(ex2, Sociologia){
    std::vector<std::pair<int,int>> res = ex2();
    ASSERT_FALSE(res.empty());
    EXPECT_EQ(0, res[0].first);
    EXPECT_EQ(4, res[0].second);
    EXPECT_EQ(1, res[1].first);
    EXPECT_EQ(0, res[1].second);
    EXPECT_EQ(1, res[2].first);
    EXPECT_EQ(2, res[2].second);
    EXPECT_EQ(2, res[3].first);
    EXPECT_EQ(2, res[3].second);
}