// Painter's Partition Problem


// Problem Statement
// Suggest Edit
// Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under a constraint that any painter will only paint the continuous sections of boards.
// For Example :
// In the below figure where array/list elements are {2, 1, 5, 6, 2, 3}.
// alt text

// A painter can paint blocks {5,6} or {1,5,6,2} together but not {2,5,6} or {5,6,3}.
// Detailed explanation ( Input/output format, Notes, Constraints, Images )

// Sample Input 1 :
// 2
// 4 2
// 5 5 5 5
// 4 2
// 10 20 30 40
// Sample Output 1 :
// 10
// 60
// Explanation For Sample Input 1 :
// In the first test case, we can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.


// In the second test case, we can divide the first 3 boards for one painter and the last board for the second painter.
// Sample Input 2 :
// 2
// 2 2
// 48 90
// 4 2
// 1 2 3 4
// Sample Output 2 :
// 90
// 6

#include<bits/stdc++.h>
bool isPossible(vector<int> &boards,int mid, int k)
{
    int painter = 1;
    int sum = 0;
    for (int i =0; i< boards.size() ; i++) {
        if ( sum + boards[i] <= mid )
            sum += boards[i];
        else {
            painter++;
            if (painter>k || boards[i]> mid)
                return false;
            sum = boards[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s = 0, n = boards.size() ;
    int sum = 0;
    for (int i = 0; i<n ; i++)
        sum += boards[i];
    int e = sum,ans =-1;
    int mid = s + (e-s)/2;
    while (s<=e)
    {
        if (isPossible(boards,mid,k))
        {
            ans = mid;
            e = mid - 1;
        }
        else 
            s = mid + 1;
        mid = s + (e-s)/2;
    }
    return ans;
}