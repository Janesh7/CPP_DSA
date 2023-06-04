// 1822. Sign of the Product of an Array

// Easy

// There is a function signFunc(x) that returns:

// 1 if x is positive.
// -1 if x is negative.
// 0 if x is equal to 0.
// You are given an integer array nums. Let product be the product of all values in the array nums.



// If element 0 found than return 0;
// keep a track for negative element
// if negative elements are odd return -1
// else return 1;

return signFunc(product).
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int x = 0;
        for(auto &i: nums){
            if(i<0)x ^= 1;
            else if(i==0)return 0;
        }
        if(x)return -1;
        return 1;
    }
};