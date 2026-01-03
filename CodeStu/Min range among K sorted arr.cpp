// Smallest Range From K Sorted List
// profile
// Contributed by
// Ankit Kharb
// Medium
// yellow-spark
// 80/80
// 15 mins
// 85 %


// 50 upvotes
// OlaCleartax
// Problem Statement
// Suggest Edit
// You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range.
// For example :
// If we have 3 lists as [1, 10, 11], [2, 3, 20], [5, 6, 12] then the [1, 5] is the range that includes 1 from the first list, 2,3 from the second list, and 5 from the third list i.e, this range contains at least one element from each list.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 1 <= 'T' <= 50
// 1 <= 'N' <= 10 ^ 4  
// 1 <= 'K' <= 10 ^ 4  
// 1 <= 'N' * 'K' <= 10 ^ 4
// 1 <= 'VAL' <= 10 ^ 9

// Where 'VAL' is the value of any element of any list.

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 3 2
// 2 4 5
// 5 6 7
// 2 3
// 1 1
// 9 12
// 4 9
// Sample Output 1 :
// 1
// 9
// Explanation For Sample Input 1 :
// Test case 1 :
// The given list are [2, 4, 5], [5, 6, 7]. The range [5, 5] will include 5 which is present in both the list and hence the length of this range is 1. This is the only possible range having the minimum length.

// Test case 2 :
// The given list are [1, 1], [9, 12], [4, 9]. The range [1, 9] will include 1 which is present in the first list, and 9 which include in both the second and third list  The length of the range is 9 (9 - 1 + 1 = 9).
// Sample Input 2 :
// 2
// 3 3
// 4 7 30
// 1 2 12
// 20 40 50
// 5 1
// 3 6 8 12 31
// Sample Output 2 :
// 14
// 1
// Explanation For Sample Input 2 :
// Test case 1 :
// The given list are [4, 7, 30], [1, 2, 12] and [20, 40, 50]. The range [7, 20], hence the length of this range is 14. This is the only possible range having the minimum length.

// Test case 2 :
// The range [3, 3] will include 3 which is present in the first list. The length of the range is 1. Infect, we can select any of element present in first list as there is only one list given to us.


#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

struct Element {
  int val; // Value of the element.
  int row; // Index of the row (array) to which the element belongs.
  int col; // Index of the column (element within the row).

  Element(int val, int row, int col) : val(val), row(row), col(col) {}
};

class Compare {
public:
  bool operator()(const Element &a, const Element &b) {
    return a.val > b.val; // Min-heap based on element values.
  }
};

int kSorted(std::vector<std::vector<int>> &sortedArrays, int k, int n) {
  int minRange = INT_MAX;
  int maxEle = INT_MIN;

  std::priority_queue<Element, std::vector<Element>, Compare> minHeap;

  // Initialize minHeap with the first element from each row.
  for (int i = 0; i < k; ++i) {
    if (!sortedArrays[i].empty()) {
      int val = sortedArrays[i][0];
      minHeap.push(Element(val, i, 0));
      maxEle = std::max(maxEle, val);
    }
  }

  int minEle = minHeap.top().val;

  // Main loop to find the minimum range.
  while (minHeap.size() == k) {
    Element current = minHeap.top();
    minHeap.pop();
    minRange = std::min(minRange,maxEle - current.val);

    if (current.col + 1 < sortedArrays[current.row].size()) {
      // Add the next element from the same row to minHeap.
      int newCol = current.col + 1;
      int val = sortedArrays[current.row][newCol];
      minHeap.push(Element(val, current.row, newCol));
      maxEle = std::max(maxEle, val);
    } else {
      // One of the rows is exhausted.
      break;
    }

    // Update minEle if the current element is the new minimum.
    if (current.val < maxEle) {
      minEle = current.val;
    }
  }

  return minRange+1;
}
