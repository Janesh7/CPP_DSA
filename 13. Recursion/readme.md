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



## VID 3

Q Is Sorted question using recursion


- base case: if array of size 0 or 1 , then its sorted , return true
- recursive function call: call the function while passing the second elements index in the function,and reducing the size by 1


## VID 4


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




## Lec 5

**Merge sort very important topic** 

### Merge sort


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

![App Screenshot](https://media.geeksforgeeks.org/wp-content/uploads/20220722205737/MergeSortTutorial.png)



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

The above recurrence can be solved either using the Recurrence Tree method or the Master method. It falls in case II of the Master Method and the solution of the recurrence is θ(Nlog(N)). 


**The time complexity of Merge Sort isθ(Nlog(N)) in all 3 cases (worst, average, and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.**



Auxiliary Space: O(n), In merge sort all elements are copied into an auxiliary array. So N auxiliary space is required for merge sort.



- Is Merge sort In Place?

No, In merge sort the merging step requires extra space to store the elements.




- Is Merge sort Stable?

Yes, merge sort is stable. 

--------------------- TBC-------------------------------


### Stability Of sorting Algos
<b>WHAT IS STABLE SORTING ALGO</b>


*A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input data set*


Informally, stability means that equivalent elements retain their relative positions, after sorting.

- Do we care for simple arrays like the array of integers? 
When equal elements are indistinguishable, such as with integers, or more generally, any data where the entire element is the key, stability is not an issue. Stability is also not an issue if all keys are different.

- Where stable sorting algorithms are useful?
 Consider the following dataset of Student Names and their respective class sections.

```
 \\ (Dave, A)\\ (Alice, B)\\ (Ken, A)\\ (Eric, B)\\ (Carol, A) 
```
If we sort this data according to name only, then it is highly unlikely that the resulting dataset will be grouped according to sections as well. 

```
\\ (Alice, B)\\ (Carol, A)\\ (Dave, A)\\ (Eric, B)\\ (Ken, A) 
```

So we might have to sort again to obtain the list of students section-wise too. But in doing so, if the sorting algorithm is not stable, we might get a result like this:

```
\\ (Carol, A)\\ (Dave, A)\\ (Ken, A)\\ (Eric, B)\\ (Alice, B) 
```

The dataset is now sorted according to sections, but not according to names. In the name-sorted dataset, the tuple (Alice, B) was before (Eric, B) , but since the sorting algorithm is not stable, the relative order is lost. If on the other hand, we used a stable sorting algorithm, the result would be:

```
\\ (Carol, A)\\ (Dave, A)\\ (Ken, A)\\ (ALice, B)\\ (Eric, B) 
```

Here the relative order between different tuples is maintained. It may be the case that the relative order is maintained in an Unstable Sort but that is highly unlikely.

- Which sorting algorithms are stable? 

Some Sorting Algorithms are stable by nature, such as Bubble Sort, Insertion Sort, Merge Sort, Count Sort, etc. Comparison-based stable sorts such as Merge Sort and Insertion Sort maintain stability by ensuring that Element A[j] comes before A[i] if and only if A[j] < A[i], here i, j are indices, and i < j. The relative order is preserved if A[i] \equiv A[j] i.e. A[i] comes before A[j]



Other non-comparison-based sorts such as Counting Sort maintain stability by ensuring that the Sorted Array is filled in reverse order so that elements with equivalent keys have the same relative position. Some sorts such as Radix Sort depend on another sort, with the only requirement that the other sort should be stable.


- Which sorting algorithms are unstable? 

Quick Sort, Heap Sort etc., can be made stable by also taking the position of the elements into consideration. This change may be done in a way that does not compromise a lot on the performance and takes some extra space, possibly \theta(n)     .

- Can we make any sorting algorithm stable? 

Any given sorting algorithm which is not stable can be modified to be stable. There can be algorithm-specific ways to make it stable, but in general, any comparison-based sorting algorithm which is not stable by nature can be modified to be stable by changing the key comparison operation so that the comparison of two keys considers position as a factor for objects with equal keys.




------------------------------------------------------- <continued> ----------------------------

- How can we make Merge sort more efficient?

Merge sort can be made more efficient by replacing recursive calls with Insertion sort for smaller array sizes, where the size of the remaining array is less or equal to 43 as the number of operations required to sort an array of max size 43 will be less in Insertion sort as compared to the number of operations required in Merge sort.



- Analysis of Merge Sort:

A merge sort consists of several passes over the input. The first pass merges segments of size 1, the second merges segments of size 2, and the i_{th}         pass merges segments of size 2i-1. Thus, the total number of passes is [log2n]. As merge showed, we can merge two sorted segments in linear time, which means that each pass takes O(n) time. Since there are [log2n] passes, the total computing time is O(nlogn).




#### IMPORTANT Applications of Merge Sort: 

- **Merge sort is often preferred for sorting a linked list. The slow random-access performance of a linked list makes some other algorithms (such as quicksort) perform poorly, and others (such as heapsort) completely impossible.** 

- Sorting large datasets: Merge sort is particularly well-suited for sorting large datasets due to its guaranteed worst-case time complexity of O(n log n). This makes it a popular choice for sorting algorithms used in databases and other data-intensive applications.

- External sorting: Merge sort is commonly used in external sorting, where the data to be sorted is too large to fit into memory. Merge sort can be adapted to work with external storage devices like hard drives or tape drives, making it useful for applications like sorting large files or processing data streams.

- Parallel processing: Merge sort is a naturally parallelizable algorithm, which means it can be easily adapted to work with multiple processors or threads. This makes it useful for applications that require high-performance computing, such as scientific simulations or financial modeling.

- Stable sorting: Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array. This makes it useful in applications where preserving the original order of equal elements is important, such as in databases or financial systems.

- Custom sorting: Merge sort can be adapted to handle different input distributions, such as partially sorted, nearly sorted, or completely unsorted data. This makes it useful in a variety of real-world applications, where data can have complex and varied distributions.

- Inversion Count Problem

#### Advantages of Merge Sort:

- Stability: Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array. This makes it useful in applications where preserving the original order of equal elements is important.

- Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(n log n), which means it performs well even on large datasets. Other sorting algorithms, such as quicksort, have a worst-case time complexity of O(n^2), which can result in poor performance on large datasets.

- Parallelizable: Merge sort is a naturally parallelizable algorithm, which means it can be easily parallelized to take advantage of multiple processors or threads. This makes it useful for high-performance computing applications.

- Memory efficient: Merge sort has a space complexity of O(n), which means it can sort datasets that are larger than the available memory on a machine. This makes it useful for applications where memory usage is a concern.

- Versatility: Merge sort can be used to sort a wide range of data types, including integers, floating-point numbers, and strings.

- Adaptability: Merge sort can be adapted to handle different input distributions, such as partially sorted, nearly sorted, or completely unsorted data. This makes it useful in a variety of real-world applications.


#### Drawbacks of Merge Sort:

- Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process. This can be a disadvantage in applications with limited memory resources.

- Recursive algorithm: Merge sort is a recursive algorithm, which can result in a large number of function calls and stack usage for very large datasets. This can cause stack overflow errors or other performance issues.

- Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.

- Not always optimal for small datasets: Merge sort has a higher time complexity than some other sorting algorithms, such as insertion sort, for small datasets. This can result in slower performance for very small datasets.

- Complexity of implementation: Merge sort can be more complex to implement than some other sorting algorithms, particularly for developers who are not familiar with recursive algorithms or the concept of merging sorted sub-arrays.



#### **IMP POINTS TO REMEMBER WHILE CODING**
- REMEMBER THE RELATIVE POS/LEN
- write base case if (s>=e) return; U CAN USE == 
- Use length variables for both the arrs, remember to use relative length **l1=mid-s+1** (as start would be 0) , **l2 = e-mid**
- How to create dynamic arrays 
```
int *first = new int[len1];
int *second = new int[len2];
delete []first;
delete []second;
```
- when copying the elements 
- while merging the mainIndex starts from s

## Lec 6 - Quick Sort

### Quick Sort

Sometimes they ask as it is, theory + code



- Quick sort is smth opposite to merge sort, in merge sort we break the array first into two and then merge accordingly(sorted), In quick sort we do the opposite ie we partion the array such that the element of the left side partion is less than the element and the other side partion is greater

- In this approach we select an element and put it in the rigth place ie after sorting.  And make sure the left side elements are smaller than it and right side elements are larger

- element which should be put into the rigth place is called pivot

1. We count all the elemrnts which are less than pivot

2. put the pivot in count+start place from above step

3. After this we make sure that the elements of the left and right side are accordingly

4. We use two pointer, each coming from the sides and we find abnormal elements(which are nit in their resp side) and swap them.

5. This process is repeated for each of the array recursively



#### Theory

Analysis of QuickSort:



Time taken by QuickSort, in general, can be written as follows. 
```
 T(n) = T(k) + T(n-k-1) + \theta    (n)
```

The first two terms are for two recursive calls, the last term is for the partition process. k is the number of elements that are smaller than the pivot. 



- Worst Case:
The worst case occurs when the partition process always picks the first or last element as the pivot. If we consider the above partition strategy where the last element is always picked as a pivot, the worst case would occur when the array is already sorted in increasing or decreasing order. Following is the recurrence for the worst case.

```
T(N) = T(0) + T(N-1) + \theta    (N) which is equivalent to 
T(N) = T(N-1) + \theta    (N)
```
<br />
The solution to the above recurrence is O(n2). 

- Best Case:
The best case occurs when the partition process always picks the middle element as the pivot. The following is recurrence for the best case. 

```
 T(N) = 2T(N/2) + \theta   (N)
```

**The solution for the above recurrence is O(N * logN). It can be solved using case 2 of the Master Theorem.**


- Average Case:
To do an average case analysis, we need to consider all possible permutations of the array and calculate the time taken by every permutation which doesn’t look easy.



We can get an idea of an average case by considering the case when partition puts O(N/9) elements in one set and O(9N/10) elements in the other set. Following is the recurrence for this case.  

```
 T(N) = T(N/9) + T(9N/10) + \theta   (N)
```


The solution of the above recurrence is also O(N * logN):


- Space complexity of quick sort is O(n)




**Although the worst case time complexity of QuickSort is O(N2) which is more than many other sorting algorithms like Merge Sort and Heap Sort, QuickSort is faster in practice, because its inner loop can be efficiently implemented on most architectures and in most real-world data. QuickSort can be implemented in different ways by changing the choice of pivot so that the worst case rarely occurs for a given type of data. However, merge sort is generally considered better when data is huge and stored in external storage.**

#### Advantages of Quick Sort:

- It is a divide-and-conquer algorithm that makes it easier to solve problems.
- It is efficient on large data sets.
- It has a low overhead, as it only requires a small amount of memory to function.
- Disadvantages of Quick Sort:
- It has a worst-case time complexity of O(N2), which occurs when the pivot is chosen poorly.
- It is not a good choice for small data sets.
- It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot’s position (without considering their original positions).


#### Some Frequently asked Questions (FAQs) on QuickSort:

- Hoare’s vs Lomuto Partition

Please note that the above implementation is Lomuto Partition(Last element as pivot and no two pointer approach is used). A more optimized implementation of QuickSort is Hoare’s partition which is more efficient than Lomuto’s partition scheme because it does three times less swaps on average.(uses two pointers as implemented in code and hence uses less swaps)



- How to pick any element as pivot?

With one minor change to the above code, we can pick any element as pivot. For example, to make the first element as pivot, we can simply swap the first and last elements and then use the same code. Same thing can be done to pick any random element as a pivot 

- Is QuickSort stable?

The default implementation is not stable. However, any sorting algorithm can be made stable by considering indices as a comparison parameter. 

- Is QuickSort In-place?

As per the broad definition of in-place algorithm, it qualifies as an in-place sorting algorithm as it uses extra space only for storing recursive function calls but not for manipulating the input. 

- What is 3-Way QuickSort?

In simple QuickSort algorithm, we select an element as pivot, partition the array around pivot and recur for subarrays on left and right of pivot. 
Consider an array which has many redundant elements. For example, {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4}. If 4 is picked as pivot in Simple QuickSort, we fix only one 4 and recursively process remaining occurrences. In 3 Way QuickSort, an array arr[l..r] is divided in 3 parts: 

1. arr[l..i] elements less than pivot. 
2. arr[i+1..j-1] elements equal to pivot. 
3. arr[j..r] elements greater than pivot. 

- How to implement QuickSort for Linked Lists?
QuickSort on Singly Linked List (TBD)
QuickSort on Doubly Linked List (TBD)


- Can we implement QuickSort Iteratively?
Yes, please refer Iterative Quick Sort.

**IMPORTANT:  Why Quick Sort is preferred over MergeSort for sorting Arrays ?**
- Quick Sort in its general form is an **in-place sort** (i.e. it doesn’t require any extra storage) whereas merge sort requires O(N) extra storage, N denoting the array size which may be quite expensive. 


- Allocating and de-allocating the extra space used for merge sort increases the running time of the algorithm. Comparing average complexity we find that both types of sorts have O(N logN) average complexity but the constants differ. For arrays, merge sort loses due to the use of extra O(N) storage space.
Most practical implementations of Quick Sort use randomized versions. The randomized version has an expected time complexity of O(N logN). The worst case is possible in the randomized version also, but the worst case doesn’t occur for a particular pattern (like sorted array) and randomized Quick Sort works well in practice.


- Quick Sort is also a **cache friendly** sorting algorithm as it has a good locality of reference when used for arrays.


- Quick Sort is also **tail recursive**, therefore tail call optimizations are done.

**IMPORTANT Why MergeSort is preferred over QuickSort for Linked Lists ?**
- In the case of linked lists, the case is different mainly due to the difference in memory allocation of arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in memory. 

- Unlike arrays, in linked lists, we can insert items in the middle in O(1) extra space and O(1) time. Therefore merge operation of merge sort can be implemented without extra space for linked lists.

- Unlike arrays, we can not do random access in linked lists. Quick Sort requires a lot of this kind of access. In a linked list to access the ith index, we have to travel each and every node from the head to ith node as we don’t have a continuous block of memory. Therefore, the overhead increases for quicksort. Merge sort accesses data sequentially and the need for random access is low. 



**How to optimize QuickSort so that it takes O(log N) extra space in the worst case?**

- As the recursion call is performed at the end of the recursive function, we can use the concept of tail recursion to optimize the space taken by Quicksort. Please refer to QuickSort Tail Call Optimization (Reducing worst case space to log N).


**Conclusion:**
To sum up, it can be said that Quicksort is a fast and efficient sorting algorithm with an average time complexity of O(N logN). It is a divide-and-conquer algorithm that breaks down the original problem into smaller subproblems that are easier to solve. It can be easily implemented in both iterative and recursive forms and it is efficient on large data sets, and can be used to sort data in place. However, it also has some drawbacks such as the worst case time complexity of O(N2) which occurs when the pivot is chosen poorly. The performance of quicksort is sensitive to the choice of the pivot.

### Tail Call Recursion used for optimizing

*Tail recursion is defined as a recursive function in which the recursive call is the last statement that is executed by the function. So basically nothing is left to execute after the recursion call.*

For example the following C++ function print() is tail recursive.

```
// An example of tail recursive function
 
static void print(int n)
{
    if (n < 0)
        return;
    cout << " " << n;
  
    // The last executed statement is recursive call
    print(n - 1);
}
```

 
Time Complexity: O(n)
Auxiliary Space: O(n)

**Need for Tail Recursion:**

- The tail recursive functions are considered better than non-tail recursive functions as tail-recursion can be optimized by the compiler. 

- Compilers usually execute recursive procedures by using a stack. This stack consists of all the pertinent information, including the parameter values, for each recursive call. When a procedure is called, its information is pushed onto a stack, and when the function terminates the information is popped out of the stack. Thus for the non-tail-recursive functions, the stack depth (maximum amount of stack space used at any time during compilation) is more. 

- The idea used by compilers to optimize tail-recursive functions is simple, since the recursive call is the last statement, there is nothing left to do in the current function, so saving the current function’s stack frame is of no use (See this for more details).



Q. Can a non-tail-recursive function be written as tail-recursive to optimize it?



Consider the following function to calculate the factorial of n. 

It is a non-tail-recursive function. Although it looks like a tail recursive at first look. If we take a closer look, we can see that the value returned by fact(n-1) is used in fact(n). So the call to fact(n-1) is not the last thing done by fact(n).

```
#include <iostream>
using namespace std;
 
// A NON-tail-recursive function.  The function is not tail
// recursive because the value returned by fact(n-1) is used
// in fact(n) and call to fact(n-1) is not the last thing
// done by fact(n)
unsigned int fact(unsigned int n)
{
    if (n <= 0)
        return 1;
 
    return n * fact(n - 1);
}
 
// Driver program to test above function
int main()
{
    cout << fact(5);
    return 0;
}
Output
120
Time Complexity: O(n)
Auxiliary Space: O(n)
```

The above function can be written as a tail-recursive function. The idea is to use one more argument and accumulate the factorial value in the second argument. When n reaches 0, return the accumulated value.


Below is the implementation using a tail-recursive function.

```
#include <iostream>
using namespace std;
 
// A tail recursive function to calculate factorial
unsigned factTR(unsigned int n, unsigned int a)
{
    if (n <= 1)
        return a;
 
    return factTR(n - 1, n * a);
}
 
// A wrapper over factTR
unsigned int fact(unsigned int n) { return factTR(n, 1); }
 
// Driver program to test above function
int main()
{
    cout << fact(5);
    return 0;
}
Output
120
Time Complexity: O(n)
Auxiliary Space: O(1)
```



#### **IMPORTANT POINTS TO REMEMBER WHILE CODING**

- Return statement in quicksort funtion: if (s>=e) return;
- quicksort is void func, partion function returns int
- pivot and pivotIndex vars
- Remember to make pivotIndex as **s+count** instead of just count, similiarly remember for loop vars
- in while loop remember to put if condition as while loop coz otherwise it will do an extra swap which should be returned