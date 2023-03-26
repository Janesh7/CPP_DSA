
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        
        //Transpose of matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(m[i][j],m[j][i]);
            }
        }
        
        // reverse the matrix
        for(int i=0;i<n;i++)
        {
            reverse(m[i].begin(),m[i].end());
        }
        
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
