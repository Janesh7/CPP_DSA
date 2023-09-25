# Lec 1

## Backtracking

Backtracking is a general algorithmic technique that is used to solve problems by incrementally building a solution and, if the current solution cannot be completed or is incorrect, it backs up and tries a different approach. It is particularly useful for solving problems where the solution is a sequence of choices, and making a choice at each step affects the choices available at subsequent steps.

The key components of backtracking are:

1. **Decision Space:** The problem is divided into a set of decisions that need to be made. Each decision can have multiple choices.

2. **Recursion:** Backtracking uses recursive functions to explore all possible choices at each decision point.

3. **Choice:** At each decision point, a choice is made from the available options.

4. **Backtrack:** If a choice leads to a dead-end or an invalid solution, the algorithm backtracks to the previous decision point and explores a different choice.

5. **Base Case:** A condition is defined that signals when a valid solution is found or when the algorithm should stop.

Now, let's apply the concept of backtracking to the "Rat in a Maze" problem.

## Rat in a Maze Problem

**Problem Statement:** Given a maze, represented as a 2D grid, where 0s represent open paths and 1s represent obstacles, find all possible paths for a rat to move from the top-left corner (start) to the bottom-right corner (finish). The rat can only move in four directions: down (D), left (L), right (R), and up (U).

**Output should be in sorted way .. that is why we move in D,L,R,U order .. which will give sorted output**
**A VISTED 2D ARRAY SHOULD BE MAINTED ..otherwise we could get stuck in a never endling loop .. like say we went from some position to D (down) and then we get a move say U (Up) .. now we will be in a endless loop as D->U->D->U and so on.**

**Algorithm:**
1. Initialize a 2D array `visited` to keep track of visited cells and set all values to 0 (unvisited).
2. Start from the top-left corner (0, 0).
3. Use backtracking to explore all possible paths:
   - Try moving down (D), left (L), right (R), and up (U) if it's a valid move.
   - Mark the current cell as visited (1) to avoid revisiting.
   - Recursively explore the chosen path.
   - If the current cell is the bottom-right corner (finish), add the path to the list of solutions.
   - Backtrack by resetting the current cell to unvisited (0).
4. Return the list of all possible paths.

**Pseudocode in C++ with Comments:**
```cpp
class Solution
{
private:

    // check if the next step can be taken by the rat
    bool isSafe(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited)
    {
        // Rat is inside the matrix and the next cell isnt visited and the rat can visit the next cell
        if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && m[x][y])
            return true;

        // Otherwise false
        return false;
    }
    void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
    {
        // base-case
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // Visited the current cell
        visited[x][y] = 1;

        // down

        if (isSafe(m, n, x + 1, y, visited))
        {
            path.push_back('D');
            solve(m, n, ans, x + 1, y, visited, path);
            path.pop_back();
        }

        // left

        if (isSafe(m, n, x, y - 1, visited))
        {
            path.push_back('L');
            solve(m, n, ans, x, y - 1, visited, path);
            path.pop_back();
        }

        // Right

        if (isSafe(m, n, x, y + 1, visited))
        {
            path.push_back('R');
            solve(m, n, ans, x, y + 1, visited, path);
            path.pop_back();
        }

        // Up

        if (isSafe(m, n, x - 1, y, visited))
        {
            path.push_back('U');
            solve(m, n, ans, x - 1, y, visited, path);
            path.pop_back();
        }

        // OR CONDENSE THE ABOVE STEPS USING FOR LOOP AND 2 ARRAYs

        // Define possible moves: down, left, right, up (sorted to get solutions in a sorted manner)
        // vector<int> dr = {1, 0, 0, -1};
        // vector<int> dc = {0, -1, 1, 0};
        // vector<char> direction = {'D', 'L', 'R', 'U'};

        // This will work as x+1,y+0 -> down .. x+0,y-1 -> Left , x+0,y+1 -> right , x-1,y+0 -> up

        // // Try all four directions
        // for (int i = 0; i < 4; i++) {
        //     int newRow = row + dr[i];
        //     int newCol = col + dc[i];

        //     // Check if the move is valid and the cell is not visited
        //     if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && maze[newRow][newCol] == 0 && visited[newRow][newCol] == 0) {
        //         visited[newRow][newCol] = 1; // Mark the cell as visited
        //         path.push_back(direction[i]); // Add the direction to the path
        //         backtrack(maze, newRow, newCol, n, m, visited, path, result);
        //         path.pop_back(); // Backtrack by removing the direction
        //         visited[newRow][newCol] = 0; // Mark the cell as unvisited (backtrack)
        //     }
        // }



        // Backtrack and make it not visited
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;

        // Matrix of visited by rat, initaily all 0's
        vector<vector<int>> visited(n, vector<int>(n, 0));
        // or use this code
        // for (int i = 0;i<n;i++)
        //     for (int j=0;j<n;j++)
        //         visited[i][j] = 0  when initialized with m, otherwise push_back(0);

        // start positions
        int srcx = 0, srcy = 0;
        string path = "";
        solve(m, n, ans, srcx, srcy, visited, path);
        // sort the answer for lexicographical order
        // sort(ans.begin(), ans.end());
        return ans;
    }
};
```

