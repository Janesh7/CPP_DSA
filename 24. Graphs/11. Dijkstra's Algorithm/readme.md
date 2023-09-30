# V IMP - Dijkstra's Algorithm

**Algorithm Overview:**
- Dijkstra's algorithm is used to find the **shortest path from a single source vertex to all other vertices in a weighted graph**, where all edge weights must be non-negative.
- Unlike other methods like BFS or Topological Sort (for DAGs), Dijkstra's algorithm works for graphs with weighted edges and can handle graphs with cycles, as long as there are no negative-weight edges.

**Key Differences from Other Methods:**
1. **Breadth-First Search (BFS)**: BFS finds the shortest path in an unweighted graph, where all edges have the same weight or unwieghted. Dijkstra's algorithm, on the other hand, handles weighted graphs where edges can have different weights.

2. **Topological Sort (for DAGs)**: Topological sorting is used for finding the shortest paths in a Directed Acyclic Graph (DAG). Dijkstra's algorithm can handle both directed and undirected graphs, and it doesn't require the graph to be acyclic. Additionally, **Dijkstra's algorithm can handle negative weights as long as they are not part of a cycle with a negative sum**.

**Data Structures Used and Why:**
- **Adjacency List (unordered_map<int, vector<pair<int, int>>>)**: An adjacency list is used to represent the graph efficiently. It allows us to store all neighbors of each vertex along with their edge weights.

- **Set (or Priority Queue in the second implementation)**: A set (or priority queue) is used to maintain a set of vertices with their tentative distances from the source vertex. This data structure is chosen because it allows for efficient retrieval of the vertex with the smallest tentative distance.

**Pseudocode**

```cpp
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create an adjacency list from the input edge list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(auto i: vec) {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    // Initialize distance vector with maximum values
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    // Create a set (or priority queue) to store vertices with their distances
    set<pair<int, int>> s;
    s.insert({distance[source], source});

    // While there are unprocessed vertices
    while(!s.empty()) {
        auto top = *(s.begin()); // Get the vertex with the smallest distance
        s.erase(top);

        int distancenode = top.first;
        int node = top.second;

        // Explore neighbors of the current vertex
        for(auto child : adj[node]) {
            if(distancenode + child.second < distance[child.first]) {
                auto record = s.find({distance[child.first], child.first});
                if (record != s.end())
                    s.erase(record);

                // Update distance and insert into the set
                distance[child.first] = distancenode + child.second;
                s.insert({distance[child.first], child.first});
            }
        }
    }

    return distance;
}
```

**Explanation:**
1. The algorithm starts by creating an adjacency list representation of the input graph.

2. It initializes a distance vector with maximum values, setting the distance to the source vertex as 0.

3. A set (or priority queue) is used to keep track of vertices with their tentative distances. The use of a set ensures efficient retrieval of the vertex with the smallest tentative distance.

4. The algorithm iteratively selects the vertex with the smallest tentative distance from the set

NOTE:
```cpp
 auto top = *(s.begin()); // to get the pair.. and not an iterator
```
explores its neighbors, and updates their distances if a shorter path is found.

5. The final result is a vector of shortest distances from the source to all other vertices.

**Time Complexity:**
- The time complexity of Dijkstra's algorithm using a set is O(V^2) for dense graphs and O(E + V log V) for sparse graphs, where V is the number of vertices and E is the number of edges.
- The time complexity of the second implementation using a priority queue is O(E + V log V) for all graphs.

**Space Complexity:**
- The space complexity is O(V) for storing the distance vector and O(E) for the adjacency list.


**Dijkstra's Algorithm and Negative Weights**

Dijkstra's algorithm, designed for finding shortest paths in graphs, generally assumes non-negative edge weights. However, it can handle negative weights under specific conditions:

**1. Non-Negative Paths:** Dijkstra's algorithm assumes all path weights are non-negative. It iteratively selects the node with the shortest tentative distance and explores neighbors.

**2. Negative Weights, No Cycles:** Dijkstra's works with negative weights if the graph doesn't contain negative weight cycles. It tracks the shortest distances and avoids revisiting nodes.

**3. Negative Weight Cycles:** The problem arises with negative weight cycles. These cycles can lead to infinite loops as paths can continually decrease in weight. Dijkstra's doesn't handle them and may not find correct shortest paths.

In summary, Dijkstra's algorithm is suitable for graphs with negative weights if no negative weight cycles are present. In cases of such cycles, consider algorithms like Bellman-Ford or Floyd-Warshall to handle them and determine correct shortest paths.