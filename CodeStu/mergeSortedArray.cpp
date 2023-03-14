
// Problem Statement
// Ninja has been given two sorted integer arrays/lists ‘ARR1’ and ‘ARR2’ of size ‘M’ and ‘N’. Ninja has to merge these sorted arrays/lists into ‘ARR1’ as one sorted array. You may have to assume that ‘ARR1’ has a size equal to ‘M’ + ‘N’ such that ‘ARR1’ has enough space to add all the elements of ‘ARR2’ in ‘ARR1’.
// For example:
// ‘ARR1’ = [3 6 9 0 0]
// ‘ARR2’ = [4 10]
// After merging the ‘ARR1’ and ‘ARR2’ in ‘ARR1’. 
// ‘ARR1’ = [3 4 6 9 10]
// Detailed explanation ( Input/output format, Notes, Constraints, Images )

// Constraints:
// 1 <= ‘T’ <= 100
// 1 <= ‘M’, ‘N’ <= 5000
// 1 <= ‘ARR1[i], ARR2[i]’ <= 100000

// Time Limit: 1 second
// Sample Input 1:
// 2
// 3 2
// 1 2 3 0 0 
// 4 5
// 4 2
// 1 4 6 10 0 0
// 2 5
// Sample Output 1:
// 1 2 3 4 5
// 1 2 4 5 6 10
// Explanation for Sample Output 1:
// For sample test case 1: 
// In this test case, After merging ‘ARR2’ into ‘ARR1’. 
// ‘ARR1’ = [1 2 3 4 5]

// For sample test case 2: 
// In this test case, After merging ‘ARR2’ into ‘ARR1’. 
// ‘ARR1’ = [1 2 4 5 6 10] 
// Sample Input 2:
// 2
// 2 3
// 1 10 0 0 0 
// 3 8 11
// 3 3
// 3 4 6 0 0 0
// 1 8 10
// Sample Output 2:
// 1 3 8 10 11
// 1 3 4 6 8 10 
// Explanation for Sample Output 2:
// For sample test case 1: 
// In this test case, After merging ‘ARR2’ into ‘ARR1’. 
// ‘ARR1’ = [1 3 8 10 11]

// For sample test case 2: 
// In this test case, After merging ‘ARR2’ into ‘ARR1’. 
// ‘ARR1’ = [1 3 4 6 8 10]

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