
# Binary Search Trees (BST) Introduction

**Definition of Binary Search Tree (BST):**
- A Binary Search Tree (BST) is a binary tree with the following properties:
  - There is one root node.
  - All data in the left subtree of a node is less than the data in that node.
  - All data in the right subtree of a node is greater than the data in that node.
  - These properties hold for every node in the tree.

## Properties of a BST:

1. **Root Node:** There is one root node that serves as the starting point of the tree.

2. **Left Subtree:** All data in the left subtree of a node is less than the data in that node. This property ensures that elements smaller than the root node are located in the left subtree.

3. **Right Subtree:** All data in the right subtree of a node is greater than the data in that node. This property ensures that elements greater than the root node are located in the right subtree.

## Illustration

Consider the following Binary Search Tree (BST):

```
        10
       /  \
      7    15
     / \   / \
    5   9 13  19
             / \
            16  21
```

In this BST:
- Data in the left subtree of the root (10) is smaller (7, 5, 9).
- Data in the right subtree of the root (10) is greater (15, 13, 19, 16, 21).
- The same property applies to all nodes in the tree.

## Pseudocode for Checking if a Tree is a Binary Search Tree


```cpp
bool isBST(TreeNode* root, int minValue, int maxValue) {
    // Base case: An empty tree is considered a BST.
    if (root == NULL) {
        return true;
    }

    // Check if the current node's value is within the valid range.
    if (root->val < minValue || root->val > maxValue) {
        return false;
    }

    // Recursively check the left and right subtrees.
    // For the left subtree, the maximum value is updated to the current node's value.
    // For the right subtree, the minimum value is updated to the current node's value.
    return isBST(root->left, minValue, root->val - 1) && isBST(root->right, root->val + 1, maxValue);
}

bool isBinarySearchTree(TreeNode* root) {
    // Call the helper function with initial minimum and maximum values.
    return isBST(root, INT_MIN, INT_MAX);
}
```




# Inserting a Node in a Binary Search Tree (BST)

To insert a node into a Binary Search Tree (BST), you follow these steps:

1. Start at the root node.
2. Compare the data of the node to be inserted with the data of the current node.
3. If the data is smaller, move to the left child.
4. If the data is greater, move to the right child.
5. Repeat steps 2-4 until you reach a NULL child.
6. Create a new node with the data to be inserted and attach it as the left or right child of the last node reached in step 5.


```cpp
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    // Function to insert a node into the BST.
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case: If the current node is NULL, create a new node and return it.
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // If the data is smaller than the current node's data, move to the left subtree.
        if (val < root->data) {
            root->left = insertIntoBST(root->left, val);
        }
        // If the data is greater than or equal to the current node's data, move to the right subtree.
        else {
            root->right = insertIntoBST(root->right, val);
        }

        // Return the modified tree with the newly inserted node.
        return root;
    }

    // Public function to insert a node into the BST.
    void insert(int val) {
        root = insertIntoBST(root, val);
    }
};
```



Here are detailed notes on the topic of searching for a node in a Binary Search Tree (BST) along with pseudocode in C++:

# Searching a Node in a Binary Search Tree (BST)

## Approach

1. **Recursive Approach**:
   - Create a recursive function that takes the current node and the target value as parameters.
   - Check if the current node is `NULL`. If it is, return `false` as the target value is not present in the empty subtree.
   - Check if the current node's data is equal to the target value. If it is, return `true` as the value is found.
   - If the target value is less than the current node's data, recursively search in the left subtree.
   - If the target value is greater than or equal to the current node's data, recursively search in the right subtree.
   - Return the result of the recursive search.

2. **Iterative Approach**:
   - Initialize a pointer `temp` to the root node.
   - Use a `while` loop to iterate until `temp` becomes `NULL`, indicating that the target value is not present.
   - Inside the loop:
     - Check if the current node's data is equal to the target value. If it is, return `true` as the value is found.
     - If the target value is less than the current node's data, update `temp` to `temp->left` to search in the left subtree.
     - If the target value is greater than the current node's data, update `temp` to `temp->right` to search in the right subtree.
   - If the loop exits without finding the target value, return `false` to indicate that it is not present in the BST.

## Pseudocode (Recursive Approach)

