//
// Created by pbarbeira on 19-05-2022.
//
#include "exercises.h"

int howManyAfter(const std::vector<std::string>& dic, char target){
    Graph<char> graph(true);
    std::string w1, w2;
    for(int i = 0; i < dic.size()-1;i++){
        w1 = dic[i];
        w2 = dic[i+1];
        for(int j = 0; j < std::min(w1.length(), w2.length());j++) {
            graph.addNode(w1[j]);
            graph.addNode(w2[j]);
            if (w1[j] != w2[j]) {
                graph.addEdge(w1[j], w2[j]);
                break;
            }
        }
    }
    int src = graph.findNode(target);
    return graph.howManyBFS(src);

}

int ex1(const std::string& path){
    std::ifstream infile(path);
    if(!infile.is_open()){
        std::cout << "Error opening file " << path << '\n';
        return 1;
    }
    std:vector<std::string> dictionary;
    std::string buffer;
    bool stop = false;
    while(!stop) {
        std::getline(infile, buffer);
        if (buffer == "#") stop = true;
        else dictionary.push_back(buffer);
    }
    char target;
    infile >> target;

    return howManyAfter(dictionary, target);
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(ex1, QuantasDepois){
    EXPECT_EQ(4, ex1("files/ex1a.txt"));
    EXPECT_EQ(3, ex1("files/ex1b.txt"));
    EXPECT_EQ(0, ex1("files/ex1c.txt"));
    EXPECT_EQ(3, ex1("files/ex1d.txt"));
}