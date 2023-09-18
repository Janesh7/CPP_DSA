#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Node {
public:
    int data;
    int i;
    int j;

    Node(int _data, int _i, int _j) : data(_data), i(_i), j(_j) {}
};

class CustomCompare {
public:
    bool operator()(const Node& a, const Node& b) {
        return a.data > b.data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    vector<int> ans;
    priority_queue<Node, vector<Node>, CustomCompare> minHeap;

    // Initialize the Min Heap with the first element from each array
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            Node node(arrays[i][0], i, 0);
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
        if (top.j + 1 < arrays[top.i].size()) {
            // Create a new Node with the next element in the same array
            Node nextNode(arrays[top.i][top.j + 1], top.i, top.j + 1);
            // Push the new Node into the Min Heap
            minHeap.push(nextNode);
        }
    }

    return ans;
}

int main() {
    // Example usage:
    vector<vector<int>> arrays = {{1, 3, 5}, {2, 4, 6}, {0, 7, 8}};
    vector<int> result = mergeKSortedArrays(arrays);

    // Print the merged sorted array
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
