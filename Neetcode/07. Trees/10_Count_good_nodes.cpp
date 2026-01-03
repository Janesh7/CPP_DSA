// 1448. Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
// Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

// Return the number of good nodes in the binary tree.

 

// Example 1:



// Input: root = [3,1,4,3,null,1,5]
// Output: 4
// Explanation: Nodes in blue are good.
// Root Node (3) is always a good node.
// Node 4 -> (3,4) is the maximum value in the path starting from the root.
// Node 5 -> (3,4,5) is the maximum value in the path
// Node 3 -> (3,1,3) is the maximum value in the path.
// Example 2:



// Input: root = [3,3,null,4,2]
// Output: 3
// Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
// Example 3:

// Input: root = [1]
// Output: 1
// Explanation: Root is considered as good.
 

// Constraints:

// The number of nodes in the binary tree is in the range [1, 10^5].
// Each node's value is between [-10^4, 10^4].

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

// Approach: Depth First Search (DFS)
// We can use a depth-first search (DFS) approach to traverse the binary tree.
// During the traversal, we will keep track of the maximum value encountered from the root to the current node.
// If the current node's value is greater than or equal to this maximum value, it is considered a "good" node.
// We will increment a counter for each good node and continue the traversal to both left and right children.
class Solution
{
public:
    int goodNodes(TreeNode *root)
    {

        if (!root)
            return 0;

        // Start the DFS with the root node and an initial maximum value of INT_MIN
        // INT_MIN is used to ensure that the root node is always considered a good node.
        return goodNodes(root, INT_MIN);
    }

private:
// Recursive helper function to count good nodes
// It takes the current node and the maximum value encountered so far as parameters.
    int goodNodes(TreeNode *root, int max_val)
    {

        if (!root)
            return 0;

        // Initialize count of good nodes
        int count = 0;

        // If the current node's value is greater than or equal to the maximum value seen so far,
        // it is a good node, so we increment the count and update the maximum value.
        if (root->val >= max_val)
        {
            count++;
            max_val = root->val;
        }

        count += goodNodes(root->left, max_val);
        count += goodNodes(root->right, max_val);

        return count;
    }
};