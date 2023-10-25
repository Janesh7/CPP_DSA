**Number of Distinct Ways to Climb Stairs:**

**Recursive Relation:**
For the number of distinct ways to climb 'n' stairs, where you can either take 1 step or 2 steps at a time, the recursive relation is as follows:

```plaintext
ways(n) = ways(n-1) + ways(n-2)
```
**Normal approach**
```cpp
int countDistinctWays(int nStairs) {
    //  Write your code here.
    if (nStairs<=0) return 1;
    return (countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2));
}
```
**see code fot 10^9+7 mod operation**
**1. Top-Down Approach (Recursion with Memoization):**

```cpp
int countWays(int n, vector<int> &dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = countWays(n-1, dp) + countWays(n-2, dp);
    return dp[n];
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(n)

**2. Bottom-Up Approach (Tabulation):**

```cpp
int countWays(int n) {
    if (n <= 1) return 1;
    vector<int> dp(n+1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(n)

**3. Space Optimization:**

```cpp
int countWays(int n) {
    if (n <= 1) return 1;
    int a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

**Without Dynamic Programming:**
- **Time Complexity:** O(2^n) 
- **Space Complexity:** O(1)

---

**Minimum Cost Climbing Stairs:**

**Recursive Relation:**
For the minimum cost climbing stairs problem, the recursive relation is as follows:

```plaintext
minCost[i] = cost[i] + min(minCost[i-1], minCost[i-2])
```
where `cost[i]` represents the cost of stepping on the i-th stair, and `minCost[i]` represents the minimum cost to reach the i-th stair.


```cpp
class Solution {
public:
    int solve(vector<int>cost,int i) {
        if (i<=1) return cost[i];
        int cur=cost[i]+min(solve(cost,i-1),solve(cost,i-2));
        return cur;
    }
    int minCostClimbingStairs(vector<int> cost) {
        int n=cost.size();
        return min(solve(cost,n-1),solve(cost,n-2);
    }
};
```

**1. Top-Down Approach (Recursion with Memoization):**

```cpp
int minCostClimbingStairs(vector<int>& cost, int n, vector<int>& dp) {
    if (n <= 1) return cost[n];
    if (dp[n] != -1) return dp[n];
    dp[n] = cost[n] + min(minCostClimbingStairs(cost, n-1, dp), minCostClimbingStairs(cost, n-2, dp));
    return dp[n];
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(n)

**2. Bottom-Up Approach (Tabulation):**

```cpp
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(n)

**3. Space Optimization:**

```cpp
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int first = cost[0];
    int second = cost[1];
    for (int i = 2; i < n; i++) {
        int current = cost[i] + min(first, second);
        first = second;
        second = current;
    }
    return min(first, second);
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

**Without Dynamic Programming:**
- **Time Complexity:** O(2n) 
- **Space Complexity:** O(1)