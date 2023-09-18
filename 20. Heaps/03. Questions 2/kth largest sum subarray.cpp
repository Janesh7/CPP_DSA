#include<queue>
int getKthLargest(vector<int> &arr, int k) {
  //	Write your code here.
  int n = arr.size();
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // Traverse the array and maintain the k largest sums in the min heap
  for (int i = 0; i < n; i++) {
    int currentSum = 0;
    for (int j = i; j < n; j++) {
      currentSum += arr[j];
      if (minHeap.size() < k) {
        minHeap.push(currentSum);
      } else if (currentSum > minHeap.top()) {
        minHeap.pop();
        minHeap.push(currentSum);
      }
    }
  }

  // The top of the min heap contains the kth largest sum
  return minHeap.top();
}