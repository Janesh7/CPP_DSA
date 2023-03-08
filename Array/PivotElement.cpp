
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int s = 0, n = nums.size();
        int sum = 0, lsum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        for (int i = 0; i < n; i++)
        {
            if (lsum == sum - lsum - nums[i])
                return i;
            lsum += nums[i];
        }
        return -1;
    }
};