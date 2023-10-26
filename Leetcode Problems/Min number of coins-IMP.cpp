// 322. Coin Change
// Medium

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
 

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104


// Memoization
class Solution {
public:
    int solve(vector<int>& coins,int amount, vector<int>& dp) {
        if (amount==0) return 0;
        if (amount<0) return INT_MAX;
        if (dp[amount]!=INT_MAX) return dp[amount];
        int res=INT_MAX;
        for (auto i:coins) {
            if (amount-i>=0) {
                int sub=solve(coins,amount-i,dp);
                if (sub!=INT_MAX)
                    res=min(res,sub+1);
            }
        }
        dp[amount]=res;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        if (amount==0) return 0;
        return (solve(coins,amount,dp)==INT_MAX)?-1:dp[amount];
    }
};

// Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};