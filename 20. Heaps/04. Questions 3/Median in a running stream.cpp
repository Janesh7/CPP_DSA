#include <bits/stdc++.h>

// A function to determine the sign of a difference between two integers.
// Returns 0 if the two integers are equal, 1 if the first integer is greater than the second integer,
// and -1 if the first integer is less than the second integer.
int signum(int a, int b) {
  if (a == b) {
    return 0;
  } else if (a > b) {
    return 1;
  } else {
    return -1;
  }
}

// A function to call the median function based on the sign of the difference between the sizes of the two heaps.
void callMedian(int ele, priority_queue<int>& maxH,
                priority_queue<int, vector<int>, greater<int>>& minH, int& median) {
  switch (signum(maxH.size(), minH.size())) {
    // ODD
    case 0:
      // If the two heaps are the same size, push the element to the min-heap if it is greater than the median,
      // or to the max-heap if it is less than the median.
      if (ele > median) {
        minH.push(ele);
        median = minH.top();
      } else {
        maxH.push(ele);
        median = maxH.top();
      }
      break;

    // EVEN
    case 1:
      // If the max-heap is larger than the min-heap, push the element to the min-heap if it is greater than the median,
      // or to the max-heap and pop the top element from the max-heap and push it to the min-heap if it is less than the median.
      if (ele > median) {
        minH.push(ele);
        median = (minH.top() + maxH.top()) / 2;
      } else {
        minH.push(maxH.top());
        maxH.pop();
        maxH.push(ele);
        median = (minH.top() + maxH.top()) / 2;
      }
      break;
    case -1:
      // If the min-heap is larger than the max-heap, push the element to the max-heap if it is greater than the median,
      // or to the min-heap and pop the top element from the min-heap and push it to the max-heap if it is less than the median.
      if (ele > median) {
        maxH.push(minH.top());
        minH.pop();
        minH.push(ele);
        median = (minH.top() + maxH.top()) / 2;
      } else {
        maxH.push(ele);
        median = (minH.top() + maxH.top()) / 2;
      }
      break;
  }
}

// A function to find the median of an array using two heaps.
vector<int> findMedian(vector<int>& arr, int n) {
  // Create a max-heap to store the smaller elements.
  priority_queue<int> maxH;

  // Create a min-heap to store the larger elements.
  priority_queue<int, vector<int>, greater<int>> minH;

  // Initialize the median.
  int median = -1;

  // Create a vector to store the median values.
  vector<int> ans;

  // Iterate over the array and call the median function for each element.
  for (int i = 0; i < n; i++) {
    callMedian(arr[i], maxH, minH, median);

    // Add the median to the answer vector.
    ans.push_back(median);
  }

  // Return the answer vector.
  return ans;
}