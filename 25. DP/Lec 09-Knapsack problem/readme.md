**0/1 Knapsack Problem:**

The 0/1 Knapsack Problem is a classic problem in the field of combinatorial optimization. It involves selecting items to maximize the total value within the constraints of a knapsack's capacity. Let's explore the problem and its dynamic programming solution.

**Problem Explanation:**

Given a set of items, each with a weight and a value, the goal is to determine the maximum value that can be obtained by selecting a subset of the items. The sum of the weights of the selected items should not exceed a given capacity. However, the constraint is that either an item is included entirely or not at all (0/1 property).

**Approach:**

The problem can be efficiently solved using dynamic programming. We build a 2D array to store the maximum value that can be attained with varying capacities and the number of items considered.

**Explanation:**

We start with the base case, where the capacity is 0 or the number of available items is 0. Then, we consider the scenarios when we include or exclude an item. By maximizing the value, we fill the 2D array based on these cases and the constraints of the problem.

**Recursive Tree Explanation:**

Consider the following recursive tree for the 0/1 Knapsack problem:
3 being the n-1 (index) and 50 being the capacity

```
                 Knapsack(3, 50)    
         inc     /            \  exclude(capacity remain same)
                /              \       
        Knapsack(2, 30)      Knapsack(2, 50)
        /      \                     /      \ 
       /        \                   /        \
Knapsack(1, 20)  Knapsack(1, 30)  Knapsack(1, 50)  Knapsack(1, 30)
```

In this tree, we include and exclude items at each level to explore all possible combinations. The recursive tree helps us visualize how the algorithm considers different combinations of items and capacities to find the optimal solution.

By exploring this recursive tree and using dynamic programming, we can efficiently solve the 0/1 Knapsack problem, considering the constraints of item weights, values, and the knapsack's capacity.

**Base Case:**

The base case for the 0/1 Knapsack Problem occurs when either the knapsack's capacity is 0 or the number of available items is 0. In these cases, the maximum value that can be obtained is 0. 
**We r going from n-1 index to 0 during recursion .. so when we come to index 0 we include the item if the item deosnt overflow the capacity**

**Condition for Including an Item:**

When considering whether to include an item, we need to check if the weight of the current item is less than or equal to the current capacity. If it is, we include the item, and the maximum value becomes the sum of the current item's value and the maximum value obtained with the remaining capacity and the remaining items.

**Condition for Excluding an Item:**

If the weight of the current item exceeds the capacity, we exclude the item and proceed to the next item without reducing the capacity. The maximum value remains the same as the value obtained with the previous items and the current capacity.


**Explanation:**

The dynamic programming approach involves building a table where each cell (i, w) represents the maximum value that can be obtained with the first 'i' items and a knapsack capacity of 'w'. By populating this table based on the conditions for including and excluding items, we can efficiently find the optimal solution to the 0/1 Knapsack Problem, considering the constraints of item weights, values, and the knapsack's capacity.

By using the base cases and the conditions for including and excluding items, the dynamic programming approach ensures that we consider all possible combinations and choose the optimal set of items to maximize the total value within the knapsack's capacity.


**1. Recursion**

The recursive solution to the knapsack problem works by considering two cases at each step:

1. **Include the current item in the knapsack.** If the current item fits in the knapsack, then we can either include it or exclude it. If we include it, then we need to recursively solve the knapsack problem with the remaining capacity reduced by the weight of the current item.
2. **Exclude the current item from the knapsack.** We can always exclude the current item from the knapsack.

The recursive solution returns the maximum value that can be achieved by including or excluding the current item.
```cpp
int Recursion(vector<int>& weight, vector<int> &value, int index, int capacity){
	
	if(index == 0){
		if(weight[0] <= capacity){
			return value[0]; // INCLUDE IF DOESNT OVERFLOW CAP
		}else{
			return 0;
		}
	}

	int include = 0;
	if(weight[index] <= capacity)
		include = value[index] + Recursion(weight, value, index-1, capacity-weight[index]); // include the cur

	int exclude = 0 + Recursion(weight, value, index-1, capacity);
	
	return max(exclude, include);

}
```
Time Complexity (Naive Recursive): O(2^n) - Exponential time complexity due to the exponential number of recursive calls.

Space Complexity (Naive Recursive): O(n) - The space used by the function call stack.

**2. Recursion with Memoization**

The recursive solution with memoization works in the same way as the recursive solution, except that it stores the results of previously computed subproblems in a memoization table. This avoids recomputing the same subproblems over and over again, which can significantly improve the performance of the algorithm.

```cpp
int RecursionWithMemoization(vector<int>& weight, vector<int> &value, int index, int capacity, vector<vector<int>>& dp){
	
	if(index == 0){
		if(weight[0] <= capacity){
			return value[0];
		}else{
			return 0;
		}
	}

	if(dp[index][capacity] != -1){
		return dp[index][capacity];
	}

	int include = 0;
	if(weight[index] <= capacity)
		include = value[index] + RecursionWithMemoization(weight, value, index-1, capacity-weight[index], dp);

	int exclude = 0 + RecursionWithMemoization(weight, value, index-1, capacity, dp);
	
	return dp[index][capacity] = max(exclude, include);

}
```
Time Complexity (Memoization): O(n * capacity) - The time complexity is proportional to the number of subproblems.

Space Complexity (Memoization): O(n * capacity) - The 2D memoization table.