**Time Complexity (TC):** The time complexity is **O(4^(N*M))** ie we can go 4 ways in each cell.. we do that for each cell in a MxN matrix, where N is the number of rows and M is the number of columns in the maze. In the worst case, we explore all possible paths.

**Space Complexity (SC):** The space complexity is O(N*M) for the `visited` array and the call stack during recursion.


# Lec 2

## N Queens Problem

**Problem Statement:** The N-Queens puzzle asks you to place N chess queens on an N×N chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal.

**We add the queen column wise .. if all columns are filled .. then we add that to our soln.. we adding each queen in a column and check which row it can possibly belong to .. for that the three main condition should be fulfiled .. we have only 3 condition (instead of 8 possible ways of queen attacking) as we r adding column wise so we dont have to check for above(1 queen per clmn) .. we dont have to check down and right as we have started from top left itself .. so we just need to check left, left up and left down..** 

**Approach 1: Backtracking with Explicit Checks**
1. We use backtracking to solve the N Queens problem.
2. The conditions we need to check to ensure that queens are not attacking each other:
   - Only one queen in each row.
   - Only one queen in each column.
   - No two queens share the same diagonal (left-up to right-down and left-down to right-up).
3. We fill the chessboard left to right, one column at a time.
4. While filling a column, we need to check that there is no queen in the same row, left-up diagonal, and left-down diagonal.
5. If we find a valid position for a queen, we place it and recursively move on to the next column.
6. If at any point we cannot place a queen without violating the above conditions, we backtrack and try a different position.
7. We continue this process until we've successfully placed all N queens.
8. When a valid arrangement is found, we add it to the result.

```cpp
bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
    int dup_row = row;
    int dup_col = col;

    // Check column for a queen
    while (dup_col >= 0) {
        if (board[row][dup_col] == 1) return false;
        dup_col--;
    }

    // Check left-up diagonal
    dup_col = col;
    dup_row = row;
    while (dup_col >= 0 && dup_row >= 0) {
        if (board[dup_row][dup_col] == 1) return false;
        dup_row--;
        dup_col--;
    }

    // Check left-down diagonal
    dup_col = col;
    dup_row = row;
    while (dup_col >= 0 && dup_row < n) {
        if (board[dup_row][dup_col] == 1) return false;
        dup_row++;
        dup_col--;
    }

    return true;
}

void addBoard(vector<vector<int>>& board, vector<vector<int>>& res) {
    vector<int> temp;
    int n = board.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }

    res.push_back(temp);
}

void solve(int col, vector<vector<int>>& board, vector<vector<int>>& ans, int n) {
    if (col == n) {
        addBoard(board, ans);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, board, ans, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, board, ans, n);
    return ans;
}
```
See CodeStu submission

**Approach 2: Formula and Bitmasking for Efficient Checks**

The idea is not to check every element in the right and left diagonal, instead use the property of diagonals: 

**The sum of i and j is constant and unique for each right diagonal, where i is the row of elements and j is the column of elements.**

**The difference between i and j is constant and unique for each left diagonal, where i and j are row and column of element respectively.**

**SEE PDF FOR EZ UNDERSTANING**

1. This approach optimizes the checks by using bitmasks and hashmaps.
2. Instead of explicitly checking each row, column, and diagonal, we use bitmasks to keep track of the occupied rows, columns, left diagonals, and right diagonals.
3. We maintain four bitmasks (`rowMask`, `colMask`, `leftDiagonalMask`, `rightDiagonalMask`) to represent which rows, columns, and diagonals are occupied.
4. We use hashmaps to quickly check if a row, left diagonal, or right diagonal is occupied.
5. While placing queens in each column, we update the bitmasks and check if the current position is valid.
6. When a valid arrangement is found, we add it to the result.


In this approach, we optimize the checking of conditions by using formulas to determine if two queens are on the same row, column, or diagonals. We also use hash maps to keep track of which rows and diagonals are occupied.

1. **One Queen per Row:** We maintain a hash map that stores whether a row is occupied. While placing a queen in a row, we check if that row is occupied. If not, we mark it as occupied.

2. **One Queen per Column:** We maintain a boolean array that keeps track of whether a column is occupied. We directly check if a column is occupied before placing a queen.

3. **No Two Queens Attack Each Other:** We use two hash maps to track the diagonals. For the down diagonals, we use `row + col` as the key, and for the up diagonals, we use `(n - 1) + col - row` as the key. If a diagonal is already occupied, we skip placing a queen there.


Here is the source code in C++ with comments:

