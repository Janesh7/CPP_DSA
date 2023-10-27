// 213. House Robber II
// Medium

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

class Solution {
public:
    int recursion(vector<int>& nums, int index, int size){
        if(index>=size){
            return 0;
        }

        int include = recursion(nums, index+2, size) + nums[index];
        int exclude = recursion(nums, index+1, size);

        return max(include, exclude);
    }

    int RecursionWithMemo(vector<int>& nums, int index, int size, vector<int>& dp){
        if(index>=size){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }
        int include = RecursionWithMemo(nums, index+2, size, dp) + nums[index];
        int exclude = RecursionWithMemo(nums, index+1, size, dp);
        return dp[index] = max(include, exclude);
    }

    int Tabulation(vector<int>& nums, int idx, int size){
        vector<int> dp(size+2, 0);

        for(int index = size-1; index>=idx; index--){
            int include = dp[index+2] + nums[index];
            int exclude = dp[index+1];
            dp[index] = max(include, exclude);
        }
        return dp[idx];
    }

    int SpaceOptimization(vector<int>& nums, int idx, int size){

        int next2 = 0;
        int next1 = 0; 

        for(int index = size-1; index>=idx; index--){
            int include = next2 + nums[index];
            int exclude = next1;
            next2 = next1;
            next1 = max(include, exclude);
        }
        return next1;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        // 1. Recusrion
        // return max(recursion(nums, 0, n-1), recursion(nums, 1, n));

        // 2. Recursion with Memoization
        // vector<int> dp(n+1, -1);
        // int ans1 = RecursionWithMemo(nums, 0, n-1, dp);
        // dp.assign(n+1, -1);
        // int ans2 =  RecursionWithMemo(nums, 1, n, dp);
        // return max(ans1, ans2);

        // 3. Tabulation
        // return max(Tabulation(nums, 0, n-1), Tabulation(nums, 1, n));

        // 4. Space Optimization
       return max(SpaceOptimization(nums, 0, n-1), SpaceOptimization(nums, 1, n));

    }
};