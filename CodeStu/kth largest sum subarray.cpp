// K-th Largest Sum Subarray
// profile
// Contributed by
// Anup Kumar Singh
// Easy
// yellow-spark
// 40/40
// 10 mins
// 90 %


// 74 upvotes
// AmazonOla
// Problem Statement
// Suggest Edit
// Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.
// Please note that a subarray is the sequence of consecutive elements of the array.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Sample Input 1 :
// 2
// 3 3
// 3 -2 5
// 2 2
// 4 1
// Sample output 1 :
// 3
// 4
// Explanation of Sample output 1 :
// For the first test case, 
// Sum of [0, 0] = 3
// Sum of [0, 1] = 1
// Sum of [0, 2] = 6
// Sum of [1, 1] = -2
// Sum of [1, 2] = 3
// Sum of [2, 2] = 5
// All sum of subarrays are {6, 5, 3, 3, 1, -2} where the third largest element is 3.

// For the second test case, 
// Sum of [0, 0] = 4
// Sum of [0, 1] = 5
// Sum of [1, 1] = 1
// All sum of subarrays are {5, 4, 1} where the second largest element is 4.
// Sample Input 2 :
// 2
// 4 10
// 5 4 -8 6
// 3 1
// 1 2 3
// Sample output 2 :
// -8
// 6
// Explanation of Sample output 2 :
// For the first test case, among the sum of all the subarray, the tenth-largest sum will be -8.

// For the second test case, among the sum of all the subarray, the largest sum will be 6.


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