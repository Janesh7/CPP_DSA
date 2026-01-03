// 235. Lowest Common Ancestor of a Binary Search Tree

// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

// Example 1:


// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.
// Example 2:


// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
// Output: 2
// Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
// Example 3:

// Input: root = [2,1], p = 2, q = 1
// Output: 2
 

// Constraints:

// The number of nodes in the tree is in the range [2, 105].
// -109 <= Node.val <= 109
// All Node.val are unique.
// p != q
// p and q will exist in the BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Approach: Since this is a Binary Search Tree (BST), we can utilize the properties of BSTs to find the lowest common ancestor (LCA) efficiently. The LCA of two nodes p and q can be found by comparing their values with the value of the current node (root). If both p and q are smaller than root, then LCA lies in the left subtree. If both are larger, then LCA lies in the right subtree. If one is on one side and the other is on the other side, then root is the LCA.

// In a binary search tree, nodes with values smaller than the parent node are gathered on the left, while nodes with larger values are gathered on the right.

// In other words, if both p and q are smaller than the parent, you move to the left. If both p and q are larger than the parent, you move to the right. At some point, if only one of the nodes is larger, that will be the lowest common ancestor.

// The conditions can be summarized as follows:

// if p and q < r → go left
// if p and q > r → go right
// if p < r < q or p > r > q → r is lowest common ancestor

// r is root(parent)

// Complexity
// Time complexity: O(h)
// Space complexity: O(1)

// Iterative solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (min(p->val, q->val) > root->val) {
                root = root->right;
            } else if (max(p->val, q->val) < root->val) {
                root = root->left;
            } else {
                return root;
            }
        }
        return nullptr;        
    }
};

//Recursive solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)
        return NULL;
    
    if(root->val > p->val && root->val > q->val){
        root = lowestCommonAncestor(root->left, p, q);
    }

    if(root->val < p->val && root->val < q->val){
        root = lowestCommonAncestor(root->right, p, q);
    }
    
    return root;

}

};