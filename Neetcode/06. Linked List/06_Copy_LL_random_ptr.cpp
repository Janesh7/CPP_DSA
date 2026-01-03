// 138. Copy List with Random Pointer

// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

 

// Example 1:


// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Example 2:


// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
// Example 3:



// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]
 

// Constraints:

// 0 <= n <= 1000
// -104 <= Node.val <= 104
// Node.random is null or is pointing to some node in the linked list.





/*
    Copying a Linked List with Random Pointers: A Dual-Approach Analysis

    --------------------------------------------------------------------
    Introduction & Problem Understanding
    --------------------------------------------------------------------
    The problem involves creating a deep copy of a singly-linked list
    where each node contains:
        - an integer value,
        - a `next` pointer to the next node,
        - a `random` pointer that may point to any node in the list or be null.
    
    The deep copy must:
        - consist of brand new nodes (no references to original nodes),
        - preserve the structure of both `next` and `random` pointers.

    --------------------------------------------------------------------
    Key Concepts and Constraints
    --------------------------------------------------------------------
    Node Anatomy:
        - Each node contains: int val, Node* next, Node* random.

    Deep Copy:
        - The copy must replicate both `next` and `random` relationships.

    Memory Efficiency:
        - Method 1 uses O(n) extra space.
        - Method 2 achieves O(1) extra space (excluding output list).

    --------------------------------------------------------------------
    Strategies to Tackle the Problem
    --------------------------------------------------------------------
    Two approaches to solve the problem:

    Method #1: Hash Map Method
    Method #2: Interweaving Nodes Method

    --------------------------------------------------------------------
    Method #1: Hash Map Method
    --------------------------------------------------------------------
    Intuition:
        - Use a hash map to store a mapping from original nodes to copied nodes.

    Step-by-step:
        1. First Pass - Node Creation:
            - Traverse original list.
            - Create a new node for each original node.
            - Store mapping: original -> copy in a hash map.

        2. Second Pass - Setting Pointers:
            - Traverse original list again.
            - Set `next` and `random` pointers of each new node using the hash map.

    Complexity:
        - Time: O(n)
        - Space: O(n)

    --------------------------------------------------------------------
    Method #2: Interweaving Nodes Method
    --------------------------------------------------------------------
    Intuition:
        - Interleave copied nodes with original nodes to leverage structure for setting random pointers.

    Step-by-step:
        1. Interleaving Nodes:
            - Traverse the list.
            - For each node, insert its copy right after it.

        2. Setting Random Pointers:
            - Traverse the interleaved list.
            - Set `random` of copy as `original->random->next`.

        3. Separating the Lists:
            - Traverse the interleaved list again.
            - Restore original list and extract copied list.

    Complexity:
        - Time: O(n)
        - Space: O(1) (excluding new nodes)

    --------------------------------------------------------------------
    Summary:
    --------------------------------------------------------------------
    Both methods produce a correct deep copy of the list:
        - Use the Hash Map Method for simplicity and readability.
        - Use the Interweaving Method for optimal space efficiency.
*/

#include <unordered_map>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> old_to_new;
        
        Node* curr = head;
        while (curr) {
            old_to_new[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            old_to_new[curr]->next = old_to_new[curr->next];
            old_to_new[curr]->random = old_to_new[curr->random];
            curr = curr->next;
        }
        
        return old_to_new[head];
    }
};





class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* cur = head;  
        Node* next = nullptr;

        while (cur) {

            // Create a new node with the same value as cur
            next = cur->next;
            Node * temp = new Node(cur->val);
            
            // and insert it right after cur
            cur->next = temp;
            temp->next = next;
            cur = next;
        }

        cur = head;

        // Set the random pointer of the new node
        while (cur) {

            // The new node is cur->next, and the random pointer of cur
            cur->next->random = cur->random ? cur->random->next : nullptr; // random can be null

            // Move to the next original node
            cur = cur->next->next;
        }

        Node* dummy = new Node (0);
        Node* new_cur = dummy;

        cur = head;
        
        // Separate the two lists
        // The original list is cur, and the new list is dummy->next
        // We will use new_cur as tail to traverse the new list 
        while (cur) {

            // cur is the original node, and cur->next is the new node
            // We need to set the next pointer of the new node
            new_cur->next = cur->next;
            cur->next = cur->next->next;

            // Move to the next original node
            // and the next new node
            cur = cur->next;
            new_cur = new_cur->next;
        }

        return dummy->next;
    }
};