// LC problem no 191
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