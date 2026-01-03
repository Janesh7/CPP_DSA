# Minimum range of K sorted arrays

**Problem**: Find the minimum range among k sorted arrays.

**Approach**:
1. We maintain two variables: `minRange` to store the minimum range, and `maxEle` to store the maximum element encountered so far.
2. We use a min-heap, `minHeap`, to keep track of the smallest element from each of the k sorted arrays.
3. Initialize `minHeap` with the first element from each row (array) and update `maxEle` accordingly.

**Pseudocode in C++**:
```cpp
struct Element {
  int val; // Value of the element.
  int row; // Index of the row (array) to which the element belongs.
  int col; // Index of the column (element within the row).

  Element(int val, int row, int col) : val(val), row(row), col(col) {}
};

class Compare {
public:
  bool operator()(const Element &a, const Element &b) {
    return a.val > b.val; // Min-heap based on element values.
  }
};

int kSorted(std::vector<std::vector<int>> &sortedArrays, int k, int n) {
  int minRange = INT_MAX;
  int maxEle = INT_MIN;

  std::priority_queue<Element, std::vector<Element>, Compare> minHeap;

  // Initialize minHeap with the first element from each row.
  for (int i = 0; i < k; ++i) {
    if (!sortedArrays[i].empty()) {
      int val = sortedArrays[i][0];
      minHeap.push(Element(val, i, 0));
      maxEle = std::max(maxEle, val);
    }
  }

  int minEle = minHeap.top().val;

  // Main loop to find the minimum range.
  while (minHeap.size() == k) {
    Element current = minHeap.top();
    minHeap.pop();
    minRange = std::min(minRange, maxEle - current.val);

    if (current.col + 1 < sortedArrays[current.row].size()) {
      // Add the next element from the same row to minHeap.
      int newCol = current.col + 1;
      int val = sortedArrays[current.row][newCol];
      minHeap.push(Element(val, current.row, newCol));
      maxEle = std::max(maxEle, val);
    } else {
      // One of the rows is exhausted.
      break;
    }

    // Update minEle if the current element is the new minimum.
    if (current.val < maxEle) {
      minEle = current.val;
    }
  }

  return minRange + 1; // Adding 1 to account for the inclusive range.
}
```

**Illustration**:
Let's illustrate the algorithm with three sorted arrays:

Array 1: [2, 6, 9, 14]
Array 2: [4, 8, 10, 11]
Array 3: [5, 7, 12, 15]

The tree diagram below represents the initial state of the minHeap:

```
           (2,0,0)
         /   |   \
      (4,1,0)  (5,2,0) 
```

- Initially, we have elements (2,0,0), (4,1,0), and (5,2,0) in the minHeap.
- `minEle` is 2, and `maxEle` is 5.
- We pop (2,0,0) from the minHeap and update `minRange` to 5 - 2 = 3.
- We add (6,0,1) to the minHeap, and `maxEle` becomes 6.
- We pop (4,1,0) from the minHeap, and `minRange` remains 3.
- We add (8,1,1) to the minHeap, and `maxEle` becomes 8.
- We pop (5,2,0) from the minHeap, and `minRange` becomes 8 - 6 = 2.
- We add (7,2,1) to the minHeap, and `maxEle` becomes 8.
- The loop continues until one of the arrays is exhausted.

The minimum range is found to be 2, which is the answer.

This algorithm efficiently finds the minimum range among k sorted arrays with a time complexity of O(n * log(k)), where n is the total number of elements across all arrays, and a space complexity of O(k) for the minHeap.




# VVVIMP Find median of a stream


**Problem**: Find the median from a running stream of unsorted elements.

**Approach 1: Insertion Sort and Find Median**

1. Maintain a sorted array and insert each incoming element into the appropriate position using insertion sort.
2. To find the median, if the array size is odd, return the middle element; if even, return the average of the middle two elements.
3. Time Complexity: O(n^2) for insertion sort.
4. Space Complexity: O(n) for the sorted array.

**Approach 2: Sort, Binary Search, Shift, Insert, and Find Median**

1. Keep a sorted array.
2. For each incoming element, use binary search to find its correct position in the sorted array.
3. Shift elements to make space for the new element.
4. Insert the new element.
5. To find the median, use the same logic as in Approach 1.
6. Time Complexity: O(n^2) for binary search and shifting.
7. Space Complexity: O(n) for the sorted array.

