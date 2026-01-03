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
#include <stack>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Approach: Inorder Traversal
// The inorder traversal of a binary search tree (BST) yields the values in sorted order.
// To find the k-th smallest element, we can perform an inorder traversal and keep track of the count of nodes visited.
// NOTE: This solution assumes that k is always valid (1 <= k <= number of nodes in the BST).
// Also if we replace left and right with right and left, we can find the k-th largest element instead.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        int count = 0;
        int val = -1;
        K = k;

        KSmallest (root, count, val);
        return val;
    }
private:
    int K;
    void KSmallest (TreeNode * root, int & count, int & val) {

        if (!root)
            return;

        KSmallest (root->left, count, val);

        count ++;
        if (count == K) {

            val = root->val;
            return;
        }

        KSmallest (root->right, count, val);
    }

    // The time complexity of this approach is O(N), where N is the number of nodes in the BST, because we may need to visit all nodes in the worst case.
    // The space complexity is O(H), where H is the height of the tree, due to the recursion stack.
};

// Alternative Approach: Iterative Inorder Traversal using Stack
// This approach uses a stack to perform an iterative inorder traversal of the BST.

int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> stk;

    // Start with the root node
    // and traverse to the leftmost node
    while (true) {
        // Push all left nodes onto the stack
        while (root) {
            stk.push(root);
            root = root->left;
        }

        // If the stack is empty, we have traversed the entire tree
        // and k is out of bounds

        if (stk.empty()) return -1; // or throw an exception
        
        // Pop the top node from the stack
        // This is the next node in the inorder traversal
        root = stk.top(); stk.pop();

        // Visit the node (inorder)

        // Decrement k for each node visited
        // If k reaches 0, we have found the k-th smallest element
        if (--k == 0) return root->val;

        // Move to the right node after visiting the left node
        root = root->right;
    }

}
// The time complexity of this approach is O(N), where N is the number of nodes in the BST, because we may need to visit all nodes in the worst case.
// The space complexity is O(H), where H is the height of the tree, due to the stack used for the iterative traversal.