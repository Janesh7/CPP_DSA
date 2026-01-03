// 217. Contains Duplicate
// Solved
// Easy

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Example 1:

// Input: nums = [1,2,3,1]

// Output: true

// Explanation:

// The element 1 occurs at the indices 0 and 3.

// Example 2:

// Input: nums = [1,2,3,4]

// Output: false

// Explanation:

// All elements are distinct.

// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]

// Output: true

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> arr;

        for (const int &i : nums)
        {

            if (arr[i] > 0)
            {
                return true;
            }

            arr[i]++;
        }

        return false;
    }
    // time complexity: O(n) for the single pass through the array
    // space complexity: O(n) for storing the indices in the hash map
};