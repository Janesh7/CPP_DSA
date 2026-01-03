// 143. Reorder List
// Solved
// Medium
// Topics
// Companies
// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:

// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

// Constraints:

// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000

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

// Approach:
// 1. Find the middle of the linked list using the slow and fast pointer technique.
// 2. Reverse the second half of the linked list.
// 3. Merge the two halves of the linked list in the required order.
// 4. The time complexity is O(n) and the space complexity is O(1).
class Solution
{
public:
    void reorderList(ListNode *head)
    {

        
        ListNode *mid = GetMid(head); // Find the middle of the linked list

        ListNode *cur = head; // First half of the linked list
        ListNode *second = mid->next; // Second half of the linked list

        mid->next = nullptr; // Split the linked list into two halves
        // Reverse the second half of the linked list

        Reverse(second);

        ListNode *n1 = nullptr; // Store the next node of the first half
        // Store the next node of the second half 
        ListNode *n2 = nullptr;

        while (cur && second)
        {
            // Store the next node of the first half
            n1 = cur->next;
            // Store the next node of the second half
            n2 = second->next;

            cur->next = second; // Link the first half with the second half
            // Link the second half with the first half
            second->next = n1;

            cur = n1;
            second = n2;
        }

        if (second)
            cur->next = second;
    }

private:
    ListNode *GetMid(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void Reverse(ListNode *&head)
    {

        ListNode *cur = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;

        while (cur != nullptr)
        {
            next = cur->next;

            cur->next = prev;
            prev = cur;
            cur = next;
        }

        head = prev;
    }
};