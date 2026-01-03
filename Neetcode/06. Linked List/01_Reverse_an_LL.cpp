// Reverse Linked List
// Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list.

// Example 1:

// Input: head = [0,1,2,3]

// Output: [3,2,1,0]
// Example 2:

// Input: head = []

// Output: []
// Constraints:

// 0 <= The length of the list <= 1000.
// -1000 <= Node.val <= 1000

#include <iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseListHelper(head, nullptr);
    }

private:
    ListNode* reverseListHelper(ListNode* current, ListNode* prev) {
        if (current == nullptr) {
            return prev;
        }

        ListNode* next = current->next;
        current->next = prev;
        return reverseListHelper(next, current);
    }
};

// Iterative approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* next = current->next; // Store the next node
            current->next = prev;           // Reverse the link
            prev = current;                 // Move prev to current
            current = next;                 // Move to the next node
        }

        return prev; // New head of the reversed list
    }
};

// Earlier had written
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        reverseList(head, nullptr, nullptr);
        return head;
    }

private:
    void reverseList(ListNode* &head, ListNode* prev, ListNode* next) {
        if (head == nullptr) {
            head = prev;
            return;
        }

        next = head->next;

        head->next = prev;
        reverseList (next, head, nullptr);
    }
};

// This didnt work 

// In your public function:

// ListNode* reverseList(ListNode* head)
// Here, head is passed by value. That means the caller gives you a copy of the pointer.

// Then inside:

// reverseList(head, nullptr, nullptr);
// You pass head by reference to the private function, which modifies it correctly inside that scope. But the original pointer from the caller is unchanged.

// So when you do:

// return head;
// You're just returning the original, unchanged value of head from before the recursive function ran.

// Simple fix is to change the public function to:
// ListNode* reverseList(ListNode*& head)
// This way, the caller's pointer is passed by reference, and any changes made to it inside the private function will be reflected in the caller's context as well.

// Analogy
void modify(int& x) {
    x = 10;
}

void wrapper(int x) {
    modify(x);  // x passed by reference here
    std::cout << x << std::endl;
}

int main() {
    int a = 5;
    wrapper(a);
    std::cout << a << std::endl;
}
