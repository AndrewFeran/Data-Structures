#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
    int size;
    std::vector<std::vector<int>> adjlist;
public:
    Graph(int V);
    void addEdge(int v, int k);
    void BFS(int s);
    void DFS(int s);
};

#endif