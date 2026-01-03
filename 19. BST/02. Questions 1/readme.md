
### Finding the Kth Smallest Element in a BST:

1. Perform an **inorder traversal** of the BST while maintaining a counter.
2. When the counter reaches k, return the current node's value.
3. Continue the traversal until you've visited all nodes.

Pseudocode for finding the Kth Smallest Element:

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> s;
    TreeNode* current = root;
    int count = 0;
    
    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }
        
        current = s.top();
        s.pop();
        count++;
        
        if (count == k) {
            return current->val;
        }
        
        current = current->right;
    }
    
    return -1; // If k is out of range or tree is empty
}
```

### Finding the Kth Largest Element in a BST:

1. Perform a **reverse inorder traversal** (right-root-left) of the BST while maintaining a counter.
2. When the counter reaches k, return the current node's value.
3. Continue the traversal until you've visited all nodes.

Pseudocode for finding the Kth Largest Element:

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int kthLargest(TreeNode* root, int k) {
    stack<TreeNode*> s;
    TreeNode* current = root;
    int count = 0;
    
    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->right; // Reverse order, right before left
        }
        
        current = s.top();
        s.pop();
        count++;
        
        if (count == k) {
            return current->val;
        }
        
        current = current->left; // Reverse order, left after right
    }
    
    return -1; // If k is out of range or tree is empty
}
```

**Notes:**
- We perform an iterative inorder traversal using a stack to keep track of nodes.
- The `count` variable keeps track of the number of nodes visited.
- When `count` reaches k, we return the value of the current node.
- Time complexity: O(H + k), where H is the height of the tree.
- Space complexity: O(H), where H is the height of the tree.

### Question 3: Find Predecessor and Successor in a BST

**Approach:**

- Perform a modified inorder traversal while keeping track of predecessor and successor.
- When the current node's value matches the target value, store the current node as the successor and move to the left subtree to find the predecessor.
- Continue the traversal until you find the target value.


1. Initialize `predecessor` and `successor` to -1 (indicating that they are not found yet).
2. Starting from the root node, traverse the tree to find the node with the given key.
3. While traversing, keep track of the possible predecessor and successor nodes based on the current node's value relative to the key.
4. When you find the key, stop traversing and return the `predecessor` and `successor`.


**Pseudocode:**

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

void findPredecessorSuccessor(TreeNode* root, int target, int& predecessor, int& successor) {
    TreeNode* current = root;
    while (current != NULL) {
        if (current->val == target) {
            // Node with the target value found
            if (current->left != NULL) {
                // Find predecessor (maximum value in the left subtree)
                TreeNode* pred = current->left;
                while (pred->right != NULL) {
                    pred = pred->right;
                }
                predecessor = pred->val;
            }
            if (current->right != NULL) {
                // Find successor (minimum value in the right subtree)
                TreeNode* succ = current->right;
                while (succ->left != NULL) {
                    succ = succ->left;
                }
                successor = succ->val;
            }
            return;
        } else if (current->val < target) {
            // Move to the right subtree
            predecessor = current->val;
            current = current->right;
        } else {
            // Move to the left subtree
            successor = current->val;
            current = current->left;
        }
    }
    // Node with the target value not found
    predecessor = -1; // No predecessor
    successor = -1;   // No successor
}
```

**Notes:**
- We traverse the BST iteratively while keeping track of predecessor and successor.
- When the target value is found, we look for the predecessor in the left subtree (maximum value) and the successor in the right subtree (minimum value).
- Time complexity: O(H), where H is the height of the tree.
- Space complexity: O(1), as we use only a constant amount of extra space.

These algorithms allow you to find the kth smallest element and the predecessor and successor of a given target value in a BST efficiently.


### Question 5: Lowest Common Ancestor (LCA) in a Binary Search Tree (BST)

**Approach:**

In a Binary Search Tree (BST), the Lowest Common Ancestor (LCA) of two nodes `p` and `q` is the node whose value is between the values of `p` and `q`. Here's how we can find it efficiently:

1. Start from the root node.
2. If `root`'s value is greater than both `p` and `q`, move to the left subtree.
3. If `root`'s value is less than both `p` and `q`, move to the right subtree.
4. If neither of the above conditions is met, it means `root` is the LCA, return `root`.

**Pseudocode (Recursive):**

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root; // Found the LCA
    }
}
```

**Pseudocode (Iterative):**

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != NULL) {
        if (root->val > p->val && root->val > q->val) {
            root = root->left;
        } else if (root->val < p->val && root->val < q->val) {
            root = root->right;
        } else {
            return root; // Found the LCA
        }
    }
    
    return NULL; // No LCA found
}
```

**Notes:**
- The algorithm starts at the root and moves down the tree based on the values of `p` and `q`.
- It efficiently finds the LCA with a time complexity of O(h), where h is the height of the BST.
- Space complexity for both approaches is O(1) as they use only a constant amount of extra space.

These pseudocode snippets efficiently find the lowest common ancestor of two nodes in a Binary Search Tree.