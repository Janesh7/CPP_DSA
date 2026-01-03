**House Robbery Problem:**

The House Robbery problem involves determining the maximum amount of money you can rob from a street of houses, where no two adjacent houses can be robbed. It's a variation of the maximum sum of non-adjacent elements problem with slight modifications.

**Approach:**

We can use dynamic programming to solve this problem efficiently. Instead of directly applying the dynamic programming approach for the maximum sum of non-adjacent elements, we can adapt it to handle the house robbery problem by making a simple adjustment: avoid robbing both the first and last houses together.

**Four Approaches to Solve the Problem:**

1. **Naive Recursive Approach:**
   - Define a recursive function that explores two cases at each house: robbing it or skipping it.
   - To avoid robbing both the first and last houses, we can make two separate recursive calls, one starting from the first house and another from the second house.

   ```cpp
    int robHelper(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        if (start + 1 == end) return max(nums[start], nums[end]);
        return max(robHelper(nums, start, end - 2) + nums[end], robHelper(nums, start, end - 1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(robHelper(nums, 0, n - 2), robHelper(nums, 1, n - 1));
    }
   ```

   **Time Complexity:** O(2^n)
   **Space Complexity:** O(n) due to the recursive call stack.

2. **Memoization (Top-Down Approach):**
   - Implement a memoization approach where we store results of subproblems to avoid redundant calculations.
   - Similar to the naive recursive approach, but with memoization.

   ```cpp
   int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(robHelper(nums, 0, n - 2, dp1), robHelper(nums, 1, n - 1, dp2));
    }

    int robHelper(vector<int>& nums, int start, int end, vector<int>& dp) {
        if (start == end) return nums[start];
        if (start + 1 == end) return max(nums[start], nums[end]);
        if (dp[end] != -1) return dp[end];
        dp[end] = max(robHelper(nums, start, end - 2, dp) + nums[end], robHelper(nums, start, end - 1, dp));
        return dp[end];
    }
   ```

   **Time Complexity:** O(n^2)
   **Space Complexity:** O(n^2) for the memoization array.

3. **Tabulation (Bottom-Up Approach):**
   - Use a tabulation approach to fill a DP table iteratively.
   - Start from the beginning and calculate the maximum amount of money that can be robbed considering each house.

   ```cpp
   int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[1] = nums[1];
        for (int i = 2; i < n - 1; i++) {
            dp1[i] = max(dp1[i-2] + nums[i], dp1[i-1]);
        }
        for (int i = 2; i < n; i++) {
            dp2[i] = max(dp2[i-2] + nums[i], dp2[i-1]);
        }
        return max(dp1[n-2], dp2[n-1]);
    } 

   ```

   **Time Complexity:** O(n)
   **Space Complexity:** O(n) for the DP array.

4. **Space Optimization Approach:**
   - A more efficient space-optimized version of the tabulation approach can be achieved using two variables to track the maximum amount of money.

   ```cpp
   int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int prev1 = nums[0], prev2 = max(nums[0], nums[1]);
        int curr1 = 0, curr2 = nums[1];
        for (int i = 2; i < n - 1; i++) {
            curr1 = max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = curr1;
        }
        for (int i = 2; i < n; i++) {
            curr2 = max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = curr2;
        }
        return max(curr1, curr2);
    }


   ```

   **Time Complexity:** O(n)
   **Space Complexity:** O(1)

In all approaches, we aim to maximize the amount of money that can be robbed while avoiding robbing adjacent houses. The space optimization approach is particularly efficient, as it uses constant space and iterates through the array once.