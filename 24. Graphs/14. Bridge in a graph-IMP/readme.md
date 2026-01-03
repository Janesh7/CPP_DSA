REVISE VID/GFG
# Bridge in a Graph - IMP

**Definition:**
- In graph theory, a bridge is an edge in a graph whose removal increases the number of connected components in the graph.
- Bridges are critical edges because they represent connections between parts of the graph that are essential for maintaining its connectivity.

**How to Detect a Bridge:**
- Bridges can be detected using depth-first search (DFS) or a similar graph traversal algorithm.
- The concept of "back edges" plays a crucial role in detecting bridges.

**Back Edge (Backward Edge):**
- A back edge is an edge that connects a vertex to one of its ancestors in the DFS traversal tree.
- If there is a back edge in the graph, it indicates the existence of an alternative path between two vertices that doesn't depend on the current edge.

**Condition for Detecting Bridges:**

The condition for detecting a bridge during a Depth-First Search (DFS) traversal in the algorithm is as follows:

1. When exploring an edge `(node, child)` in the DFS traversal, if the following condition is met:
   
   ```plaintext
   low[child] > dis[node]
   ```

   where:
   - `node` is the current vertex (the parent of `child`) being explored.
   - `child` is the adjacent vertex.
   - `dis[child]` represents the discovery time of the child vertex.
   - `low[child]` represents the lowest discovery time that can be reached from the child vertex.

**Explanation of the Condition:**

The condition `low[child] > dis[node]` checks whether the earliest discovery time reachable from the child vertex (`low[child]`) is greater than the discovery time of the current vertex (`dis[node]`). If this condition holds, it means that there is no back edge from `child` to any ancestor vertex of `node`.

## ALGORITHM

**Overview**

To implement this algorithm, we need the following data structures:

- `visited[]`: To keep track of the visited vertices to implement DFS.
- `disc[]`: To keep track of when, for the first time, that particular vertex is reached.
- `low[]`: To keep track of the lowest possible time by which we can reach that vertex 'other than parent' so that if the edge from the parent is removed, the particular node can still be reached.

We will traverse the graph using DFS traversal but with slight modifications. While traversing, we will keep track of the parent node by which the particular node is reached because we will update the `low[node] = min(low[all its adjacent nodes except parent])`, hence we need to keep track of the parent.

**Traversing Adjacent Nodes**

While traversing adjacent nodes, let 'v' be a particular node and 'u' be its parent. Three cases arise:

1. **v is the parent of u then,**  
   - Skip that iteration.

2. **v is visited then,**  
   - Update the `low` of v, i.e., `low[u] = min(low[u], disc[v])`. This occurs when a node can be visited by more than one node, but `low` is used to keep track of the lowest possible time, so we will update it.

3. **v is not visited then,**  
   - Call the DFS to traverse ahead.
   - Now update `low[u] = min(low[u], low[v])` as we know v can't be the parent because we have handled that case first.
   - Now check if `(low[v] > disc[u])`, i.e., the lowest possible time to reach 'v' is greater than 'u'. This means we can't reach 'v' without 'u', so the edge `u -> v` is a bridge.

This algorithm efficiently identifies bridges in a graph, helping to analyze the network's connectivity and critical edges.


**Approach to Detect Bridges:**
1. Initialize arrays for tracking discovery time (`dis`), lowest reachable node (`low`), and visited status (`vis`) for each vertex.

2. Start DFS traversal from any vertex, keeping track of its parent.

3. In the DFS, if you encounter an unvisited vertex, mark it as visited and set its discovery time and lowest reachable node as the current timestamp. Continue DFS in its children.

4. If you encounter a child vertex that is already visited, update the lowest reachable node of the current vertex based on the child's discovery time.

5. While backtracking in DFS, if the lowest reachable node of a child is greater than or equal to the current vertex's discovery time, it means there's no alternative path to the child without using the current edge. In this case, the current edge is a bridge.
    Compare `dis` and `low` values to detect bridges. If `low[child] > dis[node]`, where `node` is the current vertex, and `child` is an adjacent vertex, then the edge (node, child) is a bridge

**Conditions to Find a Bridge:**
- A bridge is detected if, while backtracking in DFS:
  - The lowest reachable node of a child is greater than or equal to the discovery time of the current vertex.

