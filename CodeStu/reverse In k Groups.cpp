// Reverse List In K Groups


// Problem Statement

// You are given a linked list of 'N' nodes and an integer 'K'. You have to reverse the given linked list in groups of size K i.e if the list contains x nodes numbered from 1 to x, then you need to reverse each of the groups (1,K),(K+1,2*K), and so on.
// For example, if the list is [1, 2, 3, 4, 5, 6] and K = 2, then the new list will be [2, 1, 4, 3, 6, 5].
// Note:
// 1. In case the number of elements in the last cannot be evenly divided into groups of size k, then just reverse the last group(with any size). For example if the list is 1 2 3 4 5 and K = 3, then the answer would be 3 2 1 5 4.

// 2. All the node values will be distinct.
// Detailed explanation ( Input/output format, Notes, Images )

// Constraints:
// 1 <= T <= 100   
// 1 <= N <= 10^4
// 1 <= K <= 10^4

// Time Limit: 1sec
// Sample Input 1:
// 2
// 1 2 3 4 5 6 -1
// 2
// 5 4 3 7 9 2 -1
// 4 
// Sample Output 1:
// 2 1 4 3 6 5
// 7 3 4 5 2 9
// Explanation Of The Sample Input1:
// For the first test case, we reverse the nodes in groups of two, so we get the modified linked list as 2 1 4 3 6 5.
// For the second test case, we reverse the nodes in groups of four. But for the last 2 elements, we cannot form a group of four, so we reverse those two elements only. Hence the linked list becomes 7 3 4 5 2 9.
// Sample Input 2:
// 2
// 3 2 1 4 5 6 -1
// 1
// 4 3 2 8 -1
// 4 
// Sample Output 2:
// 3 2 1 4 5 6
// 4 3 2 8

#include <bits/stdc++.h> 
/****************************************************************
    Following is the Linked List node structure

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


Node* kReverse(Node* head, int k) {
    // Write your code here.
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    Node* cur = head;
    Node* prev = NULL;
    Node* fwd = NULL;

    while(cur!=NULL && cnt<k) {
        fwd = cur->next;
        cur->next = prev;
        prev = cur;
        cur = fwd;
        cnt++;
    }

    if (fwd != NULL)
        head->next = kReverse(fwd,k);
    return prev;
}