**3. Tabulation**

The tabulation solution to the knapsack problem works by building a table that stores the maximum value that can be achieved for each capacity and item index. The table is built bottom-up, starting from the base cases.

The **base cases** FOR LOOP are:

1. If the capacity is 0, then the maximum value is 0.
2. If the item index is 0, then the maximum value is the value of the first item if it fits in the knapsack, otherwise the maximum value is 0.

Once the base cases have been handled, we can fill in the rest of the table by considering the two cases mentioned above:
1. **Include the current item in the knapsack.** If the current item fits in the knapsack, then the maximum value for the current capacity and item index is the maximum of the following two values:
    * The value of the current item plus the maximum value for the remaining capacity and item index - 1.
    * The maximum value for the current capacity and item index - 1.
2. **Exclude the current item from the knapsack.** The maximum value for the current capacity and item index is the maximum value for the current capacity and item index - 1.

```cpp
int Tabulation(vector<int>& weight, vector<int> &value, int index, int capacity){
	vector<vector<int>> dp(index,vector<int>(capacity+1, 0));

	for(int i= weight[0]; i<=capacity; i++){
		if(weight[0] <= capacity){
			dp[0][i] = value[0];
		}else{
			dp[0][i] = 0;
		}
	}
		
	for(int i=1; i<index; i++)	{
		for(int w=0; w<=capacity; w++){
			int include = 0;
			if(weight[i] <= w)
				include = value[i] + dp[i-1][w-weight[i]];

			int exclude = 0 + dp[i-1][w];
			
			dp[i][w] = max(exclude, include);
		}
	}
	
	return dp[index-1][capacity];

}
```
Time Complexity (Tabulation): O(n * capacity) - We fill the 2D table with n * capacity cells.

Space Complexity (Tabulation): O(n * capacity) - The 2D table used for tabulation.


**4. Space Optimization**

The space optimization approach to the knapsack problem works by using only one array to store the maximum value for each capacity. The array is updated bottom-up, starting from the base cases.

The base cases are the same as in the tabulation solution.
**The sol only depends upon the curr row and column row**
Once the base cases have been handled, we can update the array for the current capacity and item index by considering the two cases mentioned above:

1. **Include the current item in the knapsack.** If the current item fits in the knapsack, then the maximum value for the current capacity and item index is the maximum of the following two values:
    * The value of the current item plus the maximum value for the remaining capacity and item index - 1.
    * The maximum value for the current capacity and item index - 1.
2. **Exclude the current item from the knapsack.** The maximum value for the current capacity and item index is the maximum value for the current capacity and item index - 1.

```cpp
int SpaceOptimization(vector<int>& weight, vector<int> &value, int index, int capacity){
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);

	for(int i= weight[0]; i<=capacity; i++){
		if(weight[0] <= capacity){
			prev[i] = value[0];
		}else{
			prev[i] = 0;
		}
	}
		
	for(int i=1; i<index; i++)	{
		for(int w=0; w<=capacity; w++){
			int include = 0;
			if(weight[i] <= w)
				include = value[i] + prev[w-weight[i]];

			int exclude = 0 + prev[w];
			
			curr[w] = max(exclude, include);
		}
		prev = curr;
	}
	
	return prev[capacity];

}
```
Time Complexity (Space Optimization Approach 1): O(n * capacity)

Space Complexity (Space Optimization Approach 1): O(capacity)

**5. Space Optimization 2**

The space optimization 2 approach to the knapsack problem works by using the same array as in the space optimization approach, but updating it in a different order. Instead of updating the array bottom-up, we update it top-down.

The base cases are the same as in the space optimization approach.
**GO FROM RIGHT TO LEFT FOR CAP (2nd loop) as if we go from left to right.. then updating thr value will polute that value for further calculation**
Once the base cases have been handled, we can update the array for the current capacity and item index by considering the two cases mentioned above:

1. **Include the current item in the knapsack.** If the current item fits in the knapsack, then the maximum value for the current capacity and item index is the maximum of the following two values:
    * The value of the current item plus the maximum value for the remaining capacity and item index - 1.
    * The maximum value for the current capacity and item index - 1.
2. **Exclude the current item from the knapsack.** The maximum value for the current capacity and item index is the maximum value for the current capacity and item index - 1.

```cpp
int SpaceOptimization2(vector<int>& weight, vector<int> &value, int index, int capacity){
	vector<int> curr(capacity+1, 0);

	for(int i= weight[0]; i<=capacity; i++){
		if(weight[0] <= capacity){
			curr[i] = value[0];
		}else{
			curr[i] = 0;
		}
	}
		
	for(int i=1; i<index; i++)	{
		for(int w=capacity; w>=0; w--){ // curr[w]-> is depend on either left side of prev[w] or prev[w] 
                                        // so just run the loop inversely no problem will occurs
			int include = 0;
			if(weight[i] <= w)
				include = value[i] + curr[w-weight[i]];

			int exclude = 0 + curr[w];
			
			curr[w] = max(exclude, include);
		}
	}
	
	return curr[capacity];

}
```
Time Complexity (Space Optimization Approach 2): O(n * capacity)

Space Complexity (Space Optimization Approach 2): O(capacity)

**SAME QUESTIONS:**

- 0/1 Knapsack
- Equal subset sum problem
- Subset sum
- Minimum subset sum difference
- Count of subset sum
- Target Sum