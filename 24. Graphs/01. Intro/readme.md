# Graphs

## Definitions
1. **Graph**: A graph is a mathematical structure used to represent pairwise relationships between objects. It consists of a set of vertices (nodes) and a set of edges that connect pairs of vertices.

2. **Vertex (Node)**: A fundamental unit of a graph representing an object or entity. Vertices are connected by edges.

3. **Edge**: A connection or link between two vertices in a graph. Edges can be directed (one-way) or undirected (two-way).

4. **Directed Graph (Digraph)**: A graph in which edges have a direction, meaning they go from one vertex to another. In a directed graph, the order of vertices in an edge matters.

5. **Undirected Graph**: A graph in which edges have no direction, meaning they connect vertices without a specified order.

6. **Cyclic Graph**: A graph that contains at least one cycle (a closed path where you can return to the starting vertex by following edges).

7. **Acyclic Graph**: A graph that has no cycles; it is a graph without closed paths.

8. **Degree**: The degree of a vertex is the number of edges connected to it. (usually for undirected)

9. **In-Degree**: In a directed graph, the in-degree of a vertex is the number of edges coming into it.

10. **Out-Degree**: In a directed graph, the out-degree of a vertex is the number of edges going out from it.

11. **Weighted Graph**: A graph in which each edge has a weight or cost associated with it. Weighted graphs are used to represent situations where the connections between vertices have different values.

## Types of Graphs
1. **Directed Acyclic Graph (DAG)**: A directed graph with no cycles.

2. **Tree**: A **connected acyclic graph with no cycles**. A tree has exactly one vertex called the root from which all other vertices are reachable.

3. **Complete Graph**: An undirected graph in which there is an edge between every pair of distinct vertices.

4. **Bipartite Graph**: A graph whose vertices can be divided into two **disjoint sets such that no two vertices within the same set are adjacent**. Imagine two set of nodes. Nodes from one side only connects to the other side and mot among its own set.

## Representation of Graphs
There are several ways to represent graphs, including:

1. **Adjacency Matrix**: A two-dimensional array where `matrix[i][j]` represents the presence (or weight) of an edge between vertex `i` and vertex `j`. Suitable for dense graphs.

2. **Adjacency List**: A collection of lists, where each list represents the neighbors of a vertex. Suitable for sparse graphs.

```cpp
// Example: Adjacency List Representation
unordered_map<int, vector<int>> adjList;
adjList[0] = {1, 2};
adjList[1] = {0, 2};
adjList[2] = {0, 1};
```

## Basic Code Snippets

### Graph Representation Using Adjacency List
```cpp
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph {
public:
    unordered_map<int, vector<int>> adjList;

    // Add an edge between vertices u and v
    void addEdge(int u, int v, bool directed) {
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    // Print the adjacency list
    void printAdjList() {
        for (const auto& pair : adjList) {
            cout << "Vertex " << pair.first << ": ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph;

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
```

### Generic Graph Class
```cpp
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
```

## Time and Space Complexity
- Time Complexity for Adjacency Matrix: O(V^2), where V is the number of vertices.
- Time Complexity for Adjacency List: O(E), where E is the number of edges.
- Space Complexity for Adjacency Matrix: O(V^2).
- Space Complexity for Adjacency List: O(V + E).


Explanation for using const auto& pair while iterating in for loops:
- `const auto& pair` is used for iterating over the elements in the `adjList`. Let's break it down:
    - `auto` is used to automatically deduce the type of each element in the `adjList`.
    - `const` is used to indicate that the elements should not be modified while iterating.
    - `&` (reference) is used to avoid making a copy of each element, which is more efficient in terms of memory and performance.
- By using `const auto& pair`, we can access the key (vertex) and value (list of neighbors) of the unordered map without changing them. It's a good practice to use `const` when iterating over data structures to ensure they remain unchanged during the iteration.

