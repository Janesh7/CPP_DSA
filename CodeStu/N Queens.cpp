// N Queens
// Hard 

// You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.
// A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints:
// 1 <= 'N' <= 10

// Time Limit: 1sec
// Sample Input 1:
// 4
// Sample Output 1:
// 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
// 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
// Explanation For Sample Input 1:
// Output depicts two possible configurations of the chessboard for 4 queens.

// The Chessboard matrix for the first configuration looks as follows:-

// 0 0 1 0
// 1 0 0 0
// 0 0 0 1
// 0 1 0 0

// Queen contained cell is depicted by 1. As seen, No queen is in the same row, column, or diagonal as the other queens. Hence this is a valid configuration.
// Sample Input 2:
// 3
// Sample Output2:
//       (Blank)
// Explanation For Sample Input 2:
// Since no possible configuration exists for 3 Queen's.The output remains Empty.


bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{

    int dup_row = row;

    int dup_col = col;

    // first case

    while (dup_col >= 0)
    {

        if (board[row][dup_col] == 1)
            return false;

        dup_col--;
    }

    // second case-->first diagonal;

    dup_col = col;

    dup_row = row;

    while (dup_col >= 0 && dup_row >= 0)
    {

        if (board[dup_row][dup_col] == 1)
            return false;

        dup_row--;

        dup_col--;
    }

    // third case-->second diagonal;

    dup_col = col;

    dup_row = row;

    while (dup_col >= 0 && dup_row < n)
    {

        if (board[dup_row][dup_col] == 1)
            return false;

        dup_row++;

        dup_col--;
    }

    return true;
}

void addBoard(vector<vector<int>> &board, vector<vector<int>> &res)
{

    vector<int> temp;

    int n = board.size();

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            temp.push_back(board[i][j]);
        }
    }

    res.push_back(temp);
}

void solve(int col, vector<vector<int>> &board,
           vector<vector<int>> &ans, int n)
{

    // base case;

    vector<int> temp;

    if (col == n)
    {

        addBoard(board, ans);

        return;
    }

    for (int row = 0; row < n; row++)
    {

        if (isSafe(row, col, board, n))
        {

            board[row][col] = 1;

            solve(col + 1, board, ans, n);

            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{

    // Write your code here.

    vector<vector<int>> ans;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(0, board, ans, n);

    return ans;
}
