// Search In Rotated Sorted Array
// Easy
//
// Problem Statement
// You have been given a sorted array/list ARR consisting of ‘N’ elements. You are also given an integer ‘K’.
// Now the array is rotated at some pivot point unknown to you. For example, if ARR = [ 1, 3, 5, 7, 8]. Then after rotating ARR at index 3, the array will be ARR = [7, 8, 1, 3, 5].
// Now, your task is to find the index at which ‘K’ is present in ARR.
// Note :
// 1. If ‘K’ is not present in ARR then print -1.
// 2. There are no duplicate elements present in ARR. 
// 3. ARR can be rotated only in the right direction.
// For example, if ARR = [12, 15, 18, 2, 4] and K = 2, then the position at which K is present in the array is 3 (0-indexed).
// Follow Up
// Can you do this in Logarithmic time and constant additional space? 
// Detailed explanation ( Input/output format, Notes, Constraints, Images )

// Sample Input 1:
// 4 3
// 8 9 4 5
// Sample Output 1:
// -1 
// Explanation Of Sample Output 1:
// For the test case, 3 is not present in the array. Hence the output will be -1.
// Sample Input 2:
// 4 3
// 2 3 5 8
// Sample Output 2:
// 1

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