**Question: Find the kth largest sum of the subarray for the given array.**


**Approach 1: Brute Force**

1. Calculate the sum of all possible subarrays of the given array. This can be done using two nested loops, resulting in a time complexity of O(n^2).
2. Store these sums in an array.
3. Sort the array in descending order.
4. Return the element at the (n - k) index of the sorted array as the kth largest sum.

**Time Complexity**: O(n^2) for calculating sums + O(nlogn) for sorting = O(n^2) (dominated by the sorting).

**Space Complexity**: O(n) for the array to store sums.

**Approach 2: Using a Min Heap**

1. Initialize a min heap (priority queue) with a maximum size of k.
2. Traverse the array, and for each element:
   - Calculate the sum of subarrays ending at the current element.
   - If the size of the heap is less than k, insert the sum into the heap.
   - If the size of the heap is equal to k, compare the sum with the minimum element (top of the heap).
     - If the current sum is larger than the minimum, pop the minimum from the heap and insert the current sum.
3. After the traversal is complete, the heap will contain the k largest sums.
4. The top of the heap will be the kth largest sum.

**Time Complexity**: O(n * log(k)) for the traversal and heap operations. This is more efficient than the brute force approach when k is much smaller than n.

**Space Complexity**: O(k) for the min heap.

Now, let's illustrate these approaches with an example:

**Example:**

Consider the array `[10, -4, 5, -2, 3]` and k = 3.

**Approach 1 (Brute Force):**

1. Calculate subarray sums: `[10, 6, 11, 9, 13, -4, 1, -1, 3, 5]`
2. Sort the sums: `[13, 11, 10, 9, 6, 5, 3, 1, -1, -4]`
3. The 3rd largest sum is 10.

**Approach 2 (Using Min Heap):**

1. Initialize the heap: `[10, -4, 5]`
2. Traverse the array:
   - For the second element (-4), the sums are [6, -4], so heap becomes [6, 5, -4].
   - For the third element (5), the sums are [11, 6, 5], but 5 is smaller than -4, so the heap remains [6, 5, -4].
   - For the fourth element (-2), the sums are [9, 7, 3, -2], so the heap becomes [7, 6, 5].
   - For the fifth element (3), the sums are [13, 11, 10, 9, 6, 5, 3], so the heap becomes [9, 7, 6].
3. The top of the heap is 9, which is the 3rd largest sum.

In this example, the two approaches yield the same result, but the second approach is more efficient, especially for large arrays or when k is small compared to n.

Sure, here are the pseudocodes in C++ for both approaches:

**Approach 1: Brute Force**

```cpp
int kthLargestSum_BruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Calculate all subarray sums
    vector<int> subarraySums;
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += nums[j];
            subarraySums.push_back(currentSum);
        }
    }

    // Sort the subarray sums in descending order
    sort(subarraySums.rbegin(), subarraySums.rend());

    // The kth largest sum is at index k - 1 (0-based index)
    return subarraySums[k - 1];
}
```

**Approach 2: Using a Min Heap**

```cpp
int kthLargestSum_MinHeap(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Traverse the array and maintain the k largest sums in the min heap
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += nums[j];
            if (minHeap.size() < k) {
                minHeap.push(currentSum);
            } else if (currentSum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(currentSum);
            }
        }
    }

    // The top of the min heap contains the kth largest sum
    return minHeap.top();
}
```

# VVIMP Merge k Sorted array

Merging k sorted arrays using a Min Heap of a custom class `Node`. Here are the detailed quality notes:

**Problem Statement:**
Given k sorted arrays, each of size n, merge them into a single sorted array.

**Approach: Using a Min Heap of Custom Class Node**

1. **Custom Class Node:**
   - Define a custom class named `Node`, which will contain three attributes:
     - `data`: To store the element value.
     - `i`: To store the row index (array index) from which the element originates.
     - `j`: To store the column index (position in the array) from which the element originates.
   - This custom class allows us to track which element comes from which array and where it is located.

**WE ARE CREATING A CUSTOM COMPARE CLASS TO COMAPARE**

Certainly, I'll explain the `CustomCompare` class and provide the time and space complexities for the code.

**CustomCompare Class Explanation:**

The `CustomCompare` class is used to define a custom comparison function for the priority queue (Min Heap) to determine the order of elements. In this specific case, we want to maintain a Min Heap based on the `data` attribute of the `Node` class. 

