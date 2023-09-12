// Boundary Traversal of Binary Tree
// Hard


// Problem Statement


// You are given a binary tree having 'n' nodes.


// The boundary nodes of a binary tree include the nodes from the left and right boundaries and the leaf nodes, each node considered once.


// Figure out the boundary nodes of this binary tree in an Anti-Clockwise direction starting from the root node.


// Example :
// Input: Consider the binary tree A as shown in the figure:
// alt text

// Output: [10, 5, 3, 7, 18, 25, 20]

// Explanation: As shown in the figure

// The nodes on the left boundary are [10, 5, 3]

// The nodes on the right boundary are [10, 20, 25]

// The leaf nodes are [3, 7, 18, 25].

// Please note that nodes 3 and 25 appear in two places but are considered once.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Sample Input 1:
// 10 5 20 3 8 18 25 -1 -1 7 -1 -1 -1 -1 -1 -1 -1
// Sample Output 1:
// 10 5 3 7 18 25 20
// Explanation Of Sample Input 1:
// The nodes on the left boundary are [10, 5, 3]

// The nodes on the right boundary are [10, 20, 25]

// The leaf nodes are [3, 7, 18, 25].

// Please note that nodes 3 and 25 appear in two places but are considered once.
// Sample Input 2:
// 100 50 150 25 75 140 200 -1 30 70 80 -1 -1 -1 -1 -1 35 -1 -1 -1 -1 -1 -1
// Sample Output 2:
// 100 50 25 30 35 70 80 140 200 150
// Constraints:
// 1 <= n <= 10000

// Where 'n' is the total number of nodes in the binary tree.

// Time Limit: 1 sec


#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

template <typename T>
void traverseLeft(TreeNode<T> *root, vector<T> &ans) {
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

template <typename T>
void traverseLeaf(TreeNode<T> *root, vector<T> &ans) {
    // base case
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

template <typename T>
void traverseRight(TreeNode<T> *root, vector<T> &ans) {
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // wapas aagye
    ans.push_back(root->data);
}

template <typename T>
vector<T> traverseBoundary(TreeNode<T> *root) {
    vector<T> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // left part print/store
    traverseLeft(root->left, ans);

    // traverse Leaf Nodes

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);

    return ans;
}
