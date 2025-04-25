#include "Graph.h"
#include <iostream>
#include <queue>
#include <stack>

Graph::Graph(int V) : size(V), adjlist(V) {}

void Graph::addEdge(int v, int k) {
    adjlist[v].push_back(k);
}

void Graph::BFS(int s) {
    bool* visited = new bool[size]();
    std::queue<int> Q;

    visited[s] = true;
    Q.push(s);

    while (!Q.empty()) {
        s = Q.front();
        std::cout << s << " ";
        Q.pop();

        for (auto it = adjlist[s].begin(); it != adjlist[s].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                Q.push(*it);
            }
        }
    }

    delete[] visited;
}

void Graph::DFS(int s) {
    bool* visited = new bool[size]();
    std::stack<int> Stack;

    Stack.push(s);

    while (!Stack.empty()) {
        s = Stack.top();
        Stack.pop();

        if (!visited[s]) {
            std::cout << s << " ";
            visited[s] = true;
        }

        for (auto it = adjlist[s].rbegin(); it != adjlist[s].rend(); it++) {
            if (!visited[*it]) {
                Stack.push(*it);
            }
        }
    }

    delete[] visited;
}