**Data Structures Used and Why:**
- `dis[]`: To store discovery times.
- `low[]`: To store lowest reachable nodes.
- `vis[]`: To track visited vertices.
- `unordered_map<int, vector<int>> ad`: An adjacency list to represent the graph efficiently.

**Pseudocode in C++ with Comments:**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> dis, low, vis;

void dfs(int node, int parent, int &timer, unordered_map<int, vector<int>> &ad,
         vector<vector<int>> &result)
{
    vis[node] = true;
    dis[node] = low[node] = timer++;
    
    for (auto child : ad[node])
    {
        if (child == parent) // v is parent
            continue;

        if (vis[child] == false) // not visited - so explore ahead and check cond while coming back
        {
            dfs(child, node, timer, ad, result);
            low[node] = min(low[node], low[child]);

            if (low[child] > dis[node])
            {
                result.push_back({node, child}); // Found a bridge
            }
        }
        else // alr visited so update
        {
            low[node] = min(low[node], dis[child]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, vector<int>> ad;
    for (auto i : edges)
    {
        ad[i[0]].push_back(i[1]);
        ad[i[1]].push_back(i[0]);
    }

    vector<vector<int>> result;
    dis.resize(v), low.resize(v), vis.resize(v);
    
    for (int i = 0; i < v; i++)
    {
        dis[i] = -1;
        low[i] = -1;
        vis[i] = false;
    }

    int parent = -1;
    int timer = 0;
    
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, ad, result);
        }
    }

    return result;
}
```

**Time Complexity:**
- The time complexity of the algorithm is O(V + E), where V is the number of vertices and E is the number of edges in the graph.

**Space Complexity:**
- The space complexity is O(V) for the `dis[]`, `low[]`, and `vis[]` arrays and O(E) for the adjacency list.

## Full code

```cpp
// A C++ program to find bridges in a given undirected graph
#include<bits/stdc++.h>
using namespace std;

// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
	void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc,
								vector<int>& low, int parent);
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	void bridge(); // prints all bridges
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}

// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc,
								vector<int>& low, int parent)
{
	// A static variable is used for simplicity, we can
	// avoid use of static variable by passing a pointer.
	static int time = 0;

	// Mark the current node as visited
	visited[u] = true;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;

	// Go through all vertices adjacent to this
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // v is current adjacent of u
		
		// 1. If v is parent
		if(v==parent)
			continue;
	
		//2. If v is visited
		if(visited[v]){
		low[u] = min(low[u], disc[v]);
		}
	
		//3. If v is not visited
		else{
		parent = u;
		bridgeUtil(v, visited, disc, low, parent);

		// update the low of u as it's quite possible
		// a connection exists from v's descendants to u
		low[u] = min(low[u], low[v]);
		
		// if the lowest possible time to reach vertex v
		// is greater than discovery time of u it means
		// that v can be only be reached by vertex above v
		// so if that edge is removed v can't be reached so it's a bridge
		if (low[v] > disc[u])
			cout << u <<" " << v << endl;
		
		}
	}
}

// DFS based function to find all bridges. It uses recursive
// function bridgeUtil()
void Graph::bridge()
{
	// Mark all the vertices as not visited disc and low as -1
	vector<bool> visited (V,false);
	vector<int> disc (V,-1);
	vector<int> low (V,-1);
	
	// Initially there is no parent so let it be -1
	int parent = -1;

	// Call the recursive helper function to find Bridges
	// in DFS tree rooted with vertex 'i'
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			bridgeUtil(i, visited, disc, low, parent);
}

// Driver program to test above function
int main()
{
	// Create graphs given in above diagrams
	cout << "\nBridges in first graph \n";
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.bridge();

	cout << "\nBridges in second graph \n";
	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.bridge();

	cout << "\nBridges in third graph \n";
	Graph g3(7);
	g3.addEdge(0, 1);
	g3.addEdge(1, 2);
	g3.addEdge(2, 0);
	g3.addEdge(1, 3);
	g3.addEdge(1, 4);
	g3.addEdge(1, 6);
	g3.addEdge(3, 5);
	g3.addEdge(4, 5);
	g3.bridge();

	return 0;
}

```
