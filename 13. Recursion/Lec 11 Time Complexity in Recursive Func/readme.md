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



![App Screenshot](https://www.aprogrammerlife.com/images/pictuers/array_sorting_algorithms_bigo_complexity_chart.jpg)