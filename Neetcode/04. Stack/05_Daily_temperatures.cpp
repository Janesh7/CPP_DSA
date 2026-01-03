// 739. Daily Temperatures

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

// Approach 1 - Brute Force

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            int count = 1;
            int j = i + 1;
            while (j < n)
            {
                if (temperatures[j] > temperatures[i])
                {
                    break;
                }
                j++;
                count++;
            }
            count = (j == n) ? 0 : count;
            res[i] = count;
        }
        return res;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Approach 2 - Stack

// We can use a stack to keep track of the indices of the temperatures. We will iterate through the temperatures array and for each temperature, we will check if it is greater than the temperature at the index stored at the top of the stack. If it is, we pop the index from the stack and calculate the difference between the current index and the popped index. We will continue this process until we find a temperature that is greater than the current temperature or until the stack is empty. Finally, we will push the current index onto the stack.

// Monotonic Stack is a stack that is either increasing or decreasing. In this case, we will use a decreasing stack to keep track of the indices of the temperatures. The top of the stack will always be the index of the temperature that is greater than the current temperature.
// This way, we can find the next greater temperature for each temperature in O(n) time.

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // Create a stack to store the indices of the temperatures - these are the temps whose next greater elements we are looking for
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);

        // Iterate through the temperatures array
        for (int i = 0; i < n; i++)
        {
            // While the stack is not empty and the current temperature is greater than the temperature at the index stored at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                // we found the next greater temperature for the index stored at the top of the stack
                // Calculate the difference between the current index and the popped index and thats our answer for that index
                ans[st.top()] = i - st.top();
                st.pop();
            }
            // Push the current index onto the stack
            // This index is a candidate for the next greater temperature for future temperatures
            st.push(i);
        }

        return ans;
    }
};
// time complexity: O(n) - each index is pushed and popped from the stack at most once
// space complexity: O(n) - in the worst case, all indices are stored in the stack (if the temperatures are in increasing order)