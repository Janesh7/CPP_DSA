// 146. LRU Cache

// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

 

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4
 

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 104
// 0 <= value <= 105
// At most 2 * 105 calls will be made to get and put.



/*
===============================
EXPLANATION:
===============================

Goal: Implement an LRU (Least Recently Used) Cache with O(1) time complexity for both get() and put() operations.

How O(1) is Achieved:
---------------------------
1. **Hash Map (`unordered_map<int, Node*>`)**
   - Provides constant-time access to nodes by key.
   - We used key - node instead of key - value to get the node directly and we can remove it from the list in O(1) time.

2. **Doubly Linked List**
   - Maintains order of usage: head (least recently used) to tail (most recently used).
   - Allows O(1) removal and insertion of nodes.
   - Double coz we need to access both previous and next nodes easily in case of middle node removal.

Role of Dummy Nodes:
---------------------------
- `left` (dummy head): Acts as a placeholder before the LRU node.
- `right` (dummy tail): Acts as a placeholder after the MRU node.
- Using dummy nodes simplifies edge-case logic (e.g., when the list is empty or has one item).

Why Doubly Linked List?
---------------------------
- We need to **move accessed nodes** to the end (MRU position).
- Doubly linked list allows:
  - O(1) removal: thanks to back-pointer (`prev`)
  - O(1) insertion: at the tail, using the `prev` of dummy tail

This combination of data structures enables the cache to perform all operations efficiently in constant time.

*/


#include <iostream>
#include <unordered_map>
using namespace std;

// Definition of a Node in Doubly Linked List
class Node {
public:
    int key;    // Key of the cache entry
    int val;    // Value of the cache entry
    Node* prev; // Pointer to previous node
    Node* next; // Pointer to next node

    // Constructor
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

// LRU Cache class
class LRUCache {
private:
    int cap; // Maximum capacity of the cache
    unordered_map<int, Node*> cache; // Hash map to store key-node pairs
    Node* left;  // Dummy head (Least Recently Used)
    Node* right; // Dummy tail (Most Recently Used)

    // Remove a node from the doubly linked list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    // Insert a node at the tail (right before dummy tail)
    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    // Constructor to initialize LRUCache with given capacity
    LRUCache(int capacity) : cap(capacity) {
        cache.clear();

        // Initialize dummy head and tail
        left = new Node(0, 0);  // Dummy node before least recently used
        right = new Node(0, 0); // Dummy node after most recently used

        left->next = right;
        right->prev = left;
    }

    // Get the value of the key if present in cache, otherwise return -1
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            // Since it's accessed, it's now most recently used. Move it to the end.
            remove(node);
            insert(node);
            return node->val;
        }
        return -1; // Key not found
    }

    // Put the key-value pair in the cache. If key already exists, update it.
    void put(int key, int value) {
        // If key already exists, remove the old node
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key]; // Free old memory
        }

        // Create new node and insert at the tail (most recently used position)
        Node* newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;

        // If cache exceeds capacity, remove the least recently used node (head's next)
        if (cache.size() > cap) {
            Node* lru = left->next; // Least Recently Used is right after dummy head
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

    // Destructor to avoid memory leak
    ~LRUCache() {
        Node* current = left;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};
