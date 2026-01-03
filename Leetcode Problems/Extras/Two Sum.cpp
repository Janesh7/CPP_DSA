// 1. Two Sum
// Easy

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?



// Approac 1: Two pointer

//  Make a vector of pairs of int, first being the value and other being its index
//  Sort the vector
// Take a pointer at each end
// while loop until the pointers crosses or at the same int
// if the elements sum to target break
// else if the sum is less than increment from the small element's end
// else (if the sum is more) decrement from the large element's end
// return the original indexes (second part of pair) 


class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        int i = 0, j = nums.size() - 1;

        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++)
        {

            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        while (i < j)
        {

            if (v[i].first + v[j].first == target)
            {

                break;
            }

            else if (v[i].first + v[j].first < target)
            {

                i++;
            }

            else if (v[i].first + v[j].first > target)
            {

                j--;
            }
        }

        return {v[i].second, v[j].second};
    }
};



// Approach 2 OPTIMISED - hash map



// First loop saves the corresponding index and second loop to check if the 2nd number exists.
// Ofcourse we don't want to return {0,0} if target is 6 and nums={3,1,2}. So, checked for distinct index.

// Now for nums={3,1,3} and target=6, map stores 2 for key 3 i.e, m[3]=2. So, i=0 and m[target-nums[i]]=2.


class Solution
{

public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {

            int complement = target - nums[i];

            if (map.find(complement) != map.end())
            {

                return {map[complement], i};
            }

            map[nums[i]] = i;
        }

        return {-1, -1}; // or return {};
    }
};