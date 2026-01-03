// 234. Palindrome Linked List
// Easy



// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
 

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9
 

// Follow up: Could you do it in O(n) time and O(1) space?


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
private:
    ListNode* mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next!=NULL){
            if (fast->next->next!=NULL) {
                fast=fast->next->next;
                slow = slow->next;
            }
            else 
                break;
        }
        return slow;
    }
    
    ListNode* reverse (ListNode* head) {
        ListNode* cur = head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while (cur!=NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL) 
            return true;
        ListNode* m = mid(head);
        ListNode* rev = reverse(m->next);
        ListNode* temp = head;
        while (rev!=NULL) {
            if (rev->val!=temp->val)
                return false;
            rev = rev->next;
            temp = temp->next;
        }
        return true;
    }
};