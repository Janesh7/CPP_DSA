// 239. Sliding Window Maximum
// Hard

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length

// ------------------------------------------------------

// Intuition and Approach
// 1. Sliding Window Mechanism: The sliding window moves from the beginning to the end of the array, one element at a time. For each position of the window, we need to determine the maximum element within that window.

// 2. Deque as a Double-ended Queue: The deque helps in maintaining the indices of the elements of the current window in a way that the front of the deque always contains the index of the maximum element for that window.

// 3. Maintaining the Deque:

// We maintain the indices in the deque in such a way that their corresponding values in nums are in decreasing order.
// When moving the window, remove indices that are out of the bounds of the current window from the front of the deque.
// Before adding a new element's index to the deque, remove all indices from the back of the deque whose corresponding values in nums are less than the current element (as they cannot be the maximum for any future windows that include the current element).


// Steps in the Algorithm
// 1. Initialize Data Structures:

// - A deque dq to store indices.
// - A vector ans to store the results (maximums of each window).

// 2. Iterate Through the Array:

// - For each element nums[i]:
//      . Remove the index at the front of the deque if it is out of the current window (i.e., i - k).
//      . Remove indices from the back of the deque while the corresponding elements in nums are less than nums[i].
//      . Add the current index i to the deque.
//      . Once the first window is formed (i.e., i >= k - 1), add the front element of the deque (which is the maximum for the current window) to the result vector ans.


// Complexity Analysis
// Time Complexity: The overall time complexity is (O(n)), where (n) is the length of the array nums. Each element is processed (added to and removed from the deque) at most once.
// Space Complexity: The space complexity is (O(k)) for the deque, which stores at most (k) indices at any time.
// Here's the function with added comments for clarity:

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // Deque to store indices of useful elements
        deque<int> dq;
        // Vector to store results
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            // Remove indices out of the current window from the front
            if (!dq.empty() && dq.front() == (i - k))
            {
                dq.pop_front();
            }
            // Remove elements from the back while they are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            // Add current element's index to the deque
            dq.push_back(i);
            // Once the first window is formed, add the maximum (front of deque) to the result
            if (i >= (k - 1))
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};