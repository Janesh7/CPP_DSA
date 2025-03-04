// LC problem no 191 - Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

// Note:

// Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
// In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.
class Solution {
public:
    int hammingWeight(int n) { // Use unsigned 32 bit integer for leetcode (uint32_t n) to remove compiler error
    
        int count = 0;
        while(n!=0) {
            
            //checking last bit
            if(n&1) { // bitwise AND with the last digit to see if its 1
                count++;
            }
            n = n>>1; // shift right hence move the bit 
        }
        return count;
    }
};