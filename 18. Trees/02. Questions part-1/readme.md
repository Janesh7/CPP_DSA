
# Finding the Height of a Binary Tree Using Recursion

### Introduction
- Welcome to Code Help's lecture on binary trees.
- In the last lecture, we learned about trees, and now we'll tackle basic questions often asked in interviews.

### Problem Statement
- Given a binary tree, find its height (also known as depth).
- Height is the longest path between the root node and a leaf node.

### Approach
1. Recursion is a key tool to solve this problem efficiently.
2. The height of a binary tree can be computed by recursively finding the heights of its left and right subtrees.

### Algorithm
1. Base Case: If the current node is NULL (empty), return 0.
2. Recursively calculate the height of the left subtree.
3. Recursively calculate the height of the right subtree.
4. Return the maximum of the heights of the left and right subtrees, plus 1 (to include the root node).

**Recursively goes to the left most leaf..then goes back and right.. then comapare .. then go back to the higher**

### Pseudocode
```cpp
int findHeight(Node* root) {
    if (root == NULL) {
        return 0; // Base case: empty node has height 0
    }
    
    int leftHeight = findHeight(root->left);   // Height of left subtree
    int rightHeight = findHeight(root->right); // Height of right subtree
    
    return max(leftHeight, rightHeight) + 1;   // Max height + 1 (for root node)
}
```

### Complexity Analysis
- Time Complexity: O(n) - We visit each node once.
- Space Complexity: O(h) - Recursion call stack space (worst case height of the tree).

### Summary
- The height of a binary tree is the longest path from the root node to a leaf node.
- Use recursion to find the height of the left and right subtrees, and then return the maximum plus 1 for the root node.



# Diameter of Binary Tree

### Introduction
- The diameter of a binary tree is the number of nodes on the longest path between two end nodes.
- The path can be between any two nodes, including leaf nodes or the root node.

### Examples
1. Single Path: The longest path in a linear tree.
2. Branching Path: A path through branches.
3. Combination: Combining paths from both subtrees.

### Approach
1. **Naive Approach**: Try all possibilities (left, right, combination) and choose the maximum. **O(N^2)**.. we find the left part width.. we find the rigth part width.. we find the combo of both.. ie we reuse heigth algo from prev .. find heigth from left and right and plus one (root node) .. and at last find the largest of the three 
**BASICALLY at eac node we r finding the left node width, right node width and sum of hieght of both left and right +1... see pdf for recursion tree**

**int diameter = max(op1, max(op2, op3)); // Maximum of three options,,,,int height = max(left.second, right.second) + 1;**

2. **Optimized Approach**: Use a pair of integers to store diameter and height at each step.

### Optimized Algorithm
1. Base Case: If the root is NULL, return a pair (0, 0) [Diameter, Height].
2. Recursively calculate left subtree diameter and height.
3. Recursively calculate right subtree diameter and height.
4. Calculate diameter using three options:
   - Diameter of left subtree.
   - Diameter of right subtree.
   - Sum of left height, right height, and 1 (for the root).
5. Return a pair with diameter as the maximum of the three options and height as the maximum of left and right heights plus 1.
6. in the main function u have to return an int not pair.. so make this other function and then make the call from the main and return the diameterFast(..).first.

### Pseudocode
```cpp
pair<int, int> diameterFast(Node* root) {
    if (root == NULL) {
        return make_pair(0, 0); // Base case: (Diameter, Height)
    }

    pair<int, int> left = diameterFast(root->left);   // Left subtree
    pair<int, int> right = diameterFast(root->right); // Right subtree

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    int diameter = max(op1, max(op2, op3)); // Maximum of three options
    int height = max(left.second, right.second) + 1; // Max of left and right height + 1

    return make_pair(diameter, height); // Return as pair
}
```

### Complexity Analysis
- Time Complexity: O(n) - Each node is visited once.
- Space Complexity: O(n) - Recursion call stack space.



# Check for Balanced Binary Tree

