# Depth first search

**Depth First Search (DFS)** is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It's used to traverse and search through a graph or tree data structure. Here are some detailed notes on DFS:

**Definition**:
- Depth First Search (DFS) is an algorithm used to traverse or search through a graph or tree data structure.
- It explores as far as possible along each branch before backtracking.

**Key Characteristics**:
- DFS can be applied to both directed and undirected graphs.
- It can be used for various purposes, such as searching for a specific node, checking for connectivity, and more.

**CDONT FORGET TO MARK VISTED IN START OF REC FUNC**

**Approach**:
1. Start from an initial node (usually the source node).
2. Visit the node and mark it as visited.
3. Explore all unvisited neighbors of the current node.
4. Recursively apply DFS to the unvisited neighbors.
5. Repeat steps 2-4 until all nodes are visited.

**Key Differences Between DFS and BFS**:
- DFS explores as deeply as possible along each branch before backtracking, while BFS explores all neighbors at the current level before moving to the next level.
- DFS uses a stack data structure (either explicitly or via recursion), while BFS uses a queue data structure.
- DFS may not necessarily find the shortest path in an unweighted graph, whereas BFS guarantees the shortest path.

        1. **DFS**: DFS is not guaranteed to find the shortest path in an unweighted graph. This is because DFS explores as deeply as possible along each branch before backtracking. In other words, it explores one path completely before trying another. While this approach might find a path from the source to the destination, it doesn't guarantee that it's the shortest path. DFS might first find a longer path and only later find a shorter one, but it won't backtrack to the longer path because it already marked those nodes as visited.

        2. **BFS**: BFS, on the other hand, guarantees the shortest path in an unweighted graph. It explores all nodes at the current level before moving to the next level. In other words, it explores all paths of length 1 before exploring paths of length 2, and so on. This ensures that the first time the destination node is reached, it will be via the shortest path, as BFS explores nodes level by level.

- DFS can be implemented using recursion or an explicit stack, while BFS is typically implemented using a queue.

**Pseudocode for DFS (Recursive)**:
```cpp
void DFS(Node current, unordered_set<Node>& visited) {
    if (visited.contains(current)) return;
    visited.insert(current);
    // Process current node here.
    for (Node neighbor : current.neighbors) {
        DFS(neighbor, visited);
    }
}
```

**Time Complexity (TC)**:
- The time complexity of DFS is O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph.

**Space Complexity (SC)**:
- The space complexity of DFS depends on the implementation.
- In the recursive approach, the space complexity is O(V) due to the function call stack.
- In the iterative approach (using an explicit stack), the space complexity is also O(V) because it stores nodes.

**Applications of DFS**:
- Finding connected components in a graph.
- Solving problems involving backtracking, such as the N-Queens problem.
- Detecting cycles in a graph.
- Topological sorting.
- Pathfinding in mazes.

