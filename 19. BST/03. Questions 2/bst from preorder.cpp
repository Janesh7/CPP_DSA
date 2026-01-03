class Solution {
public:
    TreeNode* solve(int mini, int maxi, vector<int> &in, int &i){
        if(i>=in.size()) 
            return NULL;
        if(in[i]<mini || in[i]>maxi) 
            return NULL;

        TreeNode* root = new TreeNode(in[i++]);

        root->left = solve(mini,root->val, in, i);
        root->right = solve(root->val, maxi, in, i);
        return root;       
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(INT_MIN, INT_MAX, preorder, i);
    }
};