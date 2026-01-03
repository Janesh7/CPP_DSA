### Finding the Largest Binary Search Tree (BST) in a Binary Tree

Finding the largest Binary Search Tree (BST) in a given binary tree is a classic problem in computer science and algorithm design. It involves identifying the largest subtree within the given binary tree that adheres to the properties of a Binary Search Tree (BST). A BST is a binary tree where for each node:

1. All nodes in the left subtree have values less than or equal to the node's value.
2. All nodes in the right subtree have values greater than the node's value.

In this context, we want to find the largest BST (in terms of the number of nodes) within the given binary tree.

#### Problem Statement:

Given a binary tree, find the size (number of nodes) of the largest BST within it.

### Approach:

The problem can be efficiently solved using a recursive approach. We will maintain information for each subtree while traversing the tree and use this information to identify the largest BST. The information we need to maintain for each subtree includes:

- `mini`: The minimum value in the subtree.
- `maxi`: The maximum value in the subtree.
- `size`: The number of nodes in the subtree.
- `isBST`: A boolean flag indicating whether the subtree is a BST.

Here's how the recursive algorithm works:

1. For each node in the binary tree, perform the following steps:

   - Recursively call the function on its left subtree to get the information for the left subtree.
   - Recursively call the function on its right subtree to get the information for the right subtree.

2. Combine the information from the left and right subtrees to calculate the information for the current node:
   - `mini` is the minimum of the current node's value and the minimum value from the left subtree.
   - `maxi` is the maximum of the current node's value and the maximum value from the right subtree.
   - `size` is the sum of the sizes of the left and right subtrees, plus one (for the current node).
   - `isBST` is set to true if the left subtree is a BST, the right subtree is a BST, and the current node's value is greater than the maximum value in the left subtree and less than the minimum value in the right subtree. Otherwise, `isBST` is set to false.

3. If `isBST` is true for the current node, update the `maxsize` (the size of the largest BST found so far) with the `size` of the current subtree.

4. Return the information for the current subtree.

5. Recursively repeat steps 1-4 for all nodes in the binary tree.

6. Finally, return the `maxsize`, which represents the size of the largest BST in the entire binary tree.

#### Pseudocode (C++):

```cpp
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

class Info {
public:
    int mini;   // Minimum value in the subtree
    int maxi;   // Maximum value in the subtree
    int size;   // Number of nodes in the subtree
    bool isBST; // Whether the subtree is a BST
};

Info Recursion(TreeNode* root, int& maxsize) {
    if (!root) {
        // For a null node, return default information.
        return {INT_MAX, INT_MIN, 0, true};
    }

    // Recursively get information for the left and right subtrees.
    Info left = Recursion(root->left, maxsize);
    Info right = Recursion(root->right, maxsize);

    // Create information for the current subtree.
    Info curr;
    curr.mini = min(root->data, left.mini);
    curr.maxi = max(root->data, right.maxi);
    curr.size = left.size + right.size + 1;

    if (left.isBST && right.isBST && left.maxi < root->data && root->data < right.mini) {
        // If left and right subtrees are BSTs and the current node's value is within the valid range,
        // then the current subtree is a BST.
        curr.isBST = true;
    } else {
        curr.isBST = false;
    }

    if (curr.isBST) {
        // If the current subtree is a BST, update the maxsize if needed.
        maxsize = max(maxsize, curr.size);
    }

    // Return information for the current subtree.
    return curr;
}

int largestBST(TreeNode* root) {
    int maxsize = 0;
    Info temp = Recursion(root, maxsize);
    return maxsize;
}
```

### Illustration:

Let's illustrate the algorithm with an example binary tree:

```
        10
       /  \
      5    15
     / \     \
    1   8     7
```

- Starting at the root (10):
  - Left subtree (5):
    - Left subtree (1): Information: mini=1, maxi=1, size=1, isBST=true
    - Right subtree (8): Information: mini=1, maxi=8, size=2, isBST=true
    - Current node (5): Information: mini=1, maxi=8, size=3, isBST=true
  - Right subtree (15):
    - Right subtree (7): Information: mini=7, maxi=7, size=1, isBST=true
    - Current node (15): Information: mini=7, maxi=15, size=2, isBST=true
  - Current node (10): Information: mini=1, maxi=15, size=6, isBST=false (not a BST)
- The largest BST in the tree has a size of 3 (subtree rooted at 5).
- The function returns 3 as the result.

This illustrates how the algorithm works by recursively calculating information for each subtree and updating the `maxsize` when a larger BST is found.

The time complexity of this algorithm is O(N), where N is the number of nodes in the binary tree, as each node is visited once.