### Introduction
- A binary tree is considered balanced if the absolute difference between the height of its left and right subtrees is not greater than 1.
- This balance condition should hold true for all nodes in the tree.

### Approach
1. **Naive Approach**: Check the balance condition for each node individually using recursion.
2. **Optimized Approach**: Return both balance status and height as a pair of values to avoid redundant height calculations.

### Optimized Algorithm
1. **Base Case**: If the root is NULL, return a pair (true, 0) [Balance status, Height].
2. Recursively calculate balance and height for the left subtree.
3. Recursively calculate balance and height for the right subtree.
4. Calculate the balance status using the absolute difference of left and right heights.
5. Return a pair with balance status as true if all three conditions are met: left balance, right balance, and overall height balance.
6. The height of the current node is the maximum of left and right heights plus 1.

### Pseudocode
```cpp
pair<bool, int> isBalancedFast(Node* root) {
    if (root == NULL) {
        return make_pair(true, 0); // Base case: (Balance, Height)
    }

    pair<bool, int> left = isBalancedFast(root->left);   // Left subtree
    pair<bool, int> right = isBalancedFast(root->right); // Right subtree

    bool leftBal = left.first;
    bool rightBal = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    bool balance = leftBal && rightBal && diff;
    int height = max(left.second, right.second) + 1; // Max of left and right height + 1

    return make_pair(balance, height); // Return as pair
}
```

### Complexity Analysis
- Time Complexity: O(n) - Each node is visited once.
- Space Complexity: O(n) - Recursion call stack space.



# Check if Two Trees are Identical

### Introduction
- Given two binary trees, determine if they are identical or not.
- Identical trees have the same structure and the same values at corresponding nodes.

### Approach
- Use recursion to compare nodes at each level:
  1. If the current nodes' values are not equal, return false.
  2. Recursively compare the left subtrees of both trees.
  3. Recursively compare the right subtrees of both trees.

### Algorithm
1. **Base Case**: If both nodes are NULL, return true.
2. If one node is NULL while the other is not, return false.
3. Compare the values of the current nodes.
4. Recursively compare the left subtrees of both trees.
5. Recursively compare the right subtrees of both trees.
6. Return true only if all three conditions are satisfied.

### Pseudocode
```cpp
bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    
    if (root1 == NULL || root2 == NULL) { // one is null other is not..
        return false;
    }

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    return (root1->data == root2->data) && left && right;
}
```

### Complexity Analysis
- Time Complexity: O(n) - Each node is visited once.
- Space Complexity: O(h) - Recursion call stack space, where h is the height of the tree.



# VVIMP Check if a Tree is a Sum Tree

### Introduction
- Given a binary tree, determine if it is a Sum Tree.
- In a Sum Tree, the value of a node is equal to the sum of the values of its left and right subtrees.

### Approach
- Use recursion to traverse the tree and compare values for each node.
- At each node:
  1. Check if it's a leaf node (no children). In this case, return true.
  2. Recursively check if both the left and right subtrees are Sum Trees.
  3. Verify if the value of the current node is equal to the sum of the left and right subtrees.

### Algorithm
1. **Base Case**: If the node is NULL or a leaf node, return true.
2. Recursively check if the left subtree is a Sum Tree.
3. Recursively check if the right subtree is a Sum Tree.
4. Calculate the sum of the left and right subtrees and verify if the current node's value is equal to that sum.
5. Return true if all conditions are satisfied, else return false.

### Pseudocode
```cpp
pair<bool, int> isSumTreeFast(Node* root) {
    if (root == NULL) {
        return make_pair(true, 0);
    }

    if (root->left == NULL && root->right == NULL) {
        return make_pair(true, root->data);
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = (root->data == leftSum + rightSum);

    pair<bool, int> ans;
    ans.first = (leftAns.first && rightAns.first && condn);
    ans.second = root->data + leftSum + rightSum;

    return ans;
}
```

### Complexity Analysis
- Time Complexity: O(n) - Each node is visited once.
- Space Complexity: O(h) - Recursion call stack space, where h is the height of the tree.

