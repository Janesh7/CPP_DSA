// Rat In a Maze All Paths
// Medium

// You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).
// Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter into those cells and those with value 1 are open.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Input Format:
// The first line of input contains an integer 'N' representing the dimension of the maze.

// The next 'N' lines of input contain 'N' space-separated integers representing the type of the cell.
// Output Format :
// For each test case, return the path from the start position to the destination position and only cells that are part of the solution path should be 1, rest all cells should be 0.

// Output for every test case will be printed in a separate line.
// Note:
// You do not need to print anything, it has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= N <= 10
// 0 <= MAZE[i][j] <=1

// Where 'MAZE[i][j]' denotes the value in the cell of 'MAZE'.

// Time Limit: 1 sec
// Sample Input 1 :
// 3
// 1 0 1
// 1 0 1
// 1 1 1
// Sample Output 1 :
// 1 0 0 1 0 0 1 1 1 

// basically the visited matrix
// 1 0 0
// 1 0 0
// 1 1 1

// Explanation For Sample Output 1:
// Only 1 path is possible which contains coordinate < (1,1), (2,1), (3,1), (3,2) and (3,3) >

// So our path matrix will look like this:

// 1 0 0
// 1 0 0
// 1 1 1

// Which is returned from left to right and then top to bottom in one line.
// Sample Input 2 :
// 2
// 1 0
// 0 1
// Sample Output 2 :
//  [Blank]
// Explanation For Sample Output 2:
// As no path is possible to the last cell, a blank vector will be returned and nothing is printed.

#include <bits/stdc++.h>

bool isSafe(int x, int y, int n, vector<vector<int>> visited,
            vector<vector<int>> &maze)
{

    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 &&
        maze[x][y] == 1)

        return true;

    else

        return false;
}

void solve(vector<vector<int>> &maze, int n, vector<vector<int>> &ans, int x,
           int y, vector<vector<int>> visited)
{

    // base case

    if (x == n - 1 && y == n - 1)
    {

        vector<int> temp;

        visited[x][y] = 1;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)

                temp.push_back(visited[i][j]);
        }

        visited[x][y] = 0;

        ans.push_back(temp);

        return;
    }

    visited[x][y] = 1;

    // 4 choices - DOWN, LEFT, RIGHT, UP

    // down

    int newx = x + 1;

    int newy = y;

    if (isSafe(newx, newy, n, visited, maze))

        solve(maze, n, ans, newx, newy, visited);

    // left

    newx = x;

    newy = y - 1;

    if (isSafe(newx, newy, n, visited, maze))

        solve(maze, n, ans, newx, newy, visited);

    // right

    newx = x;

    newy = y + 1;

    if (isSafe(newx, newy, n, visited, maze))

        solve(maze, n, ans, newx, newy, visited);

    // up

    newx = x - 1;

    newy = y;

    if (isSafe(newx, newy, n, visited, maze))

        solve(maze, n, ans, newx, newy, visited);

    visited[x][y] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{

    vector<vector<int>> ans;

    if (maze[0][0] == 0)

        return ans;

    int srcx = 0;

    int srcy = 0;

    vector<vector<int>> visited = maze;

    // initialise with 0

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)

            visited[i][j] = 0;
    }

    solve(maze, n, ans, srcx, srcy, visited);

    return ans;
}