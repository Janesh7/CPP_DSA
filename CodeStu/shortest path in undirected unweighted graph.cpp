// Shortest path in an unweighted graph
// Medium

// The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.
// A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses. Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.
// For Example
// In the below map of Ninjaland let say you want to go from S=1 to T=8, the shortest path is (1, 3, 8). You can also go from S=1 to T=8  via (1, 2, 5, 8)  or (1, 4, 6, 7, 8) but these paths are not shortest.
// altImage

// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 1 <= T <= 100
// 2 <= N <= 10 ^ 3
// 1 <= M <= min( N *(N - 1) / 2 , 1000 )
// 1 <= S, T <= N

// Time Limit: 1 sec
// Sample Input 1 :
// 1
// 4 4
// 1 4
// 1 2
// 2 3
// 3 4
// 1 3
// Sample Output 1 :
// ( 1 , 3 , 4 )
// Explanation Of Sample Input 1 :
// In the above graph there are two ways to go from 1 to 4 ,
// ( 1 , 2 , 3 , 4 ) and ( 1 , 3 , 4 ) but the second path is the shortest path.
// altImage

// Sample Input 2 :
// 1
// 8 9
// 1 8
// 1 2
// 1 3
// 1 4
// 2 5
// 5 8 
// 3 8
// 4 6
// 6 7
// 7 8
// Sample Output 2 :
// ( 1 , 3 , 8 )



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