Certainly! Let's provide more detailed explanations and illustrations for the optimal approach using heaps to find the median from a running stream of unsorted elements.

**Approach 3 (Optimal): Using Heaps and Signum Function**

Here we finds the median of an array using two heaps. It works by maintaining two heaps: a max-heap to store the smaller elements and a min-heap to store the larger elements. The median of the array is the average of the top elements of the two heaps, if the two heaps are the same size, or the top element of the larger heap, if the two heaps are not the same size.

The code works as follows:

- It creates a max-heap and a min-heap.
- It initializes the median to -1.
- It iterates over the array and calls the callMedian() function for each element.
- The callMedian() function works as follows:

It determines the sign of the difference between the sizes of the two heaps.

Based on the sign of the difference, it performs one of the following actions:

- If the two heaps are the same size, it pushes the element to the min-heap if it is greater than the median, or to the max-heap if it is less than the median.
- If the max-heap is larger than the min-heap, it pushes the element to the min-heap if it is greater than the median, or to the max-heap and pops the top element from the max-heap and pushes it to the min-heap if it is less than the median.
- If the min-heap is larger than the max-heap, it pushes the element to the max-heap if it is greater than the median, or to the min-heap and pops the top element from the min-heap and pushes it to the max-heap if it is less than the median.

After calling the callMedian() function, the median is the average of the top elements of the two heaps, if the two heaps are the same size, or the top element of the larger heap, if the two heaps are not the same size.

The code adds the median to the answer vector.
The code returns the answer vector.


**Explanation:**

1. Use two heaps: a max heap (leftHeap) for the left part of the data and a min heap (rightHeap) for the right part.
2. Initialize the median as -1.
3. For each incoming element (ele), follow these steps:
   - Use the signum function to determine the balance between leftHeap and rightHeap.
   - Depending on the balance, perform the following:
     
     **Balance = 0 (Equal Size):**
     - If the incoming element (ele) is greater than the current median, it belongs to the right part.
     - Push the top element from the min heap (rightHeap) to the max heap (leftHeap) to balance.
     - Pop the top element from the min heap.
     - Push ele into the min heap (rightHeap).
     - Update the median as the average of the tops of both heaps.

     **Balance = 1 (More elements in leftHeap):**
     - If the incoming element (ele) is greater than the current median, it still belongs to the right part.
     - Push the top element from the min heap (rightHeap) into the min heap.
     - Pop the top element from the min heap.
     - Push ele into the max heap (leftHeap).
     - Update the median as the average of the tops of both heaps.

     **Balance = -1 (More elements in rightHeap):**
     - If the incoming element (ele) is greater than the current median, it belongs to the right part.
     - Push the top element from the max heap (leftHeap) into the max heap.
     - Pop the top element from the max heap.
     - Push ele into the min heap (rightHeap).
     - Update the median as the average of the tops of both heaps.

     

4. Update the median after each iteration and store it in the answer vector.
5. Time Complexity: O(n * log(n)) for inserting elements into heaps.
6. Space Complexity: O(n) for the heaps.

**Illustration of Optimal Approach**:

Let's take a stream of unsorted elements as an example:

Stream: [5, 2, 10, 7, 3]

1. Initialize leftHeap, rightHeap, and median.
   - leftHeap: Max Heap
   - rightHeap: Min Heap
   - median: -1

2. Process the stream:

   - **Step 1:** Add 5
     - leftHeap: [5]
     - rightHeap: []
     - median: 5

   - **Step 2:** Add 2
     - leftHeap: [2]
     - rightHeap: [5]
     - median: (2 + 5) / 2 = 3.5

   - **Step 3:** Add 10
     - leftHeap: [2]
     - rightHeap: [5, 10]
     - median: 5

   - **Step 4:** Add 7
     - leftHeap: [2, 7]
     - rightHeap: [5, 10]
     - median: (5 + 7) / 2 = 6

   - **Step 5:** Add 3
     - leftHeap: [2, 3, 7]
     - rightHeap: [5, 10]
     - median: 5

The final medians are [5, 3.5, 5, 6, 5]. For the even-sized array, the median is the average of the two middle elements.

This approach efficiently balances the data using heaps to find the median with a balanced time complexity of O(n * log(n)) and a space complexity of O(n).

Here's the pseudocode in C++:

