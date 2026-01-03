// Maximum Sum Path Of A Binary Tree.
// Hard


// AdobeOlaInfosys
// Problem Statement

// You are given a binary tree having 'n' nodes. Each node of the tree has an integer value.


// Your task is to find the maximum possible sum of a simple path between any two nodes (possibly the same) of the given tree.


// A simple path is a path between any two nodes of a tree, such that no edge in the path is repeated twice. The sum of a simple path is defined as the summation of all node values in a path.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Sample Input 1:
// 1 2 3 4 -1 -1 -1 -1 -1
// Sample Output 1:
// 10
// Explanation For Sample Input 1:
// The tree looks as follows:
//                         1
//                        / \
//                       2   3 
//                      /
//                     4
// The path between Node 3 (with value 3) and Node 4 (with value 4) produces the maximum sum, i.e., 10. Hence, the maximum possible sum is 10 in this case.
// Sample Input 2:
// 2 4 -1 3 6 -1 -1 -1 -1 
// Sample Output 2:
// 13
// Explanation For Sample Input 2:
// The tree looks as follows:
//                         2
//                        / 
//                       4    
//                      / \   
//                     3   6
// The path between Node 3 (with value 3) and Node 4 (with value 6) produces the maximum sum, i.e., 13. Hence, the maximum possible sum is 13 in this case.
// Expected Time Complexity:
//  The expected time complexity is O(n).
// Constraints:
// 1 <= 'n' <= 10^6
// -10^5 <= 'data' <= 10^5 and 'data' !=-1

// Where ‘n’ is the total number of nodes in the binary tree, and 'data' is the value of the binary tree node

// Time Limit: 1 sec


/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int solve(BinaryTreeNode<int> *root, int &sum) {
  if (root == NULL)
    return 0;
  int left = solve(root->left, sum);
  int right = solve(root->right, sum);
  if (left < 0)
    left = 0;
  if (right < 0)
    right = 0;
  sum = max(sum, (left + right + root->data));
  return root->data + max(left, right);
}
int maxPathSum(BinaryTreeNode<int> *root) {
  // Write your code here
  int sum = INT_MIN;
  solve(root, sum);
  return sum;
}