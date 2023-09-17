# Heaps

heap is a **complete binary tree** that comes with a **heap order property**.

- Complete BT - Every level is completely filled **except possibly the last level** .. also nodes always **lean towards the left**
 *FULL BT- all levels are completely filled*

 HEAP ORDER PROPERTY:

 - MAX HEAP: the values of the child is always lesser than the root value at each level. Root val is the largest value
 - MIN HEAP: the values of the child is always greater than the root value at each level. Root val is the lowest value


 Node -> ith index starting from 1 index
 **Its left child -> 2*i**
 **Its rigth child -> 2*i + 1**

 **its parent -> i/2**

 **leaf nodes lie in index: n/2+1 to n**

 Node -> ith index starting from 0 index
 **Its left child -> 2*i+1**
 **Its rigth child -> 2*i + 2**
 ```
        60
       /  \
      50   40
     / \     
    30  20    
```
store as 
[x,60,50,40,30,20]

*0th index is skipped*




# Foeraml Notes 

 # Comprehensive Guide to Heaps

A heap is a fundamental data structure that plays a crucial role in various algorithms and applications. It is a specialized tree-based data structure that satisfies the heap property, making it efficient for maintaining and retrieving elements with certain priority characteristics. In this comprehensive guide, we will explore heaps in detail, covering their representation, operations, algorithms, and use cases.

## 1. Introduction to Heaps

### What is a Heap?
- A heap is a specialized tree-based data structure that satisfies the heap property.
- Heap property:
   - **Min-Heap**: The value of each node is greater than or equal to the values of its children.
   - **Max-Heap**: The value of each node is less than or equal to the values of its children.

### Types of Heaps
- **Binary Heap**: The most common type, represented as a binary tree.
- **Binomial Heaps**: Supports efficient insertion and union operations. Used in Dijkstra's algorithm.
- **Fibonacci Heaps**: Offers better amortized time complexities for decrease-key and delete operations. Used in some graph algorithms.

### Applications of Heaps
- Priority Queues: Efficiently store and retrieve items with priorities.
- Dijkstra's Algorithm: Find the shortest path in a weighted graph.
- Heap Sort: An in-place sorting algorithm.
- Memory Management: Used in memory allocation algorithms.
- Task Scheduling: Manage tasks with priorities.
- Huffman Coding: Data compression technique.

## 2. Representation of Heaps

### Binary Heap
- A binary heap is a complete binary tree with the heap property.
- In a **min-heap**, the smallest element is at the root. In a **max-heap**, the largest element is at the root.
- Balanced but not sorted like a binary search tree (BST).

### Array Representation
- Heaps can be efficiently represented as arrays.
- Binary tree nodes are stored in an array in a level-wise manner.
- Parent-child relationships are preserved with simple arithmetic calculations.

### Mathematical Properties
- For a node at index `i`:
   - Its parent is at index `i/2`.
   - Its left child is at index `2i`.
   - Its right child is at index `2i + 1`.

## 3. Basic Operations

### Insertion
- To insert an element, place it at the end of the array and perform a "heapify" operation to maintain the heap property.
- **Min-Heap Insertion**:
   1. Add the new element at the end of the array.
   2. Compare it with its parent and swap if necessary until the heap property is restored.

```cpp
// Insertion function for a max-heap.
void insertion(int val)
{
    size += 1;               // Increase the heap size.
    int index = size;       // Set the current index for the new value.
    arr[index] = val;       // Place the new value at the end of the array.

    // Check if the newly inserted value is greater than its parent and swap if necessary to maintain the max-heap property.
    while (index > 1)
    {
        int parent = index / 2;  // Calculate the index of the parent node.
        if (arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);  // Swap parent and child if the parent is smaller.
            index = parent;  // Update the index to the parent for further checks.
        }
        else
        {
            break;  // If the parent is greater, the max-heap property is preserved, exit the loop.
        }
    }
}
```

**TC: O(logn)**



### Deletion (Heapify)
- To remove the root element (min or max), replace it with the last element in the array and perform a "heapify" operation to maintain the heap property.
- **Min-Heap Deletion (Extract Min)**:

