// 51. N-Queens
// Hard


// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9


// OPTIMIZED SOLUTION - using Backtracking & hashmap
/*
TC : O(n!)
SC : O(n*n) = O(n^2)
*/
class Solution {
    void solve(int col, vector<string> &board, int n, vector<int> &leftrow, vector<int> &lowerdiagonal, vector<int> &upperdiagonal, vector<vector<string>> &ans){ // TC: O(n*(n-1)*(n-2)*(n-3)...) = O(n!)
        // base case
        if(col == n){
            ans.push_back(board);
            return;
        }

        // solve 1 case and rest recurssion will take care
        for(int row=0; row<n; row++){
            if(leftrow[row] == 0 && lowerdiagonal[row+col] == 0 && upperdiagonal[n-1+col-row] == 0){ // isSafe func() --> TC: O(1)
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerdiagonal[row+col] = 1;
                upperdiagonal[n-1+col-row] = 1;
                solve(col+1, board, n, leftrow, lowerdiagonal, upperdiagonal, ans);
                // backtracking
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerdiagonal[row+col] = 0;
                upperdiagonal[n-1+col-row] = 0;
            }
        }
    }

    public:
    vector<vector<string>> solveNQueens(int n) {
        // write your code here

        vector<string> board(n, string(n, '.')); // SC: O(n*n)
        vector<vector<string>> ans; // SC: O(n*n*n)
        
        vector<int> leftrow(n, 0); // SC: O(n)
        vector<int> lowerdiagonal(2*n-1, 0); // SC: O(n)
        vector<int> upperdiagonal(2*n-1, 0); // SC: O(n)
        
        solve(0, board, n, leftrow, lowerdiagonal, upperdiagonal, ans);
        
        return ans;
    }
};