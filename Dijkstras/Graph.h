#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Edge.h"

#include <vector>

using namespace std;

// Represents the entire graph
class Graph {
private:
    vector<Vertex> vertices;
    vector<vector<Edge>> adjlist;

    int getVertexIndex(const char location) const;

public:
    void addVertex(const char location);
    void addEdge(const char origin, const char destination, int distance);
    void printGraph() const;
    void countDirectConnections() const;

    void shortestPath(char s);

    void printShortestPaths(char source, const std::vector<int>& distances, 
        const std::vector<char>& previous);
    // const vector<Vertex>& getVertices() const;
    // vector<Edge> getOutgoingEdges(const char location) const;
};

#endif