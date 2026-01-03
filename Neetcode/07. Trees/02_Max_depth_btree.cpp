// 104. Maximum Depth of Binary Tree
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -100 <= Node.val <= 100

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

// Approach
// Let me explain 2 ways.

//        3
//      /   \
//     9     20
//            \
//             7
// Solution 1 - DFS
// Let's think about subtree with 20 and 7. From 20, we have two choice.

// one is to take depth of left side
// the other is to take depth of right side
// In this case, we should take depth of right side, because

// max(left, right)
// = max(0, 1)
// = 1
// Depth of subtree of 20 and 7 is 2, but now we have 1 as a maximum depth. This happens because the current node is not yet taken into account. So when we go back to root node(= 3), the formula should be

// 1 + max(left, right)
// = 1 + max(0, 1)
// = 2
// 1 is for current node.
// max(left, right) is maximum depth of left or right from a current node.

// From node 3,

// 1 + max(left, right)
// = 1 + max(1, 2)
// = 3
// return 3


// Complexity
// Time complexity: O(n)
// n is the total number of nodes in the binary tree.

// Space complexity: O(h)
// h is the height of the binary tree. but in the worst case, it can be as large as O(n).

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));        
    }
};

// Step by Step Algorithm
// Step 1: Base Case
// Code:
// if not root:
//     return 0
// If the current node (root) is None:
// Return 0 because an empty subtree has a depth of 0.
// Step 2: Recursive Calls
// Code (integrated with Step 3):
// return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
// The function makes recursive calls to compute:
// The depth of the left subtree (self.maxDepth(root.left)).
// The depth of the right subtree (self.maxDepth(root.right)).
// Step 3: Compute Maximum Depth
// After computing the depths of the left and right subtrees:
// Use max(self.maxDepth(root.left), self.maxDepth(root.right)) to get the maximum depth of the two subtrees.
// Add 1 to account for the current node.
// Solution 2 - BFS
// ①→    3
//      /   \
// ②→ 9     20
//            \
// ③→          7
// Basically, we iterate through ① → ② → ③. When we go down to the next level, we will add +1 to depth.

// To do that, we use queue initialized with root node.

// q = [3]
// depth = 0
// Take 3 from queue and check 3 has left child and right child. If it has, add the child to queue.

// q = [9, 20]

// Take 3 and check left and right child. We find 9 and 20
// depth = 1
// Next iteration is 9 and 20 at one time.

// q = [20]

// Take 9 and check left and right child. → No child
// depth = 2
// q = [7]

// Take 20 and check left and right child. → We find 7
// depth = 2
// Next iteration is 7 at one time.

// q = []

// Take 7 and check left and right child. → No child
// depth = 3
// There is not node in queue.

// return 3


// Complexity
// Time complexity: O(n)
// n is the total number of nodes in the binary tree.

// Space complexity: O(w)
// w is the maximum width of the tree (worst-case O(n)).
#include <queue>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            depth++;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return depth;        
    }
};

// Step by Step Algorithm
// Step 1: Handle the Base Case
// Code:
// if not root:
//     return 0
// If the input tree is empty (root is None), return 0 because an empty tree has no depth.
// Step 2: Initialize the BFS Queue
// Code:
// q = deque()
// q.append(root)
// depth = 0
// Create a queue (q) using deque to store nodes to be processed.
// Add the root node to the queue.
// Initialize depth to 0 to track the levels of the tree.
// Step 3: Process Nodes Level by Level
// Code:
// while q:
//     depth += 1
// Start a while loop that runs as long as there are nodes in the queue:
// Increment the depth by 1 for each level of the tree.
// Step 4: Process All Nodes at the Current Level
// Code:
// for _ in range(len(q)):
//     node = q.popleft()
// Use a for loop to process all nodes currently in the queue (i.e., nodes at the same level).
// len(q) determines how many nodes are at the current level.
// Remove a node (node) from the front of the queue using popleft.
// Step 5: Add the Children of the Current Node
// Code:
// if node.left:
//     q.append(node.left)
// if node.right:
//     q.append(node.right)
// If the current node (node) has a left child, add it to the queue.
// If the current node has a right child, add it to the queue.
// This ensures all nodes at the next level are queued for processing.
// Step 6: Repeat Until the Queue is Empty
// Continue the while loop until all levels of the tree have been processed (i.e., the queue is empty).
// Step 7: Return the Final Depth
// Code:
// return depth
// Once the queue is empty, all levels of the tree have been processed.
// Return the value of depth, which represents the maximum depth of the tree.


class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int right = maxDepth(root->right);
        int left = maxDepth(root->left);

        return (right > left) ? right + 1 : left + 1;
    }
};