```cpp
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool searchInBST(TreeNode* root, int x) {
    // Base case: If the current node is NULL, return false.
    if (root == nullptr) {
        return false;
    }

    // If the current node's data matches the target value, return true.
    if (root->data == x) {
        return true;
    }

    // If the target value is less than the current node's data, search in the left subtree.
    if (x < root->data) {
        return searchInBST(root->left, x);
    }

    // If the target value is greater than or equal to the current node's data, search in the right subtree.
    return searchInBST(root->right, x);
}
```

## Pseudocode (Iterative Approach)

```cpp
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool searchInBST(TreeNode* root, int x) {
    // Initialize a pointer 'temp' to the root node.
    TreeNode* temp = root;

    // Iterate until 'temp' becomes NULL, indicating the target value is not found.
    while (temp != nullptr) {
        // If the current node's data matches the target value, return true.
        if (temp->data == x) {
            return true;
        }

        // If the target value is less than the current node's data, search in the left subtree.
        if (x < temp->data) {
            temp = temp->left;
        }
        // If the target value is greater than or equal to the current node's data, search in the right subtree.
        else {
            temp = temp->right;
        }
    }

    // If the loop exits without finding the target value, return false.
    return false;
}
```

# Finding Inorder Predecessor and Inorder Successor

In a BST, the inorder traversal yields elements in ascending order. The inorder predecessor is the largest element smaller than the given value, and the inorder successor is the smallest element larger than the given value.

## Approach:

**Find the node .. go to the leftmost leaf node for predecessor and go to the right subtree to find the least(leftmost) leaf which will be the successor**


1. **Inorder Traversal**:
   - Perform an inorder traversal of the BST while keeping track of the previously visited node.
   - When you encounter the given element (`target`), the predecessor is the last visited node before `target`, and the successor is the first visited node after `target`.

2. **Morris Traversal (Optimized)**:
   - Morris Traversal is an efficient way to perform inorder traversal of a BST without using a stack or recursion.
   - It modifies the tree temporarily by threading it.
   - Traverse the tree in Morris Traversal, keeping track of the predecessor and successor as you go.

## Pseudocode for Finding Inorder Predecessor and Inorder Successor (Inorder Traversal):

```cpp
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* findInorderPredecessor(TreeNode* root, int target) {
    TreeNode* predecessor = nullptr;
    while (root != nullptr) {
        if (root->data == target) {
            // If the target node has a left subtree, the predecessor is the maximum
            // node in the left subtree.
            if (root->left != nullptr) {
                TreeNode* temp = root->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                predecessor = temp;
            }
            break; // Target node found, exit loop.
        } else if (root->data < target) {
            predecessor = root; // Update predecessor.
            root = root->right; // Go right.
        } else {
            root = root->left; // Go left.
        }
    }
    return predecessor;
}

TreeNode* findInorderSuccessor(TreeNode* root, int target) {
    TreeNode* successor = nullptr;
    while (root != nullptr) {
        if (root->data == target) {
            // If the target node has a right subtree, the successor is the minimum
            // node in the right subtree.
            if (root->right != nullptr) {
                TreeNode* temp = root->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                successor = temp;
            }
            break; // Target node found, exit loop.
        } else if (root->data > target) {
            successor = root; // Update successor.
            root = root->left; // Go left.
        } else {
            root = root->right; // Go right.
        }
    }
    return successor;
}
```

## Morris Traversal Approach:

### Morris Traversal for Inorder Predecessor and Successor - Detailed Note

1. Initialize `predecessor` and `successor` as `nullptr`.
2. Start from the root of the BST.
3. While the current node `root` is not `nullptr`:
   - If the left child of `root` is `nullptr`:
     - Check if `root` contains the `target` value:
       - If yes, break from the loop (target node found).
       - If not, move to the right subtree (`root = root->right`).
   - If the left child of `root` is not `nullptr`:
     - Find the rightmost node in the left subtree (predecessor) by following `right` pointers:
       - If `temp->right == nullptr`, thread `temp->right` to `root`, then move to the left subtree (`root = root->left`).
       - If `temp->right == root`, remove the thread by setting `temp->right = nullptr`, and:
         - If `root` contains the `target` value, break from the loop (target node found).
         - If not, update `predecessor = root`, and move to the right subtree (`root = root->right`).

   - Continue this process until the loop breaks.
