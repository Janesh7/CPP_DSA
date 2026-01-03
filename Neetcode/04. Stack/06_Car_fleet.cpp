// 853. Car Fleet

// There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

// You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

// A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

// A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

// If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

// Return the number of car fleets that will arrive at the destination.

// Example 1:

// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

// Output: 3

// Explanation:

// The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
// The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
// The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
// Example 2:

// Input: target = 10, position = [3], speed = [3]

// Output: 1

// Explanation:

// There is only one car, hence there is only one fleet.
// Example 3:

// Input: target = 100, position = [0,2,4], speed = [4,2,1]

// Output: 1

// Explanation:

// The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
// Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.

// Constraints:

// n == position.length == speed.length
// 1 <= n <= 105
// 0 < target <= 106
// 0 <= position[i] < target
// All the values of position are unique.
// 0 < speed[i] <= 106

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
// Approach 1 - Stack

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {

        int n = speed.size();
        // pair<position, time taken to reach target>
        // time = (target - position) / speed
        vector<pair<int, float>> arr(n);
        stack<float> st;

        for (int i = 0; i < n; i++)
        {
            // Imp to note that we are using float for the subtrtaction answer to make one of the operand as a float. One of my wrong submission had (float) ((target - position[i]) / speed[i]) which was making the whole expression as a float and not giving the correct answer.
            // This is because the int / int division will give the answer as an int and not a float. So, we need to make one of the operand as a float to get the correct answer.
            arr[i] = {position[i], float(target - position[i]) / speed[i]};
        }

        // Sort the array based on the position of the car. This is because we need to check if the car at position[i] will catch up to the car at position[j] or not. If it does, then we need to pop the car at position[j] from the stack and push the car at position[i] into the stack.
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {

            // If the stack is empty, then we need to push the car at position[i] into the stack.
            // If the stack is not empty, then we need to check if the car at position[i] will catch up to the car at position[j] or not.
            // while is used ibstead of if because we need to check for all the cars in the stack and not just the top car.
            // If the car at position[i] will catch up to the car at position[j], then we need to pop the car at position[j] from the stack and push the car at position[i] into the stack.
            // if we had iterated from n-1 to 0, then we would have used the if condition instead of the while condition because we would have been checking the top car in the stack and not all the cars in the stack.
            while (!st.empty() && arr[i].second >= st.top())
            {
                st.pop();
            }

            st.push(arr[i].second);
        }

        return st.size();
    }
};
// Time Complexity: O(nlogn) - for sorting the array
// Space Complexity: O(n) - for the stack and the array

// Approach 2 - Without stack, local max var
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {

        int n = speed.size();
        vector<pair<int, float>> arr(n);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            arr[i] = {position[i], float(target - position[i]) / speed[i]};
        }

        sort(arr.begin(), arr.end());
        // We can remove the stack and use a local max variable to keep track of the maximum time taken to reach the target. If the time taken to reach the target for the car at position[i] is greater than the local max variable, then we need to increment the ans variable and update the local max variable.
        // This is because the car at position[i] will catch up to the car at position[j] if the time taken to reach the target for the car at position[i] is greater than the time taken to reach the target for the car at position[j].
        float local_max = -1;


        for (int i = n - 1; i >= 0; i--)
        {

            // If the car at position[i] will catch up to the car at position[j], then we need to increment the ans variable and update the local_max variable.
            if (arr[i].second > local_max)
            {
                ans++;
                local_max = arr[i].second;
            }
        }

        return ans;
    }
};
// Time Complexity: O(nlogn) - for sorting the array
// Space Complexity: O (n) - for the array