
// 48. Rotate Image

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
// Example 2:


// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        //  for 1 2 3
		//      4 5 6
		//  	7 8 9

        //Transpose of matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(m[i][j],m[j][i]);
            }
        }
		// gives
		// 		1 4 7 
		// 		2 5 8 
		// 		3 6 9
        
        // reverse the matrix
        for(int i=0;i<n;i++)
        {
            reverse(m[i].begin(),m[i].end());
        }
		//  gives
		// 7 4 1 
		// 8 5 2 
		// 9 6 3

		//  if reverse operation is done on normal 1 2 3 matrix it gives
		// 		3 2 1
		//		6 5 4
		// 		9 8 7
        
    }
};
// 
// 
int main()
{
	vector<vector<int>> m{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}};
	int n = m.size();

	// Transpose of matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			swap(m[i][j], m[j][i]);
		}
	}
	for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cout << m[row][col] << " ";
        }
        cout << endl;
    }
	cout<<endl;

	// reverse the matrix
	for (int i = 0; i < n; i++)
	{
		reverse(m[i].begin(), m[i].end());
	}
	for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cout << m[row][col] << " ";
        }
        cout << endl;
    }
}
