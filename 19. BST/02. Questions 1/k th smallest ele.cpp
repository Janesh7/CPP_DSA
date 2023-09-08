class Solution {
public:
    int K;
    void Recursion(TreeNode* root, int& count, int& value){
        if(!root)
            return;
        
        Recursion(root->left, count, value);
        count++;
        if(count==K)
            value = root->val;
        Recursion(root->right, count, value);

    }

    int kthSmallest(TreeNode* root, int k) {

        int value = -1;
        K=k;
        int count = 0;
        Recursion(root,count , value);
        return value;
    }
}