// 572. Subtree of Another Tree

// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

// Example 1:

// Input: root = [3,4,5,1,2], subRoot = [4,1,2]
// Output: true
// Example 2:

// Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
// Output: false

// Constraints:

// The number of nodes in the root tree is in the range [1, 2000].
// The number of nodes in the subRoot tree is in the range [1, 1000].
// -104 <= root.val <= 104
// -104 <= subRoot.val <= 104

// Intuition #1 - Is Same Tree
// To determine if one tree is a subtree of another, we want to see if there's a node in the larger tree whose entire subtree structure is identical to the smaller tree. If at any point, we match the smaller tree exactly (using a helper method to check equality of two trees), we've found our answer.

// Approach #1

// Traversal: Recursively traverse the main tree. At each node, check if that node’s subtree is identical to the smaller tree (using isSameTree). If true, return true immediately.

// Leetcode #100: Is Same Tree: Implement a helper function, isSameTree, to check if two binary trees are identical by comparing node values and their respective subtrees.

// Subtrees: If they are not identical at the current node, continue recursing into the left and right children of the main tree.

// Complexity #1
// Time complexity: O(n × m), where (n) = number of nodes in root, and (m) = number of nodes in subRoot. In worst case, for each node in root, we compare up to all nodes in subRoot.
// Space complexity: O(h1 + h2), where (h1, h2) are the heights of the two trees, due to recursion stack usage.

// Intuition #2 - Serialization
// Another way to check if one tree is a subtree of another is to convert each tree into a unique string representation (serialization). If the serialized form of the smaller tree appears as a substring in the larger tree's serialization, then the smaller tree is indeed a subtree.

// Approach #2
// Serialize Both Trees: Perform a preorder-like traversal and create a string that includes each node’s value and markers for null nodes.
// Substring Check: Check if the serialized string of the subRoot is contained in the serialized string of the main root.

// Example Walkthrough #2
// For:

// root = [3,4,5,1,2]
// subRoot = [4,1,2]
// Serialization might produce something like:

// root: (3,(4,(1,N,N),(2,N,N)),(5,N,N))
// subRoot: (4,(1,N,N),(2,N,N))
// Since subRoot's serialization is a substring of root's serialization, return true.

/* 
Complexity #2
String Concatenation at Each Step:
At each level of recursion, you are concatenating strings using +, which is an O(k) operation. This means, for each recursive call, you are copying the resulting string every time you add a new node's value.

Let's say:

You start with a string of length 1, then concatenate a string of length 2, then 3, and so on.

The cost at each recursion level will increase as follows: O(1) at the first level, O(2) at the second level, O(3) at the third level, and so on.

This results in a quadratic time complexity for the serialize() function itself, making the overall time complexity of serializing the tree O(n^2). (n * (n + 1) / 2 = O(n^2))

Total Time Complexity
For serializing the root tree: O(n^2)

For serializing the subRoot tree: O(m^2)

Finding the substring (via find()): O(n) (assuming average case for substring search). Tho the cpp implementation of find() is not guaranteed to be O(n) in all cases, it can be O(n * m) in the worst case, but we will assume average case for simplicity.
// Total time complexity: O(n^2 + m^2 + n) ≈ O(n^2 + m^2) where n is the number of nodes in root and m is the number of nodes in subRoot.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <string>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSame(TreeNode *a, TreeNode *b)
    {

        if (!a && !b)
            return true;

        if (!a || !b || a->val != b->val)
            return false;

        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {

        if (!root)
            return false;

        if (isSame(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

class Solution
{
private:
    string serialize(TreeNode *node)
    {
        if (!node)
            return "N";
        return "(" + to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right) + ")";
        // NOTE: "(" is required to differentiate between nodes with values like 12 and 2.
        // So the serialization of a node with value 12 will be "(12,N,N)" and a node with value 2 will be "(2,N,N)". Without the parentheses, they would both serialize to "12,N,N" and "2,N,N", which would be indistinguishable.
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        string rootSerialized = serialize(root);
        string subRootSerialized = serialize(subRoot);
        return rootSerialized.find(subRootSerialized) != string::npos;
    }
};


/*
    The following code demonstrates an optimized solution to the "subtree" problem where we want to check if
    one tree (subRoot) is a subtree of another tree (root). 

    The initial implementation uses string concatenation in a recursive serialization function. However, string 
    concatenation with the "+" operator in C++ is inefficient because it takes linear time for each concatenation. 
    This leads to a quadratic time complexity for the serialization process, making the overall solution inefficient for 
    large trees. The time complexity of serializing a tree with n nodes using string concatenation is O(n^2).

    The optimized version uses a stringstream to avoid the costly string concatenation operation. This reduces the 
    serialization complexity to O(n + m) where n is the number of nodes in root and m is the number of nodes in subRoot.
*/

#include <sstream>

class Solution {
private:
    /*
        Optimized serialization function using stringstream to avoid the O(n^2) complexity of string concatenation.
        Instead of repeatedly concatenating strings, we use a stringstream to efficiently build the serialized string.
    */
    void serialize(TreeNode* node, stringstream& ss) {
        if (!node) {
            ss << "N,";  // Use "N" to represent null nodes.
            return;
        }
        ss << "(";  // Start a new subtree representation.
        ss << node->val << ",";  // Append the node's value to the stream.
        serialize(node->left, ss);  // Recursively serialize the left subtree.
        serialize(node->right, ss);  // Recursively serialize the right subtree.
        ss << "),";  // Close the subtree representation.
    }

public:
    /*
        This function checks whether subRoot is a subtree of root by serializing both trees and finding if
        the serialized subRoot string is a substring of the serialized root string.
    */
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stringstream rootSerialized, subRootSerialized;

        // Serialize both trees using stringstream to avoid inefficient string concatenation.
        serialize(root, rootSerialized);
        serialize(subRoot, subRootSerialized);

        // Check if the serialized subRoot string is a substring of the serialized root string.
        return rootSerialized.str().find(subRootSerialized.str()) != string::npos;
    }
};

/*
    Time Complexity:
    - Serialization of the root tree: O(n) where n is the number of nodes in the root.
    - Serialization of the subRoot tree: O(m) where m is the number of nodes in the subRoot.
    - Finding the substring: O(n) on average for the root string of length n.
    - Therefore, the total time complexity is O(n + m + n) ≈ O(n + m).

    Space Complexity:
    - Space for serialized strings: O(n) for the root and O(m) for the subRoot.
    - Recursion stack: O(h) where h is the height of the tree, which in the worst case can be O(n) for a skewed tree.
    - Therefore, the total space complexity is O(n + m).
*/
