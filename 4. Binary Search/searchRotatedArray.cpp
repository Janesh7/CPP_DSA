
// LC prob 33. Search in Rotated Sorted Array
// Medium
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findpivot(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1, mid = 0;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
            return mid;
        else if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
            return mid - 1;
        else if (arr[s] >= arr[mid])
            e = mid - 1;
        else
            s = mid;
    }
    return s;
}
int binary(vector<int> &nums, int tar, int s, int e)
{
    int mid = 0;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] == tar)
            return mid;
        else if (nums[mid] < tar)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
int search(vector<int> &nums, int target)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int pivot = findpivot(nums);
    int ans = -1;
    if (target >= nums[0] && target <= nums[pivot])
        ans = binary(nums, target, 0, pivot);
    else
        ans = binary(nums, target, pivot + 1, nums.size() - 1);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // vector<int> arr ={4,5,6,7,0,1,2};
    vector<int> arr = {1, 3};
    cout << search(arr, 1);
}

// More optimum soln

// Intuition
// Need to find sorted part and use binary search in it.

// Approach
// Find sorted part of array.Then check if target lies in that sorted part using binary search. If no, then go to unsorted part and search in its sorted subpart. If yes , return ans else return -1;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0 , e = n-1;

        while(s <= e){
            int mid = s +(e-s)/2;
            if(nums[mid] == target) return mid;
            
            //if left half is sorted 
            if(nums[s] <= nums[mid]){
                // check if target lies in left side
                if(target <= nums[mid] && target >= nums[s]) e = mid-1;
                else s = mid + 1;
            }    
            //if right side is sorted 
            else{
                // check if target lies in right side
                if(target >= nums[mid] && target <= nums[e]) s = mid+1;
                else e = mid-1;
            }
        }
        return -1;
    }
};