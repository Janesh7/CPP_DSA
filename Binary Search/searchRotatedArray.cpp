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

class Solution
{
public:
    int search(vector<int> &arr, int x)
    {
        int low = 0;
        int n = arr.size();
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == x)
            {
                return mid;
            }
            if (arr[low] <= arr[mid])
            {
                if (x >= arr[low] && x <= arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (x >= arr[mid] && x <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};