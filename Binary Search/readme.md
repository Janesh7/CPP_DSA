# Binary Search

Condition: Elements should be in Monotonic function ie either should be in increasing order or decreasing sorted order.

Time complexity :
- for a array with 1000 elements, l search worst case 1000 comparisons
- whereas for b search 1000->500->250->125->62->31->15->7->3->1->0 Only 10 comparisons

<br />
IMP NOTE: If we have the largest int array possible ie from INT_MIN to INT_MAX the mid formula would become: (INT_MIN+INT_MAX)/2 which will overflow and give error hence we use a modified formula to avoid getting errors as such cases **int mid = start + (end-start)/2;** coz subtraction wouldnt overflow
<br />
Pair is used to connect two value pair. Its values can be used independently using the function first() and second()
<br />
For N elements : 1st iteration(division of array) : N/2 then N/4,N/8,N/16..... N/2^k.
For the element to be found or not found the size of the array should become 1, therefore
-   N/2^k = 1 => N = 2^k => k = logN (or log2N to be precise) Therefore worst case complexity of bsearch is logN.

<br />
Applications of Binary search:
- Find lower bound
- Find upper bound
- Finding the number of occurence -> This can be simply done by : Upper Bound - Lower Bound + 1 ie find the first and the last occurences and then L-F+1 to get the no of occurences
- Find Pivot element
- Searching in rotated array
- FInding answer by reducing the search space
- COW question, ROTI question, PARATA question, BOOK ALLOCATION problem
<br />
<br />
ADVANCED PROMBLEMS: Used in the problems where we have to find
<b>Minimum of all the maximums</b> in a problem like book allocation problem, painters partition, aggressive cows question etc. 
Ex. Given an array ‘arr’ of integer numbers . where ‘arr[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students and the task is to allocate all the books to their students. Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to a student.
3. Book allocation should be in a contiguous manner.
You have to <b>allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.</b>