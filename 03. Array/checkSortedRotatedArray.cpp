
#include<bits/stdc++.h>
using namespace std;


// Appproach: There are 3 cases:
// - It is an sorted array for ex {1,2,3,4,5}
// If we check all the adj elements (circularly) then we find that ar[i-1]>ar[i] is true for only 1 instance ie for 5,1 for the last element
// - It is rotated and sorted for ex {3,4,5,1,2}
// If we check all the adj elements (circularly) then we find that ar[i-1]>ar[i] is true for only 1 instance ie for 5,1 
// - It is not rotated and sorted ex {1,3,5,4,2}
// Here more than 1 case exist which are true for ar[i-1]>ar[i] 

// Hence we conclude that if there are more than one case for ar[i-1]>ar[i] then it is not rotated sorted

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for(int i=1;i<nums.size();i++)  // start from i=1 coz for 0 i-1 -> neg value
        {
            if(nums[i] < nums[i-1])
                cnt++;
        }
        if(nums[nums.size()-1] > nums[0]) // last element
            cnt++;
        
        return cnt<=1;
        // earlier was cnt == 1 but if we take a case where {1,1,1} cnt = 0 for this, hence we do cnt<=1
    }
};