```cpp
#include <bits/stdc++.h>

// A function to determine the sign of a difference between two integers.
// Returns 0 if the two integers are equal, 1 if the first integer is greater than the second integer,
// and -1 if the first integer is less than the second integer.
int signum(int a, int b) {
  if (a == b) {
    return 0;
  } else if (a > b) {
    return 1;
  } else {
    return -1;
  }
}

// A function to call the median function based on the sign of the difference between the sizes of the two heaps.
void callMedian(int ele, priority_queue<int>& maxH,
                priority_queue<int, vector<int>, greater<int>>& minH, int& median) {
  switch (signum(maxH.size(), minH.size())) {
    // ODD
    case 0:
      // If the two heaps are the same size, push the element to the min-heap if it is greater than the median,
      // or to the max-heap if it is less than the median.
      if (ele > median) {
        minH.push(ele);
        median = minH.top();
      } else {
        maxH.push(ele);
        median = maxH.top();
      }
      break;

    // EVEN
    case 1:
      // If the max-heap is larger than the min-heap, push the element to the min-heap if it is greater than the median,
      // or to the max-heap and pop the top element from the max-heap and push it to the min-heap if it is less than the median.
      if (ele > median) {
        minH.push(ele);
        median = (minH.top() + maxH.top()) / 2;
      } else {
        minH.push(maxH.top());
        maxH.pop();
        maxH.push(ele);
        median = (minH.top() + maxH.top()) / 2;
      }
      break;
    case -1:
      // If the min-heap is larger than the max-heap, push the element to the max-heap if it is greater than the median,
      // or to the min-heap and pop the top element from the min-heap and push it to the max-heap if it is less than the median.
      if (ele > median) {
        maxH.push(minH.top());
        minH.pop();
        minH.push(ele);
        median = (minH.top() + maxH.top()) / 2;
      } else {
        maxH.push(ele);
        median = (minH.top() + maxH.top()) / 2;
      }
      break;
  }
}

// A function to find the median of an array using two heaps.
vector<int> findMedian(vector<int>& arr, int n) {
  // Create a max-heap to store the smaller elements.
  priority_queue<int> maxH;

  // Create a min-heap to store the larger elements.
  priority_queue<int, vector<int>, greater<int>> minH;

  // Initialize the median.
  int median = -1;

  // Create a vector to store the median values.
  vector<int> ans;

  // Iterate over the array and call the median function for each element.
  for (int i = 0; i < n; i++) {
    callMedian(arr[i], maxH, minH, median);

    // Add the median to the answer vector.
    ans.push_back(median);
  }

  // Return the answer vector.
  return ans;
}

```

This pseudocode implements the optimal approach to find the median from a running stream of unsorted elements.

**Illustration of Optimal Approach**:

Let's take a stream of unsorted elements as an example:

Stream: [5, 2, 10, 7, 3]

1. Initialize leftHeap, rightHeap, and median.
   - leftHeap: Max Heap
   - rightHeap: Min Heap
   - median: -1

2. Process the stream:

   - **Step 1:** Add 5
     - leftHeap: [5]
     - rightHeap: []
     - median: 5

   - **Step 2:** Add 2
     - leftHeap: [2]
     - rightHeap: [5]
     - median: (2 + 5) / 2 = 3.5

   - **Step 3:** Add 10
     - leftHeap: [2]
     - rightHeap: [5, 10]
     - median: 5

   - **Step 4:** Add 7
     - leftHeap: [2, 7]
     - rightHeap: [5, 10]
     - median: (5 + 7) / 2 = 6

   - **Step 5:** Add 3
     - leftHeap: [2, 3, 7]
     - rightHeap: [5, 10]
     - median: 5

The final medians are [5, 3.5, 5, 6, 5]. For the even-sized array, the median is the average of the two middle elements.

The optimal heap-based approach provides an efficient way to find the median with a balanced time complexity of O(n * log(n)) and a space complexity of O(n).

**ILLUSTRATION**


**Case 1: Balance = 0 (Equal Size):**

Initially:
```
         Median
        /       \
 MaxHeap: []  minHeap: []
 Median: None
```

1. When a greater element (e.g., 5) is encountered:
```
         Median
        /       \
 MaxHeap: []  minHeap: [5]
 Median: 5
```
Explanation: The element belongs to the right part (minHeap). We push it to minHeap. The median is the top element of minHeap, which is 5.

2. When a smaller element (e.g., 2) is encountered:
```
         Median
        /       \
 MaxHeap: [2]  minHeap: [5]
 Median: 3.5
```
Explanation: The element belongs to the left part (maxHeap). We push it to maxHeap. To calculate the median, we average the tops of both heaps, which is (2 + 5) / 2 = 3.5.

