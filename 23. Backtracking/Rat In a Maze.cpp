// GFG - Rat in a Maze Problem - I
// Medium Accuracy: 35.75% Submissions: 175K+ Points: 4

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1},
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at
// (3, 3) from (0, 0) by two paths - DRDDRR
// and DDRDRR, when printed in sorted order
// we get DDRDRR DRDDRR.
// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is
// blocked.
// Your Task:
// You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order.
// Note: In case of no path, return an empty list. The driver will output "-1" automatically.

// Expected Time Complexity: O((3N^2)).
// Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

// Constraints:
// 2 ≤ N ≤ 5
// 0 ≤ m[i][j] ≤ 1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

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
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends