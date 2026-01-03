// Binary Search


// Problem Statement
// Suggest Edit
// You have been given a sorted(in ascending order) integer array/list('nums') of size N and an element 'target'. Your task is to return the index of the element 'target' in the array 'nums'. If the element is not present in the array/list, then return -1.
// Example:
// Input: ‘N’ = 7 ‘target’ = 3
// ‘A’ = [1, 3, 7, 9, 11, 12, 45]

// Output: 1

// Explanation: For nums = [1, 3, 7, 9, 11, 12, 45],
// The index of element '3' is 1.
// Hence, the answer is '1'.
// Detailed explanation ( Input/output format, Notes, Images )

// Constraints :
// 1 <= N <= 10^4
// 1 <= nums[i] <= 10^9
// 1 <= target <= 10^9
// Time Limit: 1 sec
// Sample Input 1:
// 7
// 1 3 7 9 11 12 45
// 3
// Sample Output 1:
// 1
// Explanation Of Sample Output 1:
// For nums = [1, 3, 7, 9, 11, 12, 45],
// The index of element '3' is 1.
// Hence, the answer is '1'.
// Sample Input 2:
// 7
// 1 2 3 4 5 6 7
// 9
// Sample Output 2:
// -1
// Explanation Of Sample Output 2:
// For nums = [1, 2, 3, 4, 5, 6, 7],
// Element '9' doesn't exist.
// Hence, the answer is '-1'.


int binarySearch(vector<int>& arr, int s, int e , int k ) {

    //base case

    //element not found
    if(s>e)
        return -1;

    int mid = s + (e-s)/2;

    //element found
    if(arr[mid] == k)
        return mid;

    if(arr[mid] < k) {
        return binarySearch(arr, mid+1, e, k);
    }
    else{
        return binarySearch(arr, s, mid-1, k);
    }
}


int search(vector<int>& nums, int target) {
    // Write Your Code Here
    return binarySearch(nums,0,nums.size(),target);
}