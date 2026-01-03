// 25. Reverse Nodes in k-Group
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

// Follow-up: Can you solve the problem in O(1) extra memory space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach: Recursive Solution
// Idea: Reverse the first k nodes, then recursively call the function for the next k nodes.
// If there are fewer than k nodes left, return the head as is without reversal.
// We are not using recurive stack space for the reversal, just for the recursive calls.
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        ListNode *next = head; // Initialize next to head to start checking the next k nodes
        for (int i = 0; i < k; i++)
        {
            if (!next) // If we reach the end of the list before k nodes, return head as is wo reversal
                return head;
            next = next->next;
        }

        ListNode *cur = head; // Start from the head of the current k-group
        ListNode *prev = nullptr;

        for (int i = 0; i < k; i++) // Reverse the current k nodes
        {

            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        // After reversing, head is now the last node of the reversed group
        head->next = reverseKGroup(next, k);

        // and prev is the new head of the reversed group
        return prev;
    }
    /**
     * Time Complexity: O(n), where n is the number of nodes in the linked list.
     * Space Complexity: O(1), since we are reversing in place without using extra space if we ignore the recursive stack space.
     * Note: The recursive stack space is O(n/k) in the worst case, but we consider it as O(1) for this problem.
     */
};

// Pure iterative solution

// Explanation of Key Pointers

// Dummy Node (dummy):
// This is a helper node created at the beginning. It simplifies edge cases, especially when reversing the first group (since the head of the list might change).
// dummy->next = head ensures the list starts from the original head.

// Before Pointer (before):
// This pointer is used to remember the node before the group being reversed.
// Initially, before is set to the dummy node.
// After reversing each group, we update before to point to the node right after the reversed group, effectively moving it forward by k nodes.

// After Pointer (after):
// This pointer points to the first node of the current group we want to reverse.
// Initially, after points to the head of the list (head).
// After reversing each group, after is updated to point to the node after the reversed group, which will be the start of the next group to reverse.

// Current Pointer (curr):
// This is the pointer used to traverse through the group we want to reverse.
// In the loop, we start with curr = after and iterate k times to reverse the nodes.

// Previous Pointer (prev):
// This pointer helps in reversing the current group. Initially, prev points to before, which is the node before the first node of the current group.
// As we reverse each node, prev moves to the current node (curr), and curr moves to the next node (nxt).

// Next Pointer (nxt):
// This is a temporary pointer used to store the next node in the list during the reversal process. This prevents losing reference to the rest of the list.

// Example Walkthrough
// For example, let's say you have a list: 1 -> 2 -> 3 -> 4 -> 5 and k = 3.

// 1 > Initial State:
// dummy->next = 1
// before = dummy, after = 1
// The list looks like: 1 -> 2 -> 3 -> 4 -> 5

// 2 > First Group Reversal (1 -> 2 -> 3):
// after starts at 1.
// We reverse the group [1, 2, 3], so the list looks like: 3 -> 2 -> 1 -> 4 -> 5.
// before->next = 3 (the new head of the reversed group).
// after->next = 4 (the remaining part of the list).
// before = 1, after = 4.

// 3 > Second Group Reversal (4 -> 5):
// Since k = 3, we can't reverse the group [4, 5] because there are fewer than k nodes left.
// We return the modified list: 3 -> 2 -> 1 -> 4 -> 5.

ListNode *reverseKGroup(ListNode *head, int k)
{
    // Initialize a dummy node that helps simplify edge cases (e.g., reversing at the head)
    ListNode *dummy = new ListNode(0);
    dummy->next = head; // Link the dummy node to the original head of the list

    // The 'before' pointer is initially pointing to the dummy node
    ListNode *before = dummy;

    // The 'after' pointer points to the start of the list (head) initially
    ListNode *after = head;

    // The other pointers are used for the reverse operation:
    ListNode *curr = nullptr;
    ListNode *prev = nullptr;
    ListNode *nxt = nullptr;

    while (true)
    {
        // The cursor will check if we have enough nodes left for the group
        ListNode *cursor = after;

        // Check if there are at least 'k' nodes to reverse
        for (int i = 0; i < k; i++)
        {
            if (cursor == nullptr)
            {
                // If fewer than 'k' nodes, return the list as is
                return dummy->next;
            }
            cursor = cursor->next;
        }

        // Now we know there are at least 'k' nodes to reverse
        curr = after;  // Start the reversal from 'after'
        prev = before; // 'prev' will be the node before the group (which starts as the dummy node)

        // Reverse the 'k' nodes
        for (int i = 0; i < k; i++)
        {
            nxt = curr->next;  // Store the next node temporarily
            curr->next = prev; // Reverse the current node's next pointer
            prev = curr;       // Move 'prev' forward to the current node
            curr = nxt;        // Move 'curr' forward to the next node in the group
        }

        // After the loop, 'prev' is the new head of the reversed group
        // So we update the pointers to connect the reversed group
        after->next = curr;  // After the reversed group, connect it to the remaining list
        before->next = prev; // 'before' now points to the new head of the reversed group

        // Move the 'before' pointer to the end of the reversed group
        before = after;

        // Move the 'after' pointer to the next group (after the reversed group)
        after = curr;
    }
}
