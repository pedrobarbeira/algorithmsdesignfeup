// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "minHeap.h"
#include "disjointSets.h"
#include <queue>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        int parent;
        bool visited;
        T value;
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node*> nodes; // The list of nodes being represented

public:

    explicit Graph<T>(bool dir = false):n(0), hasDir(dir){
        nodes.push_back(new Node);
    }

    void addNode(T value){
        for(auto node : nodes){
            if(node->value == value) return;
        }
        Node* node = new Node;
        node->value = value;
        node->adj.clear();
        nodes.push_back(node);
        n++;
    }

    void addEdge(int src, int dest, int weight = 1) {
        if (src<1 || src>n || dest<1 || dest>n) return;
        nodes[src]->adj.push_back({dest, weight});
        if (!hasDir) nodes[dest]->adj.push_back({src, weight});
    }


    int findNode(T value) {
        for(int i=0;i<nodes.size();i++)
            if(nodes[i]->value == value) return i;
        return 0;
    }

    int howManyBFS(int src){
        int ret = 0;
        for(int i = 1; i <= n; i++){
            nodes[i]->parent = 0;
            nodes[i]->visited = false;
        }
        nodes[src]->visited = true;
        std::queue<int> q;
        q.push(src);
        int v;
        while(!q.empty()){
            v = q.front();
            q.pop();
            for(Edge e : nodes[v]->adj){
                int w = e.dest;
                if(!nodes[w]->visited){
                    q.push(w);
                    nodes[w]->visited = true;
                    nodes[w]->parent = v;
                    ret++;
                }
            }
        }
        return ret;
    }

};

#endif
