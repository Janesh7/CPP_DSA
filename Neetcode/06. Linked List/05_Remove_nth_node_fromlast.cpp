// 19. Remove Nth Node From End of List
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

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
#include <unordered_map>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Approach 1:
// 1. Create a map to store the index of each node.
// 2. Traverse the linked list and store the index of each node in the map.
// 3. Find the index of the node to be removed by subtracting n from the length of the linked list.
// 4. If the index is 0, remove the head node and return the new head.
// 5. If n is 1, remove the last node and return the head.
// 6. Otherwise, find the node to be removed using the map and remove it by updating the next pointer of the previous node.
// 7. The time complexity is O(n) and the space complexity is O(n).
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Create a map to store the index of each node
        // Traverse the linked list and store the index of each node in the map
        unordered_map<int, ListNode *> m;
        int len = 0; // Length of the linked list

        ListNode *temp = head;
        ListNode *prev = NULL;

        while (temp != NULL)
        {
            // Store the index of each node in the map
            m[len++] = prev;
            prev = temp;
            temp = temp->next;
        }
        // Find the index of the node to be removed by subtracting n from the length of the linked list
        int index = len - n;

        // If the index is 0, remove the head node and return the new head
        if (index == 0)
        {
            temp = head;
            head = head->next;
            delete (temp);
            return head;
        }
        // If n is 1, remove the last node and return the head
        if (n == 1)
        {
            // Find the node to be removed using the map
            auto it = m.find(index);
            // If the node to be removed is the last node, update the next pointer of the previous node
            // and return the head
            prev = it->second;
            temp = prev->next;
            prev->next = NULL;

            delete (temp);
            return head;
        }

        auto it = m.find(index);

        prev = it->second;
        temp = prev->next;
        ListNode *next = temp->next;

        prev->next = next;

        delete (temp);
        return head;
    }
};

// Approach 2:
// 1. Use two pointers to find the N-th node from the end of the linked list.
// 2. Move the first pointer n+1 steps ahead.
// 3. Move both pointers until the first pointer reaches the end of the linked list.
// 4. The second pointer will be at the N-th node from the end of the linked list.
// 5. Skip the N-th node by updating the next pointer of the previous node.
// 6. The time complexity is O(n) and the space complexity is O(1).
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify edge cases where head is removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first pointer n+1 steps ahead
        // n+1 because dummy node is included
        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }

        // Move first to the end, maintaining the gap
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Skip the N-th node
        second->next = second->next->next;

        // Return the new head (skip the dummy node)
        return dummy->next;
    }
};
