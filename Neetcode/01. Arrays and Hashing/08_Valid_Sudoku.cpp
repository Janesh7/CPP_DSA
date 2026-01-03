// 36. Valid Sudoku

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

// Example 1:

// Input: board =
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board =
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit 1-9 or '.'.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {

                if (board[r][c] == '.')
                {
                    continue;
                }

                char digit = board[r][c];
                int box_idx = (r / 3) * 3 + (c / 3);

                /*
                c / 3 divides the 9 columns into three group indices: 0, 1, 2.
                So now the column index determines the block index in modulo 3.
                To convert it into the correct block index, row-based index also
                needs to be added. r / 3 does the same what c / 3 does;
                only the quotient. To give correct block index, this is
                multiplied by 3 to get the row addition.

                .e.g. for row 3 (index = 2) and column 3 (index = 2),
                block should be 1 (index = 0), which is correct.

                for row 4 (index = 3) and column 3 (index = 2), block should be 4
                (index = 3), which is correct.

                You can see that the int is incremented by 3 when going down,
                and incremented by 1 when going to the right.

                So (r / 3) * 3 - is for going down
                   (c / 3) * 1 - is for going to the right.
                */

                if (row[r].count(digit) || col[c].count(digit) || box[box_idx].count(digit))
                {
                    return false;
                }

                row[r].insert(digit);
                col[c].insert(digit);
                box[box_idx].insert(digit);
            }
        }

        return true;
    }
    // time complexity: O(1) - since the board is always 9x9, the time complexity is constant.
    // space complexity: O(1) - since the board is always 9x9, the space complexity is constant.
};

// Optimized Approach: Using Bitmasking
/* Instead of using hash sets to track which numbers have appeared in rows, columns, and boxes, we can use a bitmask (integer) to store this information. Each bit in the bitmask represents a number from 1 to 9. By turning bits on and off, we can track whether a number has been seen or not.

For example:

The number 1 will be represented by 1 << 0 (i.e., 000000001).
The number 2 will be represented by 1 << 1 (i.e., 000000010).
We perform bitwise operations to quickly check and set bits.
*/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rows[9] = {0}, columns[9] = {0}, boxes[9] = {0};

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '1'; // Convert '1'-'9' to 0-8
                int mask = 1 << num;         // Create bitmask for the number
                int boxIndex = (i / 3) * 3 + j / 3;

                // Check if the number is already set in the row, column, or box
                if (rows[i] & mask || columns[j] & mask || boxes[boxIndex] & mask)
                {
                    return false;
                }

                // Mark the number in the row, column, and box
                rows[i] |= mask;
                columns[j] |= mask;
                boxes[boxIndex] |= mask;
            }
        }
        return true;
    }
    // time complexity: O(1) - since the board is always 9x9, the time complexity is constant.
    // space complexity: O(1) - since the board is always 9x9, the space complexity is constant.
};