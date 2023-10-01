
// Bridges In A Graph
// Medium

// Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).
// For Example :
// If the given graph is :
// graph

// Then the edge between 0 and 4 is the bridge because if the edge between 0 and 4 is removed, then there will be no path left to reach from 0 to 4.and makes the graph disconnected, and increases the number of connected components.
// Note :
// There are no self-loops(an edge connecting the vertex to itself) in the given graph.

// There are no parallel edges i.e no two vertices are directly connected by more than 1 edge.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 1 <= T <= 50
// 1 <= V <= 10 ^ 3
// V-1 <= E <= 3 * 10^3
// 0 <= a, b < V

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 5 4
// 0 1
// 3 1
// 1 2
// 3 4
// 3 3
// 0 1
// 1 2
// 2 0
// Sample Output 1 :
// 4
// 0 1
// 1 2    
// 1 3
// 3 4
// 0
// Explanation For Sample Input 1 :
// For the first test case, the graph will be represented as 
// graph

// There are four bridges((0-1),(1-2),(1-3),(3-4)) in the above-given graph denoted by red lines.
// For the second test case, there is no bridge present in the given graph.
// Sample Input 2 :
// 1
// 6 7
// 1 2
// 1 0
// 0 2
// 0 4
// 5 4
// 5 3
// 3 4
// Sample Output 2 :
// 1
// 0 4
// Explanation For Sample Input 2 :
// For the first test case, the graph will be represented as 
// graph

// There is only one bridge((0-4)) in the above-given graph denoted by red lines.

#include <unordered_map>

#include <vector>

#include <list>

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,

         vector<vector<int>> &ans, unordered_map<int, list<int>> &adj,

         unordered_map<int, bool> &vis)
{

    vis[node] = true;

    disc[node] = low[node] = timer++;

    for (auto neigbour : adj[node])
    {

        if (neigbour == parent)

            continue;

        if (!vis[neigbour])
        {

            dfs(neigbour, node, timer, disc, low, ans, adj, vis);

            low[node] = min(low[node], low[neigbour]);

            // check for bridge edge

            if (low[neigbour] > disc[node])
            {

                vector<int> res;

                res.push_back(node);

                res.push_back(neigbour);

                ans.push_back(res);
            }
        }
        else
        {

            // backedge

            low[node] = min(low[node], disc[neigbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{

    // craete adj list

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];

        int v = edges[i][1];

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    // cretae data structures

    int timer = 0;

    vector<int> disc(v);

    vector<int> low(v);

    int parent = -1;

    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {

        disc[i] = -1;

        low[i] = -1;
    }

    vector<vector<int>> ans;

    // dfs

    for (int i = 0; i < v; i++)
    {

        if (!vis[i])
        {

            dfs(i, parent, timer, disc, low, ans, adj, vis);
        }
    }

    return ans;
}