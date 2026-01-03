// 98. Validate Binary Search Tree

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:

// Input: root = [2,1,3]
// Output: true
// Example 2:

// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1

// WRONG APPROACH
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <limits.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;

        if (root->right && root->val > root->right->val)
            return false;

        if (root->left && root->val < root->left->val)
            return false;

        return isValidBST(root->right) && isValidBST(root->left);
    }
};
// This approach is incorrect because it only checks the immediate children of the current node, not the entire subtree.
// A valid BST requires that all nodes in the left subtree are less than the current node and all nodes in the right subtree are greater than the current node, recursively.
/*
Ex.
    5
   / \
  1   4
     / \
    3   6
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
public:
    bool isValidBST(TreeNode* root) {

        if (!root)
            return true;

        return ValidateBST (root, LONG_MIN, LONG_MAX);
    }

private:
    bool ValidateBST (TreeNode * root, long min, long max) {

        if (!root)
            return true;
        
        if (root->val <= min || root->val >= max) {
            return false;
        }

        // Recursively check the left and right subtrees with updated min and max values
        // The left subtree must have values less than the current node's value
        // The right subtree must have values greater than the current node's value
        // Here, we use long to avoid overflow issues with large values
        return ValidateBST (root->left, min, root->val) &&
               ValidateBST (root->right, root->val, max);
    }
};
// Time Complexity: O(n), where n is the number of nodes in the tree. We visit each node exactly once.
// Space Complexity: O(h), where h is the height of the tree. This is due to the recursive stack space used during the traversal.