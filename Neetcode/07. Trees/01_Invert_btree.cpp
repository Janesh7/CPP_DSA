// 226. Invert Binary Tree
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, invert the tree, and return its root.

// Example 1:

// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]
// Example 2:

// Input: root = [2,1,3]
// Output: [2,3,1]
// Example 3:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

// Approach
//        4
//      /   \
//     2     7
//    / \   / \
//   1   3 6   9
// We start from root node(= 4). First of all, check if current node is null or not.

// If not, Swap left child and right child. Now the tree should be

//        4
//      /   \
//     7     2
//    / \   / \
//   6   9 1   3
// Move to left side. Now we are at node 7. Check if current node is null or not. It's not null, so swap left child(= node 6) and right child(= node 9)

//        4
//      /   \
//     7     2
//    / \   / \
//   9   6 1   3
// Move to left side. Now we are at node 9 and check if current node is null or not. It's not null, so swap left child(= null) and right child(= null). Now we have the same tree above.

// Move to left side. Now we are at null node, so go back to node 9 and move to right side. Now we are at null node, so go back to node 9. We already checked node 9, so go back to node 7, Move to right slide. Now we are at node 6.

// Let me skip explantion from node 6, because nothing will happen.

// After that, go back to node 7 and go back to node 4, then go to right side. Now we are at node 2. Current node is not null, so swap left child(= node 1) and right child(= node 3).

//        4
//      /   \
//     7     2
//    / \   / \
//   9   6 3   1
// Then move to left side. Now we are at node 3.

// Let me skip rest of explanation. Nothing will happen. In the end, go back to node 4 and finish traversing all node.

// We should return

//        4
//      /   \
//     7     2
//    / \   / \
//   9   6 3   1


#include <iostream>
using namespace std;

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
    // time complexity: O(n)
    // space complexity: O(h) where h is the height of the tree
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        TreeNode *temp = root->left;

        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }
    // time complexity: O(n)
    // space complexity: O(h) where h is the height of the tree
};