
## Introduction to Trees

- **Tree**: A type of non-linear data structure where nodes can be connected with multiple nodes.
- **Node**: Each element of a tree that holds data and can have multiple child nodes.
    ```
    {   
        int data;
        node* left;
        node* right; // for binary
        // otherwise list<node*> child;
    }
    ```
- **Root**: The top node of a tree from which all other nodes are connected.
- **Child**: A node directly connected to another node moving away from the root.
- **Parent**: A node that has one or more child nodes.
- **Sibling**: Nodes that share the same parent.
- **Ancestor**: Nodes connected above a particular node along the path to the root.
- **Descendant**: Nodes connected below a particular node along the path to leaves.
- **Leaf**: A node with no children.
- **Binary Tree**: A type of tree where each node can have at most two children (left and right).
- **n-ary Tree**: A tree in which nodes can have more than two children.
- **Node Structure**: A node contains data and references/pointers to its child nodes.
- **Family Tree Analogy**: A tree structure can be visualized as a family tree with relationships among nodes.
- **Level of a Node**: The number of edges between the node and the root.
- **Depth of a Node**: The number of edges in the path from the root to that node.
- **Height of a Tree**: The maximum depth among all nodes.
- **Leaf Node**: A node with no children.
- **Internal Node**: A node with at least one child.
- **Subtree**: A tree formed by a node and its descendants.
- **Forest**: A collection of disjoint trees.

## Creation of Binary Trees

### Binary Tree Structure

- Each node has data and pointers to its left and right children.
- Binary trees can be created using a recursive approach.

### Building Binary Tree

- Recursive approach: Use a function `buildTree()` that takes input for each node's data.
- Create a node structure with left and right pointers.
- If data is `-1`, return `NULL` to indicate an empty node.
- Otherwise, create a new node with the data.
- Recur for left and right subtrees using recursive calls.

## Tree Traversals

### Inorder Traversal (LNR)

- Traverse left subtree.
- Print current node's data.
- Traverse right subtree.

### Preorder Traversal (NLR)

- Print current node's data.
- Traverse left subtree.
- Traverse right subtree.

### Postorder Traversal (LRN)

- Traverse left subtree.
- Traverse right subtree.
- Print current node's data.

### Level Order Traversal

- Use a queue to traverse the tree level by level.
- Enqueue root and `NULL` as a separator.
- While the queue is not empty:
  - Dequeue the front node.
  - If it's `NULL`, print a newline and enqueue another `NULL`.
  - Otherwise, print its data, enqueue its left child, and enqueue its right child.

### Reverse Level Order Traversal

- Similar to level order traversal but enqueue right child before the left child.

### Iterative Traversals

- Implement traversals iteratively using stacks or queues.

### Build Tree from Level Order Traversal

- Given a level order traversal, build a binary tree.
- Use a queue to insert nodes in level order.
- Start from the root, dequeue the front node, insert its left and right children, and repeat.

## Homework

- Implement iterative versions of tree traversals (inorder, preorder, postorder).
- Implement reverse level order traversal.
- Implement building a tree from level order traversal using a queue.

