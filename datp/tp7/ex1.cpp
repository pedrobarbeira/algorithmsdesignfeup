//
// Created by pbarbeira on 17-05-2022.
//

#include "exercises.h"

int editDistance(std::string x, std::string y){
    x = "#" + x;
    y = "#" + y;
    int n = x.length(), m = y.length(), offset=0;
    int table[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0) table[i][j] = j;
            else if(j == 0) table[i][j] = i;
            else {
                if (x[i] == y[j]) offset = 0;
                else offset = 1;
                int minOps = std::min(table[i-1][j] + offset, table[i][j-1] + offset);
                minOps = std::min(minOps, table[i-1][j-1]+offset);
                table[i][j] = minOps;
            }
        }
    }
    return table[x.length()-1][y.length()-1];
}

void nearest(std::string filename,std::string x,int k,
             std::vector<std::pair<int,std::string> > &result){
    //TODO debug this
    std::ifstream infile(filename);
    if(!infile.is_open()){
        std::cout << "Invalid file path\n";
        return;
    }
    std::map<int, std::vector<std::string>> wordMap;
    std::string word;
    int distance;
    while(!infile.eof()){
        infile >> word;
        distance = editDistance(x, word);
        auto it = wordMap.find(distance);
        if(it == wordMap.end())
            wordMap.insert(std::pair<int, std::vector<std::string>>(distance, {word}));
        else it->second.push_back(word);
    }
    auto it = wordMap.begin();
    while(k != 0){
        if(k < it->second.size()){
            for(int i = 0; i < k; i++){
                result.push_back(std::pair<int, std::string>(it->first, it->second[i]));
            }
            k = 0;
        }
        else{
            for(int i = 0; i < it->second.size(); i++)
                result.push_back(std::pair<int, std::string>(it->first, it->second[i]));
            k-=it->second.size();
            it++;
        }
    }

}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP7_Ex1, EditDistanceAndNearest) {
    EXPECT_EQ(4, editDistance("gotas", "afoga"));
    EXPECT_EQ(3, editDistance("gota", "afoga"));
    EXPECT_EQ(3, editDistance("gotas", "afogas"));
    EXPECT_EQ(5, editDistance("", "aaaaa"));
    EXPECT_EQ(4, editDistance("aaaa", ""));
}

