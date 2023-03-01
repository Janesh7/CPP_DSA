// LC prob 231 - Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

//Alternative easy approach: If the number of set bits in the number is 1 -> then its a power of two

#include<limits.h>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int ans = 1; //for i=0
        // Using a simple brute force method - calculating all the powers of 2 (from 0 to 31 (max int range)) and comparing with the given number 
        for(int i = 0; i <= 30; i++) { // we r multiplying at last so only till 30 so 2^31 is calculated
            
            if(ans == n) // if the calculated 2 power is equal to the number
            {
                return true;
            }
            if(ans < INT_MAX/2) // Check for overflow 
            ans = ans * 2;   // Just multiply the answer with 2,( we r storing the previous answer for efficiency) rather than using pow() method
            
        }
        return false;
    }
};