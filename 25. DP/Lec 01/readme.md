**Dynamic Programming**

We usually keep an array of n+1 coz in most the cases we r not using the 0th term instead we start from like 1st term,2nd term of a fib series n so on. Its just a common practice.

**Overview:**
Dynamic Programming (DP) is a technique for solving complex problems by breaking them down into simpler subproblems. It stores the solutions to these subproblems and reuses them to solve larger subproblems, leading to more efficient and optimized solutions.

**RECURSIVE REALTION IS V IMP**

**Types of Dynamic Programming:**

1. **Top-down Approach (Recursion and Memoization):**
   - Breaks down the problem into smaller subproblems and solves them recursively.
   - Stores the solutions to subproblems in a data structure (e.g., an array or a hashmap) to avoid redundant calculations.
   - Memoization ensures that each subproblem is solved only once.
   - Example problems include Fibonacci series, factorial, and various optimization problems.

2. **Bottom-up Approach (Tabulation):**
   - Starts from the smallest subproblems and iteratively builds up solutions to larger subproblems.
   - Uses an iterative process often based on loops or iterations.
   - Avoids recursion overhead and is often more efficient for problems where the order of solving subproblems doesn't matter.
   - Example problems include dynamic programming-based optimization problems, shortest path problems, and more.

3. **Space Optimization:**
   - In some cases, it's possible to optimize space usage by storing only the necessary subproblem solutions rather than storing the entire table.
   - This approach is useful when the final solution can be computed by using only a few previous subproblem solutions.
   - It helps reduce the space complexity of the algorithm.
   - Example problems include optimization problems with constraints on space usage.

**1. Fibonacci Series:**

Let's visualize the recursive call tree for the Fibonacci problem and see how dynamic programming, specifically the top-down approach with memoization, helps optimize the computation by avoiding redundant calculations.

**Recursive Call Tree for Fibonacci without Memoization:**

When we use a simple recursive approach without memoization, the computation for Fibonacci numbers leads to redundant recursive calls. For example, when computing fib(5), it recalculates fib(3) and fib(4) multiple times.

```plaintext
                       fib(5)
                  /             \
              fib(4)            fib(3)
             /      \          /      \
         fib(3)     fib(2)   fib(2)    fib(1)
        /     \
    fib(2)    fib(1)
```

**Recursive Call Tree for Fibonacci with Memoization:**

With memoization, we store the results of subproblems, ensuring that each subproblem is solved only once. When we need the result for a subproblem, we first check if it has already been computed. This avoids redundant recursive calls and significantly optimizes the computation.

```plaintext
                       fib(5)
                  /             \
              fib(4)            fib(3)
             /      \              \
         fib(3)     fib(2)          fib(2)
        /     \       /   \           /   \
    fib(2)   fib(1) fib(1) fib(0)   fib(1) fib(0)
```

In the above tree, we can observe that fib(3), fib(2), and fib(1) are computed only once, and their results are stored for future use. This prevents redundant calculations and leads to an optimized approach, as each Fibonacci number is calculated only once during the entire process.

Using memoization in dynamic programming not only reduces redundant calculations but also significantly improves the time complexity of the algorithm. It ensures that the time complexity remains linear rather than exponential, making it a much more efficient way to compute Fibonacci numbers, especially for larger values of 'n'.

- **Top-down Approach (Recursion and Memoization):**
  ```cpp
  int fib(int n, vector<int> &memo) {
      if (n <= 1) return n;
      if (memo[n] != -1) return memo[n];
      memo[n] = fib(n-1, memo) + fib(n-2, memo);
      return memo[n];
  }
  ```
  **Time Complexity:** O(n)
  **Space Complexity:** O(n) (vector) + O(n) (recursion stack) ~ O(n)

- **Bottom-up Approach (Tabulation):**

**In the above func we can see and literally convert it into a iterative answer**

  ```cpp
  int fib(int n) {
      if (n <= 1) return n;
      vector<int> dp(n+1);
      dp[0] = 0;
      dp[1] = 1;
      for (int i = 2; i <= n; i++) {
          dp[i] = dp[i-1] + dp[i-2];
      }
      return dp[n];
  }
  ```
  **Time Complexity:** O(n)
  **Space Complexity:** O(n)

- **Space Optimization:**
  ```cpp
  int fib(int n) {
      if (n <= 1) return n;
      int a = 0, b = 1, c;
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

**2. Memoization and Tabulation:**
- **Memoization** involves storing the results of expensive function calls and returning the cached result when the same inputs occur again.
- **Tabulation** involves solving a dynamic programming problem by filling the lookup table starting from the smallest problem and moving up to the given problem size.

**3. Space Optimization:**
- **Space optimization** in dynamic programming aims to reduce the space complexity of the algorithm while maintaining the same time complexity. This is achieved by only storing the necessary data that is required for computation and discarding unnecessary data. It is particularly useful in problems where the final solution can be computed using only a few previous subproblem solutions.

**Dynamic Programming (DP)** is a technique used to solve complex problems by breaking them down into simpler subproblems. It stores the solutions to these subproblems and reuses them to solve larger subproblems, leading to more efficient and optimized solutions.

**1D, 2D, and 3D DP:**

1. **1D Dynamic Programming:**
   - In 1D DP, we use a 1-dimensional array to store the solutions of subproblems.
   - It is often used for problems where only one parameter changes, such as the number of steps, the size of an array, or the length of a sequence.

   **Example:** The Fibonacci series is a classic example of 1D DP, where we use a 1D array to store the values for each Fibonacci number.

2. **2D Dynamic Programming:**
   - In 2D DP, we use a 2-dimensional array or matrix to store the solutions of subproblems.
   - It is suitable for problems where two parameters change, such as the dimensions of a grid, or when considering two different sequences simultaneously.

   **Example:** The classic example of 2D DP is the problem of finding the length of the longest common subsequence between two strings.

3. **3D Dynamic Programming:**
   - In 3D DP, we use a 3-dimensional array or matrix to store the solutions of subproblems.
   - It is utilized when three parameters change and interact with each other in the problem.

   **Example:** An example of 3D DP is a problem where we have to consider three sequences simultaneously, and the solution depends on the state of all three sequences.

**Identifying Dynamic Programming:**

To identify if a problem can be solved using dynamic programming, look for the following characteristics:

1. **Overlapping Subproblems:** The problem can be divided into smaller subproblems, and the same subproblems are encountered multiple times during the solution process.

2. **Optimal Substructure:** The problem can be solved by combining the solutions of its subproblems. Optimal solutions of subproblems lead to an optimal solution for the whole problem.

**Approaches from DP (Memoization and Tabulation):**

1. **Memoization (Top-down Approach):**
   - In the memoization approach, we use recursion to solve the problem, but we also store the results of subproblems in a data structure (like an array or hashmap) to avoid redundant calculations.
   - This approach helps in handling overlapping subproblems efficiently.

2. **Tabulation (Bottom-up Approach):**
   - In the tabulation approach, we solve the problem by iteratively filling a table (like an array or matrix) in a bottom-up fashion.
   - We start from the base case and then fill up the table with the results of subproblems until we reach the desired solution.

2. **Space optimization:**
   - Only store the required stuff

By understanding these concepts and characteristics, you can efficiently recognize and solve dynamic programming problems using the appropriate approach, be it 1D, 2D, or 3D, based on the problem's requirements and constraints.