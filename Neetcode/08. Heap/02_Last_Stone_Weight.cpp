// 1046. Last Stone Weight

// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0.

 

// Example 1:

// Input: stones = [2,7,4,1,8,1]
// Output: 1
// Explanation: 
// We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
// we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
// we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
// we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
// Example 2:

// Input: stones = [1]
// Output: 1
 

// Constraints:

// 1 <= stones.length <= 30
// 1 <= stones[i] <= 1000


#include <vector>
#include <queue>
using namespace std;

class Solution
{
/*
We're not using sort() followed by repeated pop_back() and push_back() operations, because the its not maintaining sorted order after each operation. The new stone weight after smashing two stones together may not be the largest or smallest, hence we need a data structure that allows us to efficiently retrieve and remove the largest elements. A max-heap (priority queue) is ideal for this purpose.
*/
public:
    int lastStoneWeight(vector<int> &stones)
    {
        // Create a max-heap (priority queue) to store the stones
        // The priority queue will automatically sort the stones in descending order
        priority_queue<int> pq(stones.begin(), stones.end()); // time complexity: O(n log n)

        // While there are more than one stone left
        // We keep smashing the two heaviest stones together
        // time complexity: O(n log n) for this loop is O(n log n) in the worst case
        while (pq.size() > 1)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            // If the two stones are not equal, push the difference back into the heap
            // If they are equal, both stones are destroyed and nothing is pushed back
            if (first != second)
            {
                pq.push(first - second);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
    // time complexity: O(n log n) where n is the number of stones
    // space complexity: O(n) for the priority queue to store the stones
};