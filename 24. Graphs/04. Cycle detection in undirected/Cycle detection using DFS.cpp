#include<unordered_map>
#include<queue>
#include<list>

bool isCyclicDFS( int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {
    visited[node] = true;

    for( auto neighbour: adj[node] ) {
        if( !visited[neighbour] ) {
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
            if(cycleDetected)
                return true;
        }
        else if( neighbour != parent ){
            //cycle present
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create adjacency list
    unordered_map<int, list<int> > adj;
    for( int i = 0; i < m; i++ ) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    for( int i = 0; i < n; i++ ) {
        if( !visited[i] ) {
            
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans)
                return "Yes";
        }
    }
    return "No";
}