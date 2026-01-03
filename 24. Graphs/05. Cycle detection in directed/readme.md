**Finding a Cycle in a Directed Graph**

Detecting a cycle in a directed graph is a crucial problem in graph theory. Unlike an undirected graph, where a cycle can be detected using simpler methods, a directed graph requires a more specific approach. Let's dive into the details of how to find a cycle in a directed graph:

**Algorithm:**

1. Start from an initial node and perform a Depth-First Search (DFS) traversal of the graph.

2. Maintain two sets or arrays: `visited` and `dfsVisited`, initialized to all `false`.

3. During DFS traversal, when you visit a node `u`, mark it as visited (`visited[u] = true`) and mark it as DFS visited (`dfsVisited[u] = true`).

4. For each adjacent node `v` of `u`, do the following:
   - If `v` is not visited, recursively explore it.
   - If `v` is already visited but **is still being explored** (i.e., `dfsVisited[v] == true`), you have detected a cycle in the graph.

5. After completing the DFS traversal of a node `u`, mark it as no longer being explored (`dfsVisited[u] = false`).

6. Continue the DFS traversal until you have visited all nodes in the graph or until you find a cycle. If you visit all nodes without finding a cycle, the graph is acyclic.

**Explanation:**

- The reason an undirected graph cannot be used here is that it can contain bidirectional edges, which may lead to false cycle detections. In a directed graph, edges have a clear direction, allowing us to distinguish cycles.

- The condition for detecting a cycle in the directed graph is that if you encounter an already visited node `v` that is currently being explored (`dfsVisited[v] == true`), it indicates a cycle in the graph. This is because **you have reached a node that is part of the current traversal path.**

- We use two sets or arrays, `visited` and `dfsVisited`, for different purposes. `visited` keeps track of nodes that have been visited at least once, while `dfsVisited` keeps track of nodes that are currently part of the DFS traversal path. When a node completes its DFS traversal, it is no longer being explored (`dfsVisited[u] = false`).

**Pseudocode (C++) for Finding a Cycle in a Directed Graph:**

```cpp
bool hasCycleDFS(int u, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& dfsVisited) {
    visited[u] = true;
    dfsVisited[u] = true;

    for (int v : adjList[u]) {
        if (!visited[v]) {
            if (hasCycleDFS(v, adjList, visited, dfsVisited)) {
                return true;
            }
        } else if (dfsVisited[v]) {
            // Cycle detected
            return true;
        }
    }

    dfsVisited[u] = false; // No longer being explored
    return false;
}

bool hasCycleDirectedGraph(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<bool> dfsVisited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && hasCycleDFS(i, adjList, visited, dfsVisited)) {
            return true;
        }
    }

    return false;
}
```

**Time Complexity (DFS):** O(V + E), where V is the number of vertices, and E is the number of edges.

**Space Complexity (DFS):** O(V) for the visited and dfsVisited arrays, O(V) for the recursion stack.

This algorithm effectively detects cycles in a directed graph and is a fundamental tool in various applications such as scheduling, network analysis, and constraint satisfaction problems.