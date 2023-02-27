
# Decimal to Binary

Basic Algo
- / by 2
- store remainder in answer
- repeat above two steps until n!=0
- reverse answer

## Creating a number(and reverse) from the given bits

1. answer = digit * 10^i + answer

    This formula gives the reverse of the given bits
    Ex. 1,2,3
      answer=0
    - answer=digit*1+ answer
      answer=1+0
      answer=1
    - answer=digit*10 + answer
      answer=2x10 +1
      answer=21
    - answer=digit*100 + answer
      answer=3x100 +21
      answer=321

2. answer = answer*10^i + digit 
    
   This formula gives the answer from  the given bits
   Ex. 
   - answer=1
   - answer=12
   - answer=123
    
      
## Optimized Logic

Better ALgo as for code below
- while neq 0
-     bit = n&1 ie bitwise AND to each bit gives the same bit
-     ans = 10^i*bit + answer

NOTE : The answer is in int for very big int conversion this would give error as its range is between [2^31,2^31 -1] thats why use string 