// Middle Of Linked List

// Easy
// Problem Statement
// Suggest Edit
// Given the head node of the singly linked list, return a pointer pointing to the middle of the linked list.
// If there are an odd number of elements, return the middle element if there are even elements return the one which is farther from the head node.
// For example, let the linked list be 1->2->3->4->null
// add-image

// Since the number of elements in this linked list is 4 so we have 2 middle elements, i.e. 2 and 3, but we return 3 as it is farther from the head node, i.e. 1.
// Detailed explanation ( Input/output format, Notes, Images )

// Constraints :
// 1 <= T <= 50
// 1 <= N <= 4*10^4
// -10^9 <= data <= 10^9 
// data ≠ -1

// Where 'N' is the number of nodes and 'data' is the value of nodes.

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 1 2 3 4 5 -1
// 4 0 32 5 48 6 -1
// Sample Output 1 :
// 3
// 5
// Explanation Of Sample Input 1 :
// For the first test case:

// The linked List is 1->2->3->4->5->NULL
// We can clearly see that there are 5 elements in the linked list and the middle element is 3 hence we return a pointer poiniting to the middle element i.e 3.

// For the second test case:

// The linked List is : 4->0->32->5->48->6->NULL

// We have 6 elements in the linked list. we will have 2 middle elements i.e 32 and 5. Since it is specified to return the element farther from the root node, we return 5.
// Sample Input 2 :
// 2
// 2 69 7 -1
// 1 4 5 8 9 6 3 -1
// Sample Output 2 :
// 69
// 8



// APPROACH

/*
- If the head is null or the head-> next is null ie the size is 0 or 1, then return the head (null or first ele only which is head in both case)
- If the size of the LL is 2 return head->next ie 1st ele


MAIN
- Make two pointer, fast and slow resp
- fast traverse two nodes at a time, TAKE THE SECOND STEP IF fast(IMP:ALREADY INCREMENTED IN PREVIOUS STEP, so dont do fast->next rather use fast!=null) is not null
- slow traverse one node at a time

So when the fast pointer reaches the end , the slow points to the mid element

FOR ODD: (n/2+1)=3
ex 
1 2 3 4 5 

1>
slow -> 1
fast -> 2

2>
slow -> 2
fast -> 4

3> 
slow -> 3
fast -> NULL exit and return 3rd node




FOR EVEN: (n/2+1) = 4
ex
1 2 3 4 5 6

1>
slow -> 1
fast -> 2

2>
slow -> 2
fast -> 4

3>
slow -> 3
fast -> 6

4> 
first step for fast, it becomes null, therefore no second step
slow -> 4

return 4
*/

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/



Node *findMiddle(Node *head) {
    // Write your code here
    if (head==NULL || head->next==NULL)
        return head;
    
    if (head->next->next==NULL)
        return head->next;
        
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL) {
        fast=fast->next;
        if (fast!=NULL)
            fast=fast->next;
        
        slow=slow->next;
    }
    return slow;
}