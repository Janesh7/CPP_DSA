// 37. Sudoku Solver
// Hard
// 8.8K
// 223
// Companies
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

 

// Example 1:


// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:


 

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.


class Solution
{
public:
    bool isFeasible(vector<vector<char>> &board, int row, int col, char key)
    {
        // Check for row
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == key)
                return false;
            // Check for col
            if (board[i][col] == key)
                return false;

            // check for 3x3 matrix
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == key)
                return false;
        }
        return true;
    }
    bool solver(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
            for (int col = 0; col < 9; col++)
                if (board[row][col] == '.')
                {
                    for (int i = 1; i <= 9; i++)
                    {
                        char t = '0' + i;
                        if (isFeasible(board, row, col, t))
                        {
                            board[row][col] = t;
                            bool ans = solver(board);
                            if (ans)
                                return true;
                            else
                                board[row][col] = '.';
                        }
                    }
                    return false;
                }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        bool ans = solver(board);
    }
};