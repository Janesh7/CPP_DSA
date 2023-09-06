**Title: Sum of the Longest Bloodline in a Tree**

**Objective:**
Find the sum of nodes along the longest path from the root to a leaf in a tree.

**Concept Explanation:**
- In a tree, we aim to calculate the sum of nodes along the longest path from the root to a leaf.
- Consider the following tree example:

    ```
          4
         / \
        2   5
       / \
      6   7
     / \
    9   10
    ```

- The task is to identify the longest path from the root (4) to a leaf and calculate the sum of nodes on that path.
- Example paths:
    - Path 1: 4 -> 2 -> 6 -> 9 (Sum = 21)
    - Path 2: 4 -> 2 -> 6 -> 10 (Sum = 22)
    - Path 3: 4 -> 2 -> 7 (Sum = 13)
    - Path 4: 4 -> 5 (Sum = 9)

**Approach:**
- Use recursive traversal to explore all paths in the tree.
- Maintain a running sum and length of the current path.
- Update the answer whenever a longer path is discovered.

**Pseudocode:**
```cpp
int maxSum = INT_MIN; // Initialize maxSum as minimum integer value

void findMaxSumPath(Node* root, int currSum, int currLength) {
    if (root == NULL) {
        // The path has ended; compare and update if this is a longer path
        if (currLength >= maxLength) {
            maxSum = currSum;
            maxLength = currLength;
        }
        return;
    }
    
    currSum += root->data; // Add the current node's value to the current sum
    currLength++; // Increase the current length
    
    // Recursively explore left and right children
    findMaxSumPath(root->left, currSum, currLength);
    findMaxSumPath(root->right, currSum, currLength);
}

int maxLength = 0; // Initialize maxLength as 0
int maxSum = 0; // Initialize maxSum as 0

// Call the function with the root of the tree
findMaxSumPath(root, 0, 0);

// The answer is stored in maxSum
```

**Complexity Analysis:**
- **Time Complexity (T.C):** O(n) - Every node is visited exactly once.
- **Space Complexity (S.C):** O(h) - Recursion stack space, where h is the height of the tree. In the worst case (skewed tree), it can be O(n).

**Summary:**
- To find the sum of nodes along the longest path from the root to a leaf in a tree, we use a recursive approach.
- The maximum sum and maximum path length are updated as we traverse the tree.
- The provided pseudocode and complexity analysis offer a clear understanding of the solution.




**Lowest Common Ancestor (LCA) in Binary Tree**

**Concept:**
- Given two nodes, n1 and n2, in a binary tree, we need to find their lowest common ancestor.
- The lowest common ancestor (LCA) is the node that is an ancestor of both n1 and n2 and is located farthest from the root.

**Example:**
- We have a binary tree:
```plaintext
        1
       / \
      3   6
     / \   \
    4   5   8
       /
      21
```
- Let n1 = 21 and n2 = 4.
- The lowest common ancestor (LCA) of n1 and n2 is 3.

**Approach:**
1. We can find the LCA by finding the paths from the root to n1 and n2 and then comparing the paths to find the common node.
2. Another approach is to use recursion to traverse the tree and find the LCA.
3. We start at the root and recursively search for n1 and n2 in the left and right subtrees.
4. If we find n1 or n2 at the current node, we return that node.
5. If we find n1 and n2 in different subtrees, the current node is the LCA.
6. If we find n1 and n2 in the same subtree, we continue searching for the LCA in that subtree.

**Pseudocode:**
```cpp
Node* findLCA(Node* root, int n1, int n2) {
    // Base case: If the root is NULL, return NULL.
    if (root == NULL) {
        return NULL;
    }
    
    // If n1 or n2 is found at the current node, return the current node.
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    
    // Recursively search for n1 and n2 in the left and right subtrees.
    Node* leftAns = findLCA(root->left, n1, n2);
    Node* rightAns = findLCA(root->right, n1, n2);
    
    // If both leftAns and rightAns are non-NULL, return the current root.
    if (leftAns != NULL && rightAns != NULL) {
        return root;
    }
    
    // If one of leftAns or rightAns is non-NULL, return that non-NULL value.
    if (leftAns != NULL) {
        return leftAns;
    }
    
    if (rightAns != NULL) {
        return rightAns;
    }
    
    // If both leftAns and rightAns are NULL, return NULL.
    return NULL;
}
```

