
## Zig Zag Traversal

#### Problem Statement:
Perform a zig-zag (spiral) traversal of a binary tree, alternating between left-to-right and right-to-left order at different levels.

#### Approach:

1. Initialize an empty vector `ans` to store the final result.
2. Create a queue of node pointers for level order traversal.
3. Push the root node into the queue.
4. While the queue is not empty, process each level:
   - Get the size of the queue for the current level.
   - Create a temporary vector `tempAns` to store nodes for the current level.
   - Use a boolean variable `leftToRight` to determine the traversal direction.
   - Iterate over the nodes in the current level:
     - Dequeue a node from the front of the queue.
     - Based on the `leftToRight` flag, insert the node's data at the appropriate index in `tempAns`.
     - Enqueue the left and right children of the dequeued node if they exist.
   - Change the value of `leftToRight` to its opposite.
   - Append the contents of `tempAns` to the final `ans` vector.

5. Return the `ans` vector.

#### Code:

```cpp
vector<int> zigzagTraversal(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> tempAns(size);

        for (int i = 0; i < size; ++i) {
            Node* frontNode = q.front();
            q.pop();

            int index = (leftToRight) ? i : size - i - 1;
            tempAns[index] = frontNode->data;

            if (frontNode->left) q.push(frontNode->left);
            if (frontNode->right) q.push(frontNode->right);
        }

        leftToRight = !leftToRight;
        ans.insert(ans.end(), tempAns.begin(), tempAns.end());
    }

    return ans;
}
```

#### Time Complexity:
- Each node is visited once, making the time complexity O(n), where n is the number of nodes in the tree.

#### Space Complexity:
- The queue and temporary vector `tempAns` are used, but at any level, the total space required is proportional to the number of nodes at that level, leading to a space complexity of O(n).





## Boundary Traversal

#### Problem Statement:
Perform the boundary traversal of a binary tree, which includes printing the left boundary, leaf nodes, and right boundary in an anti-clockwise manner.

#### Approach:

1. The boundary traversal can be divided into three parts:
   - Print the left boundary (excluding leaf nodes). (**remember that we have to print boundary nodes and it might happen that the left nodes might not have a left node in that case we will print the rigth node and keep going .. ie is why ELSE IF  ROOT->RIGHT**)
   - Print the leaf nodes.
   - Print the right boundary (excluding leaf nodes) in reverse order.

2. Create three separate functions to handle these three parts.

#### Code:

```cpp
void printLeftBoundary(Node* root, vector<int>& ans) {
    if (!root) return;

    if (root->left) {
        ans.push_back(root->data);
        printLeftBoundary(root->left, ans);
    } else if (root->right) {
        ans.push_back(root->data);
        printLeftBoundary(root->right, ans);
    }
}

void printLeafNodes(Node* root, vector<int>& ans) {
    if (!root) return;

    if (!root->left && !root->right) {
        ans.push_back(root->data);
        return;
    }

    printLeafNodes(root->left, ans);
    printLeafNodes(root->right, ans);
}

void printRightBoundary(Node* root, vector<int>& ans) {
    if (!root) return;

    if (root->right) {
        printRightBoundary(root->right, ans);
        ans.push_back(root->data);
    } else if (root->left) {
        printRightBoundary(root->left, ans);
        ans.push_back(root->data);
    }
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;

    if (!root) return ans;

    ans.push_back(root->data);

    printLeftBoundary(root->left, ans);
    printLeafNodes(root, ans);
    printRightBoundary(root->right, ans);

    return ans;
}
```

#### Time Complexity:
- Each node is visited once, making the time complexity O(n), where n is the number of nodes in the tree.

#### Space Complexity:
- The recursive stack is used for function calls, leading to a space complexity proportional to the height of the tree, which is O(h) in the worst case (unbalanced tree) and O(log n) in the best case (balanced tree).




## IMP Vertical Order Traversal

#### Problem Statement:
Perform the vertical order traversal of a binary tree, which involves printing nodes at each vertical level from left to right.

#### Approach:

