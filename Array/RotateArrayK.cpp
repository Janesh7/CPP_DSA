
// Rotate array
// Easy
// yellow-spark
// 40/40

// Share

// 244 upvotes
// Problem Statement
// Suggest Edit
// Given an array with N elements, the task is to rotate the array to the left by K steps, where K is non-negative.
// Detailed explanation ( Input/output format, Notes, Images )

// Input Format:
// The first line contains an integer N representing the size of the array.

// The second line contains N space-separated integers representing the elements of the array.

// The last line contains an integer K representing the number of times the array has to be rotated in the left direction. 
// Output Format:
// The only line of the output prints N space-separated integers representing the Rotated array elements.
// Constraints:
// 1 <= N <= 10^3
// 1 <= arr[i] <= 10^9
// 1 <= K < N
// Sample Input:
// 8
// 7 5 2 11 2 43 1 1
// 2
// Sample Output:
// 2 11 2 43 1 1 7 5
// Explanation Of Sample Input:
// Rotate 1 steps to the left: 5 2 11 2 43 1 1 7
// Rotate 2 steps to the left: 2 11 2 43 1 1 7 5

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{

    // Write your code here

    int n, step;
    cin >> n;
    int arr[n], ar[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> step;

    // reverse the array

    for (int i = 0; i < n - step; i++)

    {
        ar[i] = arr[step + i];
    }

    for (int i = 0; i < step; i++)

    {
        ar[n + i - step] = arr[i];
    }

    for (int i = 0; i < n; i++)

    {
        cout << ar[i] << " ";
    }

    cout << endl;

    return 0;
}
