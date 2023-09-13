// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Medium

// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
 

// Constraints:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.


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
    void creatmap(vector<int> in, map<int,int> &mappings, int n){
        for(int i=0; i<n; i++)
            mappings[in[i]] = i;
    }
    
    TreeNode* solve(vector<int> in, vector<int> pre, int &index, int start, int end, int n, map<int,int> &mappings){
        // Base case: return null for leaf nodes
        if(index>=n || start>end)
            return NULL;
            
        int element = pre[index++]; // The first element of preorder is the root
        TreeNode* root = new TreeNode(element);
        int position = mappings[element]; // Find the index of the root value in inorder traversal
        

		// To optomise this step .. ie finding pos for each will increase TC.. so we create a hashmap with value and index and simply get the answer from it each time
    	// refer code for hashmap
		// int rootIndex = inStart;
		// while (inorder[rootIndex] != rootVal) {
		// 	rootIndex++;
		// }
		
		// Recursively build left and right subtrees
        root->left = solve(in, pre, index, start, position-1, n, mappings);
        root->right = solve(in, pre, index, position+1, end, n, mappings);
        
        return root;
        
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        map<int,int> mappings;
        int n = preorder.size();
        creatmap(inorder, mappings, n);
        TreeNode *ans = solve(inorder, preorder, index,0, n-1, n, mappings);
        return ans;
    }
};