**Time Complexity (T.C.):**
- We visit each node once, so T.C. is O(n), where n is the number of nodes in the tree.

**Space Complexity (S.C.):**
- The space complexity depends on the height of the tree, which is O(h), where h is the height.
- In the worst case, when the tree is skewed, the height can be equal to the number of nodes, so S.C. is O(n).
- In a balanced tree, the height is log(n), so S.C. is O(log(n)).

**Summary:**
- We can find the lowest common ancestor (LCA) of two nodes in a binary tree by recursively searching for the nodes in the left and right subtrees and comparing the results.
- The LCA is the first node we encounter that has one node in its left subtree and the other node in its right subtree.
- The time complexity is O(n), and the space complexity is O(h) or O(log(n)) depending on the height of the tree.


**K Sum Path in Binary Tree**

**Concept:**
- Given a binary tree and an integer `k`, we need to find the count of all paths in the tree such that the sum of nodes in the path equals `k`.

**Example:**
- We have a binary tree:
```plaintext
        1
       / \
      3   6
     / \   \
    4   5   8
```
- Let `k = 5`.
- There are 3 paths with a sum equal to 5: `[1, 3, 1]`, `[3, 2]`, and `[4, 1]`.
- So, the count of paths with sum `k` is 3.

**Approach:**
- To find all paths with a sum equal to `k`, we can use recursion to traverse the binary tree.
- At each node, we maintain a path that stores the values of nodes encountered from the root to the current node.
- We keep track of the sum of the nodes in the path.
- If the sum becomes equal to `k`, we increment the count of valid paths.
- We then continue the traversal in both the left and right subtrees.
- When we move back up in the recursion, we remove the last element from the path to explore other paths.

**Pseudocode:**
```cpp
void findKSumPaths(Node* root, int k, int& count, vector<int>& path) {
    if (root == NULL) {
        return;
    }
    
    // Add the current node to the path.
    path.push_back(root->data);
    
    int sum = 0;
    
    // Check for valid paths by iterating through the path from the current node to the root.
    for (int i = path.size() - 1; i >= 0; i--) {
        sum += path[i];
        if (sum == k) {
            count++;
        }
    }
    
    // Recursively explore left and right subtrees.
    findKSumPaths(root->left, k, count, path);
    findKSumPaths(root->right, k, count, path);
    
    // Remove the current node from the path before going back up.
    path.pop_back();
}
```

**Time Complexity (T.C.):**
- We visit each node once, so T.C. is O(n), where n is the number of nodes in the tree.

**Space Complexity (S.C.):**
- The space complexity depends on the height of the tree, which is O(h), where h is the height.
- In the worst case, when the tree is skewed, the height can be equal to the number of nodes, so S.C. is O(n).
- In a balanced tree, the height is log(n), so S.C. is O(log(n)).

**Summary:**
- We can find the count of paths in a binary tree with a sum equal to `k` by recursively traversing the tree and maintaining a path from the root to the current node.
- We increment the count when the sum of the path equals `k`.
- The time complexity is O(n), and the space complexity is O(h) or O(log(n)) depending on the height of the tree.



**Finding kth Ancestor in Binary Tree**

**Concept:**
- Given a binary tree and a node `N`, we need to find the `k`th ancestor of the node `N`.

**Approach (Recursion):**
- We will perform a depth-first search (DFS) on the binary tree.
- As we traverse the tree, we will maintain a count `k` and a variable to store the `k`th ancestor.
- When we reach the target node `N`, we will decrement `k`. If `k` becomes zero, we have found the `k`th ancestor, and we store the current node as the answer.
- If `k` is still greater than zero, we continue to explore the tree.
- When we return from a recursive call, we check if `k` is zero. If it is, we update the answer node.
- Finally, we return the answer node as the `k`th ancestor.

