// 404. Sum of Left Leaves
// Easy

// Given the root of a binary tree, return the sum of all left leaves.

// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
// Example 2:

// Input: root = [1]
// Output: 0
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -1000 <= Node.val <= 1000


// We are given a binary tree and need to find the sum of all leaves which are left child of some parent node.

// ✔️ Solution - I (Recursive DFS)

// One way we could solve this problem is using simple DFS traversal technique while keeping track of whether the current node is a left child or not.

// We start at root node. A boolean parameter isLeft is initialized to false denoting that root node is not left child.
// Recursively explore the left child nodes by setting the isLeft=true and right child nodes by setting isLeft=false.
// If the current node is a leaf node and isLeft=true, we return the node's value. Otherwise, we return 0.

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    int dfs(TreeNode* root, bool isLeft) {
        if(!root) return 0;
        if(!root -> left && !root -> right) return isLeft ? root -> val : 0;
        return dfs(root -> left, true) + dfs(root -> right, false);
    }
};				

// One-Liner
// Time Complexity: O(N), where N is the number of nodes in the given binary tree. It is a standard DFS traversal technique where each node is visited once.
// Space Complexity : O(H), where H is the height of given binary tree. It is required for implicit recursive stack space. H = logN in case of a complete binary tree and H=N in case of a skewed tree.

// ✔️ Solution - II (Iterative DFS)

// We can also solve the above using an iterative version of DFS.

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<pair<TreeNode*, bool>> s;
        s.push({root, false});
        int ans = 0;
        while(s.size()) {
            auto [cur, isLeft] = s.top(); s.pop();
            if(!cur -> left && !cur -> right && isLeft) 
                ans += cur -> val;
            if(cur -> right) s.push({cur -> right, false});
            if(cur -> left) s.push({cur -> left, true});
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity : O(H)

// ✔️ Solution - III (BFS)

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        int ans = 0;
        while(q.size()) {
            auto [cur, isLeft] = q.front(); q.pop();
            if(!cur -> left && !cur -> right && isLeft) 
                ans += cur -> val;
            if(cur -> right) q.push({cur -> right, false});
            if(cur -> left) q.push({cur -> left, true});
        }
        return ans;
    }
};

// Another way to solve this problem is using BFS traversal technique with keeping track of whether current node is left child or not.

// We start at root node and push it along with the isLeft parameter set to false into a queue
// Iteratively pop the front nodes from queue. If it is a leaf node, add to the final sum if the corresponding isLeft parameter is true.
// Iteratively push the left and right child nodes into the queue till it becomes empty

// Time Complexity: O(N)
// Space Complexity : O(W), where W is the maximum width of tree. In case of complete binary tree, the maximium nodes stored in queue will be (N+1)/2 ≅ O(N) and in case of skewed tree where all nodes are lopsided to one end, queue will store 1 node at max.

// ✔️ Solution - IV (Morris Traversal)

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        while(root) {
            if(root -> left) {
                auto pre = root -> left;  // find predecessor of root
                while(pre -> right && pre -> right != root) 
                    pre = pre -> right;
                // make root as right child of predecessor (temporary link)
                if(!pre -> right) {
                    pre -> right = root;
                    root = root -> left;                    
                }
                else {
                    pre -> right = nullptr;  // revert the changes - remove temporary link
                    // add to sum if node is left child and a leaf
                    if(pre == root -> left && !pre -> left) ans += pre -> val;
                    root = root -> right;
                }
            } 
			else root = root -> right;
        }
        return ans;
    }
};

// This solution involves using the morris traversal technique to solve the problem. The advantage of this traversal is that we can traverse the tree in O(1) space complexity. The basic idea is to link predecessors to root nodes so we can trace it back once we have traversed a side without need of maintaining a stack. You can also find some good explanation here or check out my previous 129. Sum Root to Leaf Numbers post where I have posted an image of steps involved in morris traversal to get better idea of working.


// Time Complexity: O(N), each node is visited once.
// Space Complexity : O(1), we are not maintaining any stack or queue and just iterate the whole tree using pointer manipulations within the given tree.


