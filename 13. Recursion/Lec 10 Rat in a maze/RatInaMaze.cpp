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