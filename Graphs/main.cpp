#include "Graph.h"
#include <iostream>
using namespace std;

int main() {
    // Create a larger graph with 8 vertices
    Graph g(8);
    
    // Add edges to create a more complex graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
    
    cout << "Graph Structure:" << endl;
    cout << "Vertex 0 -> 1, 2" << endl;
    cout << "Vertex 1 -> 3, 4" << endl;
    cout << "Vertex 2 -> 5, 6" << endl;
    cout << "Vertex 3 -> 7" << endl;
    cout << "Vertex 4 -> 7" << endl;
    cout << "Vertex 5 -> 7" << endl;
    cout << "Vertex 6 -> 7" << endl;
    cout << "Vertex 7 -> (none)" << endl;
    
    cout << "\nBreadth First Traversal (starting from vertex 0): ";
    g.BFS(0);
    
    cout << "\nDepth First Traversal (starting from vertex 0): ";
    g.DFS(0);
    
    cout << "\n\nBreadth First Traversal (starting from vertex 3): ";
    g.BFS(3);
    
    cout << "\nDepth First Traversal (starting from vertex 3): ";
    g.DFS(3);
    
    return 0;
}