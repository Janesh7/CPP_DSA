#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, vector<T>> adjList;

    void addEdge(T u, T v, bool directed) {
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (const auto& pair : adjList) {
            cout << "Vertex " << pair.first << ": ";
            for (const T& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph<int> graph;

    // Input: Number of nodes (vertices) and edges
    int nodes, edges;
    cin >> nodes >> edges;

    // Input: Edges
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        // Add edges to the graph
        graph.addEdge(u, v, false); // Use true for directed graph
    }

    // Print the adjacency list
    graph.printAdjList();

    return 0;
}
