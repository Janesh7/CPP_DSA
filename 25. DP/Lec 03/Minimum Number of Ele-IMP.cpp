// Minimum Elements
// Medium

// You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.
// Note:
// You have an infinite number of elements of each type.
// For Example
// If N=3 and X=7 and array elements are [1,2,3]. 
// Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
// Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
// Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
// Hence the output is 3.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 15
// 1 <= nums[i] <= (2^31) - 1
// 1 <= X <= 10000

// All the elements of the “nums” array will be unique.
// Time limit: 1 sec
// Sample Input 1 :
// 2
// 3 7
// 1 2 3
// 1 0
// 1
// Sample Output 1 :
//  3
//  0
// Explanation For Sample Output 1:
// For the first test case,
// Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
// Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
// Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
// Hence the output is 3.

// For the second test case,
// Way 1 - You can take 3 elements  [1, 1, 1] as 1 + 1 + 1  = 3.
// Way 2 - You can take 2 elements  [2, 1] as 2 + 1 = 3.
// Here, you can see in Way 2 we have used 2 coins to reach the target sum of 7.
// Hence the output is 2.
// Sample Input 2 :
// 2
// 3 4
// 12 1 3
// 2 11
// 2 1
// Sample Output 2 :
// 2
// 6 


#include <bits/stdc++.h> 

// 1 Recursion
int recursion(vector<int>& num, int x){
    if(x == 0)
        return 0;

    if(x<0)
        return INT_MAX;
    

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++) {
        int ans = recursion(num, x-num[i]);

        if(ans != INT_MAX){
            mini = min(mini, ans+1);
        }
    }

   return mini;
}

// 2 Recursion with memoizatoin
int recursion_with_memo(vector<int>&num ,int x, vector<int>& dp){

    if(x == 0)
        return 0;

    if(x<0)
        return INT_MAX;
    

    if(dp[x] != -1){
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++) {
        int ans = recursion_with_memo(num, x-num[i]);

        if(ans != INT_MAX){
            mini = min(mini, ans+1);
        }
    }
    
    dp[x] = mini;
    return mini;

}

int minimumElements(vector<int> &num, int x)
{   
    // 1 Recursion
    
    // int recursion_ans = recursion(num, x);
    // return recursion_ans != INT_MAX ? recursion_ans:-1;
    
    // 2 Recursion with memo
    vector<int> dp(x+1, -1);
    int memo_ans = recursion_with_memo(num, x, dp);
    return memo_ans != INT_MAX ? memo_ans:-1;

    
}

// Tabulation
#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;
    for (int j=1;j<=x;j++)
        for(auto i:num)
        {
          if (j - i >= 0) {
            int subproblem = dp[j - i];
            if (subproblem!=INT_MAX)
                dp[j]=min(dp[j],subproblem+1);
          }
        }
    return (dp[x]==INT_MAX)?-1:dp[x];
}