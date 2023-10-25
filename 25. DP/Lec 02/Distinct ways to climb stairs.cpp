// Problem Statement
// Suggest Edit
// You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps. You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.
// Example :
// N=3
// Example

// We can climb one step at a time i.e. {(0, 1) ,(1, 2),(2,3)} or we can climb the first two-step and then one step i.e. {(0,2),(1, 3)} or we can climb first one step and then two step i.e. {(0,1), (1,3)}.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Input format :
// The first line contains an integer 'T', which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first and the only argument of each test case contains an integer 'N', representing the number of stairs.
// Output Format :
// For each test case/query, print the number of distinct ways to reach the top of stairs. Since the number can be huge, so return output modulo 10^9+7.

// Output for every test case will be printed in a separate line.
// Note :
// You do not need to print anything. It has already been taken care of.
// Constraints :
// 1 <= 'T' <= 10
// 0 <= 'N' <= 10^5

// Where 'T' is the number of test cases, and 'N' is the number of stairs.

// It is guaranteed that sum of 'N' over all test cases is <= 10^5.
// Sample Input 1 :
// 2
// 2
// 3
// Sample Output 1 :
// 2
// 3
// Explanation Of Sample Input 1 :
// In the first test case, there are only two ways to climb the stairs, i.e. {1,1} and {2}.

// In the second test case, there are three ways to climb the stairs i.e. {1,1,1} , {1,2} and {2,1}.
// Sample Input 2 :
// 2
// 4
// 5
// Sample Output 2 :
// 5
// 8
// Explanation Of Sample Input 2 :
// In the first test case, there are five ways to climb the stairs i.e. {1,1,1,1} , {1,1,2} , {2,1,1} , {1,2,1} , {2,2}.

// In the second test case, there are eight ways to climb the stairs i.e. {1,1,1,1,1} , {1,1,1,2} , {1,1,2,1}, {1,2,1,1}, {2,1,1},{2,2,1},{2,1,2} and {2,2,1}.


#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    //  Write your code here.
    if (nStairs<=0) return 1;

    return (countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2));
}


// Memoization
#define MOD 1000000007
int countWays(int n, vector<int> &dp) {
  if (n <= 1)
    return 1;
  if (dp[n] != -1)
    return dp[n]%MOD;
  dp[n] = countWays(n - 1, dp) + countWays(n - 2, dp);
  return dp[n]%MOD;
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int> dp(nStairs + 1, -1);
    return countWays(nStairs, dp);
}


// Tabular
#define MOD 1000000007

int countDistinctWays(int nStairs) {
    //  Write your code here.
    if (nStairs<=1) return 1;
    vector<int> dp(nStairs + 1, -1);
    dp[0]=dp[1]=1;
    for (int i=2;i<=nStairs;i++) {
        dp[i]=dp[i-1]%MOD+dp[i-2]%MOD;
    }
    return dp[nStairs]%MOD;
}


// Space optimization
#define MOD 1000000007

int countDistinctWays(int nStairs) {
    //  Write your code here.
    if (nStairs<=1) return 1;
    int prev1=1,prev2=1;
    int cur;
    for (int i=2;i<=nStairs;i++) {
        cur = prev1%MOD+prev2%MOD;
        prev1 = prev2%MOD;
        prev2 = cur%MOD;
    }
    return cur%MOD;
}