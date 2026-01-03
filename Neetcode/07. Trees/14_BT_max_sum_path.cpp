// 124. Binary Tree Maximum Path Sum
// LeetCode Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

// Example 1:


// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
// Example 2:


// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 3 * 104].
// -1000 <= Node.val <= 1000

/*
    Problem: Binary Tree Maximum Path Sum

    Goal:
    Given a binary tree, find the maximum path sum.
    A path is defined as any sequence of nodes from some starting node to any node
    in the tree along the parent-child connections. The path must contain at least
    one node and does not need to go through the root.

    -------------------------------------------------------
    Understanding the Problem:

    - A path in this context is any valid sequence of nodes connected by parent-child links.
    - The path can start and end at any node (not necessarily the root or a leaf).
    - A valid path may "fork" at a node — that is, it can go down both left and right subtrees.

    Example:
             -1
            /  \
           2    3

    The maximum path is: 2 → -1 → 3 = 4

    -------------------------------------------------------
    Naive Approach That Doesn't Work:

    You might be tempted to compute the maximum path sum for left and right subtrees
    recursively and combine them like this:

        int maxLeft = maxPathSum(root->left);
        int maxRight = maxPathSum(root->right);
        ans = max(ans, maxLeft + maxRight + root->val);
        return max(maxLeft, maxRight) + root->val;

    Earlier wrote this single func but this returns the max path sum from the current node and not the ans.

    This is incorrect because:
    - maxLeft and maxRight represent **the best path sum anywhere in the subtree**,
      not the best single path **that can be extended upward** through the current node.
    - This causes confusion between:
        ➤ the best forked path (for total answer),
        ➤ and the best upward path (to be returned to parent).
    - Also, this approach doesn’t handle **negative subtrees** correctly.

    -------------------------------------------------------
    Correct Approach (DFS with tracking):

    ➤ Use a recursive DFS function that does two things:
        1. Returns the best **single path** going upward through one child and the current node.
        2. While doing so, it updates a global `ans` variable which tracks the **best overall path**,
           including forked paths that go through both children.

    ➤ Use this formula at each node:
        left = max(0, dfs(root->left))   // ignore negative paths
        right = max(0, dfs(root->right)) // ignore negative paths
        currentMax = root->val + left + right

        ans = max(ans, currentMax)

        return root->val + max(left, right) // only one path can be used going upward

    -------------------------------------------------------
    Why We Use max(0, dfs(...)):

    - Any negative contribution from a child subtree would reduce the overall path sum.
    - If the best path in the left or right subtree is negative, we treat it as 0 — meaning we ignore it.
    - This is crucial for pruning non-beneficial branches.

    ➤ For example:
             -10
             /  \
           -5   -20

      Possible path sums:
      - -10 alone = -10
      - -10 + (-5) + (-20) = -35 ❌ (worse)
      - So we should return just -10.

      By using max(0, ...), both children are treated as contributing 0.
      The node's value alone (-10) becomes the best path.

    -------------------------------------------------------
    How Returning Works:

    When returning to the parent, we can't fork — only one path can be continued upward.

    So we return:
        root->val + max(left, right)

    ➤ Why only one?
      - Because a path to parent must remain linear.
      - If you try to return left + right + root, you’re sending a forked path,
        which violates the parent-child constraint.

    -------------------------------------------------------
    Why We Initialize ans = INT_MIN:

    - Because node values can be negative, and we must ensure that even a single negative node
      is considered as a potential path.
    - If we initialize ans = 0, we could mistakenly reject all negative paths.

    ➤ For example:
             -3

      If we use ans = 0, we’d wrongly return 0, but the correct answer is -3.

    -------------------------------------------------------
    Summary:

    At each node:
    - Compute the best path sum from the left and right child.
    - Ignore any path that gives a negative sum.
    - Update the global max with root->val + left + right.
    - Return to parent the best single path: root->val + max(left, right)

    This ensures:
    - The global `ans` tracks the best forked path.
    - The return value gives the best extendable path.

    -------------------------------------------------------
    ime and Space Complexity:

    Time:  O(N)  where N is the number of nodes in the tree
    Space: O(H)  where H is the height of the tree (due to recursion stack)

    -------------------------------------------------------
    Final Notes:

    - Don't mix up "total path through the node" vs "extendable path to parent".
    - Always guard against negative values in the tree.
    - Separate the concerns: use `ans` for overall best, use return for best upward path.
*/

#include <limits.h>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
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
private:
    int ans = INT_MIN; // Handle negative-only trees
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        // Ignore negative paths
        int max_left = max(0, dfs(root->left));
        int max_right = max(0, dfs(root->right));

        // Possible best path THROUGH current node
        ans = max(ans, max_left + max_right + root->val);

        // Return the best single path to parent
        return max(max_left, max_right) + root->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