Here's how it works:
- When you push a new `Node` into the priority queue, it will use the `CustomCompare` function to decide where to place this node within the heap.
- The `CustomCompare` function's `operator()` compares two `Node` objects, `a` and `b`.
- It returns `true` if `a.data` is greater than `b.data`, indicating that `a` should come after `b` in the Min Heap. This means that the element with the smallest `data` value will be at the top of the Min Heap.
- When you pop elements from the Min Heap, it will always pop the one with the smallest `data` value first, maintaining the sorted order.

In summary, this custom comparison function ensures that the Min Heap always keeps the smallest element at the top, which is essential for merging k sorted arrays efficiently.


2. **Create a Min Heap:**
   - Create a Min Heap (Priority Queue) of type `Node`. We will use this heap to keep track of the smallest element among all the k arrays.
   - Define a custom comparison class to compare two nodes based on their `data` values. This comparison class ensures that the Node with the smallest `data` value is at the top of the heap.

3. **Initialize Min Heap:**
   - For each of the k sorted arrays, create a Node containing the first element from that array, i.e., `data = array[i][0]`, `i = array_index`, and `j = 0`. Push this Node into the Min Heap.
   - This step initializes the Min Heap with the first element from each array.

4. **Merging Sorted Arrays:**
   - Initialize an empty array `ans` to store the merged result.
   - While the Min Heap is not empty:
     - Pop the top element (smallest element) from the Min Heap. This element represents the smallest unprocessed element among all k arrays.
     - Add the `data` value of the popped Node to the `ans` array since it is the next smallest element.
     - Check if there are more elements in the same array (same row). If yes, create a new Node with the next element in the same array and push it into the Min Heap.
     - Repeat this process until all elements from all arrays are processed.

5. **Return Merged Array:**
   - After processing all elements, the `ans` array contains the merged sorted array. Return `ans` as the final result.

**Time Complexity:**
- Pushing the first element from each of the k arrays into the Min Heap takes O(k * log k) time.
- Processing each element (n * k elements in total) and inserting them into the Min Heap takes O(n * k * log k) time.
- Thus, the overall time complexity is O(n * k * log k).

**Space Complexity:**
- The space complexity is O(k) for the Min Heap and O(n * k) for the `ans` array.
- Therefore, the total space complexity is O(n * k).

This approach efficiently merges k sorted arrays into a single sorted array using a Min Heap, ensuring that the final merged array is sorted as well.

Sure, here's the pseudocode and C++ code for merging k sorted arrays using a Min Heap of a custom class `Node`:

**Pseudocode:**


```cpp
class Node {
public:
    int data;
    int i;
    int j;

    Node(int _data, int _i, int _j) : data(_data), i(_i), j(_j) {}
};

class CustomCompare {
public:
    bool operator()(const Node& a, const Node& b) {
        return a.data > b.data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    vector<int> ans;
    priority_queue<Node, vector<Node>, CustomCompare> minHeap;

    // Initialize the Min Heap with the first element from each array
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            Node node(arrays[i][0], i, 0);
            minHeap.push(node);
        }
    }

    // Merge sorted arrays
    while (!minHeap.empty()) {
        // Pop the smallest element from the Min Heap
        Node top = minHeap.top();
        minHeap.pop();

        // Add the data value of the popped Node to the ans vector
        ans.push_back(top.data);

        // Check if there are more elements in the same array (same row)
        if (top.j + 1 < arrays[top.i].size()) {
            // Create a new Node with the next element in the same array
            Node nextNode(arrays[top.i][top.j + 1], top.i, top.j + 1);
            // Push the new Node into the Min Heap
            minHeap.push(nextNode);
        }
    }

    return ans;
}

```

**Time Complexity (TC):**


The time complexity of the mergeKSortedArrays algorithm is O(N * K * log K), where N is the total number of elements in all the arrays and K is the number of arrays.

The algorithm works by maintaining a min-heap of size K, where each element in the heap represents the smallest element in one of the K arrays. At each step, the algorithm pops the smallest element from the heap and adds it to the output array. If the popped element is not the last element in its array, the algorithm pushes the next element from that array into the heap.

The time complexity of each step of the algorithm is O(log K), since we need to insert and delete elements from the min-heap. The algorithm terminates when the heap is empty, which happens when all the arrays have been merged.

Since the algorithm performs O(log K) operations for each of the N elements in all the arrays, the overall time complexity is O(N * K * log K).

Here is a breakdown of the time complexity of each part of the algorithm:

Initializing the min-heap: O(K * log K)
Merging sorted arrays: O(N * log K)
Total time complexity: O(N * K * log K)
It is important to note that the time complexity of the mergeKSortedArrays algorithm can be improved to O(N * log K) if we use a more efficient data structure, such as a pairing heap, to maintain the min-heap.

