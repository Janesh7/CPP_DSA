// 145. Binary Tree Postorder Traversal
// Easy

// Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

// Example 1:


// Input: root = [1,null,2,3]
// Output: [3,2,1]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
 

// Constraints:

// The number of the nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 

// Follow up: Recursive solution is trivial, could you do it iteratively?


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
// Recursive approach
class Solution1 {
public:
    void postorder(TreeNode* root, vector<int> &ans){
        //base case
        if(root == NULL)
            return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

// Iterative approach - Using 2 stacks
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)        return ans;
        stack<TreeNode*> s1, s2;

        s1.push(root);
        while(!s1.empty()){
            TreeNode *curr = s1.top();
            s1.pop();
            s2.push(curr);

            if(curr->left != NULL)
                s1.push(curr->left);
            if(curr->right != NULL)
                s1.push(curr->right);
        }

        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};

// Iterative approach - Using 1 stack
class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)        return ans;

        stack<TreeNode*> s;
        TreeNode *curr = root;

        while(curr != NULL || !s.empty()){
            if(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode *temp = s.top()->right;
                if(temp == NULL){
                    while(!s.empty() && temp == s.top()->right){
                        temp = s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        return ans;
    }
};


// Morris traversal - Space O(1)
class Solution4 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans ;
        TreeNode *curr = root, *pre;

        while(curr != NULL){
            if(curr->right == NULL){
                ans.push_back(curr->val);
                curr = curr->left;
            }
            else{
                pre = curr->right;
                while(pre->left != NULL && pre->left != curr)
                    pre = pre->left;
                
                if(pre->left == NULL){
                    ans.push_back(curr->val);
                    pre->left = curr;
                    curr = curr->right;
                }
                else{
                    pre->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};