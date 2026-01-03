**Kruskal's Algorithm**

**Disjoint Set Data Structure:**
- Kruskal's algorithm uses a Disjoint Set data structure (also known as Union-Find) to efficiently manage connected components and detect cycles in a graph.
- It has two main operations: `Find` to determine which set a particular element belongs to and `Union` to merge two sets into one.

**Union by Rank and Path Compression:**
- To optimize the Disjoint Set data structure, Kruskal's algorithm employs two techniques:
  - **Union by Rank**: Each set (component) is assigned a rank based on its depth in the tree. When two sets are merged, the one with the lower rank is attached to the one with the higher rank, minimizing the tree's depth.
  - **Path Compression**: When performing `Find` (to find the representative of a set), path compression ensures that each node on the path to the root directly points to the root. This helps reduce the time complexity of `Find` operations.

**Algorithm Overview:**
- Kruskal's algorithm finds the Minimum Spanning Tree (MST) of a weighted, connected, and undirected graph.
- It starts with an empty set of edges and repeatedly adds the smallest edge that does not form a cycle.

**IMP: Basically we just initialize each vertex as an INDIVIDUAL components.. we find the shortest edges and then check if both the vertex are in the same component(if both the vertex are alr in the same component adding this edge would lead to cycle.. hence ignore this edge).. since all the nodes are individual components in the begining we include the shortest edge and make those 2 a component.. we keep on adding to the componets.. till all the vertexes are covered**

**In disjoint set .. we find the top most parent.. if they are same.. the edge would lead to cycle.. if different safe to include the edge**

**Data Structures Used and Why:**
- **Disjoint Set (Union-Find)**: This data structure is used to manage connected components efficiently, detect cycles, and merge sets with union by rank and path compression.
- **Edges List with Sorting**: The edges are initially stored in a list and sorted by weight to select the smallest edge first.


**Pseudocode (Kruskal's Algorithm):**

```cpp
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2]; // Comparator to sort edges by weight (which is at 3(2nd index).. as (vertex1,vertex2,weight))
}

void makeset(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Initialize each element as its own set
        rank[i] = 0;   // Initialize rank to 0
    }
}

int findParent(vector<int> &parent, int node) {
    if (parent[node] == node) { // We have initailed all the nodes as parent to itself.. so when we find such node(there is no parent above) we can return 
        return node;
    }
    return parent[node] = findParent(parent, parent[node]); // Path compression - reursive find the node .. and when found just directly attach it to its parent so we dont have to go each time again and again
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        // Both are equal.. so any can be parent.. just make sure to increase parents rank (v here is parent of u)
        parent[u] = v;
        rank[v]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n) {
    sort(begin(edges), end(edges), cmp); // Sort edges by weight
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n);

    int maxweight = 0; // Total weight of MST

    for (int i = 0; i < edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];

        // if vertices are from different component then merge.. 
        if (u != v) { // No cycle is formed
            maxweight += w; // Add edge weight to MST
            unionset(u, v, parent, rank); // Merge sets
        }
    }

    return maxweight; // Return the total weight of MST
}
```

**Explanation:**
1. The algorithm starts with an empty set of edges and sorts the edges by weight.

2. It initializes each element as its own set with rank 0 and uses the Disjoint Set data structure to manage connected components efficiently.

3. The algorithm iterates through the sorted edges, adding each edge to the MST if it does not form a cycle. If an edge is added, it is also included in the MST, and the corresponding sets are merged.

4. The result is the total weight of the MST.

**Time Complexity:**
- The time complexity of Kruskal's algorithm is O(E log E), where E is the number of edges, primarily due to sorting the edges.

**Space Complexity:**
- The space complexity is O(V) for storing the parent and rank arrays, and O(E) for storing the edges.