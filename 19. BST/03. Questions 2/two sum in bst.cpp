class Solution {
public:
    void inorder(TreeNode* root, vector<int> &in){
        if(!root)
        return ;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root, in);

        int i=0, j=in.size()-1;

        while(i<j){
            if(in[i]+in[j]==k)
                return true;
            else if(in[i]+in[j]<k)
                i++;
            else
                j--;
        }

        return false;
    }
};