**Pseudocode (Recursion):**
```cpp
Node* findKthAncestor(Node* root, int& k, int N) {
    // Base case: If the current node is NULL, return NULL.
    if (root == NULL) {
        return NULL;
    }
    
    // Check if the current node is the target node N.
    if (root->data == N) {
        // Decrement k for the target node.
        k--;
        // If k becomes zero, return the current node as the kth ancestor.
        if (k == 0) {
            return root;
        }
    }
    
    // Recursively explore the left and right subtrees.
    Node* leftAns = findKthAncestor(root->left, k, N);
    Node* rightAns = findKthAncestor(root->right, k, N);
    
    // Check if the answer is found in the left or right subtree.
    if (leftAns != NULL || rightAns != NULL) {
        // Decrement k.
        k--;
        // If k becomes zero, return the current node as the kth ancestor.
        if (k == 0) {
            return root;
        }
        // Return the non-NULL answer from the left or right subtree.
        return (leftAns != NULL) ? leftAns : rightAns;
    }
    
    // If the current node is not the target node, return NULL.
    return NULL;
}
```

**Approach (Iteration):**
- We can solve this problem iteratively using a while loop.
- Initialize a variable `ancestors` to keep track of ancestors and set it as an empty stack.
- Start from the root node and traverse the tree.
- Whenever we encounter a node, we push it onto the `ancestors` stack.
- If the current node is the target node `N`, we break out of the loop.
- After finding the target node `N`, we continue to traverse the tree, but now we pop nodes from the `ancestors` stack.
- For each popped node, we decrement `k`. If `k` becomes zero, we have found the `k`th ancestor, and we return it.
- If `k` is still greater than zero and the stack becomes empty, we return -1 to indicate that the `k`th ancestor does not exist.

**Pseudocode (Iteration):**
```cpp
int findKthAncestor(Node* root, int k, int N) {
    stack<Node*> ancestors;
    
    // Traverse the tree to find the target node N.
    while (root != NULL) {
        ancestors.push(root);
        
        if (root->data == N) {
            break;
        }
        
        if (root->data < N) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    
    // If the target node is not found, return -1.
    if (root == NULL) {
        return -1;
    }
    
    // Pop nodes from ancestors to find the kth ancestor.
    while (!ancestors.empty()) {
        Node* current = ancestors.top();
        ancestors.pop();
        
        k--;
        
        if (k == 0) {
            return current->data;
        }
        
        // If k becomes negative, return -1.
        if (k < 0) {
            return -1;
        }
        
        // If the current node has a left subtree and the left child is not the ancestor,
        // traverse the left subtree to find the kth ancestor.
        if (current->left != NULL && current->left != ancestors.top()) {
            root = current->left;
            while (root != NULL) {
                ancestors.push(root);
                root = root->right;
            }
        }
    }
    
    // If k is still greater than zero, return -1.
    if (k > 0) {
        return -1;
    }
    
    // If k becomes zero,

 return the root node as the kth ancestor.
    return root->data;
}
```

**Time Complexity (T.C.):**
- In the recursive approach, the time complexity is O(n) where n is the number of nodes in the tree, as we visit each node once.
- In the iterative approach, the time complexity is O(h) where h is the height of the tree.

**Space Complexity (S.C.):**
- In the recursive approach, the space complexity is O(h) due to the recursive call stack.
- In the iterative approach, the space complexity is O(h) as we use a stack to store ancestors.

**Summary:**
- We can find the kth ancestor of a node in a binary tree by either using recursion or iteration.
- In the recursive approach, we perform a DFS traversal and maintain a count `k` to find the kth ancestor.
- In the iterative approach, we use a stack to keep track of ancestors while traversing the tree.






**Finding Maximum Sum in a Binary Tree with Constraints**

**Problem Statement**

You are given a binary tree, and you want to find the maximum sum of nodes in a path such that you can choose to include or exclude nodes at each level. In other words, you can select a node and include it in the sum along with its descendants, or you can exclude it and move on to its children.

