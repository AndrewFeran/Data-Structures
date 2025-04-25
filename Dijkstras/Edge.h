#ifndef EDGE_H
#define EDGE_H

#include <string>

struct Edge {
    char destination;
    int distance;
    
    Edge(const char dest, int dist)
        : destination(dest), distance(dist) {}
};

#endif