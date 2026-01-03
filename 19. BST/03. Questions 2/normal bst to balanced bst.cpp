class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*> &in){
        if(!root)
        return ;

        inorder(root->left, in);
        in.push_back(root);
        inorder(root->right, in);
    }

    TreeNode* balancing(int start, int end, vector<TreeNode*> &in){
        if(start>end) return NULL;

        int mid = (start+end)/2;
        in[mid]->left = balancing(start, mid-1, in);
        in[mid]->right = balancing(mid+1, end, in);
        return in[mid];
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> in;
        inorder(root, in);
        return balancing(0,in.size()-1, in);
    }
};
