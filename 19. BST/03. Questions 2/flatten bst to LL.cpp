class Solution {
public:
    void invector(TreeNode* root, vector<TreeNode*> &in){
        if(!root) return;
        in.push_back(root);
        invector(root->left, in);
        invector(root->right, in);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> in;
        invector(root, in);
        int i;
        for(i=1; i<in.size(); i++){
            in[i-1]->right = in[i];
            in[i-1]->left = NULL;
            if(i==in.size()-1){
                in[i]->right = NULL;
                in[i]->left = NULL;
            }
        }   
    }
};