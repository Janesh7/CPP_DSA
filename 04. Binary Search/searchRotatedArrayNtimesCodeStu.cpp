//  Search In Rotated Sorted Array

// Problem Statement
// Suggest Edit
// Aahad and Harshit always have fun by solving problems. Harshit took a sorted array consisting of distinct integers and rotated it clockwise by an unknown amount. For example, he took a sorted array = [1, 2, 3, 4, 5] and if he rotates it by 2, then the array becomes: [4, 5, 1, 2, 3].
// After rotating a sorted array, Aahad needs to answer Q queries asked by Harshit, each of them is described by one integer Q[i]. which Harshit wanted him to search in the array. For each query, if he found it, he had to shout the index of the number, otherwise, he had to shout -1.
// For each query, you have to complete the given method where 'key' denotes Q[i]. If the key exists in the array, return the index of the 'key', otherwise, return -1.
// Note:
// Can you solve each query in O(logN) ?
// Detailed explanation ( Input/output format, Notes, Constraints, Images )

// Sample Input 1:
// 4
// 2 5 -3 0
// 2
// 5
// 1
// Sample Output 1:
// 1
// -1
// Explanation For Sample Input 1:
// In the 1st test case, 5 is found at index 1

// In the 2nd test case, 1 is not found in the array, hence return -1. 

int search(int *nums, int n, int target) {
  // Write your code here.
  int s = 0, e = n - 1;

  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (nums[mid] == target)
      return mid;

    // if left half is sorted
    if (nums[s] <= nums[mid]) {
      // check if target lies in left side
      if (target <= nums[mid] && target >= nums[s])
        e = mid - 1;
      else
        s = mid + 1;
    }
    // if right side is sorted
    else {
      // check if target lies in right side
      if (target >= nums[mid] && target <= nums[e])
        s = mid + 1;
      else
        e = mid - 1;
    }
  }
  return -1;
}