- Given a binary tree, find the maximum sum such that:
  1. If a node is included in the sum, its child nodes cannot be included.
  2. The maximum sum can include any number of nodes but must follow the above constraint.

**Explanation**

The problem is asking for the maximum sum of nodes in a path from the binary tree, with the option to either include or exclude each node at every level. Let's understand this with examples:

Example 1:
```
       1
      / \
     2   3
    / \
   4   5
```
- If we include node 1, we can't include nodes 2 and 3, but we can include nodes 4 and 5. So the sum is 1 (node 1) + 4 + 5 = 10.
- If we exclude node 1, we can choose either node 2 or node 3, but not both. So the maximum sum is either 2 + 4 or 3 + 5, which is 9.

In this case, the maximum sum is 10.

Example 2:
```
       1
      / \
     2   3
    /   / \
   4   5   6
```
- If we include node 1, we can't include node 3, but we can include nodes 2, 4, 5, and 6. So the sum is 1 + 2 + 4 + 5 + 6 = 18.
- If we exclude node 1, we can choose either node 2 or node 3, but not both. So the maximum sum is either 2 + 4 or 3 + 5 + 6, which is 10.

In this case, the maximum sum is 18.

**Approach**

To find the maximum sum of nodes while allowing the choice of including or excluding each node, we can use a recursive approach. At each node, we need to consider two cases:

1. Include the current node in the sum and recursively calculate the maximum sum for its children.
2. Exclude the current node and recursively calculate the maximum sum for its children.

We can maintain two values at each node:

- `a`: The maximum sum including the current node.
- `b`: The maximum sum excluding the current node.

For each node, we update `a` and `b` as follows:

- `a` for the current node is the sum of the current node's value, `b` from its left child, and `b` from its right child.
- `b` for the current node is the maximum of `a` from its left child and `b` from its left child, plus the maximum of `a` from its right child and `b` from its right child.

We start the recursion from the root node and return the maximum of `a` and `b` for the root node, as it represents the maximum sum of nodes considering both inclusion and exclusion.


**Pseudocode:**
```cpp
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

pair<int, int> solve(TreeNode* root) {
    // Base case: If the current node is NULL, return (0, 0).
    if (root == NULL) {
        return make_pair(0, 0);
    }

    // Recursively find values for left and right subtrees.
    pair<int, int> leftResult = solve(root->left);
    pair<int, int> rightResult = solve(root->right);

    // Compute values for the current node.
    int a = max(leftResult.first, leftResult.second) + max(rightResult.first, rightResult.second);
    int b = root->data + leftResult.first + rightResult.first;

    // Return the pair of values (a, b) for the current node.
    return make_pair(a, b);
}

int maxSum(TreeNode* root) {
    pair<int, int> result = solve(root);
    // The maximum sum is the maximum of values a and b for the root node.
    return max(result.first, result.second);
}
```

**Explanation:**
- We define a recursive function `solve` that takes a node as input and returns a pair of values `(a, b)` representing the maximum sums.
- In the `solve` function, we handle the base case where the current node is `NULL`, and we return `(0, 0)` since there are no nodes to include in the sum.
- For non-null nodes, we recursively compute the maximum sums for the left and right subtrees using the `solve` function.
- We calculate `a` and `b` for the current node based on the maximum sums of its child nodes and its own value.
- `a` represents the maximum sum that includes the current node but excludes its child nodes, while `b` represents the maximum sum that includes the current node and its child nodes.
- Finally, in the `maxSum` function, we call `solve` for the root node and return the maximum of the `a` and `b` values, which represents the maximum sum that follows the given constraints.

**Complexity Analysis**

The time complexity for this approach is O(n), where n is the number of nodes in the binary tree, as we visit each node once.

The space complexity is O(h), where h is the height of the binary tree, due to the recursive call stack.

**Summary**

This problem involves finding the maximum sum of nodes in a binary tree while allowing the choice of including or excluding nodes at each level. By using a recursive approach with dynamic programming, we can efficiently calculate the maximum sum, considering both inclusion and exclusion of nodes.
