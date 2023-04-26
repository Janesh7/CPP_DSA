// Code Stu Prob : first and last occurence of the element in a sorted array

// You have been given a sorted array/list ARR consisting of ‘N’ elements. You are also given an integer ‘K’.
// Now, your task is to find the first and last occurrence of ‘K’ in ARR.
// Note :
// 1. If ‘K’ is not present in the array, then the first and the last occurrence will be -1. 
// 2. ARR may contain duplicate elements.
// For example, if ARR = [0, 1, 1, 5] and K = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

// 2
// 6 3
// 0 5 5 6 6 6
// 8 2
// 0 0 1 1 2 2 2 2
// Sample Output 1:
// -1 -1 
// 4 7

#include <vector>
using namespace std;
int firstOcc(vector<int> &arr, int n, int key)
{

    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {

        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1; // Dont return rather ignore the right part by this operation as we r interested in first occ coz that would be on the left side 
        }
        else if (key > arr[mid])
        { // go to Right
            s = mid + 1;
        }
        else if (key < arr[mid])
        { // go to left
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(vector<int> &arr, int n, int key)
{

    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {

        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        { 
            s = mid + 1;
        }
        else if (key < arr[mid])
        { 
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

// Pair is used to connect two value pair. Its values can be used independently using the function first() and second()

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    pair<int, int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);

    return p;
}