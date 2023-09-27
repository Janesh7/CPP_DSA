**Cycle Detection Using BFS and DFS**

Cycle detection is a fundamental problem in graph theory, where we aim to identify whether a given graph contains any cycles (loops). Cycles can be detected using both Breadth-First Search (BFS) and Depth-First Search (DFS). Let's delve into the details of how this is done for both algorithms:

**KEY: Do BFS/DFS but just add a condition that if the neighbour node is visted and the node is not the parent than cycle**

**Using BFS (Breadth-First Search):**

**Algorithm:**

1. Start from an initial node (usually the source node) and perform a BFS traversal of the graph.

2. Maintain a "visited" set or array to keep track of nodes that have been visited. Initialize all nodes as unvisited.

3. During BFS traversal, when you visit a node `u`, mark it as visited.

4. For each **adjacent node `v` of `u` that is already visited and is not the parent of `u`** (i.e., `v` is not the node from which you came to `u`), you have detected a cycle.

5. Continue the BFS traversal until you have visited all nodes in the graph or until you find a cycle. If you visit all nodes without finding a cycle, the graph is acyclic.

**Data Structures Used:**

- Queue (for BFS traversal)
- Visited array or set
- Parent mapping (to keep track of the parent node while traversing)

**Neglecting a Node:**

When using BFS for cycle detection, if you encounter an already visited node `v` that is not the parent of the current node `u`, it indicates a cycle in the graph. You can neglect `v` and move on to explore other nodes.

**Using DFS (Depth-First Search):**

**Algorithm:**

1. Start from an initial node (usually the source node) and perform a DFS traversal of the graph.

2. Maintain a "visited" set or array to keep track of nodes that have been visited. Initialize all nodes as unvisited.

3. During DFS traversal, when you visit a node `u`, mark it as visited.

4. For each adjacent node `v` of `u`, do the following:
   - If `v` is not visited, recursively explore it.
   - If `v` is already visited and is not the parent of `u`, you have detected a cycle.

5. Continue the DFS traversal until you have visited all nodes in the graph or until you find a cycle. If you visit all nodes without finding a cycle, the graph is acyclic.

**Data Structures Used:**

- Recursion stack (to keep track of the current path)
- Visited array or set
- Parent mapping (to keep track of the parent node while traversing)

**Neglecting a Node:**

When using DFS for cycle detection, if you encounter an already visited node `v` that is not the parent of the current node `u`, it indicates a cycle in the graph. You can neglect `v` and move on to explore other nodes.

**REMEMBER that the making parent condition is parent[neighbour]=front; and the parent[front]!=neighbour.. ie neighbour is visted and is not the parent of front**

**Pseudocode (C++) for Cycle Detection Using BFS:**

```cpp
bool isCyclicBFS( int src, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj ) {
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;

    q.push(src);

    while( !q.empty() ) {
        int frontNode = q.front();
        q.pop();

        for( auto neighbour : adj[frontNode] ) {
            // NOTE THE CONDITION: neighbour != parent[frontnode] which is opp to the other block 
            if( visited[neighbour] == true && neighbour != parent[frontNode] ) {
                return true;
            } else if( !visited[neighbour] ) {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}
```

**Pseudocode (C++) for Cycle Detection Using DFS:**

```cpp
// CHECK PROGRAM FOR EASIER
bool hasCycleDFS(int u, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& parent) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (hasCycleDFS(v, adjList, visited, parent)) {
                return true;
            }
        } else if (parent[u] != v) {
            // Cycle detected
            return true;
        }
    }
    return false;
}
```

**Time Complexity (BFS):** O(V + E), where V is the number of vertices, and E is the number of edges.

**Space Complexity (BFS):** O(V) for the visited and parent arrays, O(V) for the queue.

**Time Complexity (DFS):** O(V + E), where V is the number of vertices, and E is the number of edges.

**Space Complexity (DFS):** O(V) for the visited and parent arrays, O(V) for the recursion stack.

Both BFS and DFS can effectively detect cycles in a graph, and the choice between them depends on the specific requirements of your problem and the characteristics of the graph you are dealing with.