# Time complexity in recursive functions


In recursion , the time complexity is the time reuired as function of input. ie F(n)


**IMP: REMEMBER TO USE K, the constant time which will be required except the recursive function call**


Steps:

- write the recurrence relation
- make the recurrence go to the base case 
- add all the above tc , cancelling same stuff from lhs and previous step rhs
- it will lead to a*K, find a based on how many iterations it took, ex for factorial it will revursively call the prev number func, hence n calls will be made, but for binary search log2n calls will be made as the array is divided into 2 each call



OR 


Recursion tree method
- K as the time for each node
- Count the node

1. Factorial


Recurrence relation:

```
F(n) = n*F(n-1)
```

... Refer the pdf for all the complexities and here for followup


- T(n-1) cuts T(n-1) in Lhs of the next eqn , same for T(n-2) and so on


**TC: O(n)**

2. Binary search
- refer pdf

**TC: O(logn)**


3. Merge sort
refer pdf
- K1 -> base case, mid -> K2, n/2 for both left and right part, merge -> K3n , copy new array conetent -> K4n

- Ignoring k as k is nothing if we compare it with the n*k5 at end

**TC: O(nlogn)**


4. Fibonacci

- Here we get T(n) functions even after cutting, therefore this is diff, and hence we use different methods to find the answer ie recursion tree
- we make a recursion tree , and say each node take K time, hence total time is n*K where n is the total number of nodes 
- wkt at each level of a tree we have 2^n nodes
- so sum pf it = 1+ 2+ 4 + 8 + ...  2^n
- which is equal to 2^(n+1) - 1 
- removing constants we get 2^n (also 2x2^n consider that 2 as constant)


**TC: O(2^n)**


exponential




# Space Complexity

Space required as a function of input, f(n)

- The space complexity is difficult to find as it might take different memory at different time (graph)
- Therefore we say the maximum space complexity over the time as the space complexity

**IMP- Calculate the space complexity of 1 call, and then muliply it to the number of times the func is called  || For recursion trees we need to consider the recursion tree depth**


1. Factorial

we r just using a constant space of k of all the ints and stuff

**SC: O(k*n) -> O(n)**



2. Binary search
we r just using a constant space of k of all the ints and stuff


**SC: O(log2n) or O(logn)**


3. Merge sort
Firstly 
- we r just using a constant space of k of all the ints (mid) and stuff
- and that is called for logn times 
Secondly we r creating a new array to store the values but also deleting it with each call
- we need consider the maximum space complexity and that will be for the main array of length n
- so totally klogn + n, we can neglect klogn as n is greater, hence 


**SC: O(N)**




4. Fibonacci series
- consider the max depth of the tree
- which is n, which takes K spaces

**SC: O(N)**


Time complexity of all sorting methods
![App Screenshot](https://www.aprogrammerlife.com/images/pictuers/array_sorting_algorithms_bigo_complexity_chart.jpg)