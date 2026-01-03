# Lec 2

# Breadth first search

**Introduction**
Breadth-First Search (BFS) is a fundamental graph traversal algorithm that explores all the vertices and edges of a graph in a breadthward motion. It starts from a source vertex and explores all its neighbors before moving on to their neighbors. BFS is widely used for various graph-related problems, such as finding the shortest path, connected components, and more.

**Data Structures Used**
1. **Visited Map**: To keep track of visited vertices.
2. **Queue**: To maintain the order of traversal, ensuring that vertices at the same level are visited before moving deeper.

**Algorithm Overview**
BFS can be summarized in five key steps:

**Step 1:** Initialize a visited map to keep track of visited vertices, initially marking all vertices as unvisited. Create a queue to store the vertices for traversal.

**Step 2:** Start from the source vertex and mark it as visited. Push it into the queue and begin traversal.

**Step 3:** While the queue is not empty, repeat the following steps:
   - **Step 3.1:** Dequeue a vertex from the front of the queue (removing it from the queue).
   - **Step 3.2:** Output the vertex or perform any desired operation on it.
   - **Step 3.3:** Explore all unvisited neighbors of the dequeued vertex.
   - **Step 3.4:** For each unvisited neighbor, mark it as visited, push it into the queue, and continue.

**Step 4:** Continue until the queue is empty, ensuring that all reachable vertices are visited.

**Step 5:** If there are unvisited vertices in the graph, select one of them as the new source and repeat the BFS process. Continue this step until all vertices are visited.

**Handling Disconnected Graphs**
- In the case of disconnected graphs (multiple disconnected components), you may have to apply BFS from multiple source vertices to ensure all components are explored. use for loop to check if all nodes are visted at end

**Pseudocode in C++**
```cpp
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

void bfs(unordered_map<int, vector<int>>& adjList, int startVertex) {
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";

        for (int neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    unordered_map<int, vector<int>> adjList;

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // If you want sorted output, use a set instead of a vector.
    }

    // Starting from vertex 0 (you can choose any starting point).
    bfs(adjList, 0);

    return 0;
}
```

**Time Complexity (TC):**
- The overall time complexity of BFS is O(V + E), where V is the number of vertices, and E is the number of edges.

**Space Complexity (SC):**
- The space complexity is O(V) due to the visited map and queue, where V is the number of vertices in the graph.

**Note:** To ensure sorted output of neighbors, you can use a `set` instead of a `vector` in the adjacency list, as mentioned in the pseudocode.


**Applications of BFS**:

BFS has several important applications in computer science and various domains:

1. **Shortest Path Finding**: As mentioned earlier, BFS is used to find the shortest path between two nodes in an unweighted graph.

2. **Connectivity**: BFS can determine whether a graph is connected or not. If BFS can visit all nodes starting from a source node, the graph is connected; otherwise, it's disconnected.

3. **Network Routing**: BFS is used in network routing algorithms to find the shortest path between routers or nodes in a computer network.

4. **Web Crawling**: Web crawlers or spiders use BFS to index web pages. Starting from a seed URL, they follow links to explore web pages systematically.

5. **Maze Solving**: BFS can be employed to find the shortest path through a maze, where each cell represents a point in the maze.

6. **Social Network Analysis**: BFS is used in social network analysis to find the degrees of separation between individuals in a social network (e.g., the "Six Degrees of Kevin Bacon" game).

7. **Puzzle Solving**: BFS can be used to solve puzzles like the 15-puzzle or the Rubik's Cube by exploring possible moves and states.

8. **Shortest Flight Paths**: In air travel, BFS can help find the shortest flight path between two airports, considering stopovers and connections.

9. **Image Processing**: In image processing, BFS is used for tasks like region growing, connected component analysis, and contour tracing.

