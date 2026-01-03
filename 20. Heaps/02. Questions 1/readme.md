# Finding the kth Smallest Element Using Max Heap

**Algorithm:**
1. Create an empty max heap.
2. Add the first k elements from the array to the max heap.
3. For the remaining elements in the array:
   - If the current element is smaller than the root of the max heap (i.e., the largest element among the k smallest elements):
     - Pop the root element from the max heap.
     - Push the current element into the max heap.
4. After processing all elements, the root of the max heap will be the kth smallest element.

**C++ Pseudocode:**

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap; // Max heap to maintain k smallest elements.

    // Add the first k elements to the max heap.
    for (int i = 0; i < k; i++) {
        maxHeap.push(nums[i]);
    }

    // Process the remaining elements.
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] < maxHeap.top()) {
            maxHeap.pop();          // Remove the largest element among the k smallest elements.
            maxHeap.push(nums[i]);  // Add the current element.
        }
    }

    // The root of the max heap contains the kth smallest element.
    return maxHeap.top();
}

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    int k = 3;
    int result = findKthSmallest(nums, k);
    cout << "The " << k << "th smallest element is: " << result << endl;
    return 0;
}
```

**Illustration:**


Suppose we have the following array of integers: `[3, 1, 4, 1, 5, 9, 2, 6]`, and we want to find the 3rd smallest element (k = 3).

1. **Initial Max Heap (k = 3):**

   We start by adding the first 3 elements `[3, 1, 4]` to the max heap:

   ```
   Max Heap (k = 3):
        4
       / \
      3   1
   ```

2. **Iterating Through the Array (Remaining Elements):**

   We continue iterating through the remaining elements of the array `[5, 9, 2, 6]` and compare each element with the root of the max heap (the largest element among the k smallest elements).

   - For `5`, it is larger than the root (4) of the max heap. So, we don't change anything in the heap:

     ```
     Max Heap (k = 3):
        4
       / \
      3   1
     ```

   - For `9`, it is larger than the root (4) of the max heap. So, we don't change anything in the heap:

     ```
     Max Heap (k = 3):
        4
       / \
      3   1
     ```

   - For `2`, it is smaller than the root (4) of the max heap. So, we pop the root (4) and push 2:

     ```
     Max Heap (k = 3):
        3
       / \
      2   1
     ```

   - For `6`, it is larger than the root (3) of the max heap. So, we don't change anything in the heap:

     ```
     Max Heap (k = 3):
        3
       / \
      2   1
     ```

3. **Final Max Heap (k = 3):**

   After processing all elements, the max heap contains the kth smallest elements:

   ```
   Max Heap (k = 3):
        3
       / \
      2   1
   ```

4. **Result:**

   The root of the max heap (3) is the 3rd smallest element, and we return 3 as the result.


This algorithm efficiently finds the kth smallest element in **O(n*log(k)) time complexity**, where n is the number of elements in the array.
SC: O(K)


**We can use min heap for largest ele**



# is BT a Heap

**Part 1: Checking if it's a Complete Binary Tree (CBT)**

A Complete Binary Tree (CBT) is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as left as possible. To check if a tree is a CBT, the code recursively counts the number of nodes and then compares it with the index of nodes to ensure all nodes are as left as possible.

**Algorithm to Check CBT:**

1. Define a function `Nodecount` that counts the total number of nodes in the tree.
2. Define a function `CBT` that checks whether the tree satisfies the CBT property.
3. In the `CBT` function, compare the index of nodes (`index`) with the total count of nodes (`totalcount`) to ensure all nodes are as left as possible.

**Illustration:**

Suppose we have the following binary tree:

```
        10
       /  \
      9    8
     / \
    7   6
   / \
  5   4
```

The `Nodecount` function returns `7` as there are 7 nodes in the tree. The `CBT` function checks that all nodes are as left as possible based on their indices.

**Pseudocode for CBT Check:**

```cpp
int Nodecount(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int ans = 1 + Nodecount(root->left) + Nodecount(root->right);
        return ans;
    }
}

bool CBT(Node* root, int index, int totalcount) {
    if (root == NULL) {
        return true;
    }
    if (index >= totalcount) {
        return false;
    } else {
        bool left = CBT(root->left, 2 * index + 1, totalcount);
        bool right = CBT(root->right, 2 * index + 2, totalcount);
        return (left && right);
    }
}
```

**Part 2: Checking the Max Heap Property**

In a Max Heap, for any given node 'N,' the value of 'N' is greater than or equal to the values of its children. The code checks this property recursively for each node in the tree.

**Algorithm to Check Max Heap Property:**

1. Define a function `maxheap` that checks whether the tree satisfies the Max Heap property.
2. In the `maxheap` function, compare the value of each node with the values of its left and right children, if they exist.

**Illustration:**

Suppose we have the following binary tree:

```
        10
       /  \
      9    8
     / \
    7   6
   / \
  5   4
