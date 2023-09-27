// Cycle Detection In Undirected Graph
// profile
// Contributed by
// Ambuj verma
// Medium
// yellow-spark
// 80/80


// 136 upvotes
// AmazonAdobeSamsung
// +14 more
// Problem Statement
// Suggest Edit
// You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.
// Your task is to find if the graph contains a cycle or not.
// A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.
// Example :
// In the below graph, there exists a cycle between vertex 1, 2 and 3. 
// Example

// Note:
// 1. There are no parallel edges between two vertices.

// 2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

// 3. The graph can be disconnected.
// For Example :
// Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
// Output: Yes

// Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 5000
// 0 <= M <= min(5000, (N * (N - 1)) / 2)
// 1 <= edges[i][0] <= N 
// 1 <= edges[i][1] <= N 

// Time Limit: 1 sec 
// Sample Input 1:
// 1
// 3 2
// 1 2
// 2 3
// Sample Output 1:
// No
// Explanation Of Sample Output 1:
//  The above graph can be represented as 
// Example

// There are a total of 3 vertices in the graph.There is an edge between vertex 1 and 2 and vertex 2 and 3. So, there is no cycle present in the graph. 
// Sample Input 2:
// 2
// 4 0 
// 4 3
// 1 4
// 4 3
// 3 1
// Sample Output 2:
// No
// Yes

#include<unordered_map>
#include<queue>
#include<list>

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