**Case 2: Balance = 1 (More elements in leftHeap):**

Initially:
```
         Median
        /       \
 MaxHeap: [2]  minHeap: []
 Median: 2
```

1. When a greater element (e.g., 4) is encountered:
```
         Median
        /       \
 MaxHeap: [2]  minHeap: [4]
 Median: 3
```
Explanation: The element still belongs to the right part (minHeap). We push it to minHeap, move the top element from minHeap (4) to maxHeap, and calculate the median as the top element of maxHeap, which is 3.

2. When a smaller element (e.g., 1) is encountered:
```
         Median
        /       \
 MaxHeap: [1, 2]  minHeap: [4]
 Median: 2
```
Explanation: The element belongs to the left part (maxHeap). We push it to maxHeap. To calculate the median, we average the tops of both heaps, which is (1 + 4) / 2 = 2.

**Case 3: Balance = -1 (More elements in rightHeap):**

Initially:
```
         Median
        /       \
 MaxHeap: []  minHeap: [4]
 Median: 4
```

1. When a greater element (e.g., 6) is encountered:
```
         Median
        /       \
 MaxHeap: [4]  minHeap: [6]
 Median: 5
```
Explanation: The element belongs to the right part (minHeap). We push it to minHeap, move the top element from maxHeap (4) to minHeap, and calculate the median as the average of the tops of both heaps, which is (4 + 6) / 2 = 5.

2. When a smaller element (e.g., 3) is encountered:
```
         Median
        /       \
 MaxHeap: [3]  minHeap: [4, 6]
 Median: 4
```
Explanation: The element belongs to the left part (maxHeap). We push it to maxHeap, move the top element from maxHeap (3) to minHeap, and calculate the median as the average of the tops of both heaps, which is (3 + 4) / 2 = 4.

These examples illustrate how the median is calculated and updated as elements are added while maintaining balance in the maxHeap (leftHeap) and minHeap (rightHeap).

# Problem: Reorganize String

**Intuition:**
- The idea is to place the character with the highest frequency as far apart as possible to avoid adjacent characters being the same.

**Approach:**
1. Count the frequency of each character in the input string.
2. Check if the frequency of any character exceeds half the length of the string. If it does, it's not possible to reorganize the string, so return an empty string.
3. Build a priority queue (max heap) of character frequencies and characters themselves.
4. While the priority queue has at least two elements:
   - Pop the two characters with the highest frequencies from the priority queue.
   - Append these characters to the result string.
   - Decrease their frequencies by 1 and push them back to the priority queue if their frequency is still greater than 1.
5. If there's one character left in the priority queue, append it to the result string.
6. Return the result string as the reorganized string.

**Explanation:**
- The algorithm ensures that characters with the highest frequencies are placed as far apart as possible in the reorganized string, preventing adjacent characters from being the same.

- By using a priority queue, we always have access to the character with the highest frequency. We repeatedly select the two characters with the highest frequencies and alternate between them to construct the reorganized string.

- The check for a character's frequency exceeding half the length of the string is crucial. If a character appears more frequently than that, it would be impossible to avoid having adjacent characters, making the reorganization impossible.

**Complexity:**
- Time complexity: O(n log n) where n is the length of the input string.
- Space complexity: O(n) for the frequency array and the priority queue.

**C++ Code:**
```cpp
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> f(26, 0);
        int n = s.size();
        
        // Count the frequency of each character and check if any frequency exceeds half the length.
        for (int i = 0; i < s.size(); i++) {
            f[s[i] - 'a']++;
            if (f[s[i] - 'a'] > (n + 1) / 2)
                return "";
        }
        
        priority_queue<pair<int, char>> p;
        for (int i = 0; i < 26; i++) {
            if (f[i] != 0) {
                p.push({f[i], (char)i + 'a'});
            }
        }
        
        string ans = "";
        while (p.size() >= 2) {
            pair<int, char> p1 = p.top();
            p.pop();
            pair<int, char> p2 = p.top();
            p.pop();
            ans += p1.second;
            ans += p2.second;
            if (p1.first > 1) {
                p.push({p1.first - 1, p1.second});
            }
            if (p2.first > 1) {
                p.push({p2.first - 1, p2.second});
            }
        }
        if (p.size() == 1)
            ans += p.top().second;
        
        return ans;
    }
};
```
