// Prim's MST
// Medium
// You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.
// For Example :
// alt text

// The MST (Minimum Spanning Tree) for the above graph is:
// alt text

// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 1 ≤ T ≤ 5
// 2 <= N <= 100
// 1 <= M <= min(1000, N(N - 1) / 2)
// 1 <= E[i][0], E[i][1] <= N


// Time Limit: 1 sec
// Sample Input 1 :
// 1
// 5 14
// 1 2 2
// 1 4 6
// 2 1 2
// 2 3 3
// 2 4 8
// 2 5 5
// 3 2 3
// 3 5 7
// 4 1 6
// 4 2 8
// 4 5 9
// 5 2 5
// 5 3 7
// 5 4 9
// Sample Output 1 :
// 1 2 2
// 1 4 6
// 2 3 3
// 2 5 5
// Explanation Of Input 1 :
// The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 2, (1,4) with weight 6, (2,3) with weight 3 and (2,5) with weight 5.
// Sample Input 2 :
// 1
// 5 15
// 1 2 21
// 1 4 16
// 2 1 12
// 2 3 13
// 2 4 18
// 2 5 15
// 3 2 13
// 3 5 17
// 4 1 16
// 4 2 18
// 4 5 19
// 5 1 18
// 5 2 15
// 5 3 17
// 5 4 19
// Sample Output 2 :
// 1 2 12
// 1 4 16
// 2 3 13
// 2 5 15
// Explanation Of Input 2 :
// The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 12, (1,4) with weight 16, (2,3) with weight 13 and (2,5) with weight 15.
// 


#include <bits/stdc++.h>

// Define a function to calculate the Minimum Spanning Tree (MST) using Prim's algorithm.
// The function takes the number of nodes 'n', the number of edges 'm', and a vector 'g'
// representing the graph's edges as input.
std::vector<std::pair<std::pair<int, int>, int>> calculatePrimsMST(int n, int m, std::vector<std::pair<std::pair<int, int>, int>> &g)
{
    // Create an adjacency list to represent the graph.
    std::unordered_map<int, std::list<std::pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        // Add edges to the adjacency list.
        adj[u].push_back(std::make_pair(v, w));
        adj[v].push_back(std::make_pair(u, w));
    }

    // Initialize arrays and vectors for key values, MST inclusion, and parent nodes.
    std::vector<int> key(n + 1);   // Minimum distance to nodes.
    std::vector<int> mst(n + 1);   // Whether nodes are included in MST.
    std::vector<int> parent(n + 1);// Parent node of each node in the MST.

    // Initialize key values, parent nodes, and MST inclusion status.
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;    // Initialize distances to infinity.
        parent[i] = -1;      // Initialize parent as -1.
        mst[i] = false;      // None of the nodes are in MST initially.
    }

    // Start with the first node (1) and set its key to 0.
    key[1] = 0;
    parent[1] = -1;

    // Perform Prim's algorithm to construct the MST.
    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // Find the node with the minimum key value not yet included in the MST.
        for (int v = 1; v <= n; v++)
        {
            // Check if the node is not in MST and has a smaller key value.
            if (mst[v] == false && key[v] < mini)
            {
                u = v;       // Update the current minimum node.
                mini = key[v];// Update the minimum key value.
            }
        }

        // Mark the minimum key node as included in MST.
        mst[u] = true;

        // Check its adjacent nodes and update key values and parent nodes.
        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;

            // If the adjacent node is not in MST and the weight is smaller, update key and parent.
            if (mst[v] == false && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    // Create a vector to store the MST edges and their weights.
    std::vector<std::pair<std::pair<int, int>, int>> result;

    // Build the MST edges and their weights based on parent information.
    // Start from 2 since the parent of the first node is -1 and is not included.
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result; // Return the MST edges and their weights.
}
