// 543. Diameter of Binary Tree

// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

// Example 1:

// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
// Example 2:

// Input: root = [1,2]
// Output: 1

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -100 <= Node.val <= 100

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <utility>
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

// Key is that the max is the max of the left and right subtree's diameter or the sum of the left and right subtree's height.
// we are not keeping track of the max so we have to find it among the left and right subtree's diameters and comapare it with the diameter including the current node.
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        // Call the helper function 'DiameterOfBinaryTree', which returns the diameter
        // as the first value in the pair, and the height of the tree as the second value.
        return DiameterOfBinaryTree(root).first;
    }

private:
    // Helper function that returns a pair:
    //   - The first value in the pair is the diameter of the current subtree.
    //   - The second value in the pair is the height of the current subtree.
    pair<int, int> DiameterOfBinaryTree(TreeNode *root)
    {
        // Base case: If the node is null, return a pair {0, 0}:
        //    - 0 as the diameter (there is no path in an empty tree),
        //    - 0 as the height (an empty tree has no height).
        if (!root)
            return {0, 0};

        // Recursively calculate the diameter and height for the left and right subtrees.
        pair<int, int> l = DiameterOfBinaryTree(root->left);  // Left subtree
        pair<int, int> r = DiameterOfBinaryTree(root->right); // Right subtree

        // Calculate the current diameter at the current node:
        //   - The current diameter is the maximum of the diameter of the left subtree,
        //     the diameter of the right subtree, and the sum of the heights of the left
        //     and right subtrees (which represents the path through the current node).
        //   - The height of the current node is the maximum height between the left and
        //     right subtrees plus 1 (to account for the current node).
        return {max(max(l.first, r.first), (l.second + r.second)),  // Diameter: Max of left/right diameters or sum of left/right heights
                max(l.second, r.second) + 1};                    // Height: Max of left/right heights + 1 (for current node)
    }
};

// The key is that we keep track the max diameter found so far, and we update it whenever we find a longer path.
// Which can be either including the current node or not.
// Here we are just calculating the diameter of the current node which is left height and right height and updating the diameter in place if bigger.
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        // Declare a reference variable 'diameter' to store the maximum diameter found.
        int diameter = 0;

        // Call the helper function 'DiameterOfBinaryTree' with the root and the 'diameter' reference.
        DiameterOfBinaryTree(root, diameter);

        // After the recursion, the variable 'diameter' contains the maximum diameter.
        return diameter;
    }

private:
    // Helper function that calculates the height of the current node and updates the diameter.
    //   - The first argument is the current node.
    //   - The second argument is a reference to the variable 'diameter' to update it in place.
    int DiameterOfBinaryTree(TreeNode *root, int &diameter)
    {
        // Base case: If the node is null, return 0 (height of null node).
        if (!root)
            return 0;

        // Recursively calculate the height of the left and right subtrees.
        int left_height = DiameterOfBinaryTree(root->left, diameter);
        int right_height = DiameterOfBinaryTree(root->right, diameter);

        // Update the diameter. The diameter at the current node is the sum of the left and right heights.
        // This is the longest path that goes through the current node.
        diameter = max(diameter, left_height + right_height);

        // Return the height of the current node. It is 1 more than the maximum height of the left and right subtrees.
        return max(left_height, right_height) + 1;
    }
};
