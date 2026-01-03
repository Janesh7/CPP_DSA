// 59. Spiral Matrix II
// Medium


// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

// Example 1:


// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 0,total=n*n;
        int x = 1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = n-1;
        int endingCol = n-1;
        while(count < total) {
    
            //add starting row ------> right
            for(int index = startingCol; count < total && index<=endingCol; index++) {
                ans[startingRow][index]=x++;
                count++;
            }
            startingRow++;
            
            //add ending column  || down
            for(int index = startingRow; count < total && index<=endingRow; index++) {
                ans[index][endingCol]=x++;
                count++;
            }
            endingCol--;
            
            //add ending row   <------- left 
            for(int index = endingCol; count < total && index>=startingCol; index--) {
                ans[endingRow][index]=x++;
                count++;
            }
            endingRow--;
            
            //add starting column ^ ^ up
            for(int index = endingRow; count < total && index>=startingRow; index--) {
                ans[index][startingCol]=x++;
                count++;
            }
            startingCol++;
        } 
        return ans;
        
    }
};