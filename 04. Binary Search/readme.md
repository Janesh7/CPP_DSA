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
check while(s<e>) condition if only give few correct answer try (s<=e) may give correct answer... try based on the dry runs <-IMP 
<br />
ADVANCED PROMBLEMS: Used in the problems where we have to find
<b>Minimum of all the maximums</b> in a problem like book allocation problem, painters partition, aggressive cows question etc. 
Ex. Given an array ‘arr’ of integer numbers . where ‘arr[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students and the task is to allocate all the books to their students. Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to a student.
3. Book allocation should be in a contiguous manner.
You have to <b>allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.</b>


why we apply b search on non sorted?

we use mostly on sorted array, but here we know the fact that if we choose the middle one then we can eliminate either side of the array and more important is that we are working on sum of the array not as per the values reside into the vector, so we can use that binary search into it. Also given that they r contiguous.




------------------------------------------------------------------------------------------------------------------------------------------------------------------


# Structured notes

## Lec 1

**Lecture Topic: Binary Search**

**Introduction to Binary Search:**
- Binary search is a powerful searching algorithm.
- It's used for searching in a sorted array.
- Extremely efficient compared to linear search, especially for large datasets.
- Key takeaways: It's applied on monotonic functions, values in increasing or decreasing order.

**Linear Search Revision:**
- Linear search: Comparing each element with the key sequentially until a match is found or the end is reached.
- Linear search complexity: O(n), where n is the size of the array.

**Why Use Binary Search?**
- Binary search is efficient. It significantly reduces the number of comparisons needed.
- Example: In a sorted array of 1000 elements, linear search requires up to 1000 comparisons, while binary search needs just around 10 comparisons.
- Binary search complexity: O(log n), where n is the size of the array.

**Binary Search Algorithm:**
- Binary search requires a sorted array.
- Start with the entire sorted array.
- Find the middle element.
- Compare the middle element to the key.
- If the middle element matches the key, return the index.
- If the key is smaller, search the left half; if larger, search the right half.
- Repeat the process in the selected half.
- Continue until the key is found or the search space is empty (start > end).

**Pseudocode in C++:**
```cpp
int binarySearch(int arr[], int size, int key) {
    int start = 0;          // Start index of the search space
    int end = size - 1;     // End index of the search space

    while (start <= end) {  // Continue while the search space is valid
        int mid = start + (end - start) / 2;  // Calculate the middle index

        if (arr[mid] == key) {
            return mid;      // Key found, return its index
        } else if (arr[mid] < key) {
            start = mid + 1; // Search the right half
        } else {
            end = mid - 1;   // Search the left half
        }
    }
    
    return -1;              // Key not found
}
```

**Examples of Binary Search:**
1. Search for 12 in an array [2, 4, 6, 8, 12, 18].
   - Binary Search Result: Index of 12 is 4.

2. Search for 8 in an array [3, 5, 11, 14, 16].
   - Binary Search Result: Index of 8 is 1.

3. Search for 20 in an array [3, 5, 11, 14, 16].
   - Binary Search Result: Index of 20 is -1 (not found).

4. Search for 25 in an array [5, 11, 13, 17, 19, 27].
   - Binary Search Result: Index of 25 is -1 (not found).

**Conclusion:**
- Binary search is a powerful algorithm for searching in sorted arrays.
- It's efficient with a time complexity of O(log n).
- The pseudocode provided in C++ demonstrates how binary search can be implemented.


## Lec 2: Questions


**Lecture Notes: Solving "First and Last Position of an Element in Sorted Array"**

**Introduction:**

**Problem Description:**
- Given a sorted array and an element K, find the first and last positions of K in the array.
- If K is not present, return -1 for both positions.
- If K is present, return the indices of its first and last occurrences.

**Approach: Binary Search for First and Last Occurrence:**
- The problem involves applying binary search twice: once to find the first occurrence and once for the last occurrence.
- Binary search helps optimize the search process, making it efficient.
- The key idea is to determine whether to move left or right based on comparisons with the mid element.

**Binary Search Code for First Occurrence:**
```cpp
pair<int, int> firstAndLastOccurrence(vector<int>& arr, int n, int key) {
    int start = 0;
    int end = n - 1;
    pair<int, int> result = {-1, -1};  // Default result if not found

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            result.first = mid;   // Store first occurrence index
            end = mid - 1;        // Move to left to search for earlier occurrences
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return result;
}
```

**Binary Search Code for Last Occurrence:**
```cpp
pair<int, int> firstAndLastOccurrence(vector<int>& arr, int n, int key) {
    int start = 0;
    int end = n - 1;
    pair<int, int> result = {-1, -1};  // Default result if not found

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            result.second = mid;  // Store last occurrence index
            start = mid + 1;      // Move to right to search for later occurrences
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return result;
}
```

**Implementation:**
- Love Babbar explains how to use the code by passing the array, its size, and the key to the function.
- The function returns a pair of integers representing the first and last occurrences of the key.



### Peak element in mountain

Detailed explanation of how to find the peak element in a mountain array using binary search in C++:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& arr) {
    int start = 0;          // Initialize the start index
    int end = arr.size() - 1;  // Initialize the end index

    while (start < end) {
        int mid = start + (end - start) / 2;  // Calculate the middle index

        if (arr[mid] < arr[mid + 1]) {
            // If the middle element is smaller than the next element,
            // we know that the peak lies to the right.
            start = mid + 1;
        } else {
            // If the middle element is greater than or equal to the next element,
            // we know that the peak lies to the left, or the middle element itself is the peak.
            end = mid;
        }
    }

    // 'start' now contains the index of the peak element
    return start;
}