**Space Complexity (SC):**

The space complexity is primarily determined by the space needed to store the Min Heap and the `ans` vector. Here's a breakdown:

1. Min Heap: O(k) - The Min Heap can contain at most `k` elements, one from each array.
2. `ans` vector: O(n*m) - The merged array can have up to `n*m` elements.
3. Other variables: O(1) - Variables like iterators and loop counters.

The dominant factor in the space complexity is the `ans` vector, which is O(n*m).
For correctness this is ignored as this is the answer.. therefore the SC is O(K) for the min heap.

So, the overall space complexity is O(N) because it depends on the size of the merged array.



**Merging K Sorted Linked Lists**

In this problem, we are given an array of k sorted linked lists, and we need to merge them into a single sorted linked list. We'll use a min-heap to efficiently select the smallest element among all the linked lists at each step, ensuring that the final merged list remains sorted.

Here's the detailed explanation of the code provided:

1. **Node Structure**: A template class `Node` is provided for a singly-linked list node. It contains a data value of type T and a pointer to the next node. A destructor is implemented to recursively delete the linked list when the node goes out of scope.

2. **Custom Comparison Class**: The `Compare` class is defined, which is used to compare two linked list nodes based on their `data` values. This class is essential for the priority queue (min-heap) to compare and select the smallest node.

3. **Merging Function** (`mergeKLists`):
   - We create a `std::priority_queue` (`minHeap`) that stores pointers to linked list nodes. The custom comparison class `Compare` is used to compare these nodes based on their data values, ensuring the smallest node is always at the top of the min-heap.
   
   - We iterate through the input `listArray`, which contains the heads of k sorted linked lists.
   
   - For each non-empty linked list, we push its head node into the `minHeap`.
   
   - We initialize two pointers, `mergedHead` and `mergedTail`, to manage the merged linked list. They initially point to `nullptr`.
   
   - We enter a loop that continues until the `minHeap` is empty:
     - Pop the smallest node (i.e., the top of the min-heap) from `minHeap`.
     - Add this node to the merged list:
       - If `mergedHead` is `nullptr`, set both `mergedHead` and `mergedTail` to this node.
       - Otherwise, set the `next` pointer of `mergedTail` to the current node and update `mergedTail` to the current node.
       
     - Check if the current node has a non-null `next` pointer (i.e., there are more nodes in its linked list). If yes, push the next node into `minHeap`.
   
   - After the loop, we have a merged linked list starting from `mergedHead`. If `mergedHead` is still `nullptr`, it means all input linked lists were empty, and we return `nullptr` as the result.
   
4. **Time Complexity Analysis**:
   - Initializing the min-heap takes O(k * log(k)) time as we push the head of each linked list into the min-heap (where k is the number of linked lists).
   - Merging the linked lists takes O(N * log(k)) time, where **N is the total number of nodes across all linked lists**. We repeatedly pop the smallest node from the min-heap and push its next node if it exists.
   - Constructing the final merged list by updating `mergedTail` takes O(N) time.
   - Overall, the time complexity is O(N * log(k)).

5. **Space Complexity Analysis**:
   - The space complexity primarily depends on the `minHeap`, which stores at most k elements at any time.
   - Therefore, the space complexity is O(k).

**Pseudocode in C++**:

```cpp
#include <vector>
#include <queue>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        next = nullptr;
        this->data = data;
    }

    ~Node() {
        if (next != nullptr) {
            delete next;
        }
    }
};

class Compare {
public:
    bool operator()(Node<int>* a, Node<int>* b) {
        return a->data > b->data;
    }
};

Node<int>* mergeKLists(std::vector<Node<int>*>& listArray) {
    std::priority_queue<Node<int>*, std::vector<Node<int>*>, Compare> minHeap;

    for (Node<int>* node : listArray) {
        if (node != nullptr) {
            minHeap.push(node);
        }
    }

    Node<int>* mergedHead = nullptr;
    Node<int>* mergedTail = nullptr;

    while (!minHeap.empty()) {
        Node<int>* current = minHeap.top();
        minHeap.pop();

        if (mergedHead == nullptr) {
            mergedHead = mergedTail = current;
        } else {
            mergedTail->next = current;
            mergedTail = mergedTail->next;
        }

        if (current->next != nullptr) {
            minHeap.push(current->next);
        }
    }

    return mergedHead;
}
```

This algorithm efficiently merges k sorted linked lists with a time complexity of O(N * log(k)) and a space complexity of O(k), where N is the total number of nodes in all linked lists.