```

This tree satisfies the Max Heap property because, at every node, the value of the node is greater than or equal to its children.

**Pseudocode for Max Heap Property Check:**

```cpp
bool maxheap(Node* root) {
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    if (root->right == NULL) {
        return (root->data > root->left->data);
    } else {
        bool left = maxheap(root->left);
        bool right = maxheap(root->right);
        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}
```

**Putting It All Together:**

The `isHeap` function combines both checks. It first calculates the total node count and checks if the tree is a CBT. Then, it checks if the tree satisfies the Max Heap property. If both conditions are met, it returns `true`, indicating that the tree is a heap.

These functions can be used to determine whether a binary tree is a heap, ensuring both the Complete Binary Tree property and the Max Heap property are satisfied.

**TC: O(n)+O(n)O(n) = O(n)**
**TC: O(h)+O(h)O(h) = O(h)**



# Merge two binary max heap


**Merging Two Binary Max Heaps**


**Pseudocode for Merging Two Binary Max Heaps:**

```cpp
// Define a function to heapify a binary max heap.
void heapify(vector<int> &ans, int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && ans[largest] < ans[left])
        largest = left;

    if (right < n && ans[largest] < ans[right])
        largest = right;

    if (largest != i) {
        swap(ans[i], ans[largest]);
        heapify(ans, largest, n);
    }
}

// Define a function to merge two binary max heaps.
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // Create a new vector to store the merged heap.
    vector<int> ans;

    // Copy elements from the first heap (a) to the merged heap (ans).
    for (auto i : a)
        ans.push_back(i);

    // Copy elements from the second heap (b) to the merged heap (ans).
    for (auto i : b)
        ans.push_back(i);

    // Calculate the size of the merged heap.
    int size = ans.size();

    // Perform heapify on the merged heap from the bottom-up.
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(ans, i, size);

    // Return the merged binary max heap.
    return ans;
}
```
REMEMBER:
Node -> ith index starting from 0 index
 **Its left child -> 2*i+1**
 **Its rigth child -> 2*i + 2**

```cpp
for (int i=n/2-1;i<=0;i--) // NON LEAF NODES      , if 0 index - start from n/2-1
        heapify(arr[i]);
```
and in function left/right < size

Node -> ith index starting from 1 index
 **Its left child -> 2*i**
 **Its rigth child -> 2*i + 1**

```cpp
for (int i=n/2;i<0;i--) // Dont consider 0th index  .. if 0 index start from n/2-1
        heapify(arr[i]);
