#include "Graph.h"

int main() {
    Graph g;
    // Create a more complex graph with 8 vertices
    g.addVertex('A'); // Starting point
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');
    g.addVertex('F');
    g.addVertex('G');
    g.addVertex('H');

    // Add edges with various weights
    // Multiple paths from A to other vertices
    g.addEdge('A', 'B', 10);
    g.addEdge('A', 'C', 15);
    g.addEdge('A', 'D', 30);
    
    // Intermediate connections
    g.addEdge('B', 'C', 12);
    g.addEdge('B', 'E', 25);
    g.addEdge('C', 'D', 10);
    g.addEdge('C', 'F', 40);
    g.addEdge('D', 'F', 22);
    g.addEdge('D', 'G', 18);
    g.addEdge('E', 'F', 15);
    g.addEdge('E', 'H', 12);
    g.addEdge('F', 'G', 8);
    g.addEdge('F', 'H', 20);
    g.addEdge('G', 'H', 10);
    
    // Create some cycles and alternative paths
    g.addEdge('B', 'D', 28);
    g.addEdge('C', 'G', 45);
    g.addEdge('E', 'G', 30);
    
    // Print the graph structure
    g.printGraph();
    
    // Run Dijkstra's algorithm
    g.shortestPath('A');

    return 0;
}