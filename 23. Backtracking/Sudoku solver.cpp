#include <bits/stdc++.h>

bool isSafe(int k, vector<vector<int>> &sudoku, int row, int col) {

  for (int i = 0; i < 9; i++) {

    // check in column

    if (sudoku[i][col] == k)
      return false;

    // check in the row

    if (sudoku[row][i] == k)
      return false;

    // check in matrix (3x3)

    if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k)
      return false;
  }

  return true;
}

bool solve(vector<vector<int>> &sudoku) {

  for (int i = 0; i < 9; i++) {

    for (int j = 0; j < 9; j++) {

      if (sudoku[i][j] == 0) {

        for (int k = 1; k <= 9; k++) {

          if (isSafe(k, sudoku, i, j)) {

            sudoku[i][j] = k;

            bool possible = solve(sudoku);

            if (possible) {

              return true;

            } else {

              sudoku[i][j] = 0;
            }
          }
        }

        return false;
      }
    }
  }

  return true;
}

void solveSudoku(vector<vector<int>> &sudoku) { bool ans = solve(sudoku); }