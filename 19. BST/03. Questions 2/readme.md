### Two Sum in a Binary Search Tree

**Problem Description:**

Given a Binary Search Tree (BST) and a target value, determine if there exist two distinct nodes in the tree whose sum equals the target value.

**Approach:**

1. Traverse the BST in an **inorder** fashion to create a sorted list of values.
2. Initialize two pointers, one at the beginning (left end) of the sorted list and the other at the end (right end) of the sorted list.
3. Use a two-pointer approach to check if there exist two distinct values in the sorted list that sum up to the target value.
4. If such a pair exists, return `true`. Otherwise, return `false`.

**Pseudocode (C++):**

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool findTarget(TreeNode* root, int k) {
    // Step 1: Inorder traversal to create a sorted list
    vector<int> inorderValues;
    inorder(root, inorderValues);

    // Step 2: Initialize two pointers
    int left = 0;
    int right = inorderValues.size() - 1;

    // Step 3: Two-pointer approach to find the pair
    while (left < right) {
        int sum = inorderValues[left] + inorderValues[right];
        if (sum == k) {
            return true; // Found a pair
        } else if (sum < k) {
            left++; // Move the left pointer to increase the sum
        } else {
            right--; // Move the right pointer to decrease the sum
        }
    }

    // Step 4: If no such pair is found
    return false;
}

// Inorder traversal to populate the sorted list
void inorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}
```

**Notes:**

- The `inorder` function performs an inorder traversal of the BST and populates the `inorderValues` vector with the sorted values.
- The two-pointer approach efficiently finds the pair of values that sum up to the target value.
- The time complexity of this solution is O(n) as it performs a single traversal of the tree and a single traversal of the sorted list.
- The space complexity is O(n) due to the storage of the inorder values in the vector.


### Flatten Binary Search Tree to Sorted Linked List

**Problem Description:**

Given a Binary Search Tree (BST), flatten it to a sorted linked list. The linked list should be in ascending order.

**Approach:**

1. Perform an **inorder traversal** of the BST to get the elements in sorted order.
2. Create a new linked list where each node represents an element from the sorted order.
3. Maintain a `prev` pointer to keep track of the previous node in the linked list.
4. For each element encountered during the inorder traversal, create a new linked list node, set its value, make its `next` pointer point to `nullptr`, and connect the `prev` node's `next` to this new node.
5. Update the `prev` pointer to the newly created node.
6. Finally, the linked list will be sorted in ascending order.

**Pseudocode (C++):**

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* flattenBST(TreeNode* root) {
    if (!root) return nullptr; // Empty tree case
    
    // Step 1: Inorder traversal to get sorted elements
    vector<int> sortedElements;
    inorder(root, sortedElements);
    
    // Step 2: Create a new linked list and maintain prev pointer
    ListNode* dummyHead = new ListNode(0);
    ListNode* prev = dummyHead;
    
    // Step 3: Iterate through sorted elements and create linked list nodes
    for (int val : sortedElements) {
        ListNode* newNode = new ListNode(val);
        prev->next = newNode;
        prev = newNode;
    }
    
    // Step 4: Return the sorted linked list
    return dummyHead->next;
}

// Inorder traversal to populate the sorted elements
void inorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}
```

**Notes:**

- The `inorder` function performs an inorder traversal of the BST and populates the `sortedElements` vector with values in sorted order.
- The `flattenBST` function creates a sorted linked list from the sorted elements.
- It uses a `dummyHead` to simplify the creation of the linked list.
- The time complexity of this solution is O(n) as it performs a single traversal of the tree and a single traversal of the sorted elements.
- The space complexity is O(n) due to the storage of the `sortedElements` vector and the linked list nodes.

This code takes a BST and flattens it into a sorted linked list, preserving the sorted order of elements.


### Convert Normal Binary Search Tree to Balanced Binary Search Tree

**Problem Description:**

Given a Binary Search Tree (BST), the task is to convert it into a balanced BST. A balanced BST is defined as a BST in which the height of the left and right subtrees of every node differs by at most 1.

**Approach:**

1. Perform an **inorder traversal** of the given BST to get the elements in sorted order. The inorder traversal of a BST results in elements sorted in ascending order.
2. Create a new balanced BST using a recursive function:
   - Find the middle element from the sorted elements obtained from the inorder traversal. This element will be the root of the balanced BST.
   - Recursively construct the left subtree using the elements to the left of the middle element in the sorted order.
   - Recursively construct the right subtree using the elements to the right of the middle element in the sorted order.