**The below algo seems to be errorneous .. but actaully U CAN JUST SWAP ELEMENT WITH THE LAST.. size-- .. AND HEAPIFY THE ARR**
   1. Replace the root with the last element.
   2. Compare it with its children (NOTE": CHECK OVERFLOW OF INDEX as we r doing 2*i to find (left) child) and swap with the smaller child until the heap property is restored.


```cpp
// Deletion function for a max-heap.
void deletion(int i)
{
    if (size == 0)
    {
        cout << "nothing to delete";  // Check if the heap is empty.
        return;
    }

    swap(arr[i], arr[size]);  // Replace the element to be deleted with the last element.
    size -= 1;  // Reduce the heap size.

    // Restore the max-heap property by comparing and swapping the element with its children if necessary.
    while (i < size)
    {
        int leftchild = 2 * i;  // Calculate the index of the left child.
        int rightchild = 2 * i + 1;  // Calculate the index of the right child.

        // Check if the left child exists and is greater than the current element.
        if (leftchild < size && arr[i] < arr[leftchild])
        {
            swap(arr[i], arr[leftchild]);  // Swap with the left child.
            i = leftchild;  // Update the index to the left child.
        }
        // Check if the right child exists and is greater than the current element.
        else if (rightchild < size && arr[i] < arr[rightchild])
        {
            swap(arr[i], arr[rightchild]);  // Swap with the right child.
            i = rightchild;  // Update the index to the right child.
        }
        else
        {
            return;  // If neither child is greater, the max-heap property is preserved, exit the loop.
        }
    }
}
```


### Peek (Find Minimum/Maximum)
- To retrieve the root element (min or max), simply return the root without removing it.

## 4. VVIMP Heapify Algorithm

We start a loop from n/2 to 0 and see if the node is correct as per the heap
if not.. we take the node to the place it belongs
 **leaf nodes lie in index: n/2+1 to n**
So we dont need to process these leaf nodes.. as we know these are already Heaps

**So we only process 1-n/2**

- Convert the given array to a heap.

**ALGO**
- Take the index which has to be heapified.
- get left and right node usong the formula
- **CHECK IF left index is in bounds (1 based indexing to <=n)** and the largest(curr) index is lesser than the left part(this is against the max heap rule).. if yes make the left index largest so it can be processed again
- same for right node
- check if the largest index has been changed .. if yes we swap the element and recursively check for the new index (which is now largest again as we had swapped indexes in prev step)

- To heapify the whole array .. **iteratively call heapify function from n/2 to 1 index**

```cpp
// Recursive heapify function to maintain the max-heap property.
void heapify(int *arr, int size, int i) // Given the array size and the index which has to be heapified
{
    int largest = i;   // Initialize the largest as the current element.
    int left = 2 * i;  // Calculate the index of the left child.
    int right = 2 * i + 1;  // Calculate the index of the right child.

    // Check if the left child exists and is greater than the current element.
    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;  // Update largest to the left child.
    }

    // Check if the right child exists and is greater than the current element or the left child.
    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;  // Update largest to the right child.
    }

    // If the largest element is not the current element, swap them and recursively call heapify on the affected subtree.
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest); // check again for the swapped index
    }
}
int main() {
    ...
    ...
    // HEAPIFY ONLY NON LEAF NODES 
    for (int i=n/2;i<0;i--) // Dont consider 0th index  .. if 0 index start from n/2-1
        heapify(arr[i]);

    ...
}
```
**TC: O(logn)**
### Percolate Up (For Min-Heap)
- Used after insertion or replacement to move an element up the tree until the heap property is satisfied.
- Compare the element with its parent and swap if it violates the heap property.
- Repeat until the element is in its correct position or reaches the root.

### Percolate Down (For Min-Heap)
- Used after deletion or replacement to move an element down the tree until the heap property is satisfied.
- Compare the element with its children and swap with the smaller child until the heap property is restored.
- Repeat until the element is in its correct position or reaches a leaf.

### Complexity Analysis
- Time Complexity: O(log N) for both insertion and deletion (heapify).
- Space Complexity: O(1) as it is performed in-place.

## 5. Heap Sort Algorithm

### Sorting with Heaps
- Heap Sort is an in-place, comparison-based sorting algorithm.
- The idea is to build a max-heap (for ascending order) or min-heap (for descending order) from the input array.
- Repeatedly remove the root element to build the sorted output.


```cpp
// Sorting function using heap sort.
void sorting(int *arr, int size)
{
    if (size == 0)
    {
        return;  // If the heap is empty, nothing to sort.
    }

    // Move the largest element (root) to the end and heapify the remaining elements.
    int index = size;
    while (size > 0)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1); // heapify the ele at 1st index 
    }

    return;
}
```

**We need to build a heap first if normal array is given and then do this sort**
for the above function it was alr done

### Time and Space Complexity
- Time Complexity: O(N * log N), where N is the number of elements.
- Space Complexity: O(1) as it is performed in-place.

## 6. Priority Queue and STL

### Priority Queue Overview
- A priority queue is an abstract data type that provides efficient access to the element with the highest (or lowest) priority.
- Implemented using heaps (usually min-heaps in C++).

### C++ STL Priority Queue
- `std::priority_queue` is the C++ Standard Library's implementation of a priority queue.
- By default, it is a max-heap (use `std::greater` for a min-heap).
- Supports `push`, `pop`, `top`, and other operations.

```cpp
// max heap
priority_queue<int> pq;
pq.push(1);
..
pq.pop();
if (pq.isempty()) cout<<"empty";


// Min heap
priority_queue<int, vector<int>, greater<int> > min_heap;
min_heap.push(3);
...
```

### Custom Comparators
- You can define custom comparators for user-defined types.
- Example: `std::priority_queue<MyType, std::vector<MyType>, MyComparator>`.

