#include <bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int, list<int>> adjList;
	for (auto i:edges) {
		int u = i.first;
		int v = i.second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	vector<int> visited(n+1,0);
	vector<int> parent(n+1,-1);
	
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int front = q.front();
		visited[front]=1;
		q.pop();
		for (auto i:adjList[front]) {
			if (!visited[i]) {
				parent[i]=front;
				visited[i]=1;
				q.push(i);
				if (i==t)
					break;
			}
		}
	}
	vector<int> ans;
	int cur = t;
	ans.push_back(t);
	while (cur!=s) {
		cur = parent[cur];
		ans.push_back(cur);
	}
	reverse(ans.begin(),ans.end());

	return ans;
}
