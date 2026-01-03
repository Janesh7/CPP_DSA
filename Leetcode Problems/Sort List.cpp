// 148. Sort List
// Medium


// Given the head of a linked list, return the list after sorting it in ascending order.

 

// Example 1:


// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:


// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105
 

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?


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
    ListNode* findMid(ListNode* head) {
        if (head->next==NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow!=NULL && fast->next!=NULL) {
            slow = slow->next;
            if (fast->next->next==NULL)
                break;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* left, ListNode* right) {
        if (left==NULL)
            return right;
        if (right==NULL)
            return left;
        ListNode* temp = new ListNode(-1);
        ListNode* head = temp;
        while (left!=NULL && right!=NULL) {
            if (left->val<=right->val)
            {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;

        }
        if (left!=NULL)
        {
            while (left!=NULL)
            {
                temp->next = left;
                left = left->next;
                temp = temp->next;
            }
        }
        if (right!=NULL)
        {
            while (right!=NULL)
            {
                temp->next = right;
                right = right->next;
                temp = temp->next;
            }
        }
        return head->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head==NULL || head->next==NULL) 
            return head;
        ListNode* left = head;
        ListNode* mid = findMid(left);
        ListNode* right = mid ->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* result = mergeList(left,right);
        return result;
    }
};