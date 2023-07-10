// 326. Power of Three
// Easy
// 2.7K
// 252
// Companies
// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.

 

// Example 1:

// Input: n = 27
// Output: true
// Explanation: 27 = 33
// Example 2:

// Input: n = 0
// Output: false
// Explanation: There is no x where 3x = 0.
// Example 3:

// Input: n = -1
// Output: false
// Explanation: There is no x where 3x = (-1).
 

// Constraints:

// -231 <= n <= 231 - 1
 

// Follow up: Could you solve it without loops/recursion?


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0 || n == 2) return false;
        long long x =1; 
        while(x <= n){
            if(x == n) return true;
            else{
                x = x * 3;
            }
        }
        return false;
        
    }
};


// MATH APPROACH: 

// 1162261467 is the largest integer power of 3. so if n is power of 3 it definitely divides 1162261467.
// Hope you understand it.
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};