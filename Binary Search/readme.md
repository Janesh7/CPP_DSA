# Binary Search

Condition: Elements should be in Monotonic function ie either should be in increasing order or decreasing sorted order.

Time complexity :
- for a array with 1000 elements, l search worst case 1000 comparisons
- whereas for b search 1000->500->250->125->62->31->15->7->3->1->0 Only 10 comparisons

<br />
<br />
For N elements : 1st iteration(division of array) : N/2 then N/4,N/8,N/16..... N/2^k.
For the element to be found or not found the size of the array should become 1, therefore
-   N/2^k = 1 => N = 2^k => k = logN (or log2N to be precise) Therefore worst case complexity of bsearch is logN.

<br />
Applications of Binary search:
- Find lower bound
- Find upper bound
- Finding the number of occurence
- Find Pivot element
- Searching in rotated array
- FInding answer by reducing the search space
- COW question, ROTI question, PARATA question, BOOK ALLOCATION problem