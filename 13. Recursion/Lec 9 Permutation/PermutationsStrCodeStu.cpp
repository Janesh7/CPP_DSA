// Permutations of a String

// Medium

// Problem Statement
// Suggest Edit
// You are given a string 'STR' consisting of lowercase English letters. Your task is to return all permutations of the given string in lexicographically increasing order.
// String A is lexicographically less than string B, if either A is a prefix of B (and A ≠ B), or there exists such i (1 <= i <= min(|A|, |B|)), that A[i] < B[i], and for any j (1 <= j < i) A[i] = B[i]. Here |A| denotes the length of the string A.
// For example :
// If the string is “bca”, then its permutations in lexicographically increasing order are { “abc”, “acb”, “bac”, “bca”, “cab”, “cba” }.
// Note:
// Given string contains unique characters.
// Detailed explanation ( Input/output format, Notes, Images )

// Constraints :
// 1 <= T <= 5
// 1 <= |STR| <= 9

// Where |STR| is the length of the string.

// Time Limit: 1 sec
// Sample Input 1:
// 3
// abc
// bc
// c
// Sample Output 1:
// abc acb bac bca cab cba
// bc cb
// c
// Explanation For Sample Input 1:
// In the 1st test case, there are 6 permutations of the given string.
// In the 2nd test case, there are 2 permutations of the given string.
// In the 3rd test case, there is only 1 permutation of the given string.
// Sample Input 2:
// 1
// xyz
// Sample Output 2:
// xyz xzy yxz yzx zxy zyx 


#include<bits/stdc++.h>
void solve(string nums, vector<string> &ans, int index) {
    if (index>=nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = index;i<nums.size();i++)
    {
        swap(nums[i],nums[index]);
        solve(nums,ans,index+1);
        swap(nums[i],nums[index]);
    }
}
vector<string> generatePermutations(string &str)
{
    // write your code here
    vector<string> ans;
    solve(str,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}