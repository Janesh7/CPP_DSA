The Morris Traversal algorithm allows for the traversal of a binary tree in O(n) time and O(1) space. It establishes temporary links to navigate the tree and then removes these links to retain the original structure. Here's the detailed explanation, illustrations, and pseudo code in C++ with comments:

**It uses threaded binary tree - create temp threads to come back to the parent/root fast**


### Morris Traversal Algorithm:

1. Initialize a current pointer to the root of the tree.
2. While the current pointer is not NULL:
   a. If the current node has no left child:
      - Print or process the current node.
      - Move to the right child (current = current->right).
   b. If the current node has a left child:
      - Find the in-order predecessor, which is the rightmost node in the left subtree.
      - If the predecessor's right pointer is NULL:
        - Set the right pointer of the predecessor to the current node.
        - Move to the left child (current = current->left).
      - If the predecessor's right pointer is not NULL (already connected):
        - Reset the right pointer of the predecessor to NULL (removing the link).
        - Print or process the current node.
        - Move to the right child (current = current->right).

**A link is visited at most 3 times 1- Link creation 2- print node 3- link removal node** 13:18

### Pseudo Code:

```cpp
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void MorrisTraversal(TreeNode* root) {
    TreeNode* current = root;
    TreeNode* predecessor;

    while (current != NULL) {
        if (current->left == NULL) {
            // If no left child, process the current node and move to the right.
            cout << "Data: " << current->data << endl;
            current = current->right;
        } else {
            // Find the predecessor (rightmost node in the left subtree).
            predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) { // And condition so it doesnt run in loops 
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                // Establish the temporary link and move to the left child.
                predecessor->right = current;
                current = current->left;
            } else {
                // Remove the temporary link, process the current node, and move to the right.
                predecessor->right = NULL;
                cout << "Data: " << current->data << endl;
                current = current->right;
            }
        }
    }
}
```

### Raw explanantion (check)

```plaintext
         1
        / \
       2   3
      / \   
     4   5   
          \
           6
```
The Inorder traversal is 

4 2 5 6 1 3

... In Case of normal traversals we go back track to the root/parent node .. but in morris traversal we samrt create a link to the parent.

**Short Algo: if left is null print it and make curr to right.. else {find the predecessor and create a link to its parent, if predecessor alr exist(link is present) print it and move toits right(parent) while deleting it** 

**We just go to left and go to the right most node(This will be the last node to be printed) and then link it to the parent to create temp link back to the parent**

**Predecessor - Go One left .. and go full right till the rightmost leaf.. this last node is called predecessor**
**We just take the last node from each sub tree(imagine) and link it to the root.. ie so after traversong the last node we can directly jump back to the parent node**

**We just go to the left most tree leaf while printing (just as in inorder) then we jump back to the prev parent and then print it .. then move to the right part and print .. we have created link to the prev parent .. hence jump and delete the temp link**

Ex. 4 will be linked to its aprent 2 ..so it can jump back to 2.. (since its a left short leaf node .. we cant find the efficiency)
But the efficiency can be seen in the case of the right leaf node 6.  It the case of 6.. it will be temporarily be linked to the parent node ie 1.. hence after 6 is traversalled .. it wiill directy go back to 1.. instead of goung 6->5->2->1 like in normal in order traversal


### Detailed Explanation with Illustrations:

Let's go through the code and its execution step by step using an example tree:

```plaintext
         1
        / \
       2   3
      / \   \
     4   5   6
```

1. Start with `current` pointing to the root (Node 1).

### Step 1:

- Start with `current` pointing to the root (Node 1).
- `current` has a left child, so we find the in-order predecessor by moving right from Node 2.

### Step 2:

- The predecessor's right pointer is NULL, so we establish a temporary link from the predecessor to the current node (Node 1) and move to the left child (Node 2).

### Step 3:

- Now, Node 2 becomes the current node. It also has a left child, so we find the predecessor by moving right from Node 4.

### Step 4:

- The predecessor's right pointer is NULL, so we establish a temporary link from the predecessor to Node 2 and move to the left child (Node 4).

### Step 5:

- Node 4 becomes the current node. It has no left child, so we print/process Node 4 and move to the right (Node 2).

### Step 6:

- Since Node 2's left subtree is already processed (due to the temporary link), we print/process Node 2 and move to the right (Node 5).

### Step 7:

- Node 5 has no left child, so we print/process Node 5 and move to the right (Node 3).

### Step 8:

- Node 3 has no left child, so we print/process Node 3 and move to the right (Node 6).

### Step 9:

- Node 6 has no left child, so we print/process Node 6.

### Step 10:

- The traversal is complete.

These steps illustrate how the Morris Traversal algorithm works to traverse the binary tree and how it establishes and removes temporary links to achieve an in-order traversal in this example.