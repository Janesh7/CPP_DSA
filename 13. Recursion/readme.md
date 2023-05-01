# Recursion


- If a function calls itself directly or indirectly its called recursion

In better terms:


**If the solution of the bigger problem depends upon a smaller same problem then we use recursion**


- It can be represented in recursive function
- The last case of a recursive function is called **base case**


In recursion 3 things
- base case (return is mandatory)
- recursive function (smaller func and bigger func, refer factorial)
- processing ( might process the data, or print it ) (optional)

TYPES:
- Tail Recursion: where recursive function comes at the end ( base case -> processing -> recursive function )
- Head recursion : where recursive fucntion is above the processing ( base case -> recursive function -> processing )



Diff: Like the conting.cpp , if we use tail recursion o/p: 5 4 3 2 1 , if we use head recursion o/p: 1 2 3 4 5, depends upon where we put the cout statement

<br />

When we dont have a base case we have infinite fucntion calls which will fill the fucntion calls, and a time wil come when the stack memory is filled and hence it will give a segmentation fault( stack overflow ). Hence base case is mandatory.


- Functiona call stack-> main, fact(3), fact(2), fact(1),fact(0)-> returns 1, and so on 1*2*3, returns 6.




-----------------------------------<br />

## VID 2
Whenever we r trying to solve a problem by recursion **we must focus on solving 1 case and rest would come automatically**


Recursion is similar to PMI (principle of mathematical induction )- where we used to prove P(0) or P(1) as true and then assume P(k) is true, and prove P(k+1) is true , These conditions match the fib series as well, ( base case, solve 1 case, hence all the case will be solved)

Q. Find nth fibonacci series number


Recurence relation: f(n) = f(n-1) + f(n-2)


Note: starting from 0th term


 refer PDF FOR RECURSION TREE TO EASILY UNDERSTAND IT


----------------------------------------------------------------
<br />

Q Count Ways To Reach The N-th Stairs



Taking the last steps into consideration, the guy wouldve jumped from the last step(1 jump) or the one before it (2 jumps), hence gives the recurrence relation:



f(n) = f(n-1) + f(n-2)



Base case: we know that there is no staircase underground and hence gives -> if (n<0) return 0;
also another case when guy is at first step (basement), he jumps at the same spot hence 1 step -> if (n==0) return 1; ie there is 1 way of getting from 0th step to 0th step



Note : this approach gives TLE, code studio expects us to solve this by dp


Refer PDF FOR RECURSION TREE TO EASILY UNDERSTAND IT, SAME AS FIB



### VID 3

Q Is Sorted question using recursion


- base case: if array of size 0 or 1 , then its sorted , return true
- recursive function call: call the function while passing the second elements index in the function,and reducing the size by 1


### VID 4


Exponent using recursion (optimised)

- Normal a^b , multiply a to itself b times
- OPTIMIZED: take two cases



1. if b is even :
    ```
        a^b = a^(b\2) x a^(b\2)
    ```


2. if b is odd :
    ```
        a^b = a x a^(b\2) x a^(b\2)
    ```



Example :
2^9 -> 2 x (2^4) x (2^4) <br />
-> 2^4 = 2^2 x 2^2 <br />
-> 2^2 = 2^1 x 2^1 <br />
-> 2^1 = 2 x 2^0 , which we know is 1


- Hence only 4 iteration is required , otherwise 9



This is significant for higher numbers 



Example:
<br />
2^1024 can be computed in 2^1024 -> 2^512 -> 2^256 -> 2^128 -> 2^64 -> 2^32 -> 2^16 -> 2^8 -> 2^4 -> 2^2 -> 2^1 -> 2^0

<br />
That is in 11 iterations this is computed wheareas it wouldve taken 1024 iterations.



<br />

**Bubble sort**


- Bubble sort using recursion: In Bubble sort our aim is to get the largest element to the last and repeat it, hence recursion can be used
- We use iteration to find the largest element and swap it with the last  element, and recursively do this process until the size of the array left is 1 or 0
