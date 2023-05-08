// 1572. Matrix Diagonal Sum
// Easy


// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

// Example 1:


// Input: mat = [[1,2,3],
//               [4,5,6],
//               [7,8,9]]
// Output: 25
// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
// Notice that element mat[1][1] = 5 is counted only once.
// Example 2:

// Input: mat = [[1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1]]
// Output: 8
// Example 3:

// Input: mat = [[5]]
// Output: 5
 

// Constraints:

// n == mat.length == mat[i].length
// 1 <= n <= 100
// 1 <= mat[i][j] <= 100





// My soln

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int pi=0,pj=0;
        int si=0;
        int sj=mat[0].size()-1;
        int sum = 0;
        while (pi<mat[0].size()) {
            if (pi==si && pj==sj) {
                sum += mat[pi++][pj++];
                si++;
                sj--;
                continue;
            }
            sum += mat[pi++][pj++];
            sum += mat[si++][sj--];
        }
        return sum;
    }
};


// Discuss section ans, same

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            // primary diagonal
            sum += mat[i][i]; 
            // neglect the central element
            if (i != n - i - 1) { 
                // secondary diagonal
                sum += mat[i][n - i - 1]; 
            }
        }
        return sum;
    }
};