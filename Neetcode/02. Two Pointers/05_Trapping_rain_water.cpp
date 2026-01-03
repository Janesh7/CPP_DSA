// 42. Trapping Rain Water
// Hard
// https://leetcode.com/problems/trapping-rain-water/ for pics.
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {

        int left_max = 0;              // Keeps track of the maximum height seen so far from the left
        int right_max = 0;             // Keeps track of the maximum height seen so far from the right
        int left = 0;                  // Pointer starting from the left of the array
        int right = height.size() - 1; // Pointer starting from the right of the array
        int water = 0;                 // Variable to accumulate the total trapped water

        // Loop until the two pointers meet - they will always meet at the highest point (coz we will be traversing the lower pointer always) and end up at the max
        while (left < right)
        {

            // Compare the heights at left and right pointers.. we only need the lower height (till there the water can be trapped)
            if (height[left] <= height[right])
            { // If the left bar is shorter or equal
                // If the current left bar is lower than the maximum height encountered from the left
                if (height[left] < left_max)
                {
                    // We have bigger height on left and we definitely know that we also have on right so water can be trapped
                    // add the difference between left_max and height[left]
                    water += left_max - height[left];
                }
                else
                {
                    // Otherwise update the max
                    // If the current height is greater or equal to left_max, update left_max
                    left_max = height[left];
                }
                // Move the left pointer to the right
                left++;
            }
            else
            { // If the right bar is shorter
                // If the current right bar is lower than the maximum height encountered from the right
                if (height[right] < right_max)
                {
                    // Water can be trapped, add the difference between right_max and height[right]
                    water += right_max - height[right];
                }
                else
                {
                    // If the current height is greater or equal to right_max, update right_max
                    right_max = height[right];
                }
                // Move the right pointer to the left
                right--;
            }
        }

        // Return the total trapped water
        return water;
    }
    // Time Complexity: O(n), where n is the length of the input array height.
    // Space Complexity: O(1), as we are using only a constant amount of extra space.
};
