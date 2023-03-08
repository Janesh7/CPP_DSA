
// LC prob 852. 
// Peak Index in a Mountain Array
// Medium

// An array arr a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]
// Output: 1
// Example 2:

// Input: arr = [0,2,1,0]
// Output: 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    int find_pivot(vector<int> v) {
	int s = 0, e = v.size() - 1;
	int mid=(s + e) / 2;
	while (s < e)
	{
		if(v[mid] < v[mid+1])
     			s=mid+1;
    		else
      			e = mid;
    
		mid = (s + e) / 2;
	}
	return s;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return find_pivot(arr);
    }
};

int PeakMontain(int arr[],int n)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    while (start<end)
    {
        if (arr[mid]<arr[mid+1])
            start = mid +1;
        else 
            end = mid;
        mid = start + (end - start)/2;
    } 
    return start;
}
int main()
{
    int arr[10] = {6,7,8,9,10,5,4,3,2,1};
    cout<<PeakMontain(arr,10);
    return 0;
}