int main() {
    vector<int> arr = {3, 4, 5, 1};
    int peakIndex = findPeakElement(arr);
    
    cout << "Peak element is at index: " << peakIndex << endl;
    
    return 0;
}
```

In this code, we start with the entire array and iteratively narrow it down until we find the peak element. The binary search is performed by comparing the middle element with the next element in the array. If the middle element is smaller than the next element, it means the peak lies to the right of the middle element, so we update the `start` index to `mid + 1`. If the middle element is greater than or equal to the next element, it means the peak lies to the left or the middle element itself is the peak, so we update the `end` index to `mid`.

We repeat this process until `start` and `end` become equal, at which point we have found the index of the peak element, and we return it.

You can replace the `arr` vector with your own mountain array to find the peak element in that array.


## LEC 3: Questions


**Problem Description:**
Given a rotated sorted array of distinct integers and a target element, we need to find and return the index of the target element in the array. If the target is not found, return -1.

**Notes:**
- This problem is a variation of binary search.
- The key insight is to determine which part of the array (left or right of the pivot) is sorted, and then perform binary search accordingly.

**Pseudocode in C++:**
```cpp
int searchRotatedArray(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found
        }

        // Check which part is sorted: left or right
        if (nums[left] <= nums[mid]) {
            // Left part is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Search in the left sorted part
            } else {
                left = mid + 1; // Search in the right part
            }
        } else {
            // Right part is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Search in the right sorted part
            } else {
                right = mid - 1; // Search in the left part
            }
        }
    }

    return -1; // Target not found
}
```

**Explanation:**
- We maintain two pointers, `left` and `right`, representing the search range.
- In each iteration, we calculate the `mid` point and compare `nums[mid]` with the target.
- We check which part of the array is sorted: the left part (from `left` to `mid`) or the right part (from `mid` to `right`).
- Based on the sorted part and the target value, we update the `left` and `right` pointers accordingly.
- We continue the loop until `left` is less than or equal to `right`.
- If the target is found, we return its index; otherwise, we return -1 if the loop exits without finding the target.




**QUESTION: Search in a Rotated and Sorted Array**

* **Introduction**
  - Problem: Search for an element in a sorted, rotated array.
  - Example: Array [7, 9, 1, 2, 3].
  - Objective: Find if a target element (e.g., 2) is present in the array.

* **Approach**
  - Visualize the array as two monotonic functions.
  - Determine which part of the array to apply binary search to.
  - Use a pivot element to make this decision.

* **Finding the Pivot**
  - Two known values: 0th index and (n-1)th index.
  - Identify the pivot as the leftmost and rightmost values from the same line.
  - Pivot element represents a point of rotation.

* **Comparing with the Target**
  - Compare the target value with the pivot and (n-1)th index value.
  - If target lies between them, apply binary search on the second line.
  - Otherwise, apply binary search on the first line.

* **Implementation in C++**
  - Define a function to find the pivot element.
  - Use binary search to locate the target based on the determined line.
  - Handle conditions for where to apply binary search.

* **Complexity**
  - Time complexity: O(log n) due to binary search.
  - Comparing with linear search (O(n)), this approach is more efficient.

**Topic: Finding Square Root using Binary Search**

* **Introduction**
  - Problem: Find the square root of a given number using binary search.
  - Precision controlled by an optional 'epsilon' parameter.

* **Approach**
  - Initialize left and right bounds for binary search.
  - Calculate the middle point and square it.
  - Adjust bounds based on the square comparison.
  - Repeat until the difference between bounds is less than epsilon.

* **Implementation in C++**
  - Define a `squareRoot` function with 'x' and optional 'epsilon' parameters.
  - Handle negative 'x' values as needed.
  - Set initial left and right bounds.
  - Use a while loop to perform binary search.
  - Return the approximate square root.

* **Complexity**
  - Time complexity: O(log n) due to binary search.
  - Precision controlled by the 'epsilon' parameter.





**QUESTION: Finding Square Root with Decimal Precision using Binary Search**

* **Introduction**
  - Objective: Find the square root of a given number with decimal precision using binary search.
  - Example: Input: 37, Output: 6.082 (approximately).
  - Approach: Incrementally add decimal places and compare with the given number.

* **Pseudocode**
  ```cpp
  double findSquareRoot(int n, int precision) {
      double answer = n;  // Initialize the answer with the integer part of the square root.
      double factor = 1.0; // Initialize the factor to add decimal places.
      
      for (int i = 0; i < precision; i++) {
          factor /= 10; // Reduce the factor to add the next decimal place.
          
          for (int j = 0; (answer + factor * j) * (answer + factor * j) <= n; j++) {
              answer += factor * j;
          }
      }
      return answer;
  }
  ```

* **Explanation**
  - The function `findSquareRoot` takes two parameters: `n` (the number to find the square root of) and `precision` (the number of decimal places to consider).
  - Initialize `answer` to `n`, as the integer part of the square root.
  - Initialize `factor` to `1.0`, which is used to add decimal places (e.g., 0.1, 0.01, etc.).
  - Use a nested loop structure to incrementally add decimal places to `answer`.
  - In the inner loop, add `factor` to `answer` while ensuring the square of the updated `answer` does not exceed `n`.
  - Repeat this process for the desired level of precision.
  - Finally, return the `answer` with decimal precision.

**Example Usage**
```cpp
int main() {
    int n = 37;
    int precision = 3;
    double result = findSquareRoot(n, precision);
    cout << "Square root of " << n << " with " << precision << " decimal places: " << result << endl;
    return 0;
}
```

This code finds the square root of `n` with `precision` decimal places. You can change the values of `n` and `precision` to calculate square roots with different inputs and precisions.