4. Return the `predecessor` (inorder predecessor) and `successor` (inorder successor).


- Morris Traversal allows us to find the inorder predecessor and successor efficiently with constant space.
- It threads the tree temporarily to traverse it without using additional data structures.
- The key idea is to utilize the `right` pointers in the threaded tree for Morris Traversal.


```cpp
TreeNode* findInorderPredecessorMorris(TreeNode* root, int target) {
    TreeNode* predecessor = nullptr;
    while (root != nullptr) {
        if (root->left == nullptr) {
            // If there's no left subtree, check the current node.
            if (root->data == target) {
                break; // Target node found, exit loop.
            }
            root = root->right; // Move to the right subtree.
        } else {
            // Find the rightmost node in the left subtree (predecessor).
            TreeNode* temp = root->left;
            while (temp->right != nullptr && temp->right != root) {
                temp = temp->right;
            }

            if (temp->right == nullptr) {
                // Thread the predecessor to the current node.
                temp->right = root;
                root = root->left; // Move to the left subtree.
            } else {
                // Remove the thread and check the current node.
                temp->right = nullptr;
                if (root->data == target) {
                    break; // Target node found, exit loop.
                }
                predecessor = root; // Update predecessor.
                root = root->right; // Move to the right subtree.
            }
        }
    }
    return predecessor;
}

TreeNode* findInorderSuccessorMorris(TreeNode* root, int target) {
    TreeNode* successor = nullptr;
    while (root != nullptr) {
        if (root->right == nullptr) {
            // If there's no right subtree, check the current node.
            if (root->data == target) {
                break; // Target node found, exit loop.
            }
            root = root->left; // Move to the left subtree.
        } else {
            // Find the leftmost node in the right subtree (successor).
            TreeNode* temp = root->right;
            while (temp->left != nullptr && temp->left != root) {
                temp = temp->left;
            }

            if (temp->left == nullptr) {
                // Thread the successor to the current node.
                temp->left = root;
                root = root->right; // Move to the right subtree.
            } else {
                // Remove the thread and check the current node.
                temp->left = nullptr;
                if (root->data == target) {
                    break; // Target node found, exit loop.
                }
                successor = root; // Update successor.
                root = root->left; // Move to the left subtree.
            }
        }
    }
    return successor;
}
```



# Deleting a Node in a BST

## Approach:
1. If the BST is empty or the node to delete is not found, return `NULL`.
2. If the value to delete is smaller than the current node's value, recursively search and delete in the left subtree.
3. If the value to delete is greater than the current node's value, recursively search and delete in the right subtree.
4. If the value to delete is found:
   - If the node to delete has 0 children (a leaf node), simply remove it and return `NULL`.
   - If the node to delete has 1 child, remove it and return its child node.
   - If the node to delete has 2 children, replace it with either the maximum value node from the left subtree (in-order predecessor) or the minimum value node from the right subtree (in-order successor), and recursively delete that node from its original location.

## Pseudocode for Deleting a Node

```cpp
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteFromBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return root;
    }

    if (val < root->data) {
        root->left = deleteFromBST(root->left, val);
    } else if (val > root->data) {
        root->right = deleteFromBST(root->right, val);
    } else {
        // Node to delete found

        // Case 1: Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        TreeNode* temp = findMin(root->right); // Find the in-order successor
        root->data = temp->data; // Copy the in-order successor's data to this node
        root->right = deleteFromBST(root->right, temp->data); // Delete the in-order successor
    }
    return root;
}
```

## Illustrations:

Let's consider an example BST for deletion:

```
        50
       /  \
     20    70
    / \   / \
   10  30 60 90
              \
              110
```

### Example 1: Deleting a Leaf Node (e.g., `10`)
- Node to delete (`10`) is a leaf node.
- It's a 0 child case.
- Delete it and return `NULL`.

### Example 2: Deleting a Node with One Child (e.g., `70`)
- Node to delete (`70`) has one child (`60`) on the right.
- Remove `70` and return `60`.

### Example 3: Deleting a Node with Two Children (e.g., `50`)
- Node to delete (`50`) has two children.
- Find the in-order successor (`60`) from the right subtree.
- Copy the value of `60` to `50`.
- Recursively delete the original `60`.
- The resulting tree:

```
        60
       /  \
     20    70
    / \     \
   10  30    90
              \
              110
```

