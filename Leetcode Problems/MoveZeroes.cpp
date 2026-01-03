
// 283. Move Zeroes


// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]
 

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int NonZero =0; // Means the non zero value should come to this index
        for (int j = 0; j<nums.size();j++)
        {
            if (nums[j] != 0) { // FInd a non zero element
                swap(nums[j],nums[NonZero]); // Swap to the pos in Non Zero
                NonZero++; // Increment the non zero element
            }
        }
    }
};