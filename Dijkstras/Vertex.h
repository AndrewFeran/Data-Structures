#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
public:
    Vertex(const char d) : data(d), visited(false) {};
    const char getData() const { return data; }
    bool isVisited() const { return visited; }
    void setVisited(bool v) { visited = v; }
private:
    char data;
    bool visited;
};

#endif