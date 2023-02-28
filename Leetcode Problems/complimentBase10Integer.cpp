// LC prob 1009 - The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.
class Solution {
public:
    int bitwiseComplement(int n) {
        
        int m = n;
        int mask = 0;
        
        if(n == 0) // EDGE CASE -ie when n is 0 it should return 1 otherwise it wont go in the while loop only
            return 1;
        
        while( m!=0) {
            mask = (mask << 1) | 1; // Creating a mask like 000...111 where one represents where the digits of the number are, so later it will be ANDed with the negation of the number and would give the solution without having the initial 1's(-ve number rep)
            // mask which is initially all 0's, it is shifted left and 1 is appended as 1 OR anything is 1
            m = m >> 1; // Right shift and remove the last bit, runs till all the bits r gone .. ie the while condition
        }
        
        int ans = (~n) & mask;
        
        return ans;
        
    }
};