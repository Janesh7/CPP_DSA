// 153. Find Minimum in Rotated Sorted Array

// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

 

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
// Example 2:

// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
// Example 3:

// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

// Constraints:

// n == nums.length
// 1 <= n <= 5000
// -5000 <= nums[i] <= 5000
// All the integers of nums are unique.
// nums is sorted and rotated between 1 and n times.

// -----------------------------------------------------------------------------

// Approach
// The description says "You must write an algorithm that runs in O(logn) time.", 
// so we will solve this question with Binary Search.

// Input: nums = [3,4,5,1,2]
// Let me put left, right and middle pointer.

// [3,4,5,1,2]
//  L   M   R
// Typical Binary Search is like this.

// If a middle number is greater than a target number, we move right to middle - 1. 
// On the other hand if the middle number is less than the target number, 
// we will move left to middle + 1.

// Binary search assumes that the input is sorted.

// The target number for this question is a minimum number in the input, 
// but problem here is that input array is rotated a few times.

// How can we decide to move left or right pointer?
// It's tough to think about whole array but part of array is still sorted 
// in ascending order, even if the input is rotated.

// For example,

// [0,1,2,3,4,5]
// ↓
// [4,5,0,1,2,3]
// Rotated twice. Between 4 and 5, they are sorted and between 0 and 3, 
// they are also sorted. We will use those parts of array.

// Let's go back to main story.

// My strategy is to compare middle number with right number. In this case, 5 and 2.

// [3,4,5,1,2]
//  L   M   R
// 5 is greater than 2. That means we don't know how many numbers we have on 
// the right side of the middle number, but we can say the numbers return to the 
// minimum value and then begin to increase again on the right side of the middle number.

// To prove that, let's think about this example quickly.

// [1,2,3,4,5]
//  L   M   R
// In this case, 3 is less than 5. That means minimum number is definitely on the left 
// side of the middle number. That's because input array is sorted and the last 
// number (= right number) is greater than middle number. We are sure that the 
// numbers increase from middle to right.

// Let's go back to main story again.

// [3,4,5,1,2]
//  L   M   R
// Middle number is greater than right number, so we can say at some point, 
// the numbers return to minimum value. That's why we should move the left pointer 
// to middle pointer + 1.

// [3,4,5,1,2]
//      M L R
// Next, middle pointer should be...

// [3,4,5,1,2]
//        L R
//        M
// Compare 1 with 2. The middle number is less than the right number, 
// so we are sure that the minimum number is on the left of the middle number.

// There is one point when we move right pointer.

// Points

// When we move right pointer to left side, we will update right pointer with middle pointer. 
// On the other hand when we move left pointer, we will update left pointer with middle pointer + 1.

// Why? Let's think about this case.

// [1,2,3,4,5]
//  L   M   R
// Compare 3 with 5. We will move the right pointer to left side. In this case, 
// we only know that the middle number is smaller than the right number, 
// so the middle number could still be the minimum value.

// [3,4,5,1,2]
//  L   M   R
// In this case, since the middle number is greater than the right number, 
// it’s impossible for the middle number to be the minimum value. 
// That's why we can update left pointer with middle pointer + 1.

// Let's go back to main story again.

// In this case, we will update right pointer with middle pointer.

// [3,4,5,1,2]
//        L R
//        M

// ↓

// [3,4,5,1,2]
//        L 
//        M
//        R
// Now L == R. We stop iteration.

// return 1(= left number or right number)


// Complexity
// Time complexity: O(logn)
// Space complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];        
    }
};

// Step by Step Algorithm
// Initialize Pointers
// left = 0
// right = len(nums) - 1
// We define two pointers, left and right.
// left starts at the beginning of the array (0), and right starts at the last index (len(nums) - 1).
// The goal is to narrow down the range between left and right until we find the minimum element.

// Binary Search Loop
// while left < right:
// We enter a loop that continues as long as left is less than right.
// This loop performs a binary search to locate the minimum value in the rotated sorted array.

// Calculate Midpoint
// mid = (left + right) // 2
// We calculate the midpoint mid by taking the integer division of (left + right) / 2.
// mid represents the middle index of the current subarray defined by left and right.

// Compare Midpoint with Right Element
// if nums[mid] <= nums[right]:
//     right = mid
// If the element at mid is less than or equal to the element at right, 
// this means the minimum element could be at mid or to its left (in the left half of the current subarray).
// We update right to mid, effectively discarding the right half of the array in the next iteration.

// Move Left Pointer
// else:
//     left = mid + 1
// If nums[mid] is greater than nums[right], this means the minimum element must be in the right half 
// of the current subarray.
// We update left to mid + 1, moving it to the right half of the array for the next iteration.

// Return Minimum Element
// return nums[left]
// Once the loop exits (when left == right), both left and right will be pointing to the minimum element in the array.
// We return nums[left] as the minimum value.