1. The vertical order traversal involves maintaining a map where each key corresponds to a horizontal distance and the associated value is a vector of nodes present at that horizontal distance.

2. We can achieve this by doing a level order traversal of the binary tree and keeping track of the horizontal distance and level of each node.

3. Create a map where the key is the horizontal distance and the value is another map where the key is the level and the value is a vector of nodes.

4. Traverse the tree using a queue while storing horizontal distance and level as part of the queue element.

5. For each node, insert the node into the appropriate location in the map structure.

6. After traversing the entire tree, iterate through the map structure to retrieve nodes and construct the final answer vector.

#### Code:

```cpp
vector<int> verticalTraversal(TreeNode* root) {
    vector<int> ans;

    if (!root) return ans;

    // Create a map to store nodes at each horizontal distance and level
    map<int, map<int, vector<int>>> nodesMap;

    // Create a queue to perform level order traversal
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}}); // {node, {horizontal distance, level}}

    // Perform level order traversal
    while (!q.empty()) {
        TreeNode* currNode = q.front().first;
        int hd = q.front().second.first;
        int level = q.front().second.second;
        q.pop();

        // Insert the current node into the map at its corresponding location
        nodesMap[hd][level].push_back(currNode->val);

        // Enqueue left child with updated horizontal distance and level
        if (currNode->left) q.push({currNode->left, {hd - 1, level + 1}}); // Going left .. so horizontal distance -1.. like it goes ..-2,-1,0

        // Level always increases .. so +1 

        // Enqueue right child with updated horizontal distance and level
        if (currNode->right) q.push({currNode->right, {hd + 1, level + 1}}); // Going right .. so horizontal distance +1.. like it goes 0,1,2,3..
    }

    // Iterate through the map to retrieve nodes in vertical order
    for (auto& hdLevelMap : nodesMap) {
        for (auto& levelNodes : hdLevelMap.second) {
            for (int nodeVal : levelNodes.second) {
                ans.push_back(nodeVal);
            }
        }
    }

    return ans;
}
```

#### Time Complexity:
- Each node is visited once, making the time complexity O(n), where n is the number of nodes in the tree.

#### Space Complexity:
- A map structure is used to store nodes, which can have a maximum of n entries.
- The queue size can also go up to n in the worst case.
- Thus, the space complexity is O(n).





# Views of tree

**IMP POINT TO REMEMBER**: 
    - for bottom and top view .. we consider the horizontal distance HD (..-2,-1,0,1,2)
        - for **bottom view** we want the last element to be included ..so we change the value for each HD .. so the last one can remain
        - for **top view** we just want the first elements at eacch HD .. si we ignore all the rest values for that particular HD once we get a value for the horizontal distance.
    - for left and right view .. we consider the level (0->root,1,2,3...) and each node at each level
        - for **left** we go to left subtree first to get the left part (ALSO WE HAVE RIGHT PART but that is there if there is no left part then we go to right)
        - same the case for **right view** .. just make the right  subtree call first.

**NOTE**: 

- for **HD questions use map**, to map each HD to an element val.. **HD-1 for going to left and HD+1 for going to right** .. we have to **traverse** the map later.. **when we use map the time complexity becomes N*logN** (logN to inserting an element in the map and since we r traversing N node)

- for **Level questions** like left, rigth view .. **we can use index of an array to depict as the level**.. therefore we can use **size() function smartly to get next the level for the view** .. **Example** initiallly size of the main vector which stores answers(passed as ref)  ans.size()=0 means 0 lvl .. we will push root element .. recursive call (can be left or right based on view) .. say left .. that will be the left node for that level (now size of arr is 1) .. and so on



## Bottom View of a Binary Tree:

**Pseudocode:**
```cpp
vector<int> bottomView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    map<int, int> horizontalDistanceToValue;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int horizontalDistance = q.front().second;
        q.pop();

        horizontalDistanceToValue[horizontalDistance] = node->val;

        if (node->left) q.push({node->left, horizontalDistance - 1});
        if (node->right) q.push({node->right, horizontalDistance + 1});
    }

    for (const auto& entry : horizontalDistanceToValue) {
        result.push_back(entry.second);
    }

    return result;
}
```

