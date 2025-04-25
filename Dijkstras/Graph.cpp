#include "Graph.h"
#include <iostream>
#include <limits>
#include <queue>

int Graph::getVertexIndex(const char location) const {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].getData() == location) {
            return i;
        }
    }
    return -1;  // Not found
}

void Graph::addVertex(const char location) {
    // Check if vertex already exists
    if (getVertexIndex(location) == -1) {
        vertices.push_back(location);
        adjlist.push_back(vector<Edge>()); // Add empty adjacency list
    }
}

void Graph::addEdge(const char origin, const char destination, int distance) {
    // Add vertices if they don't exist
    addVertex(origin);
    addVertex(destination);
    
    // Get indices
    int originIndex = getVertexIndex(origin);
    
    // Add edge
    adjlist[originIndex].push_back(Edge(destination, distance));
}

void Graph::printGraph() const {
    for (int i = 0; i < vertices.size(); i++) {
        cout << "Vertice: " << vertices[i].getData() << " connects to:\n";
        for (const Edge& edge : adjlist[i]) {
            cout << "  -> " << edge.destination <<
                " (Distance: " << edge.distance << ")\n";
        }
        cout << endl;
    }
}

void Graph::countDirectConnections() const {
    cout << "Direct Connections" << endl;

    vector<int> totalConnections(vertices.size(), 0);

    // Get all Connections
    for (int i = 0; i < vertices.size(); i++) {
        totalConnections[i] += adjlist[i].size();
        for(int j = 0; j < adjlist[i].size(); j++){
            totalConnections[getVertexIndex(adjlist[i][j].destination)]++;
        }
    }
    // Print Connections
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i].getData() << " \t" << totalConnections[i] << endl;
    }
}

void Graph::shortestPath(char s) {
    // set all the vertices as unvisited
    for (auto it : vertices) { it.setVisited(false); }
    // create a list of the shortest path lengths
    std::vector<int> shortest_path_lengths(vertices.size(),
        std::numeric_limits<int>::infinity());
    // create the list of previous vertices (for determining shortest path)
    std::vector<char> prev_vertex(vertices.size(), '\0');
    // find the source vertex index
    int source_idx = getVertexIndex(s);
    shortest_path_lengths[source_idx] = 0;
    
    std::priority_queue<std::pair<int, int>, 
        std::vector<std::pair<int, int>>, 
        std::greater<std::pair<int, int>>> pq;

    pq.push({0, source_idx});

    while(!pq.empty()) {
        int u_dist = pq.top().first;
        int u_idx = pq.top().second;
        pq.pop();

        if (u_dist > shortest_path_lengths[u_idx]) continue;

        vertices[u_idx].setVisited(true);

        for (auto edge : adjlist[u_idx]) {
            int v_idx = getVertexIndex(edge.destination);
            int weight = edge.distance;

            int new_dist = shortest_path_lengths[u_idx] + weight;

            if (shortest_path_lengths[v_idx] == std::numeric_limits<int>::infinity() || 
                new_dist < shortest_path_lengths[v_idx]) {
                shortest_path_lengths[v_idx] = new_dist;
                prev_vertex[v_idx] = vertices[u_idx].getData();

                pq.push({new_dist, v_idx});
            }
        }
    }

    printShortestPaths(s, shortest_path_lengths, prev_vertex);
}

// Helper method to print the results
void Graph::printShortestPaths(char source, const std::vector<int>& distances, 
        const std::vector<char>& previous) {
    std::cout << "Shortest paths from " << source << ":\n";

    for (int i = 0; i < vertices.size(); i++) {
        char dest = vertices[i].getData();

        if (dest == source) continue;

        std::cout << "  To " << dest << ": ";

        if (distances[i] == std::numeric_limits<int>::infinity()) {
            std::cout << "No path exists\n";
            continue;
        }

        std::cout << distances[i] << " via path ";

        // Reconstruct path
        std::vector<char> path;
        char current = dest;

        while (current != source) {
            path.push_back(current);
            int current_idx = getVertexIndex(current);
            current = previous[current_idx]; // Simplified path reconstruction
            if (current == '\0') break; // No previous vertex found
        }

        path.push_back(source);

        // Print path in correct order
        for (int j = path.size() - 1; j >= 0; j--) {
            std::cout << path[j];
            if (j > 0) std::cout << " -> ";
        }

        std::cout << "\n";
    }
}