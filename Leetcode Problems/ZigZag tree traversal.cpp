// 103. Binary Tree Zigzag Level Order Traversal
// Medium


// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
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
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        bool leftToRight = true;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp(size);
            for (int i = 0; i < size; i++)
            {

                TreeNode *frontNode = q.front();
                q.pop();

                // normal insert or reverse insert
                int index = leftToRight ? i : size - i - 1;
                temp[index] = frontNode->val;

                if (frontNode->left)
                    q.push(frontNode->left);

                if (frontNode->right)
                    q.push(frontNode->right);
            }

            // direction change karni h
            leftToRight = !leftToRight;

            ans.push_back(temp);
        }

        return ans;
    }
};