```
and in function left/right <= size



**Explanation:**

1. The `heapify` function is used to maintain the max heap property. It takes an array `ans`, the current index `i`, and the total number of elements `n`. It finds the largest element among the node at index `i`, its left child, and its right child. If necessary, it swaps elements to ensure the max heap property.

2. The `mergeHeaps` function takes two binary max heaps (`a` and `b`) along with their sizes (`n` and `m`) as input.

3. It creates a new vector `ans` to store the merged heap.

4. It copies all elements from heap `a` to `ans` and then all elements from heap `b` to `ans`, effectively merging the two heaps.

5. It calculates the size of the merged heap.

6. It performs a bottom-up heapify operation on the merged heap to ensure that it satisfies the max heap property.

7. Finally, it returns the merged binary max heap.





**Min Cost of Ropes Using Priority Queue**

The problem of finding the minimum cost of joining ropes involves having a set of ropes with different lengths and finding the minimum cost to connect them all into a single rope. The cost of connecting two ropes is equal to their combined length. To minimize the cost, we should connect the ropes with the smallest lengths first.

The provided code offers an efficient solution to this problem using a priority queue. Below are detailed notes on how the code works:

**Pseudocode for Finding Min Cost of Joining Ropes:**

```cpp
long long minCost(long long arr[], long long n) {
    // Create a min-heap (priority queue) to store rope lengths.
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    // Add all the rope lengths to the priority queue.
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    
    long long ans = 0;
    
    // Continue until there is only one rope left in the priority queue.
    while (pq.size() > 1) {
        // Extract the two smallest rope lengths.
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        
        // Calculate the sum of these two lengths.
        long long sum = first + second;
        
        // Add the sum to the answer (total cost).
        ans += sum;
        
        // Push the sum (new rope) back into the priority queue.
        pq.push(sum);
    }
    
    // Return the minimum cost (the answer).
    return ans;
}
```

**Explanation:**

1. The code starts by creating a min-heap (priority queue) called `pq` that stores rope lengths. The priority queue is configured to ensure that the smallest rope length is always at the top.

2. All rope lengths from the input array `arr` are pushed into the priority queue `pq`.

3. The `ans` variable is initialized to zero. It will store the total minimum cost of joining ropes.

4. The code enters a loop that continues until there is only one rope left in the priority queue. The loop's condition checks `pq.size() > 1`.

5. Inside the loop, the two smallest rope lengths are extracted from the priority queue. These lengths are stored in variables `first` and `second`.

6. The sum of these two lengths is calculated and stored in the variable `sum`.

7. The `sum` value (representing the newly joined rope) is added to the `ans` variable, which accumulates the total cost.

8. The `sum` value (new rope) is pushed back into the priority queue.

9. The loop continues, and the process repeats until there is only one rope left.

10. Finally, the function returns the `ans` variable, which contains the minimum cost of joining all the ropes into a single rope.

By using a priority queue to continuously join the smallest ropes, the code efficiently finds the minimum cost of connecting the given set of ropes.


**TC: nlogn, SC: n**


# Min Cost of Ropes Using Priority Queue

The problem of finding the minimum cost of joining ropes involves having a set of ropes with different lengths and finding the minimum cost to connect them all into a single rope. The cost of connecting two ropes is equal to their combined length. To minimize the cost, we should connect the ropes with the smallest lengths first.

The provided code offers an efficient solution to this problem using a priority queue. Below are detailed notes on how the code works:

**Pseudocode for Finding Min Cost of Joining Ropes:**

```cpp
long long minCost(long long arr[], long long n) {
    // Create a min-heap (priority queue) to store rope lengths.
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    // Add all the rope lengths to the priority queue.
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    
    long long ans = 0;
    
    // Continue until there is only one rope left in the priority queue.
    while (pq.size() > 1) {
        // Extract the two smallest rope lengths.
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        
        // Calculate the sum of these two lengths.
        long long sum = first + second;
        
        // Add the sum to the answer (total cost).
        ans += sum;
        
        // Push the sum (new rope) back into the priority queue.
        pq.push(sum);
    }
    
    // Return the minimum cost (the answer).
    return ans;
}
```

**Explanation:**

1. The code starts by creating a min-heap (priority queue) called `pq` that stores rope lengths. The priority queue is configured to ensure that the smallest rope length is always at the top.

2. All rope lengths from the input array `arr` are pushed into the priority queue `pq`.

3. The `ans` variable is initialized to zero. It will store the total minimum cost of joining ropes.

4. The code enters a loop that continues until there is only one rope left in the priority queue. The loop's condition checks `pq.size() > 1`.

5. Inside the loop, the two smallest rope lengths are extracted from the priority queue. These lengths are stored in variables `first` and `second`.

6. The sum of these two lengths is calculated and stored in the variable `sum`.

7. The `sum` value (representing the newly joined rope) is added to the `ans` variable, which accumulates the total cost.

8. The `sum` value (new rope) is pushed back into the priority queue.

9. The loop continues, and the process repeats until there is only one rope left.

10. Finally, the function returns the `ans` variable, which contains the minimum cost of joining all the ropes into a single rope.

By using a priority queue to continuously join the smallest ropes, the code efficiently finds the minimum cost of connecting the given set of ropes.


# Convert BST to Min Heap

**Converting a Complete Binary Search Tree (BST) to a Min Heap**

The problem involves converting a complete binary search tree (BST) into a min heap. A complete BST is a binary search tree in which all levels of the tree are completely filled except possibly for the last level, which is filled from left to right. A min heap is a binary tree where each node has a value less than or equal to the values of its children.

Here's a detailed explanation of how to approach and solve this problem:

**Approach:**

**Since no change in structure we utilized the property of both traversals**

1. First, understand that a complete BST, when traversed in an inorder fashion, gives you a sorted list of elements. In other words, if you perform an inorder traversal on a complete BST, you'll get a sorted array.

2. To convert a complete BST to a min heap, we can take advantage of the fact that the sorted array resulting from an inorder traversal of a BST is essentially a sorted list of elements.

3. We can populate the min heap using a preorder traversal of the tree.


**Illustration:**

Let's consider an example:

Complete BST:
```
      4
     / \
    2   6
   / \ / \
  1  3 5  7
```

Inorder traversal of the BST (sorted order): `[1, 2, 3, 4, 5, 6, 7]`

Now, we'll create an empty min heap and insert elements from the sorted list:

1. Insert 1 into the min heap. Min Heap: `[1]`
2. Insert 2 into the min heap. Min Heap: `[1, 2]`
3. Insert 3 into the min heap. Min Heap: `[1, 2, 3]`
4. Insert 4 into the min heap. Min Heap: `[1, 2, 3, 4]`
5. Insert 5 into the min heap. Min Heap: `[1, 2, 3, 4, 5]`
6. Insert 6 into the min heap. Min Heap: `[1, 2, 3, 4, 5, 6]`
7. Insert 7 into the min heap. Min Heap: `[1, 2, 3, 4, 5, 6, 7]`

The min heap is now complete and represents the min-heapified version of the initial complete BST.

**Time Complexity:**

- Inorder traversal takes O(n) time, where n is the number of nodes in the tree.
- Inserting n elements into the min heap takes O(n * log(n)) time.
- Overall, the time complexity of the algorithm is O(n * log(n)).


```cpp
// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node* root, vector<int> arr, int* i)
{
    if (root == NULL)
        return;
 
    // first copy data at index 'i' of 'arr' to
    // the node
    root->data = arr[++*i];
 
    // then recur on left subtree
    BSTToMinHeap(root->left, arr, i);
 
    // now recur on right subtree
    BSTToMinHeap(root->right, arr, i);
}
 
// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node* root)
{
    // vector to store the data of all the
    // nodes of the BST
    vector<int> arr;
    int i = -1;
 
    // inorder traversal to populate 'arr'
    inorderTraversal(root, arr);
 
    // BST to MIN HEAP conversion
    BSTToMinHeap(root, arr, &i);
}
```