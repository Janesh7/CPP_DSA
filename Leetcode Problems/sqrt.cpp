
// 69. Sqrt(x)
// Easy
// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

#include<iostream>
using namespace std;

class solution
{
public:
    long long int sqrtInteger(int n)
    {
        // using bsearch
        int s = 0;
        int e = n;
        long long int mid = s + (e - s) / 2;

        //  In the question we r given int as the value, here we r multiplying int with another int , to not overflow the int limit, we r using long long

        long long int ans = -1;
        while (s <= e)
        {

            long long int square = mid * mid;

            if (square == n)
                return mid;

            if (square < n)
            { // if answer is lower than then the n therefore it has a chance being the sqrt therefore store it , if its greater than the number then no way it can be the sqtt(as the sqrt of n will always be in the range 1-n at max)
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};