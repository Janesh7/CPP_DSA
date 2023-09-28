**TIMP: opological Sorting in Directed Acyclic Graphs (DAGs)**

Topological sorting is a linear ordering of vertices in a directed graph, such that for every directed edge `(u, v)`, vertex `u` comes before `v` in the ordering. This concept is primarily used in directed acyclic graphs (DAGs) to represent dependencies or precedence relationships. Let's delve into the details of topological sorting:

**Directed Acyclic Graph (DAG):**

- A directed acyclic graph (DAG) is a graph in which there are no cycles. In other words, there is no way to start at a vertex and follow a sequence of directed edges that eventually leads back to the same vertex.

- DAGs are commonly used to model systems with dependencies or tasks that must be executed in a specific order. Examples include project scheduling, task execution, and course prerequisites.

**NOTE: Here we use a stack.. therefore as soon as we find a node which cant be propagated(no more adj ele to traverse) we add it to the stack.. therefore it adds nodes which cant be propagated to satck so .. due to its LIFO property the first added elements will be the last one to come out**

**Topological Sorting Algorithm:**

The topological sorting algorithm works as follows:

1. Initialize an empty stack to store the topological ordering.

2. Start a Depth-First Search (DFS) traversal from any unvisited vertex in the DAG.

3. During the DFS traversal, when you visit a vertex `u`, mark it as visited and recursively visit all its adjacent vertices that have not been visited yet.

4. Once you have visited all the adjacent vertices of `u` and explored its subtree, push `u` onto the stack. **This step ensures that vertices with no outgoing edges appear at the top of the stack.**

5. Continue the DFS traversal until all vertices are visited.

6. Pop vertices from the stack one by one. The order in which you pop them will be the topological ordering of the vertices.

**Why Doesn't Topological Sorting Work for Cyclic Graphs?**

- Topological sorting relies on the absence of cycles in a graph. If a graph contains cycles, it cannot have a valid topological ordering because you cannot define a linear order for nodes involved in cycles. Cycles create ambiguity in the ordering of dependent tasks or elements.

- Therefore, topological sorting is meaningful and applicable only to DAGs.

**Using Topological Sorting to Detect Cycles:**

- One interesting application of topological sorting is that it can be used to detect cycles in a graph. If a graph has a cycle, it cannot have a valid topological ordering.

- While performing topological sorting, if at any point there are still unvisited vertices, but you reach a visited vertex, it indicates a cycle in the graph. This is because you should have visited all ancestors of a node before visiting that node in a valid topological ordering.

**Pseudocode (C++) for Topological Sorting:**

```cpp
void topologicalSortDFS(int u, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& topoOrder) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            topologicalSortDFS(v, adjList, visited, topoOrder);
        }
    }
    topoOrder.push(u);
}

vector<int> topologicalSort(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    stack<int> topoOrder;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            topologicalSortDFS(i, adjList, visited, topoOrder);
        }
    }

    vector<int> result;
    while (!topoOrder.empty()) {
        result.push_back(topoOrder.top());
        topoOrder.pop();
    }

    return result;
}
```

**Time Complexity (DFS for Topological Sorting):** O(V + E), where V is the number of vertices, and E is the number of edges.

**IMP NOTE: Sometimes using maps cause TLE.. instead use a vector for visited etc to prevent it**

**Space Complexity (DFS for Topological Sorting):** O(V) for the visited array and stack, where V is the number of vertices.

Topological sorting is a fundamental algorithm with applications in various domains, including build systems, task scheduling, and dependency resolution. It allows us to determine a valid sequence of tasks or elements while respecting their dependencies.

Consider a simple example of a directed acyclic graph (DAG) and perform topological sorting on it. In this example, we'll represent the graph using an adjacency list and then apply the topological sorting algorithm.

**Example Graph:**

Let's assume we have a DAG that represents course dependencies in a university curriculum:

Courses (Vertices):
- A (Art)
- B (Biology)
- C (Calculus)
- D (Data Structures)
- E (English)
- F (French)

Dependencies (Edges):
- A -> C (Art requires Calculus)
- B -> C (Biology requires Calculus)
- C -> D (Calculus requires Data Structures)
- D -> E (Data Structures require English)
- E -> F (English requires French)

Here's the representation of this DAG as an adjacency list:

```
A -> C
B -> C
C -> D
D -> E
E -> F
```

**Illustration of the DAG:**

```
   A      B
    \    /
     C
     |
     D
     |
     E
     |
     F
```

**Topological Sorting:**

Let's apply the topological sorting algorithm to find a valid sequence of courses based on their dependencies. We start with any unvisited node and perform DFS.

1. Start with an unvisited node, for example, 'A'.
2. Explore 'A' and its dependencies, pushing them onto the stack. In this case, we push 'C' onto the stack.
3. Move to 'C' and explore its dependencies, pushing 'D' onto the stack.
4. Move to 'D' and explore its dependencies, pushing 'E' onto the stack.
5. Move to 'E' and explore its dependencies, pushing 'F' onto the stack.
6. 'F' has no further dependencies, so we push it onto the stack.
7. Continue this process until all nodes are visited.

After this process, the stack will contain the topological ordering of the courses:

```
Topological Ordering: F -> E -> D -> C -> B -> A
```

This sequence represents a valid order in which a student can take these courses while satisfying their prerequisites.