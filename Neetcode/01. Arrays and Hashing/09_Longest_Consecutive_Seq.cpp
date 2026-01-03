// 128. Longest Consecutive Sequence

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
// Example 3:

// Input: nums = [1,0,1,2]
// Output: 3

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        int n = nums.size();

        if (n < 2)
        {
            return n;
        }

        // create a set from nums
        unordered_set<int> ints(nums.begin(), nums.end());

        int cur_max_seq = 0;

        for (int num : ints)
        {

            // find the least num of the seq
            // if a int just lesser than the current num exist constinue
            if (ints.find(num - 1) != ints.end())
            {
                continue;
            }

            // found start of the seq
            int seq = 1;

            while (ints.find(++num) != ints.end())
            { // find next num in set
                seq++;
            }

            // update the max
            cur_max_seq = max(cur_max_seq, seq);
        }

        return cur_max_seq;
    }
    // time complexity: O(n) as we are iterating through the set and each number is checked at most twice (once when checking for the start of a sequence and once when counting the length of the sequence).
    // space complexity: O(n) - for the set
};