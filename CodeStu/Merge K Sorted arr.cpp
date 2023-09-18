// Merge K Sorted Arrays
// Medium 

// Problem Statement

// You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 1 <= T <= 5
// 1 <= K <= 5
// 1 <= N <= 20
// -10^5 <= DATA <= 10^5

// Time Limit: 1 sec 
// Sample Input 1:
// 1
// 2
// 3 
// 3 5 9 
// 4 
// 1 2 3 8   
// Sample Output 1:
// 1 2 3 3 5 8 9 
// Explanation Of Sample Input 1:
// After merging the two given arrays/lists [3, 5, 9] and [ 1, 2, 3, 8], the output sorted array will be [1, 2, 3, 3, 5, 8, 9].
// Sample Input 2:
// 1
// 4
// 3
// 1 5 9
// 2
// 45 90
// 5
// 2 6 78 100 234
// 1
// 0
// Sample Output 2:
// 0 1 2 5 6 9 45 78 90 100 234
// Explanation Of Sample Input 2 :
// After merging the given arrays/lists [1, 5, 9], [45, 90], [2, 6, 78, 100, 234] and [0], the output sorted array will be [0, 1, 2, 5, 6, 9, 45, 78, 90, 100, 234].


#include <bits/stdc++.h>

class Node {
public:
  int data;
  int i;
  int j;

  Node(int _data, int _i, int _j) : data(_data), i(_i), j(_j) {}
};

class CustomCompare {
public:
  bool operator()(const Node &a, const Node &b) { return a.data > b.data; }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {
  // Write your code here.
  vector<int> ans;
  priority_queue<Node, vector<Node>, CustomCompare> minHeap;

  // Initialize the Min Heap with the first element from each array
  for (int i = 0; i < kArrays.size(); i++) {
    if (!kArrays[i].empty()) {
      Node node(kArrays[i][0], i, 0);
      minHeap.push(node);
    }
  }

  // Merge sorted arrays
  while (!minHeap.empty()) {
    // Pop the smallest element from the Min Heap
    Node top = minHeap.top();
    minHeap.pop();

    // Add the data value of the popped Node to the ans vector
    ans.push_back(top.data);

    // Check if there are more elements in the same array (same row)
    if (top.j + 1 < kArrays[top.i].size()) {
      // Create a new Node with the next element in the same array
      Node nextNode(kArrays[top.i][top.j + 1], top.i, top.j + 1);
      // Push the new Node into the Min Heap
      minHeap.push(nextNode);
    }
  }

  return ans;
}
