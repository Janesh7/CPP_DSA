#include <bits/stdc++.h> 
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int i=0,j=0,k=0;
	vector<int> temp(arr1);
	while (i<m && j<n)
	{
		if (temp[i]<=arr2[j])
		{
			arr1[k] = temp[i];
			i++;
			k++;
		}
		else{
			arr1[k] = arr2[j];
			j++;
			k++;
		}
	}
	if (i == m)
          while (j < n ) {
            arr1[k] = arr2[j];
			k++;
			j++;
          }
    else
          while (i < m) {
            arr1[k] = temp[i];
			k++;
			i++;
		  }
        return arr1;
}