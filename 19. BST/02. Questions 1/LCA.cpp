TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)
        return NULL;
    
    if(root->val > p->val and root->val > q->val){
        root = lowestCommonAncestor(root->left, p, q);
    }

    if(root->val < p->val and root->val < q->val){
        root = lowestCommonAncestor(root->right, p, q);
    }
    
    return root;

}
