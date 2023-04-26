
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
	while (s < e) // NOT LESS THAN  EQUAL TO COZ OTHERWISE IT WILL BE ITERATING OVER THE SAME ELEMENT IF = condition is there
	{
		if(v[mid] < v[mid+1]) //Case when mid lies in the left hand slope ie the inclined incrementing slope /
        // since in while loop this condition helps us find s such that element next to it v[mid]>v[mid+1] ie the opposite to the above equation becomes true otherwise go to the else part and reduce the search space
        // therefore it internally forms this eq: if v[mid-1]>v[mid] and v[mid] < v[mid+1] which is the required condition to find the peak (highest) element.
     			s=mid+1;
    		else    // Covers two cases ie when element is in the right hand slope decrementing inclined \ and the case when it could be the peak element aswell that is y no  mid-1 like the other prev prog.
      			e = mid;
    
		mid = (s + e) / 2;
	}
	return s; //RETURN START OR u could even return end.. both will be same .. this is the reasaon why while (s<e) coz everytime they both will be same
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