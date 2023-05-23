// Reverse Linked List


// Avg time to solve 15 mins

// Problem Statement
// Suggest Edit
// Given a singly linked list of integers. Your task is to return the head of the reversed linked list.
// For Example:
// The given linked list is 1 -> 2 -> 3 -> 4-> NULL. Then the reverse linked list is 4 -> 3 -> 2 -> 1 -> NULL and the head of the reversed linked list will be 4.
// Follow Up :
// Can you solve this problem in O(N) time and O(1) space complexity?
// Detailed explanation ( Input/output format, Notes, Images )

// Constraints :
// 1 <= T <= 5
// 0 <= L <= 10^5
// 1 <= data <= 10^9 and data != -1

// Time Limit: 1 sec
// Sample Input 1 :
// 1
// 1 2 3 4 5 6 -1
// Sample Output 1 :
// 6 5 4 3 2 1 -1
// Explanation For Sample Input 1 :
// For the first test case,  After changing the next pointer of each node to the previous node, The given linked list is reversed.
// Sample Input 2 :
// 1
// 10 21 3 2 4 -1
// Sample Output 2 :
// 4 2 3 21 10 -1

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* cur=head;
    LinkedListNode<int>* n = NULL;
    // If we r writing n = head->next in starting and doing similiar stuff, it gives segmentation fault
    while (cur!=NULL) {
        n=cur->next;
        cur->next=prev;
        prev = cur;
        cur=n;
    } 
    return prev;
}


// Recursive soln


void reverse(LinkedListNode<int>* &head,LinkedListNode<int>* cur,LinkedListNode<int>* prev) {
    if (cur==NULL) {
        head = prev;
        return;
    }

    LinkedListNode<int>* forward = cur->next; 
    // it works if u swap the below two statements
    reverse(head,forward,cur);
    cur-> next = prev;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* cur=head;
    reverse(head,cur,prev);
    return head;
}