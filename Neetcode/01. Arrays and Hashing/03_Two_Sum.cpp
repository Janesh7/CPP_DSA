// 1. Two Sum

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

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility> // for std::pair

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        int i = 0, j = nums.size() - 1;

        // Create a vector of pairs to store the original indices
        // along with the values from the nums array
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
    // time complexity: O(nlogn) for sorting + O(n) for the two-pointer approach = O(nlogn)
    // space complexity: O(n) for storing the pairs in the vector
};

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Create a hash map to store the indices of the numbers
        // The key is the number itself, and the value is its index
        unordered_map<int, int> num_map;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            // Check if the complement exists in the map
            // If it does, return the indices of the current number and its complement
            if (num_map.count(complement))
            {
                return {num_map[complement], i};
            }
            // Store the index of the current number in the map
            // The number itself is the key, and the index is the value
            num_map[nums[i]] = i;
        }

        return {};
    }
    // time complexity: O(n) for the single pass through the array
    // space complexity: O(n) for storing the indices in the hash map
};
