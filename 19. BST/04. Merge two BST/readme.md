### Merging Two Binary Search Trees (BSTs) in C++

Merging two Binary Search Trees (BSTs) involves combining two separate BSTs into a single BST while maintaining the properties of a BST. This process can be broken down into several steps, including merging the trees, converting the merged BST into a sorted doubly linked list (DLL), merging two sorted linked lists, and converting a sorted linked list into a BST. Let's break down these steps in detail.

#### Merging Two BSTs

**Problem Description:**

Given two Binary Search Trees (BSTs), merge them into a single BST.

**Approach:**

To merge two BSTs, you can follow these steps:

1. Perform an in-order traversal of the first BST and store its elements in a sorted array. This will give you the elements of the first BST in sorted order.

2. Perform an in-order traversal of the second BST and store its elements in another sorted array. This will give you the elements of the second BST in sorted order.

3. Merge the two sorted arrays into a single sorted array. This can be done efficiently using a merge-like operation.

4. Construct a new BST from the merged sorted array. You can do this by recursively selecting the middle element of the sorted array as the root and applying the same process to the left and right subarrays.

5. The resulting BST is the merged BST of the two original BSTs.

**Pseudocode (C++):**

```cpp
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
    }
    return result;
}

TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
    // Step 1: Perform in-order traversal of the first BST and store elements in an array.
    vector<int> arr1 = inorderTraversal(root1);
    
    // Step 2: Perform in-order traversal of the second BST and store elements in another array.
    vector<int> arr2 = inorderTraversal(root2);
    
    // Step 3: Merge the two sorted arrays into a single sorted array.
    vector<int> mergedArr;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            mergedArr.push_back(arr1[i]);
            i++;
        } else {
            mergedArr.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        mergedArr.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        mergedArr.push_back(arr2[j]);
        j++;
    }
    
    // Step 4: Construct a new BST from the merged sorted array.
    return sortedArrayToBST(mergedArr, 0, mergedArr.size() - 1);
}

TreeNode* sortedArrayToBST(vector<int>& arr, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = sortedArrayToBST(arr, left, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, right);
    return root;
}
```

#### Convert BST to Sorted Doubly Linked List

**Problem Description:**

Given a BST, convert it to a sorted doubly linked list (DLL).

**Approach:**

To convert a BST to a sorted doubly linked list, you can follow these steps:

1. Perform an in-order traversal of the BST.

2. While traversing, modify the pointers of each node to create the DLL. Specifically, for each node, set its `right` pointer to the next node in the in-order traversal and the `left` pointer to the previous node.

3. Keep track of the head and tail pointers of the DLL during traversal.

4. At the end of the traversal, the `head` pointer will point to the first node of the DLL, and the `tail` pointer will point to the last node.

5. Return the `head` pointer of the DLL.

**Pseudocode (C++):**

```cpp
class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node() {}
    
    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

Node* treeToDoublyList(Node* root) {
    if (!root) return nullptr;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* prev = nullptr;
    
    stack<Node*> stk;
    Node* curr = root;
    
    while (curr || !stk.empty()) {
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }
        
        curr = stk.top();
        stk.pop();
        
        if (!head) head = curr;
        if (prev) {
            prev->right = curr;
            curr->left = prev;
        }
        prev = curr;
        tail = curr;
        
        curr = curr->right;
    }
    
    head->left = tail;
    tail->right = head;
    
    return head;
}
```

#### Merge Two Sorted Linked Lists

**Problem Description:**

Given two sorted linked lists, merge them into a single sorted linked list.

**Approach:**

Merging two sorted linked lists is a classic problem that can be solved using a recursive approach:

1. If either of the linked lists is empty, return the other list as the result.

2. Compare the values of the current nodes of the two linked lists.

3. Select the smaller node as the current node in the merged list and set its `next` pointer to the result of merging the remaining nodes.

4. Repeat steps 2 and 3 until one of the linked lists becomes empty.

5. Append the remaining nodes from the non-empty list to the merged list.

6. Return the merged list.

**Pseudocode (C++):**

```cpp
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
```

#### Convert Sorted Linked List to BST



**Problem Description:**

Given a sorted linked list, convert it into a balanced Binary Search Tree (BST).

**Approach:**

Converting a sorted linked list to a balanced BST can be done efficiently by using a recursive approach:

1. Find the middle node of the linked list. You can do this by using two pointers, one that moves one step at a time and another that moves two steps at a time. When the faster pointer reaches the end, the slower pointer will be at the middle.

2. Create a new TreeNode using the value of the middle node as the root of the BST.

3. Recursively build the left subtree of the BST using the nodes before the middle node in the linked list.

4. Recursively build the right subtree of the BST using the nodes after the middle node in the linked list.

5. Return the root of the BST.

**Pseudocode (C++):**

```cpp
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    
    // Find the middle of the linked list.
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Create a new TreeNode for the middle node.
    TreeNode* root = new TreeNode(slow->val);
    
    // If there's a previous node, split the linked list into two halves.
    if (prev) {
        prev->next = nullptr;
    } else {
        // Handle the case when there's no previous node.
        head = nullptr;
    }
    
    // Recursively build the left and right subtrees.
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    
    return root;
}
```

