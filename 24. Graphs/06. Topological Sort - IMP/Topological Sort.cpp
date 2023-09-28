// Topological Sort
// Medium

// A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
// Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
// Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.
// For example, Consider the DAG shown in the picture.
// alt tex

// In this graph, there are directed edges from 0 to 1 and 0 to 3, so 0 should come before 1 and 3. Also, there are directed edges from 1 to 2 and 3 to 2 so 1 and 3 should come before 2.
// So, The topological sorting of this DAG is {0 1 3 2}.
// Note that there are multiple topological sortings possible for a DAG. For the graph given above one another topological sorting is: {0, 3, 1, 2}
// Note:
// 1. It is guaranteed that the given graph is DAG.
// 2. There will be no multiple edges and self-loops in the given DAG.
// 3. There can be multiple correct solutions, you can find any one of them. 
// 4. Don’t print anything, just return an array representing the topological sort of the vertices of the given DAG.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints:
// 1 <= T <= 50
// 1 <= V <= 10^4
// 0 <= E <= 10^4
// 0 <= u, v < V 

// Where ‘T’ is the total number of test cases, ‘V’ is the number of vertices, ‘E’ is the number of edges, and ‘u’ and ‘v’ both represent the vertex of a given graph.

// Time limit: 2 sec
// Sample Input 1:
// 2
// 2 1
// 1 0
// 3 2
// 0 1
// 0 2
// Sample Output 1:
// 1 0
// 0 2 1
// Explanation Of Sample Input 1:
// Test case 1:
// The number of vertices ‘V’ = 2 and number of edges ‘E’ = 1.
// The graph is shown in the picture: 
// alt text

// The topological sorting of this graph should be {1, 0}  as there is a directed edge from vertex 1 to vertex 0, thus 1 should come before 0 according to the given definition of topological sorting.

// Test case 2:
// The number of vertices ‘V’ = 3 and number of edges ‘E’ = 2.
// The graph is shown in the picture:
// alt text

// As there are two directed edges starting from 0, so 0 should come before 1 and 2 in topological sorting. 
// Thus the topological sorting of this graph should be {0, 2, 1} or {0, 1, 2}
// Sample Input 2:
// 2
// 1 0
// 4 4
// 0 1
// 0 3
// 1 2
// 3 2
// Sample Output 2:
// 0
// 0 1 3 2
// Explanation Of Sample Input 2:
// Test case 1:   
// There is only a single vertex in the graph that is 0, so its topological sort will be {0}.

// Test case 2:
// See problem statement for its explanation


#include <bits/stdc++.h>
void DFStopsort(int node, unordered_map<int, list<int>> &adjList,
                vector<int> &visited, stack<int> &topOrder) {
  visited[node] = true;
  for (auto i:adjList[node]){
      if (!visited[i])
      {
          DFStopsort(i, adjList, visited, topOrder);
      }
  }
  topOrder.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
  // Write your code here
  unordered_map<int, list<int>> adjList;

  for (auto i : edges) {
    int u = i[0];
    int v = i[1];

    adjList[u].push_back(v);
  }

  vector<int>visited(v);
  stack<int> topOrder;

  for (int i = 0; i < v; i++) {
    if (!visited[i])
    {
        DFStopsort(i, adjList, visited, topOrder);
    }
  }
  vector<int> ans;
  while (!topOrder.empty()) {
      int temp = topOrder.top();
      ans.push_back(temp);
      topOrder.pop();
  }
  return ans;
}