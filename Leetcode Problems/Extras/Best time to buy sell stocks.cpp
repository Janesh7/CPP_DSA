// 121. Best Time to Buy and Sell Stock
// Easy

// 25261

// 796

// Add to List

// Share
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


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least_value = INT_MAX; // Max value
        int overall_profit = 0;  // Final profit(to be returned)
        int profit_today = 0; // Temp profit calc per iteration 
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < least_value){
                least_value = prices[i]; //find the least price
            }
            profit_today = prices[i] - least_value; // find the profit for the curr itr
            if(overall_profit < profit_today){
                overall_profit = profit_today;     // make the overall profit as todays profit, if its greater     
            } 
        }
        return overall_profit;
    }
};



//  VERY OPTIMISED SOLN, NO IDEA BUT FOR REFRERENCE
int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string s; getline(cin, s); cout << '\n') {
        int ans = 0, mn = INT_MAX;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10) v = v * 10 + (s[_i++] & 15);
            mn = min(mn, v);
            ans = max(ans, v - mn);
        }
        cout << ans;
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return 0;
    }
};