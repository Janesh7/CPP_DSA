#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    // Write your code here
    unordered_map<int, list<int>> adjList;
    vector<int> inDegree(v, 0);
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];

        adjList[u].push_back(v);
        // Make indegree as well
        inDegree[v]++;
    }
    queue<int> q;

    //  Insert all 0 indegree nodes to queue
    for (int i = 0; i < v; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int f = q.front();
        ans.push_back(f);
        q.pop();
        for (auto neighbour : adjList[f])
        {
            // Act like we have removed the node and its edges .. therefore remove all count of edges to its neighbours
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return ans;
}