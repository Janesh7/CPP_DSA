
// Aggressive Cows


// Problem Statement
// Suggest Edit
// You are given an array consisting of 'N' integers which denote the position of a stall. You are also given an integer 'K' which denotes the number of aggressive cows. You are given the task of assigning stalls to 'K' cows such that the minimum distance between any two of them is the maximum possible.
// Detailed explanation ( Input/output format, Notes, Constraints, Images )

// Sample Input 1 :
// 3 2
// 1 2 3
// Sample Output 1 :
// 2
// Explanation To Sample Input 1 :
// The largest minimum distance will be 2 when 2 cows are placed at positions {1, 3}.
// Sample Input 2 :
// 6 4
// 0 3 4 7 10 9
// Sample Output 2 :
// 3
// Explanation To Sample Input 2 :
// The largest minimum distance will be 3 when 4 cows are placed at positions {0, 3, 7, 10}.
// Sample Input 3 :
// 5 2
// 4 2 1 3 6
// Sample Output 3 :
// 5


// IMP : *minimum* distance between any two of them is the maximum possible.
// in a *sorted* vector if n is possi 
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i=0; i<n; i++ ){
        
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
   	int s = 0;
    int n = stalls.size();
    int e=stalls[n-1];
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e) {
        if(isPossible(stalls, k, mid, n)) {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
