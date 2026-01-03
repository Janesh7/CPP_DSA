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