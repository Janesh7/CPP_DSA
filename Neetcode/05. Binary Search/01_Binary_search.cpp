// 704. Binary Search

// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1

// Constraints:

// 1 <= nums.length <= 104
// -104 < nums[i], target < 104
// All the integers in nums are unique.
// nums is sorted in ascending order.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1;

        while (s <= e)
        {                              // Use <= instead of < to handle the case when s == e
            int mid = s + (e - s) / 2; // Calculate mid and avoid overflow

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return -1;
    }
    // Time complexity: O(log n) because we are halving the search space in each iteration. Math log2(n) gives us the number of times we can halve n until we reach 1.
    // The while loop runs log2(n) times, where n is the size of the input array.
    // Space complexity: O(1) because we are using a constant amount of space
};
