// Minimum Spanning Tree
// Medium

// You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices (numbered from 0 to V-1) and E number of edges.
// Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.
// By definition, a minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 2 <= V <= 10^5
// 1 <= E <= 3 * 10^5
// 0 <= X < N
// 0 <= Y < N
// 1 <= W <= 10^4

// where V and E represent the number of vertices and edges respectively.
// X and Y represent the vertices between which there is an edge.
// W is the weight of the edge.

// Time limit: 1sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 9
// Explanation For Sample Input 1:
// The edge (2,3) having weight 8 will be excluded from the MST. The total weight of the MST then will be 1 + 3 + 5 = 9.
// Sample Input 2:
// 4 4
// 1 2 6
// 2 3 2
// 1 3 2
// 1 0 2
// Sample Output 2:
// 6


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
    return maxweight;
}