

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i =0;
        for (int j = 0; j<nums.size();j++)
        {
            if (nums[j] != 0) {
                swap(nums[j],nums[i]);
                i++;
            }
        }
    }
};