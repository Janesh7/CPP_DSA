// 110. Balanced Binary Tree

// Given a binary tree, determine if it is height-balanced.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104

#include <algorithm>
#include <cstdlib>  // For abs function
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

private:
    int height(TreeNode* node) {
        if (node == nullptr) return 0;  // Base case: empty tree has height 0
        
        // Recursively get the height of the left subtree
        int leftHeight = height(node->left);
        if (leftHeight == -1) return -1;  // If the left subtree is unbalanced, return -1
        
        // Recursively get the height of the right subtree
        int rightHeight = height(node->right);
        if (rightHeight == -1) return -1;  // If the right subtree is unbalanced, return -1
        
        // If the height difference between left and right subtrees is more than 1, return -1
        if (abs(leftHeight - rightHeight) > 1) return -1;
        
        // Return the height of the current node
        return max(leftHeight, rightHeight) + 1;
    }
};