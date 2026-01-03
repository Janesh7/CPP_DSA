// 1232. Check If It Is a Straight Line
// Easy
// 2K
// 217
// Companies
// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

// Example 1:



// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true
// Example 2:



// Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
// Output: false



// Intuition
// To determine if a set of coordinates forms a straight line, we need to check if the slopes between consecutive points are equal. If the slopes are equal, it indicates that all the points lie on the same line. We can use this property to solve the problem.

// Approach
// Take the first two points from the given coordinates and store their coordinates as (x1, y1) and (x2, y2) respectively. These two points will serve as reference points for slope comparison.

// Iterate through the remaining points starting from the third point.

// For each point (x, y) in the iteration:

// Calculate the left-hand side of the equation: (y - y1) * (x2 - x1)
// Calculate the right-hand side of the equation: (y2 - y1) * (x - x1)
// Compare the left-hand side and right-hand side of the equation. If they are not equal, return false immediately, as the points do not form a straight line.
// If the loop completes without returning false, return true, indicating that all the points form a straight line.

// By comparing the products of differences (instead of directly dividing), we can avoid the risk of division by zero error. This is important because directly dividing by (x2 - x1) can lead to an error when the points are vertically aligned.

// Using this approach, we can efficiently determine whether a set of coordinates forms a straight line or not.

// Complexity
// Time complexity:
// O(n)
// where n is the number of coordinates in the input vector. This is because the code iterates through the coordinates once, comparing the slopes for each point.

// Space complexity:
// O(1)
// The code uses a fixed amount of extra space to store the variables for the reference points (x1, y1) and (x2, y2), as well as the loop iterator variables.

// Code


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();

        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];

        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        for(int i = 2; i < n; i++){
            int x = coordinates[i][0];
            int y = coordinates[i][1];

            // y - y1 / x - x1 != y - y2 / x - x2
            // Division may cause division by zero error.

            if((y - y1) * (x - x2) != (y - y2) * (x - x1)){
                return false;
            } 
        }
        return true;
    }
};