// 102. Binary Tree Level Order Traversal
// Medium

// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (root==NULL)
            return ans;
        q.push(root);
        q.push(NULL);
        vector<int> t;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) { 
                //Last level has been completed
                // cout << endl;
                ans.push_back(t);
                t.clear();
                if(!q.empty()) { 
                    //queue still has some child ndoes
                    q.push(NULL);
                }  
            }
            else{
                // cout << temp -> val << " ";
                t.push_back(temp->val);
                if(temp ->left) {
                    q.push(temp ->left);
                }

                if(temp ->right) {
                    q.push(temp ->right);
                }
            }
        }
        return ans;
    }
};



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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int n  = q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode *curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};