// Cut Into Segments
// Medium

// You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Sample Input 1:
// 2
// 7 5 2 2
// 8 3 3 3
// Sample Output 1:
// 2
// 0
// Explanation For Sample Input 1:


// In the first test case, cut it into 2 parts of 5 and 2.

// In the second case, there is no way to cut into segments of 3 length only as the length of the rod is less than the given length. 
// Sample Input 2:
// 2
// 7 3 2 2
// 8 1 4 4
// Sample Output 2:
// 3
// 8
// Explanation For Sample Input 2:
// In the first test case, cut it into 3 parts of 3, 2 and 2.

// In the second case, cut it into 8 parts of length 1.


#include<bits/stdc++.h>

int Recursion(int n, int x, int y, int z){
	if(n ==0 ){
		return 0;
	}

	if(n<0)
		return INT_MIN;

	int a = Recursion(n-x, x, y, z);
	int b = Recursion(n-y, x, y, z);
	int c = Recursion(n-z, x, y, z);

	return max({a, b, c}) + 1;
}

int RecursionWithMemoization(int n, int x, int y, int z, vector<int>& dp){
	if(n ==0 ){
		return 0;
	}

	if(n<0)
		return INT_MIN;

	if(dp[n] != -1){
		return dp[n];
	}

	int a = RecursionWithMemoization(n-x, x, y, z, dp);
	int b = RecursionWithMemoization(n-y, x, y, z, dp);
	int c = RecursionWithMemoization(n-z, x, y, z, dp);

	return dp[n] = max({a, b, c}) + 1;

}

int Tabulation(int n, int x, int y, int z){
	vector<int> dp(n+1, -1);
	dp[0] = 0;

	for(int i=1; i<=n; i++){

		if(i-x >=0 and dp[i-x] != -1)
			dp[i] = max(dp[i], dp[i-x]+1);
		
		if(i-y >=0 and dp[i-y] != -1)
			dp[i] = max(dp[i], dp[i-y]+1);
		
		if(i-z >=0 and dp[i-z] != -1)
			dp[i] = max(dp[i], dp[i-z]+1);

	}

	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	// 1. Recursion
	// int ans =  Recursion(n, x, y, z);
	// return ans > 0? ans:0;

	// 2. Recursion with memoization
	// vector<int>dp(n+1, -1);
	// int ans =  RecursionWithMemoization(n, x, y, z, dp);
	// return ans > 0? ans:0;

	// 3. Tabulation
	int ans =  Tabulation(n, x, y, z);
	return ans > 0? ans:0;	


}