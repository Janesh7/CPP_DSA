// Code Stu prob 3sum
// You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.
// An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

// 1
// 5
// 10 5 5 5 2
// 12

// Sample Output 1:
// 5 5 2
// Explanation For Sample Input 1:
// 5 5 2 is the only triplet that adds up to 15. Note that the order of the output doesn’t matter, so 5 2 5 or 2 5 5 is also acceptable.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// My approach: Having some issues in 1 case where an element (ie 0) which is not present in ^ in somehow considered and (0,2,10) is shown as an extra answer for it,whereas that is not shown in personal compiler
vector<vector<int>> Threesum(vector<int> arr, int n, int s)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    vector<int> a;
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = i + 2;
        while (j < n)
        {
            if (arr[i] + arr[j] + arr[k] > s)
            {
                k = ++j + 1;
                continue;
            }
            else if (arr[i] + arr[j] + arr[k] == s)
            {
                vector<int> temp;
                int flag = 1;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[k]);
                for (int i = 0; i < ans.size(); i++)
                    if (ans[i][0] == temp[0] && ans[i][1] == temp[1] && ans[i][2] == temp[2])
                    {
                        flag = 0;
                    }
                if (not(flag))
                {
                    k++;
                    continue;
                }
                ans.push_back(temp);
                continue;
            }
            else if (k < n)
            {
                k++;
            }
            else
                k = ++j + 1;
        }
    }
    if (ans.size() == 0)
        cout << -1;
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < 3; j++)
                cout << ans[i][j];
            cout << endl;
        }
        return ans;
    }
}

int main()
{
    // vector<int> ar ={9, 5, -20, -70, 2, 1, 82, 1, 4, 8, 55, -100 };
    vector<int> ar = {10, 5, 5, 5, 2};
    // vector<int> ar = {1,1,2,2,1,1};
    // vector<int> ar = {-26 ,32 ,4 ,17, -16, 18, 1, 8, 6, 8, 3, -13 };
    vector<vector<int>> a = Threesum(ar, 5, 12);
    return 0;
}

// Optimised approach using 2 pointer approach

vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{

    vector<vector<int>> ans;

    sort(arr.begin(), arr.end()); // sort the input array

    for (int i = 0; i < n - 2; i++)
    {

        int left = i + 1;

        int right = n - 1;

        while (left < right)
        {

            int sum = arr[i] + arr[left] + arr[right];

            if (sum == K)
            {

                vector<int> temp = {arr[i], arr[left], arr[right]};

                ans.push_back(temp);

                left++;

                right--;

                // Ignore duplicate values for the second element
                //  Since it cant have same left value aswell

                while (left < right && arr[left] == arr[left - 1])
                {

                    left++;
                }

                // Ignore duplicate values for the third element
                //  Since it cant have same right value aswell

                while (left < right && arr[right] == arr[right + 1])
                {

                    right--;
                }
            }
            else if (sum < K)
            {

                left++;
            }
            else
            {

                right--;
            }
        }

        // Ignore duplicate values for the first element

        while (i + 1 < n && arr[i] == arr[i + 1])
        {

            i++;
        }
    }

    return ans;
}