// Merge Sort


// Problem Statement
// Suggest Edit
// Given a sequence of numbers ‘ARR’. Your task is to return a sorted sequence of ‘ARR’ in non-descending order with help of the merge sort algorithm.
// Example :
// Merge Sort Algorithm -

// Merge sort is a Divide and Conquer based Algorithm. It divides the input array into two-parts, until the size of the input array is not ‘1’. In the return part, it will merge two sorted arrays a return a whole merged sorted array.
// subsequence

// The above illustrates shows how merge sort works.
// Note :
// It is compulsory to use the ‘Merge Sort’ algorithm.
// Detailed explanation ( Input/output format, Notes, Images )

// Constraints :
// 1 <= T <= 50
// 1 <= N <= 10^4
// -10^9 <= arr[i] <= 10^9

// Time Limit : 1 sec
// Sample Input 1 :
// 2
// 7
// 3 4 1 6 2 5 7
// 4
// 4 3 1 2
// Sample Output 1 :
// 1 2 3 4 5 6 7
// 1 2 3 4
// Explanation For Sample Input 1:
// Test Case 1 :

// Given ‘ARR’ : { 3, 4, 1, 6, 2, 5, 7 }

// Then sorted 'ARR' in non-descending order will be : { 1, 2, 3, 4, 5, 6, 7 }. Non-descending order means every element must be greater than or equal to the previse element.

// Test Case 2 :

// Given ‘ARR’ : { 4, 3, 1, 2 }

// Then sorted 'ARR' in non-descending order will be : { 1, 2, 3, 4 }. 
// Sample Input 2 :
// 2
// 4
// 5 4 6 7
// 3
// 2 1 1
// Sample Output 2 :
// 4 5 6 7
// 1 1 2


void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void ms(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    int mid = (low + high) / 2;
    ms(arr, low, mid);
    ms(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n) { ms(arr, 0, n - 1); }
