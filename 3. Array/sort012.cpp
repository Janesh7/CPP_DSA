
// Code Stu problem sort012

// You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.
// Note :
// Try to solve the problem in 'Single Scan'. ' Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.

// 2
// 6
// 0 1 2 2 1 0
// 7
// 0 1 2 1 2 1 2
// Sample Output 1 :
// 0 0 1 1 2 2
// 0 1 1 1 2 2 2

#include <bits/stdc++.h>
using namespace std;
// very simple approach to count the number of  0,1,2 and then replace elements accordingly
void sort012(int *arr, int n)
{
    //   Write your code here
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0) // count number of 0s
            count0++;
        else if (arr[i] == 1) // count number of 1s
            count1++;
        else // count number of 2s
            count2++;
    }
    for (int i = 0; i < count0; i++) // add 0s till the number of zeros
        arr[i] = 0;
    for (int j = count0; j < (count0 + count1); j++) // start from the number of zeros and add 1s till the number of 1s + number of 0s as we r starting from number of 0s
        arr[j] = 1;
    for (int k = (count0 + count1); k < (count0 + count1 + count2); k++) // similiarly this to replace the number of 2s
        arr[k] = 2;
}


// Dutch National Flag Algorithm to sort the array in linear time.

#include <bits/stdc++.h> // non-standard header, includes all standard headers

void sort012(int *arr, int n)
{ // function to sort array of 0's, 1's, and 2's in ascending order

    int low = 0; // pointer to the beginning of the array

    int mid = 0; // pointer to the current element being processed

    int high = 0; // pointer to the end of the array

    // count the occurrences of 0's, 1's, and 2's in the array

    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 0)
        {

            low++;
        }
        else if (arr[i] == 1)
        {

            mid++;
        }
        else
        {

            high++;
        }
    }

    // set the elements of the array in sorted order

    for (int j = 0; j < n; j++)
    {

        if (j < low)
        {

            arr[j] = 0;
        }
        else if (j < low + mid)
        {

            arr[j] = 1;
        }
        else
        {

            arr[j] = 2;
        }
    }
}

// Time complexity: O(n) (two loops that iterate over the array once)

// Space complexity: O(1) (only three pointers are used to keep track of indices)

/*-------------------------------------------------------------------------------------*/

// OPTIMISED SOLN

// Same algorithm with three pointers - low, mid, and high but with SINGLE SCAN

#include <bits/stdc++.h>

void sort012(int *arr, int n)
{

    int low = 0; // pointer to the beginning of the array

    int mid = 0; // pointer to the current element being processed

    int high = n - 1; // pointer to the end of the array

    while (mid <= high)
    { // traverse the array using the mid pointer

        if (arr[mid] == 0)
        { // if the current element is 0, swap it with the element at the low pointer

            std::swap(arr[low], arr[mid]);

            low++;

            mid++;
        }
        else if (arr[mid] == 1)
        { // if the current element is 1, simply increment the mid pointer

            mid++;
        }
        else
        { // if the current element is 2, swap it with the element at the high pointer

            std::swap(arr[mid], arr[high]);

            high--; // after swapping the current element with the element at the high pointer,

            // we decrement the high pointer to move it one position to the left

            // since the current element at mid might still need to be swapped again
        }
    }
}

// Time complexity: O(n) (single loop that iterates over the array once)

// Space complexity: O(1) (only three pointers are used to keep track of indices)