// Merge Two BSTs
// Medium



// Problem Statement
// You are given two binary search trees of integers having ‘N’ and ‘M’ nodes. Return an array that contains elements of both BST in sorted order.


// A binary search tree (BST) is a binary tree data structure with the following properties.
// • The left subtree of a node contains only nodes with data less than the node’s data.

// • The right subtree of a node contains only nodes with data greater than the node’s data.

// • Both the left and right subtrees must also be binary search trees.


// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Sample Input 1:
// 2 1 3 -1 -1 -1 -1
// 4 -1 -1
// Sample Output 1:
// 1 2 3 4 
// Explanation For Sample Output 1:
//  The given BST are:-




// The output will be 1 2 3 4
// Sample Input 2:
// 4 2 7 -1 3 -1 -1 -1 -1  
// 5 1 7 -1 -1 -1 -1
// Sample Output 2:
// 1 2 3 4 5 7 7 
// Constraints:
// 1 <= 'N', 'M' <= 10^5

// Time Limit: 1 sec


/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
#include<bits/stdc++.h>
void inorder(TreeNode* root,vector<int> &a){
    if (root == NULL)
        return; 
    inorder(root->left, a);
    a.push_back(root->data);
    inorder(root->right, a);
}

vector<int> mergetwosorted(vector<int> a1, vector<int> a2) {
    int index=0,i=0,j=0;
    vector<int> ans;

    while (i<a1.size() && j<a2.size()) {
        if (a1[i] <= a2[j]) {
          ans.push_back(a1[i++]);
          index++;
        }
        else {
            ans.push_back(a2[j++]);
            index++;
        }

    }
    if (i<a1.size())
        while (i<a1.size()) {
           ans.push_back(a1[i++]);
           index++; 
        }
    if (j<a2.size())
        while (j < a2.size()) {
           ans.push_back(a2[j++]);
           index++;
        }
    return ans;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> in1,in2,ans;
    inorder(root1,in1);
    inorder(root2,in2);
    ans=mergetwosorted(in1,in2);
    return ans;
}