```cpp
// C++ program to solve N Queen Problem using backtracking

#include <bits/stdc++.h>
using namespace std;
#define N 4

// ld is an array where its indices indicate row-col+N-1
// (N-1) is for shifting the difference to store negative
// indices
int ld[30] = { 0 };

// rd is an array where its indices indicate row+col
// and used to check whether a queen can be placed on
// right diagonal or not
int rd[30] = { 0 };

// Column array where its indices indicates column and
// used to check whether a queen can be placed in that
// row or not*/
int cl[30] = { 0 };

// A utility function to print solution
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << " " << board[i][j] << " ";
		cout << endl;
	}
}

// A recursive utility function to solve N
// Queen problem
bool solveNQUtil(int board[N][N], int col)
{
	// Base case: If all queens are placed
	// then return true
	if (col >= N)
		return true;

	// Consider this column and try placing
	// this queen in all rows one by one
	for (int i = 0; i < N; i++) {
		
		// Check if the queen can be placed on
		// board[i][col]
		
		// To check if a queen can be placed on
		// board[row][col].We just need to check
		// ld[row-col+n-1] and rd[row+coln] where
		// ld and rd are for left and right
		// diagonal respectively
		if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1)
			&& cl[i] != 1) {
			
			// Place this queen in board[i][col]
			board[i][col] = 1;
			ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

			// Recur to place rest of the queens
			if (solveNQUtil(board, col + 1))
				return true;

			// If placing queen in board[i][col]
			// doesn't lead to a solution, then
			// remove queen from board[i][col]
			board[i][col] = 0; // BACKTRACK
			ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
		}
	}

	// If the queen cannot be placed in any row in
	// this column col then return false
	return false;
}

// This function solves the N Queen problem using
// Backtracking. It mainly uses solveNQUtil() to
// solve the problem. It returns false if queens
// cannot be placed, otherwise, return true and
// prints placement of queens in the form of 1s.
// Please note that there may be more than one
// solutions, this function prints one of the
// feasible solutions.
bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

// Driver program to test above function
int main()
{
	solveNQ();
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

```
See leetcode submission

**Time Complexity (Both Approaches):** O(N!) as **N*(N-1)*(N-2) and so on as we r going for each column**, where N is the size of the chessboard (number of rows/columns). In the worst case, we explore all possible permutations of queen placements.

**Space Complexity (Both Approaches):** O(N^2) due to the chessboard and O(N) for recursion stack.



# Lec 3

## Sudoku Solver for M Empty Cells

**Problem Statement**: Given a partially filled 9x9 Sudoku board and an integer M, determine if it is possible to fill the remaining M empty cells such that the Sudoku rules are satisfied.

### Approach Explanation

In this approach, we'll solve the Sudoku puzzle when M cells are empty by trying all possible values for the empty cells. We'll utilize backtracking to explore different configurations.

**Algorithm Steps**:

1. Start with a partially filled 9x9 Sudoku board.

2. Implement a helper function that checks whether a particular value can be placed in a given cell. This function will verify the following conditions:
   - Each 3x3 subgrid (box) must have unique values from 1 to 9.
           if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == k) return false;
           **SEE PDF FOR DRY RUN**

   - Each row must have unique values from 1 to 9.
           if(sudoku[row][i] == k) return false;

   - Each column must have unique values from 1 to 9.
           if(sudoku[i][col] == k) return false;


   // check in column


        // check in the row


        // check in matrix (3x3)


3. Find an empty cell (cell with a value of 0) and try all possible values from 1 to 9 to fill that cell.

4. Recursively move on to the next empty cell and continue the process.

5. If, at any point, a value cannot be placed in a cell without violating the Sudoku rules, backtrack to the previous cell and try the next value.

6. Continue this process until you fill all M empty cells or exhaust all possibilities.

7. Record the solution if it exists.


We start with this partially filled Sudoku board and try different values for empty cells to solve the puzzle.

**Complexity Analysis**:

- Time Complexity: **O(9^M)** - In the worst case, we try all possible values for the M empty cells.
- Space Complexity: O(1) - The space used is constant as we modify the given Sudoku board in place.

**Pseudocode**:

```cpp
bool isSafe(int board[9][9], int row, int col, int num) {
    // Check if 'num' is not already in current row, column, or 3x3 box.
    // Implement the conditions using mathematical formulas.
    // Return true if 'num' can be placed in (row, col); otherwise, false.
    for(int i=0; i<9; i++){

        // check in column

        if(sudoku[i][col] == k) return false;

        // check in the row

        if(sudoku[row][i] == k) return false;

        // check in matrix (3x3)

        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == k) return false;

    }

    return true;

}

bool solveSudoku(int board[9][9], int M) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                // Try all possible values from 1 to 9.
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        // Place 'num' in (row, col) if safe.
                        board[row][col] = num;
                        
                        // Recursively solve the next empty cell.
                        if (solveSudoku(board, M - 1)) {
                            return true;  // Solution found.
                        }
                        
                        // If placing 'num' didn't lead to a solution, backtrack.
                        board[row][col] = 0;
                    }
                }
                return false;  // No valid value for this cell.
            }
        }
    }
    return true;  // All empty cells filled; solution found.
}
```

This pseudocode outlines the recursive backtracking approach to solve Sudoku when M cells are empty. It ensures that the Sudoku rules are satisfied while trying different values for empty cells.