// LC prob 1207: 
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int i = 0;
        sort(arr.begin(), arr.end());
        vector<int> ans;
        while (i < arr.size())
        {
            int count = 1;
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] == arr[j])
                    count++;
            }
            ans.push_back(count);
            i = i + count;
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (ans[i] == ans[i + 1])
                return false;
        }
        return true;
    }
};

bool uniqueOccurrences(vector<int> &arr)
{
    vector<int> ans;
    sort(arr.begin(), arr.end());
    int i = 0;
    while (i < arr.size())
    {
        int count = 1;
        int j = i + 1;
        while (arr[i] == arr[j])
        {
            count++;
            j++;
        }
        ans.push_back(count);
        i = j;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        int j = i + 1;
        if (ans[i] == ans[j])
            return false;
    }
    return true;
}
int main()
{
    vector<int> arr = {1, 0};
    cout << uniqueOccurrences(arr);
    return 0;
}