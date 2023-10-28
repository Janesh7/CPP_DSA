**Count Derangements:**

The problem of counting derangements involves finding the number of permutations of n distinct elements in which no element appears in its original position. Let's explore the approach to solving this problem.

**Approach:**

 **consider a array as reference 0,1,2..i...n ..  we can keep 0 to n-1 places.. therefor it is n-1*(solve sub problem) ..**
    **We can solve the sub problem by two possibilty** 
        - swap 0,i.. now we r left with n-2 elements to derange.. 
        - 2nd case now we have have placed 0 to ith index, but we dont want to put i on 0th index .. so basicallly now we r left with a subproblem ie .. derange n-1 elements (0 got fixed to ith index)

 **base case: if n=1 .. there is no derange possible.. return 0 .. also n=2 only 1 derangement ie reverse**

We can solve the problem using dynamic programming. To count derangements, we consider the following approach:

1. We consider an array of n elements, numbered from 0 to n-1, and aim to find the count of derangements for n elements.
2. For the first case, we consider the possibility of swapping the 0th element with any other element i. After the swap, we are left with n-2 elements to derange.
3. For the second case, we assume that we have already placed 0 to the ith index, and we don't want to put i on the 0th index. We are then left with a subproblem, where we need to derange the remaining n-1 elements.

**Recursive Relation for Derangements:**

The recursive relation for calculating the count of derangements follows the formula:

```
F(n) = (n - 1) * [F(n - 2) + F(n - 1)]
```

where F(n) represents the count of derangements for n elements. It involves multiplying (n - 1) with the sum of the derangements for (n - 2) and (n - 1) elements. **This is because there are (n - 1) choices for placing the first element, and for each choice, the remaining subproblem can either have (n - 2) or (n - 1) elements.**

By following this recursive relation, we can efficiently count derangements for a given number of elements, considering the constraints of not having any element in its original position.

The dynamic programming approach based on this recursive relation helps us avoid redundant calculations and efficiently compute the count of derangements for different values of n.

The different implementations of the Derangements problem using the naive recursive approach, memoization, tabulation, and space optimization techniques:

**1. Naive Recursive Approach:**

```cpp
int countDerangementsNaive(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return (n - 1) * (countDerangementsNaive(n - 1) + countDerangementsNaive(n - 2));
}
```

**Time Complexity (Naive Recursive):** Exponential, O(2^n).
**Space Complexity:** O(n) due to the recursive call stack.

**2. Memoization (Top-Down Approach):**

```cpp
int countDerangementsMemo(int n, vector<int>& dp) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = (n - 1) * (countDerangementsMemo(n - 1, dp) + countDerangementsMemo(n - 2, dp));
    return dp[n];
}
```

**Time Complexity (Memoization):** O(n).
**Space Complexity:** O(n) for the memoization array.

**3. Tabulation (Bottom-Up Approach):**

SEE CODE FOR MOD FOR long long int
```cpp
int countDerangementsTabulation(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    vector<int> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}
```

**Time Complexity (Tabulation):** O(n).
**Space Complexity:** O(n) for the DP array.

**4. Space Optimization Approach:**

```cpp
int countDerangementsSpaceOptimized(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    int a = 0, b = 1, result;
    for (int i = 3; i <= n; i++) {
        result = (i - 1) * (b + a);
        a = b;
        b = result;
    }
    return result;
}
```

**Time Complexity (Space-Optimized):** O(n).
**Space Complexity:** O(1).

These implementations provide various ways to solve the Derangements problem, utilizing techniques such as memoization and tabulation to optimize the recursive solution and space optimization to further improve the space complexity of the solution.