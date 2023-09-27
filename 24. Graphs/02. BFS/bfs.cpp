#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// Function to perform BFS on a single connected component of the graph.
void bfsComponent(unordered_map<int, set<int>> &adjList, int startVertex, unordered_map<int, bool> &visited)
{
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty())
    {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";

        for (int neighbor : adjList[currentVertex])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Function to perform BFS on the entire graph (including disconnected components).
void bfsDisconnectedGraph(unordered_map<int, set<int>> &adjList)
{
    unordered_map<int, bool> visited;

    for (auto &pair : adjList)
    {
        int vertex = pair.first;

        if (!visited[vertex])
        {
            bfsComponent(adjList, vertex, visited);
        }
    }
}
void printAdjList(unordered_map<int, set<int>> &adjList)
{
    for (const auto &pair : adjList)
    {
        cout << "Vertex " << pair.first << ": ";
        for (const auto &neighbor : pair.second)
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    unordered_map<int, set<int>> adjList;

    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].insert(v);
        adjList[v].insert(u); // For undirected graph.
    }

    cout << "BFS Traversal for the entire graph: ";
    printAdjList(adjList);
    bfsDisconnectedGraph(adjList);

    return 0;
}
