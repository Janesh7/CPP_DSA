// 746. Min Cost Climbing Stairs
// Easy

// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

 

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.
// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.
 

// Constraints:

// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999


class Solution {
public:
    //15-Mar-2023
    // 1 Recursion
    int for_recusrion_only(vector<int>& cost, int n){
        if(n == 0 || n == 1) return cost[n];

        return cost[n] + min(for_recusrion_only(cost, n-1), for_recusrion_only(cost, n-2));
    }


    // 2 Recusrion with memoization
    int rec_memo(vector<int>& cost, vector<int> &dp, int n){
        if(n == 0 || n ==1) return cost[n];

        if(dp[n] != -1) return dp[n];

        dp[n] = cost[n] + min(rec_memo(cost, dp, n-1), rec_memo(cost, dp, n-2));
        return dp[n];
    }

    // 3 Tabulation (Bottom-up) Approach
    int Tabulation(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }

    // 4 Space Optimised Approach
    int SpaceOptimization(vector<int>& cost) {
        int size = cost.size();
        int prev1=cost[0];
        int prev2=cost[1];
        int current = 0;
        for(int i=2; i<size; i++){
            current = cost[i] + min(prev1,prev2);
            prev1 = prev2;
            prev2 = current;
        }
        
        return min(prev1,prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        //1 Recursion
        // return min(for_recusrion_only(cost, n-1), for_recusrion_only(cost, n-2));

        //2 Recursion with memoization
        // vector<int> dp(n+1, -1);
        // int ans = min(rec_memo(cost, dp, n-1), rec_memo(cost, dp, n-2));
        // return ans;

        //3 Tabulation
        // return Tabulation(cost);

        //4 Space Optimization
        return SpaceOptimization(cost);

    }

};