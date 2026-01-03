// Count derangements
// Medium

// A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.
// Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.
// Note:
// The answer could be very large, output answer %(10 ^ 9 + 7).
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 3000

// Time limit: 1 sec
// Sample Input 1:
// 2
// 2
// 3
// Sample Output 1:
// 1
// 2
// Explanation Of Sample Output 1:
// In test case 1, For two elements say {0, 1}, there is only one possible derangement {1, 0}. 1 is present at index 0 and not at its actual position, that is, 1. Similarly, 0 is present at index 1 and not at its actual position, that is, 0.

// In test case 2, For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}. In both the derangements, no element is present at its actual position.
// alt text

// Sample Input 2:
// 2
// 1
// 4
// Sample Output 2:
// 0
// 9
// Explanation Of Sample Output 2:
// In test case 1, For the array = {0}, there is no possible derrangements. Hence the answer is 0 (zero).

// In test case 2, For the array elements = {0, 1, 2, 3}, total 9 derrangements are possible. One of them is: { 3, 2, 1, 0}.


#define MOD 1000000007
#include<bits/stdc++.h>
// 1 Recursion
long long int recursion(int n){
    if(n == 1) return 0;
    if(n == 2) return 1;

    long long int ans = (n-1) * (recursion(n-1) + recursion(n-2));
    return ans %  MOD;
}

// 2 Recursion With Memoization
long long int RecursionWithMemoization(int n, vector<int>& dp){
    if(n == 1) return 0;
    if(n == 2) return 1;

    if(dp[n] != -1){
        return dp[n];
    }

    long long int ans = (n-1) * (RecursionWithMemoization(n-1, dp) + RecursionWithMemoization(n-2, dp));
    return dp[n] = ans %  MOD;
}

// 3 Tabulation
long long int Tabulation(int n){
    vector<int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        long long int ans = (i-1) * (dp[i-1] + dp[i-2]);
        dp[i] = ans %  MOD;
    }

    return dp[n];

}

// 4 Space Optimization
long long int SpaceOptimization(int n){
    if(n == 1 ) return 0;
    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i=3; i<=n; i++){
        long long int ans = (i-1) * (prev1 + prev2);
        prev2 = prev1;
        prev1 = ans % MOD;
    }

    return prev1;
}

long long int countDerangements(int n) {
    
    //1 Recursion
    // return recursion(n);

    //2 Recursion with Memoization
    // vector<int> dp(n+1, -1);
    // return RecursionWithMemoization(n, dp);

    //3 Tabulation
    // return Tabulation(n);

    //4 Space Optimization
    return SpaceOptimization(n);
}

/*
Formulation Understanding
example : 2|3|4

agr hum 2 ke liye spaces dekhe to case bnenge
Case 1: _|2|_
Case 2: _|_|2

total n-1 spaces for 2

aur ab 3 ko place krne ka dekhe to 3 ke pass 
Case 1 me 2 places hai, means all total n-1
aur Case 2 me bs 1, 1 kyo?? kyoki 3 ko uski original place pr rakh nhi skte hai hum to uske pass ab n-2
places bache 
to overall dekha jaye to 
(n-1) original ke liye aur sub problems ke liye ya to vo (n-1)->sabhi places pr ja skte hai ya (n-2) apni vo fixed palce ko chhodkr kahi pr bhi 
aur computer me OR ka mtlb hota hai +

to formula derive huya asnwer = (n-1) * {recursion(n-1) + recursion(n-2)};
Source: https://youtu.be/WJRin3A9Vjc?t=446
*/