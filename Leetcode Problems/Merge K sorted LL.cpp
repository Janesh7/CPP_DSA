// 23. Merge k Sorted Lists
// Hard


// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
 

// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.


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
class Compare {
public:
    bool operator() (ListNode* a,ListNode* b) {
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>, Compare> MinHeap;

        for (int i=0;i < lists.size(); i++) {
            auto temp = lists[i];
            if (temp!=NULL)
                MinHeap.push(temp);
        }

        ListNode* Head = new ListNode();
        ListNode* temp = Head;
        while (!MinHeap.empty()) {
            ListNode* curr = MinHeap.top();

            temp->next = curr;
            temp = temp->next;

            if (curr->next!=NULL) {
                ListNode* next = curr->next;
                MinHeap.push(next);
            }
            MinHeap.pop();
            
        }
        if (Head->next==NULL)
            return NULL;
        return Head->next;
    }
};