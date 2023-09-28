#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

bool DFScyclDetect(int node, unordered_map<int, list<int>> &adjList,
                   unordered_map<int, bool> &visited,
                   unordered_map<int, bool> &DFSprocessing) {
  visited[node] = true;
  DFSprocessing[node] = true;

  for (auto i : adjList[node]) {
    if (!visited[i]) {
      if (DFScyclDetect(i, adjList, visited, DFSprocessing)) {
        return true;
      }
    } else if (DFSprocessing[i]) {
      return true;
    }
  }

  DFSprocessing[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  // Create adj list
  unordered_map<int, list<int>> adjList;
  for (auto i : edges) {
    int u = i.first;
    int v = i.second;

    adjList[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  unordered_map<int, bool> DFSprocessing;

  for (auto i : adjList) {
    if (!visited[i.first]) {
      int node = i.first;
      bool ans = DFScyclDetect(node, adjList, visited, DFSprocessing);
      if (ans) {
        return 1;
      }
    }
  }
  return 0;
}

