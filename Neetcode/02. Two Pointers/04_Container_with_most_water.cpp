// 11. Container With Most Water

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104

#include <iostream>
#include <vector>
using namespace std;

// The approach is to use two pointers, one at the beginning and one at the end of the array. We calculate the area formed by the lines at these two pointers and then move the pointer pointing to the shorter line towards the other pointer. This is because the area is limited by the shorter line, so moving it might give us a larger area.
// We repeat this process until the two pointers meet. The maximum area found during this process is the answer.
class Solution {
    public:
        int maxArea(vector<int>& height) {
    
            int left = 0;
            int right = height.size () - 1;
            int max_area = 0;
    
            while (left < right) {
                
                max_area = max (max_area, (right - left) * min (height[left], height[right]));
                
                if (height[left] < height[right]) {
    
                    left++;
    
                } else {
                    
                    right--;
                }
    
            }
            return max_area;
        }
        // Time Complexity: O(n), where n is the number of elements in the height array.
        // Space Complexity: O(1), as we are using only a constant amount of extra space.
};