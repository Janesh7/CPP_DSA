// Linked List Cycle Detection
// Solved 
// Given the beginning of a linked list head, return true if there is a cycle in the linked list. Otherwise, return false.

// There is a cycle in a linked list if at least one node in the list can be visited again by following the next pointer.

// Internally, index determines the index of the beginning of the cycle, if it exists. The tail node of the list will set it's next pointer to the index-th node. If index = -1, then the tail node points to null and no cycle exists.

// Note: index is not given to you as a parameter.

// Example 1:



// Input: head = [1,2,3,4], index = 1

// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:



// Input: head = [1,2], index = -1

// Output: false
// Constraints:

// 1 <= Length of the list <= 1000.
// -1000 <= Node.val <= 1000
// index is -1 or a valid index in the linked list.

#include <iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;             // move by one
            fast = fast->next->next;       // move by two

            if (slow == fast) {
                return true;               // cycle detected
            }
        }

        return false; // no cycle
    }
    // time complexity: O(n)
    // space complexity: O(1)
};