**Explanation:**
- We use a `map` to store the value of the last encountered node at each horizontal distance.
- We perform a level order traversal using a queue and store nodes along with their horizontal distance.
- At each step, we update the `horizontalDistanceToValue` map with the value of the current node.
- For nodes with the same horizontal distance, the last encountered node will be at the bottom view.
- Finally, we iterate through the map and populate the result vector with the values.

## Top View of a Binary Tree:

**Pseudocode:**
```cpp
vector<int> topView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    map<int, int> horizontalDistanceToValue;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int horizontalDistance = q.front().second;
        q.pop();

        if (horizontalDistanceToValue.find(horizontalDistance) == horizontalDistanceToValue.end()) {
            horizontalDistanceToValue[horizontalDistance] = node->val;
        }

        if (node->left) q.push({node->left, horizontalDistance - 1});
        if (node->right) q.push({node->right, horizontalDistance + 1});
    }

    for (const auto& entry : horizontalDistanceToValue) {
        result.push_back(entry.second);
    }

    return result;
}
```

**Explanation:**
- Similar to the bottom view, we use a `map` to store the value of the first encountered node at each horizontal distance.
- During the traversal, we check if the current horizontal distance is not in the map; if not, we add the value to the map.
- This ensures that for nodes with the same horizontal distance, the first encountered node will be at the top view.
- The rest of the steps are similar to the bottom view approach.

Next, let's move on to the "Left View of a Binary Tree":

## Left View of a Binary Tree:

**Pseudocode:**
```cpp
vector<int> leftView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            if (i == 0) {
                result.push_back(node->val); // Add the first node of each level
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return result;
}
```

**Explanation:**
- We perform a level order traversal using a queue.
- For each level, we add the value of the first encountered node to the result vector.
- By adding only the first node of each level, we obtain the left view of the binary tree.

Finally, let's cover the "Right View of a Binary Tree":

## Right View of a Binary Tree:

**Pseudocode:**
```cpp
vector<int> rightView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            if (i == levelSize - 1) {
                result.push_back(node->val); // Add the last node of each level
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return result;
}
```

**Explanation:**
- Similar to the left view, we perform a level order traversal using a queue.
- For each level, we add the value of the last encountered node to the result vector.
- By adding only the last node of each level, we obtain the right view of the binary tree.


## Time complexities 

1. **Bottom View of a Binary Tree:**
   - **Time Complexity:** O(N*logN) on average, where N is the number of nodes in the binary tree.
   - **In the average case, we are using a balanced binary search tree (map) to store the horizontal distance to values. Inserting and retrieving from a balanced binary search tree has an average time complexity of O(logN). Since we insert N nodes, the overall time complexity is O(N*logN).**

2. **Top View of a Binary Tree:**
   - **Time Complexity:** O(N*logN) on average, where N is the number of nodes in the binary tree.
   - Similar to the bottom view, the time complexity is determined by the use of a balanced binary search tree (map). Inserting and retrieving from a balanced binary search tree has an average time complexity of O(logN). Since we insert N nodes, the overall time complexity is O(N*logN).

3. **Left View of a Binary Tree:**
   - **Time Complexity:** O(N), where N is the number of nodes in the binary tree.
   - The algorithm involves a level order traversal of the tree, visiting each node once. In the worst case, we visit all nodes, resulting in a time complexity of O(N).

4. **Right View of a Binary Tree:**
   - **Time Complexity:** O(N), where N is the number of nodes in the binary tree.
   - Similar to the left view, the algorithm involves a level order traversal of the tree, visiting each node once. In the worst case, we visit all nodes, resulting in a time complexity of O(N).

The time complexities for the bottom view and top view are higher due to the use of balanced binary search trees (maps) to maintain the mapping between horizontal distances and node values. On the other hand, the left view and right view algorithms involve a straightforward level order traversal, resulting in a linear time complexity.