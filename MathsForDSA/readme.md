# Maths for DSA

## Prime number

- basic approach - take numbers from 2-n and if any n%i == 0 return false 
- for a program for counting the primes in 0-n, the above approach will take O(n) for each i in 1-n. therefore TLE for large cases since O(n2)

#### Use Sieve of Eratosthenes approach

Here we take numbers from 0-n, mark all of them as prime except 0,1. Then we go to each prime and then increment the count as well as mark all its multuple as non prime in the range. Go till n.

- TC :
we traversing n array/vector +
we mark 2,3,5,7,11.. multiple as false
(n/2+n/3+n/5+n/7....) => n(1/2+1/3+1/5....) => n* HP of primes (hp of primes -> log(logn))  // Taylor series

<br />
<b> therefore complexity => O(n+ log(logn)) </b>

## GCD/HCF

- Euclid theorem:
gcd(a,b) = gcd(a%b,b) = gcd(a-b,b)

## LCM

wkt, <b>LCM(a,b)*HCF(a,b) = axb</b>
therefore find it using the hcf formula

## Modulu arithmetic

a%n -> [0--->(n-1)] included
- It is imp to read here as for code where output can be really big for example n!, to avoid the overflow they ask to print the answer as <b>(ans modulus 10^9+7)</b>

## Fast exponentiation
- normal approach -> a^b O(b)
- fast exp -> O(logb)
- FAST EXP:
a^b -> (a^(b/2))^2 if b is even
<br/>
    -> (a^(b/2))^2 *a if b is odd
- NOTE: multiply by 1LL to do explicit type conversion to long long int

