// 653. Two Sum IV - Input is a BST
// Easy

// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// Example 2:


// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -104 <= Node.val <= 104
// root is guaranteed to be a valid binary search tree.
// -105 <= k <= 105


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