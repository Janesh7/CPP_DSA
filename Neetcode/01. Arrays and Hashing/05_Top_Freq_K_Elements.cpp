// 347. Top K Frequent Elements

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// Approach: HashMap + Priority Queue (Heap)
class Solution
{

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        // Create a hash map to store the frequency of each number
        unordered_map<int, int> map;

        for (int num : nums)
        {

            // Increment the frequency of the number in the hash map
            map[num]++;
        }

        vector<int> res;

        // pair<first, second>: first is frequency,  second is number
        // Create a max heap (priority queue) to store the pairs of frequency and number
        // The priority queue will automatically sort the pairs based on frequency in descending order
        priority_queue<pair<int, int>> pq;

        for (auto it = map.begin(); it != map.end(); it++)
        {

            pq.push(make_pair(it->second, it->first));

            // If the size of the priority queue exceeds k, remove the top element (least frequent)
            if (pq.size() > (int)map.size() - k)
            {

                res.push_back(pq.top().second);

                pq.pop();
            }
        }

        return res;
    }
    // time complexity: O(n log k) where n is the size of the input array and k is the number of unique elements in the array.
    // space complexity: O(n) for the hash map and the priority queue
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> ans;

        // count freq
        for (const int &x : nums)
        {

            map[x]++;
        }

        vector<vector<int>> arr(n + 1); // Max size can be all the nums were same so its index n + 1

        // Create freq buckets and add the values to them
        for (const auto &[val, freq] : map)
        {

            arr[freq].push_back(val); // Different vals can have same freq hence a vector
        }

        // Start from last ie the greatest freq
        for (int i = n; i > 0; i--)
        {

            for (const int &x : arr[i])
            { // go through the freq vals

                if (ans.size() == k)
                { // Add em till the size of the ans is k
                    return ans;
                }

                ans.push_back(x);
            }
        }
        return ans;
    }
    // time complexity: O(n) where n is the size of the input array.
    // space complexity: O(n) for the hash map and the freq buckets
};