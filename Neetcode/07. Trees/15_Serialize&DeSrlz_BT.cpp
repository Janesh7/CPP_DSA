// 297. Serialize and Deserialize Binary Tree

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

// Example 1:

// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -1000 <= Node.val <= 1000
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Code by me .. no need for "(" and ")" in the serialized string
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        stringstream ss;
        DfsSerialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
            return nullptr;

        return DfsDeserialize(data);
    }

private:
    void DfsSerialize(TreeNode *root, stringstream &ss)
    {
        if (!root)
        {
            ss << "N";
            return;
        }

        ss << "(" << to_string(root->val) << ",";
        DfsSerialize(root->left, ss);
        ss << ",";
        DfsSerialize(root->right, ss);
        ss << ")";
    }

    int index = 0;

    TreeNode *DfsDeserialize(string &str)
    {

        if (str[index] == 'N')
        {
            index++;
            return nullptr;
        }

        if (str[index] == '(')
        {
            index++;
        }

        int num = 0;
        int sign = 1;

        if (str[index] == '-')
        {
            sign = -1;
            index++;
        }

        while (isdigit(str[index]))
        {
            num = num * 10 + (str[index] - '0');
            index++;
        }

        TreeNode *root = new TreeNode(sign * num);
        index++;

        root->left = DfsDeserialize(str);
        index++;

        root->right = DfsDeserialize(str);
        index++;

        return root;
    }
    // time complexity: O(n)
    // space complexity: O(n) for the serialized string and O(h) for the recursion
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

class Codec
{
public:
    // Encodes a binary tree to a single string using level-order traversal (BFS).
    string serialize(TreeNode *root)
    {
        // Initialize an empty string to build the serialized output.
        string serial = "";

        // Edge case: If the tree is empty, return an empty string.
        if (root == NULL)
            return serial;

        // Use a queue to perform level-order traversal (BFS).
        queue<TreeNode *> q;
        q.push(root);

        // Continue until all nodes are processed.
        while (!q.empty())
        {
            TreeNode *curr_node = q.front();
            q.pop();

            if (curr_node == nullptr)
            {
                // Use '#' to represent null (nullptr) nodes in the serialized string.
                // Append a comma as a delimiter after every node value or null marker.
                serial.append("#,");
            }
            else
            {
                // Convert the current node's value to a string and append it to the serialized string.
                // Append a comma as a delimiter after the value.
                // Using `append()` instead of `+` avoids creating temporary strings, making it more efficient.
                serial.append(to_string(curr_node->val).append(","));

                // Add the left and right children (even if null) to the queue.
                // This ensures we preserve the exact structure of the tree during serialization.
                q.push(curr_node->left);
                q.push(curr_node->right);
            }
        }

        // The final serialized string contains values and '#' markers separated by commas.
        // This flat format makes it easy to parse and reconstruct the tree.
        return serial;
    }

    // Decodes your encoded data to a binary tree using level-order reconstruction (BFS).
    TreeNode *deserialize(string data)
    {
        // Edge case: If the input string is empty, the tree is empty.
        if (data.empty())
            return nullptr;

        // Use a stringstream to easily split the string by commas.
        stringstream ss(data);
        string str;

        // The first token is the value of the root node.
        getline(ss, str, ',');
        TreeNode *root = new TreeNode(stoi(str));

        // Use a queue to track nodes while reconstructing their left and right children.
        queue<TreeNode *> q;
        q.push(root);

        // Continue processing the serialized data.
        while (!q.empty())
        {
            TreeNode *curr_node = q.front();
            q.pop();

            // Read the next token for the left child.
            if (getline(ss, str, ',') && str != "#")
            {
                // If the token is not '#', create a left child node and attach it.
                TreeNode *leftNode = new TreeNode(stoi(str));
                curr_node->left = leftNode;
                q.push(leftNode); // Add to queue to later assign its children.
            }

            // Read the next token for the right child.
            if (getline(ss, str, ',') && str != "#")
            {
                // If the token is not '#', create a right child node and attach it.
                TreeNode *rightNode = new TreeNode(stoi(str));
                curr_node->right = rightNode;
                q.push(rightNode); // Add to queue to later assign its children.
            }
        }

        // The tree has been reconstructed and the root node is returned.
        return root;
    }
    // time complexity: O(n) for both serialization and deserialization, where n is the number of nodes in the tree.
    // space complexity: O(n) for the serialized string and O(h) for the queue
};
