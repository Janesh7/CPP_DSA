// 875. Koko Eating Bananas

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
 

// Constraints:

// 1 <= piles.length <= 104
// piles.length <= h <= 109
// 1 <= piles[i] <= 109

#include <iostream>
#include <vector>
#include <algorithm> // for max_element
using namespace std;

// Brute force

// piles = [3,6,7,11], h = 8
// k = 1 to 11 bananas per hours

// k = 1,
// 3/1 + 6/1 + 7/1 + 11/1 = 3 + 6 + 7 + 11 = 27hrs > 8 hrs = Not enough time

// k = 2,
// 3/2 + 6/2 + 7/2 + 11/2 = 2 + 3 + 4 + 6 = 15 hrs > 8 hrs = Not enough time

// k = 3,
// 3/3 + 6/3 + 7/3 + 11/3 = 1+ 2+ 3 + 4 = 10hrs > 8 hrs = Not enough time

// k = 4,
// 3/4 + 6/4 + 7/4 + 11/4 = 1 + 2 + 2 + 3 = 8hrs = GOOD

// k = 5,
// 3/5 + 6/5 + 7/5 + 11/5 = 1 + 2 + 2 + 3 = 8hrs = GOOD, but not the minimum k

// k = 6,
// 3/6 + 6/6 + 7/6 + 11/6 = 1 + 1 + 2 + 2 = 4hrs = GOOD, but not the minimum k
// .
// .
// .
// So the answer is k=4 .
// The brute force solution is O(m*n) time complexity, where n is the number of piles. This is not efficient for large inputs.

// Binary Search
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {

        // l is the minimum speed and r is the maximum speed
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        // *max_element(piles.begin(), piles.end()) is the maximum speed because if k is greater than the maximum pile, then we can eat all the bananas in 1 hour.
        int ans = r;

        // Binary search to find the minimum speed
        // l <= r because we need to check the last element as well
        while (l <= r)
        {

            // mid is the speed we are checking
            int mid = l + (r - l) / 2;

            double time_taken = 0;
            for (int &i : piles)
            {

                // time taken to eat the bananas in the pile i with speed mid
                // (i + mid - 1) / mid is the same as ceil(i / mid)
                // For any two integers a and b:

                // ceil((double)a / b) == (a + b - 1) / b
                // This is a classic trick in integer math to simulate ceiling division.

                // a / b normally truncates toward zero.

                // To force a "round up", we artificially inflate a by (b - 1) before dividing.
                time_taken += (i + mid - 1) / mid;
            }

            // If the time taken is less than or equal to h, then we can eat all the bananas in h hours with speed mid
            if (time_taken <= h)
            {

                // We can try to find a smaller speed, so we move the right pointer to mid - 1
                // and store the answer as mid
                ans = mid;
                r = mid - 1;
            }
            else
            {

                //  If the time taken is greater than h, then we need to increase the speed
                // so we move the left pointer to mid + 1
                l = mid + 1;
            }
        }

        return ans;
    }
    // Time complexity: O(nlogm) where n is the number of piles and m is the maximum pile size.
    // Space complexity: O(1) because we are using only a few extra variables.
};