# Maths for DSA

## Prime number

- basic approach - take numbers from 2-n and if any n%i == 0 return false 
- for a program for counting the primes in 0-n, the above approach will take O(n) for each i in 1-n. therefore TLE for large cases since O(n2)

#### Use Sieve of Eratosthenes approach

Here we take numbers from 0-n, mark all of them as prime except 0,1. Then we go to each prime and then increment the count as well as mark all its multuple as non prime in the range. Go till n. therefore TC O(n).