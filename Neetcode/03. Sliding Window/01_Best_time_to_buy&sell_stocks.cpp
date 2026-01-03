// 121. Best Time to Buy and Sell Stock

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // Initialize the least value to the maximum possible integer value
        // This will help in finding the minimum price to buy the stock
        int least_val = INT_MAX;
        int todays_profit = 0;
        int max_profit = 0;

        for (const int &i : prices)
        {
            // Update the least value if the current price is less than the least value
            // This means we have found a new minimum price to buy the stock which will help us maximize profit
            if (i < least_val)
            {
                least_val = i;
            }

            todays_profit = i - least_val;

            if (todays_profit > max_profit)
            {
                max_profit = todays_profit;
            }
        }

        return max_profit;
    }
    // Time Complexity: O(n), where n is the number of days (length of prices array)
    // Space Complexity: O(1), as we are using only a constant amount of space for variables
};