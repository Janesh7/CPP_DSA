// 19. Remove Nth Node From End of List
// Medium

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
 

// Follow up: Could you do this in one pass?


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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        unordered_map <int, ListNode*> m;
        int len = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp!=NULL) {
            m[len++]=prev;
            prev = temp;
            temp = temp->next;
        }
        int index = len-n;
        if (index==0) {
            temp = head;
            head = head->next;
            delete(temp);
            return head;
        }
        if (n==1) {
            auto it = m.find(index);
            prev = it->second;
            temp = prev->next;
            prev->next = NULL;
            delete(temp);
            return head;
        }
        auto it = m.find(index);
        prev = it->second;
        temp = prev->next;
        ListNode* next = temp->next;
        prev->next = next;
        delete(temp);
        return head;

    }
};