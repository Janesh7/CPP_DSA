// 1351. Count Negative Numbers in a Sorted Matrix
// Easy
// 4.2K
// 110
// Companies
// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

// Example 1:

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:

// Input: grid = [[3,2],[1,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// -100 <= grid[i][j] <= 100
 

// Follow up: Could you find an O(n + m) solution?

// Approach :

// We have to given that Both Row And Column are in Sorted in descending Order
// j=grid[0].size()-1 ------> column pointer
// i=0 ----------> row pointer
// So Basically We Start Iterating With Last element of Row and goes to the first Element of Row
// if Any Element Found -ve then then It ensure that all elements below the Current column are Negative ( b/c sorted in descending order )
// then we add Negative Count = Total Row - current Row ( we add All -ve element in the current column )
// And then decrease the Column Pointer ( j--) and
// if Element are Positive increase the Row pointer ( i++ )
// continue this step See the code for Better Explanation :
// Complexity
// Time complexity:-->O(m+n)
// Space complexity: ----> O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       int i=0;
       int j=grid[0].size()-1;
       int count=0;
       while(i<grid.size()&&j>=0)
       {
           if(grid[i][j]<0)
           {
               count+=(grid.size()-i); // add Negative Count = Total Row - current Row
               j--; //decrease the Column Pointer ( j--)
           }
           else if(grid[i][j]>=0)
           {
               i++; // increase the Row pointer ( i++ )
           }
       }
       return count;
    }
};