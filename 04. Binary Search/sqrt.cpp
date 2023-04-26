#include<iostream>
using namespace std;

 long long int sqrtInteger(int n) {
        // using bsearch
        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;
        
        //  In the question we r given int as the value, here we r multiplying int with another int , to not overflow the int limit, we r using long long

        long long int ans = -1;
        while(s<=e) {
            
            long long int square = mid*mid;
            
            if(square == n)
                return mid;
            
            if(square < n ){ // if answer is lower than then the n therefore it has a chance being the sqrt therefore store it , if its greater than the number then no way it can be the sqtt(as the sqrt of n will always be in the range 1-n at max)
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

double morePrecision(int n, int precision, int tempSol) {
    // brute force approach to get more precision
    // we alr have the before decimal part, we can increament the after decimal part ,have a factor to determine the precision required 
    //  ex we can take sqrt of 37 we will have 6 from above function we will start the bf, ie while loo
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}

int main() {
    int n;
    cout <<" Enter the number " << endl;
    cin >> n;

    int tempSol = sqrtInteger(n);
    cout <<" Answer is " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}
