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