3. Return the root of the balanced BST.

**Pseudocode (C++):**

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* convertToBalancedBST(TreeNode* root) {
    if (!root) return nullptr; // Empty tree case
    
    // Step 1: Inorder traversal to get sorted elements
    vector<int> sortedElements;
    inorder(root, sortedElements);
    
    // Step 2: Create a balanced BST from sorted elements
    return constructBalancedBST(sortedElements, 0, sortedElements.size() - 1);
}

// Inorder traversal to populate the sorted elements
void inorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

// Recursive function to construct a balanced BST
TreeNode* constructBalancedBST(vector<int>& sortedElements, int start, int end) {
    if (start > end) return nullptr; // Base case
    
    // Find the middle element
    int mid = start + (end - start) / 2;
    
    // Create a new node with the middle element as the root
    TreeNode* root = new TreeNode(sortedElements[mid]);
    
    // Recursively construct the left and right subtrees
    root->left = constructBalancedBST(sortedElements, start, mid - 1);
    root->right = constructBalancedBST(sortedElements, mid + 1, end);
    
    return root;
}
```

**Notes:**

- The `inorder` function performs an inorder traversal of the BST and populates the `sortedElements` vector with values in sorted order.
- The `convertToBalancedBST` function converts the given BST into a balanced BST using the sorted elements.
- The `constructBalancedBST` function recursively constructs a balanced BST from the sorted elements.
- The time complexity of this solution is O(n) as it performs a single traversal of the tree to obtain sorted elements and constructs a balanced BST with them.
- The space complexity is O(n) due to the storage of the `sortedElements` vector and the recursive call stack.

This code converts a normal BST into a balanced BST while maintaining the sorted order of elements.


### Construct Binary Search Tree from Preorder Traversal

**Problem Description:**

Given a preorder traversal sequence of a Binary Search Tree (BST), the task is to construct the BST from the given preorder sequence.

**Approach:**

We can construct the BST from the given preorder sequence while maintaining a range for each node. Here's the approach:

1. Initialize two variables `mini` and `maxi` to represent the range for the current node. Initially, set `mini` to `INT_MIN` (negative infinity) and `maxi` to `INT_MAX` (positive infinity), indicating that the current node can have any value within this range.

2. Starting with the first element of the preorder sequence, create a new node using the current element's value and set it as the root node.

3. Move to the next element in the preorder sequence.

4. Recursively construct the left subtree of the current node by calling the `solve` function with `mini` and the current node's value as the range parameters. This means that any node in the left subtree must have a value less than the current node's value but greater than or equal to `mini`.

5. Recursively construct the right subtree of the current node by calling the `solve` function with the current node's value and `maxi` as the range parameters. This means that any node in the right subtree must have a value greater than the current node's value but less than `maxi`.

6. Continue this process for each element in the preorder sequence, moving from left to right.

7. Return the root node of the constructed BST.

**Pseudocode (C++):**

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* solve(vector<int>& preorder, int& i, int mini, int maxi) {
    // Base case: If i is out of bounds or the current value is not within the range, return null.
    if (i >= preorder.size() || preorder[i] < mini || preorder[i] > maxi) {
        return nullptr;
    }
    
    // Create a new node with the current value.
    TreeNode* root = new TreeNode(preorder[i]);
    
    // Move to the next element in the preorder sequence.
    i++;
    
    // Recursively construct the left subtree within the range (mini, root->val).
    root->left = solve(preorder, i, mini, root->val);
    
    // Recursively construct the right subtree within the range (root->val, maxi).
    root->right = solve(preorder, i, root->val, maxi);
    
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0; // Initialize the index to 0.
    return solve(preorder, i, INT_MIN, INT_MAX);
}
```

**Notes:**

- The `solve` function constructs the BST recursively based on the given range for each node.
- `mini` and `maxi` represent the valid range for values of nodes in the subtree.
- The `preorder` vector is passed by reference to avoid unnecessary copying.
- The `i` variable is used to keep track of the current index in the `preorder` sequence.
- The time complexity of this solution is O(n), where n is the number of nodes in the BST.
- The space complexity is O(h), where h is the height of the BST due to the recursive call stack.

