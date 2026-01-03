// 238. Product of Array Except Self

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

#include <iostream>
#include <vector>
using namespace std;
// Approach: Prefix and Suffix Products
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // left[i] = product of all elements to the left of i
        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // right[i] = product of all elements to the right of i
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            // product of all elements except nums[i] = left[i] * right[i]
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};

// Optimize the above solution to use O(1) space complexity (excluding the output array)
// By maintain left product array in first loop and then using a simple variable to store the right product in second loop
// This way we can avoid using the right array and reduce space complexity to O(1) (excluding the output array)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> output(n);

        // output[i] = product of all elements to the left of i
        // output[0] = 1 because there are no elements to the left of 0
        output[0] = 1;

        // Calculate the product of all elements to the left of i
        for (int i = 1; i < n; i++)
        {
            // output[i] = product of all elements to the left of i
            output[i] = output[i - 1] * nums[i - 1];
        }

        int right = 1;

        // Go from the end and calculate the product of all elements to the right of i
        for (int i = n - 1; i >= 0; i--)
        {
            output[i] *= right;
            right *= nums[i];
        }

        return output;
    }
    // time complexity: O(n)
    // space complexity: O(1) (excluding the output array)
};