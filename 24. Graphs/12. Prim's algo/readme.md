**Prim's Algorithm**

**Spanning Tree and Minimum Spanning Tree (MST):**
- In a graph, a spanning tree is a subgraph that is a **tree (a connected acyclic graph) and includes all the vertices of the original graph.**
- A Minimum Spanning Tree (MST) of a weighted graph is a spanning tree with the **minimum possible total edge weight.**
- MSTs are used in various applications, such as network design, cluster analysis, and approximation algorithms.

**Algorithm Overview:**
- Prim's algorithm is used to find the Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph.
- It starts with an arbitrary vertex and **repeatedly adds the nearest vertex** to the growing MST while **ensuring that no cycles** are formed.

**Key Differences from Other Methods:**
1. **Kruskal's Algorithm**: Both Kruskal's and Prim's algorithms find the MST, but they use different approaches. Kruskal's algorithm focuses on selecting edges based on weight, whereas Prim's algorithm focuses on selecting neighbouring nearest vertices.

**Data Structures Used and Why:**
- **Adjacency List with Total Distance and Parent Vector**: An adjacency list is used to represent the graph efficiently, including edge weights. Additionally, a parent vector is maintained to reconstruct the MST.
- **Priority Queue**: A priority queue is used to efficiently find the nearest vertex to the growing MST. The priority queue prioritizes vertices based on their edge weights to the MST.

**Pseudocode with Comments (Prim's Algorithm):**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> primMST(vector<vector<pair<int, int>>>& graph, int vertices) {
    vector<pair<int, int>> mst; // Stores the edges of the MST
    vector<bool> inMST(vertices, false); // Tracks vertices included in MST
    vector<int> key(vertices, INT_MAX); // Stores the minimum edge weight to each vertex
    vector<int> parent(vertices, -1); // Parent of each vertex in MST
    
    // Start with the first vertex (can be any vertex)
    int start = 0;
    key[start] = 0;

    // Priority queue to select the minimum key vertex
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue; // Skip if already in MST
        inMST[u] = true;

        // Add the edge to the MST
        if (parent[u] != -1)
            mst.push_back({parent[u], u});

        // Update key values and enqueue adjacent vertices
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    return mst;
}
```
See code for n^2 TC code (linear search instead of logn for priority q)

**Explanation:**
1. The algorithm starts with an arbitrary vertex and initializes key values to infinity (INT_MAX), parent values to -1, and inMST values to false.

2. It uses a priority queue to select the vertex with the smallest key value (minimum edge weight) at each step.

3. The selected vertex is added to the MST, and its inMST value is set to true.

4. The algorithm updates key values and parent values for adjacent vertices if they have a lower edge weight and are not yet in the MST.

5. The result is a list of edges (mst) that form the MST of the graph.

**Time Complexity:**
- The time complexity of Prim's algorithm with a priority queue(sorting edges) is O(E + V log V), where V is the number of vertices and E is the number of edges.

**Space Complexity:**
- The space complexity is O(V) for storing the parent, key, and inMST vectors, and O(E) for the adjacency list.

**REASONING**

The reason for using `w < key[v]` in Prim's algorithm, unlike Dijkstra's algorithm where we use `dist[u] + w < key[v]`, is rooted in the nature of these two algorithms and their objectives:

1. **Prim's Algorithm (Minimum Spanning Tree):**
   - Prim's algorithm aims to construct a minimum spanning tree (MST) from a given graph.
   - In Prim's algorithm, the `key[v]` represents the minimum weight of an edge that connects vertex `v` to the already selected vertices in the MST.
   - When we encounter a new edge `(u, v)` in Prim's algorithm, we want to check if `w` (the weight of the edge `(u, v)`) is less than the current `key[v]`. If it is, it means that we can reach vertex `v` from the MST using this edge `(u, v)` with a smaller weight than the current known minimum, so we update `key[v]` with this smaller weight.

2. **Dijkstra's Algorithm (Shortest Path):**
   - Dijkstra's algorithm, on the other hand, is used to find the shortest path from a single source vertex to all other vertices in a weighted graph.
   - In Dijkstra's algorithm, `dist[v]` represents the shortest known distance from the source vertex to vertex `v`.
   - When we encounter a new edge `(u, v)` in Dijkstra's algorithm, we check if `dist[u] + w` (the distance to `u` plus the weight of the edge `(u, v)`) is less than the current `dist[v]`. If it is, it means we have found a shorter path to vertex `v`, so we update `dist[v]` with this shorter distance.

In summary:

- In Prim's algorithm, we are interested in finding the minimum weight edges to expand the MST, so we compare the weight of the current edge `w` directly with the known minimum `key[v]`.
- In Dijkstra's algorithm, we are interested in finding the shortest paths, so we compare the sum of the known distance to `u` and the weight of the current edge `w` with the known distance `dist[v]`.