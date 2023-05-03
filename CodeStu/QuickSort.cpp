
// Quick Sort


// Problem Statement
// Suggest Edit
// You are given an array of integers. You need to sort the array in ascending order using quick sort.
// Quick sort is a divide and conquer algorithm in which we choose a pivot point and partition the array into two parts i.e, left and right. The left part contains the numbers smaller than the pivot element and the right part contains the numbers larger than the pivot element. Then we recursively sort the left and right parts of the array.
// Example:
// Let the array = [ 4, 2, 1, 5, 3 ]
// Let pivot to be the rightmost number.
// example

// After the 1st level partitioning the array will be { 2, 1, 3, 4, 5 } as 3 was the pivot. After 2nd level partitioning the array will be { 1, 2, 3, 4, 5 } as 1 was the pivot for the left part and 5 was the pivot for the right part. Now our array is sorted and there is no need to divide it again.
// Detailed explanation ( Input/output format, Notes, Images )

// Constraints:
// 1 <= T <= 10
// 1 <= N <= 10 ^ 3
// -10 ^ 9 <= ARR[i] <= 10 ^ 9

// Where 'T' is the number of test cases, 'N' is the length of the array 'ARR', and 'ARR[i]' is the array element at index i.

// Time limit: 1 sec.
// Sample Input 1:
// 2
// 5
// 4 2 5 1 3
// 4     
// 6 2 4 1
// Sample Output 1:
// 1 2 3 4 5
// 1 2 4 6
// Explanation Of Input 1:
// Test case 1:
// Given array =  [4, 2, 5, 1, 3]
// Sorted array = [1, 2, 3, 4, 5]

// Test case 2:
// Given array =  [6, 2, 4, 1]
// Sorted array = [1, 2, 4, 6]
// Sample Input 2:
// 2
// 5 
// 5 3 2 6 4
// 4
// 1 2 3 4
// Sample Output 2:
// 2 3 4 5 6
// 1 2 3 4


#include <bits/stdc++.h> 
int partion(vector<int> &arr,int s, int e)
{
    int count = 0;
    int pivot = arr[s];
    for (int i=s+1;i<=e;i++)
        if (arr[i]<=pivot)
            count++;
    
    swap(arr[s],arr[s+count]);
    int pivotIndex = s+count;
    int i = s,j=e;
    while (i<pivotIndex && j>pivotIndex)
    {
        while (arr[i] <= pivot)
            i++;
        
        while (arr[j] > pivot)
            j--;
        if (i<pivotIndex && j>pivotIndex)
            swap(arr[i++],arr[j--]);
    }
    return pivotIndex;
}
void qSort(vector<int> &arr,int s,int e)
{
    if (s>=e)
        return;
    int p;
    p = partion(arr,s,e);
    qSort(arr,s,p-1);
    qSort(arr,p+1,e);
}
vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    qSort(arr,0,arr.size()-1);
    return arr;
}
