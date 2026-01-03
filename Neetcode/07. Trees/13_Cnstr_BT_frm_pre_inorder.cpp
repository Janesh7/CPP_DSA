// 105. Construct Binary Tree from Preorder and Inorder Traversal
// LeetCode Problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
 * Problem:
 * Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal 
 * of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return 
 * the binary tree.
 * 
 * Approach:
 * 1. **Preorder Traversal**: Root -> Left -> Right
 *    So the first element in preorder is always the root of the (sub)tree.
 *
 * 2. **Inorder Traversal**: Left -> Root -> Right
 *    So if we find the index of the root in the inorder array, everything to the left of it 
 *    belongs to the left subtree, and everything to the right belongs to the right subtree.
 *
 * 3. **Divide and Conquer**:
 *    - Use the root value from preorder to partition the inorder array.
 *    - Recursively build the left and right subtrees from the corresponding slices of preorder and inorder.
 *
 * 4. **Note**: This implementation makes copies of array slices which has a time and space cost. 
 *    For optimization, we can pass indices instead of slicing (not shown here).
 */

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Base case: If either traversal is empty, there's no tree to build
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        // The first element in preorder is always the root of the tree/subtree
        TreeNode* root = new TreeNode(preorder[0]);

        // Find the index of the root in inorder traversal
        // This will divide the inorder array into left and right subtrees
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        // Construct the left subtree:
        // - preorder: skip the root, take 'mid' elements (which correspond to left subtree)
        // - inorder: from start to root's index (exclusive)
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);

        // Construct the right subtree:
        // - preorder: after left subtree, to the end
        // - inorder: from root's index + 1 to the end
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

        // Recursively build the left and right subtrees
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        // Return the constructed tree
        return root;
    }
    // Time Complexity: O(n2) in the worst case due to the find operation in the inorder array.
    // Space Complexity: O(n) for the recursion stack and the temporary vectors created.
};
// Note: The above code assumes that the input arrays are valid and represent a unique binary tree.
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int pre_index = 0;  // Tracks the current root index in preorder traversal
    map<int, int> mp;   // Maps each value in inorder to its index for O(1) lookups

    /**
     * Recursive function to build the tree from preorder traversal and
     * the start/end range in the inorder traversal.
     *
     * @param preorder - The full preorder traversal array.
     * @param start - Start index of the current subtree in INORDER array.
     * @param end - End index of the current subtree in INORDER array.
     * @return - The constructed TreeNode (root of current subtree).
     */
    TreeNode* buildTree(vector<int>& preorder, int start, int end) {
        // Base case: if there are no elements in this range, return nullptr
        if (start > end)
            return nullptr;

        // Create the root node with the current value from preorder
        TreeNode* root = new TreeNode(preorder[pre_index]);

        // Get the index of this root value in the inorder traversal
        int mid = mp[preorder[pre_index]];

        // Move to the next root in preorder for the next recursive call
        pre_index++;

        // Recursively build the left subtree with inorder[start ... mid-1]
        root->left = buildTree(preorder, start, mid - 1);

        // Recursively build the right subtree with inorder[mid+1 ... end]
        root->right = buildTree(preorder, mid + 1, end);

        // Return the root node of this subtree
        return root;
    }

public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        // Preprocess inorder traversal into a map for fast index lookup
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        // Start building the tree from the entire inorder range
        return buildTree(preorder, 0, n - 1);
    }
    // Time Complexity: O(n) for building the tree, where n is the number of nodes.
    // Space Complexity: O(n) for the map and the recursion stack.
};


/*
In the optimized implementation you've provided, the key improvement is avoiding the need to pass the inorder vector or its start/end indices as parameters in the recursive helper function. Instead, the approach leverages a map<int, int> (mp) to store each value from the inorder traversal along with its corresponding index. This allows for O(1) access to the index of any node value in the inorder array without having to search or pass the array repeatedly.

In typical recursive implementations, both preorder and inorder subarray bounds are passed to define the current subtree. However, since preorder is always traversed sequentially (using the pre_index counter to pick the next root), and the index of any node in the inorder array can be directly fetched from the map, it's no longer necessary to pass the actual inorder vector or maintain its start/end bounds explicitly in the function call. Instead, we only pass the bounds (start, end) which define the current range of the subtree in the inorder traversal.

This simplifies the function signature and improves readability, while still providing enough information to correctly reconstruct the left and right subtrees. The mid index (fetched from the map) divides the subtree range into left and right parts. Thus, with just the preorder vector, a single pre_index, and the inorder index map, the function achieves the same result without slicing arrays or passing extra data, which reduces space complexity and improves runtime performance.
*/