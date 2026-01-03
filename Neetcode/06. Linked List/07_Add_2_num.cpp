// 2. Add Two Numbers
// Solved
// Medium
// Topics
// Companies
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

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

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *dummyHead = new ListNode(0); // Dummy head to simplify the code
        // Pointer to the tail of the new list
        ListNode *tail = dummyHead;
        int carry = 0; // Initialize carry to 0
        // Traverse both lists until both are null and there is no carry

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {

            int digit1 = (l1 != nullptr) ? l1->val : 0; // Get the value of the current node in l1 or 0 if l1 is null
            int digit2 = (l2 != nullptr) ? l2->val : 0; // Get the value of the current node in l2 or 0 if l2 is null
            // Calculate the sum of the two digits and the carry

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            // Move to the next nodes in l1 and l2
            // If l1 or l2 is null, move to the next node
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

// Real add code
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
private:
    Node *reverse(Node *head)
    {

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(struct Node *&head, struct Node *&tail, int val)
    {

        Node *temp = new Node(val);
        // empty list
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    struct Node *add(struct Node *first, struct Node *second)
    {
        int carry = 0;

        Node *ansHead = NULL;
        Node *ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {

            int val1 = 0;
            if (first != NULL)
                val1 = first->data;

            int val2 = 0;
            if (second != NULL)
                val2 = second->data;

            int sum = carry + val1 + val2;

            int digit = sum % 10;

            // create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            if (first != NULL)
                first = first->next;

            if (second != NULL)
                second = second->next;
        }
        return ansHead;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);

        // step2 - add 2 LL
        Node *ans = add(first, second);

        // step 3
        ans = reverse(ans);

        return ans;
    }
};