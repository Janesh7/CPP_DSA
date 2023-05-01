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




### Lec 5

**Merge sort very important topic** 

#### Merge sort


- Divide the array into two, NOTE: mid = (s+e)/2 , NOTE THAT s=0 FOR THE START, so for an example of array of length 7, ITR WILL BE (0+6)/2 = 3, ie IT WILL DIVIDE THE ARRAY INTO 4 bits and 3 bits resp.



<br />
 

 APPROACHES

 - Create new array when breaking and copy the value
 - use indexes



 IMPORTANT THINGS TO REMBER:
 - IN MergeSort FUNCTION , THE BASE CASE SHOULD BE if (s>=e) return; , EQUAL TO SIGN IS IMP, othwerwise infinite loop
 - to delete an array syntax: delete []first;



#### Theory - Merge sort

*Merge sort is defined as a sorting algorithm that works by dividing an array into smaller subarrays, sorting each subarray, and then merging the sorted subarrays back together to form the final sorted array.*



We already have a number of sorting algorithms then why do we need this algorithm? One of the main advantages of merge sort is that it has a time complexity of O(n log n), which means it can sort large arrays relatively quickly. It is also a stable sort, which means that the order of elements with equal values is preserved during the sort.



Merge sort is a popular choice for sorting large datasets because it is relatively efficient and easy to implement. It is often used in conjunction with other algorithms, such as quicksort, to improve the overall performance of a sorting routine.

ILLUSTRATION

[Alt text](https://media.geeksforgeeks.org/wp-content/uploads/20220722205737/MergeSortTutorial.png)



Algorithm:

```
step 1: start

step 2: declare array and left, right, mid variable

step 3: perform merge function.
    if left > right
        return
    mid= (left+right)/2
    mergesort(array, left, mid)
    mergesort(array, mid+1, right)
    merge(array, left, mid, right)

step 4: Stop
```

The above recurrence can be solved either using the Recurrence Tree method or the Master method. It falls in case II of the Master Method and the solution of the recurrence is θ(Nlog(N)). **The time complexity of Merge Sort isθ(Nlog(N)) in all 3 cases (worst, average, and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.**



Auxiliary Space: O(n), In merge sort all elements are copied into an auxiliary array. So N auxiliary space is required for merge sort.



-Is Merge sort In Place?

No, In merge sort the merging step requires extra space to store the elements.




-Is Merge sort Stable?

Yes, merge sort is stable. 




- How can we make Merge sort more efficient?

Merge sort can be made more efficient by replacing recursive calls with Insertion sort for smaller array sizes, where the size of the remaining array is less or equal to 43 as the number of operations required to sort an array of max size 43 will be less in Insertion sort as compared to the number of operations required in Merge sort.



- Analysis of Merge Sort:

A merge sort consists of several passes over the input. The first pass merges segments of size 1, the second merges segments of size 2, and the i_{th}         pass merges segments of size 2i-1. Thus, the total number of passes is [log2n]. As merge showed, we can merge two sorted segments in linear time, which means that each pass takes O(n) time. Since there are [log2n] passes, the total computing time is O(nlogn).




##### Applications of Merge Sort: 

- Sorting large datasets: Merge sort is particularly well-suited for sorting large datasets due to its guaranteed worst-case time complexity of O(n log n). This makes it a popular choice for sorting algorithms used in databases and other data-intensive applications.

- External sorting: Merge sort is commonly used in external sorting, where the data to be sorted is too large to fit into memory. Merge sort can be adapted to work with external storage devices like hard drives or tape drives, making it useful for applications like sorting large files or processing data streams.

- Parallel processing: Merge sort is a naturally parallelizable algorithm, which means it can be easily adapted to work with multiple processors or threads. This makes it useful for applications that require high-performance computing, such as scientific simulations or financial modeling.

- Stable sorting: Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array. This makes it useful in applications where preserving the original order of equal elements is important, such as in databases or financial systems.

- Custom sorting: Merge sort can be adapted to handle different input distributions, such as partially sorted, nearly sorted, or completely unsorted data. This makes it useful in a variety of real-world applications, where data can have complex and varied distributions.

- Inversion Count Problem

##### Advantages of Merge Sort:

- Stability: Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array. This makes it useful in applications where preserving the original order of equal elements is important.

- Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(n log n), which means it performs well even on large datasets. Other sorting algorithms, such as quicksort, have a worst-case time complexity of O(n^2), which can result in poor performance on large datasets.

- Parallelizable: Merge sort is a naturally parallelizable algorithm, which means it can be easily parallelized to take advantage of multiple processors or threads. This makes it useful for high-performance computing applications.

- Memory efficient: Merge sort has a space complexity of O(n), which means it can sort datasets that are larger than the available memory on a machine. This makes it useful for applications where memory usage is a concern.

- Versatility: Merge sort can be used to sort a wide range of data types, including integers, floating-point numbers, and strings.

- Adaptability: Merge sort can be adapted to handle different input distributions, such as partially sorted, nearly sorted, or completely unsorted data. This makes it useful in a variety of real-world applications.


##### Drawbacks of Merge Sort:

- Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process. This can be a disadvantage in applications with limited memory resources.

- Recursive algorithm: Merge sort is a recursive algorithm, which can result in a large number of function calls and stack usage for very large datasets. This can cause stack overflow errors or other performance issues.

- Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.

- Not always optimal for small datasets: Merge sort has a higher time complexity than some other sorting algorithms, such as insertion sort, for small datasets. This can result in slower performance for very small datasets.

- Complexity of implementation: Merge sort can be more complex to implement than some other sorting algorithms, particularly for developers who are not familiar with recursive algorithms or the concept of merging sorted sub-arrays.