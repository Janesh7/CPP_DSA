// Median in a stream
// Hard


// Given that integers are read from a data stream. Your task is to find the median of the elements read so far.
// Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.
// For Example :
// [2,3,4] - median is 3.
// [2,3] - median is floor((2+3)/2) = 2.


// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 1 <= T <= 10
// 1 <= N <= 10^4
// 0 <= data <= 10^8
// Where T is the number of test cases, N is the number of elements in the data stream.

// Time Limit : 1 sec
// Sample Input 1:
// 3
// 3
// 1 2 3 
// 2
// 9 9 
// 1
// 4 
// Sample Output 1:
// 1 1 2
// 9 9 
// 4 
// Explanation For Sample Input 1:
// For test case 1 
// After reading first element of stream , Median of [1] is 1 
// After reading second element of stream, Median of [1, 2]  = floor((1+2)/2)  = 1
// After reading third element of stream, Median of [1,2,3] = 2
// So the output will be 1 1 2.
// Sample Input 2:
// 2
// 3
// 5 3 8
// 2
// 3 8
// Sample Output 2:
// 5 4 5
// 3 5
// Explanation For Sample Input 2:
// For test case 1 
// After reading first element of stream, Median of [5] is 5
// After reading second element of stream, Median of [5, 3]  = floor((5+3)/2)  = 4
// After reading third element of stream, Median of [5,3,8] = 5 , it is the middle value of the sorted array
// So the output will be 5 4 5.


#include <bits/stdc++.h>

// A function to determine the sign of a difference between two integers.
// Returns 0 if the two integers are equal, 1 if the first integer is greater
// than the second integer, and -1 if the first integer is less than the second
// integer.
int signum(int a, int b) {
  if (a == b) {
    return 0;
  } else if (a > b) {
    return 1;
  } else {
    return -1;
  }
}

// A function to call the median function based on the sign of the difference
// between the sizes of the two heaps.
void callMedian(int ele, priority_queue<int> &maxH,
                priority_queue<int, vector<int>, greater<int>> &minH,
                int &median) {
  switch (signum(maxH.size(), minH.size())) {
  case 0:
    // If the two heaps are the same size, push the element to the min-heap if
    // it is greater than the median, or to the max-heap if it is less than the
    // median.
    if (ele > median) {
      minH.push(ele);
      median = minH.top();
    } else {
      maxH.push(ele);
      median = maxH.top();
    }
    break;
  case 1:
    // If the max-heap is larger than the min-heap, push the element to the
    // min-heap if it is greater than the median, or to the max-heap and pop the
    // top element from the max-heap and push it to the min-heap if it is less
    // than the median.
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
    // If the min-heap is larger than the max-heap, push the element to the
    // max-heap if it is greater than the median, or to the min-heap and pop the
    // top element from the min-heap and push it to the max-heap if it is less
    // than the median.
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
vector<int> findMedian(vector<int> &arr, int n) {
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
