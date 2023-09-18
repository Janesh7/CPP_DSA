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
