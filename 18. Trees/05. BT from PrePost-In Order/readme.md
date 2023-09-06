
**Question 1: Construct Tree from Inorder and Preorder Traversals**

**Notes:**
- In this problem, you are given two arrays: the inorder traversal and the preorder traversal of a binary tree.
- The goal is to construct the binary tree and return its root node.
- The idea to solve this problem is to use recursion. The first element of the preorder traversal is always the root of the tree. You can find this root in the inorder traversal, which divides the elements into left and right subtrees.
- Recursively apply the same logic to the left and right subtrees.
- The base case for recursion is when the inorder or preorder traversal is empty, which corresponds to a leaf node (null).


**IMP: Left call first as the next index(index++) (as we r starting from index 0) of the in order array is in the left(check workerd out examples) and then right call.. it is opposite for postorder-inorder constr**


**Question 2: Construct Tree from Inorder and Postorder Traversals**

**Notes:**
- This problem is similar to the first one but uses postorder traversal instead of preorder traversal.
- In postorder traversal, the last element is always the root of the tree.
- You can use a similar recursive approach to construct the binary tree.
- The key observation is that the last element of the postorder traversal corresponds to the root, and you can find this root in the inorder traversal.

**IMP: Here we have to call right first as we r starting from n-1 index and the InOrderindex-- index will go the right part** 



**TC: O(nlogn) + O(n) = O(nlogn)** 
as it takes nlon tc to enter the index-value entry