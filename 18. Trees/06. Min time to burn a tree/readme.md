**VVV IMP**

# Min time to burn a tree from the given node

### Problem Description
- Given a binary tree and a target node, you need to find the minimum time it takes to burn the entire tree if the target node is set on fire.
- In this problem, each node can burn its neighboring nodes in one second.

### Approach Overview
1. **Create Mapping of Parent Nodes**
   - To solve this problem efficiently, you first need to create a mapping of parent nodes for each node in the binary tree. This mapping is crucial for navigating the tree effectively.

2. **Find the Target Node**
   - Start a level-order traversal (Breadth-First Search) from the root node.
   - While traversing, keep track of the target node since you need it later.

3. **Burn the Tree**
   - Perform another level-order traversal starting from the target node.
   - During this traversal, keep track of time (in seconds).
   - For each node, burn its unburned neighboring nodes (left child, right child, and parent if present).
   - Increment the time for each second of burning.
   - Continue until there are no unburned nodes left.

4. **Return the Time Taken**
   - The time taken to burn the entire tree is the answer.

### Pseudocode with Comments
Here's the pseudocode for the solution with detailed comments:

```cpp
class Solution {
  public:
    Node* createMapping(Node* root, map<Node*, Node*> &parent, int target){
        // Initialize a queue for level-order traversal
        queue<Node*> q;
        q.push(root);
        
        Node* targetNode = NULL;
        
        // Initialize parent mapping for the root node
        parent[root] = NULL;
        
        // Perform level-order traversal
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            // Check if the current node is the target
            if(front->data == target)
                targetNode = front;
            
            // Process left child
            if(front->left){
                // Create a parent mapping for the left child
                parent[front->left] = front;
                // Enqueue the left child for traversal
                q.push(front->left);
            }
            
            // Process right child
            if(front->right){
                // Create a parent mapping for the right child
                parent[front->right] = front;
                // Enqueue the right child for traversal
                q.push(front->right);
            }
        }
        
        // Return the target node found during traversal
        return targetNode;
    }
    
    int burntree(Node* targetNode, map<Node*, Node*> &parent){
        // Initialize variables
        int count = 0; // Time in seconds
        map<Node*, bool> visited; // To track visited nodes
        
        // Mark the target node as visited and enqueue it
        visited[targetNode] = true;
        queue<Node*> q;
        q.push(targetNode);
        
        // Perform level-order traversal
        while(!q.empty()){
            bool temp = false; // Flag to track whether anything new was added to the queue
            int size = q.size(); // Number of nodes at the current level
            
            // Process nodes at the current level
            for(int i = 0; i < size; i++){
                Node* front = q.front();
                q.pop();
                
                // Burn unburned left child
                if(front->left && !visited[front->left]){
                    temp = true;
                    visited[front->left] = true;
                    q.push(front->left);
                }
                
                // Burn unburned right child
                if(front->right && !visited[front->right]){
                    temp = true;
                    visited[front->right] = true;
                    q.push(front->right);
                }
                
                // Burn unburned parent node (if exists)
                if(parent[front] && !visited[parent[front]]){
                    temp = true;
                    visited[parent[front]] = true;
                    q.push(parent[front]);
                }
            }
            
            // If something new was added to the queue, increment time
            if(temp)
                count++;
        }
        
        // Return the total time taken to burn the tree
        return count;
    }
    
    int minTime(Node* root, int target) 
    {
        // Create mapping of parent nodes and find the target node
        map<Node*, Node*> parent;
        Node* targetNode = createMapping(root, parent, target);
        
        // Calculate the minimum time to burn the tree
        int count = burntree(targetNode, parent);
        
        // Return the result
        return count;
    }
};
```

