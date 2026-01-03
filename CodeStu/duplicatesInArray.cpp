// Code Studio prob: Duplicate in Array
// Given an arr with size n,and given that it always conist elements from 1..n-1 elements and a duplicate int between it, find the duplicate element
// Ex. array of size 5: [1,2,4,3,4] , ans : 4

// Approach:
//  we first xor all the elements of the array and then xor from 1 to N-1, this will cancel out all the 1-N-1 present in the array and give the duplicate int as answer
//  illustration: [1,2,3,4......X,......N-1,X] so 
//             XOR
//                [1,2,3,4......X.......N-1]
//                 00000000000000000000000 ^X = X as answer 
#include<vector>
using namespace std;
int findDuplicate(vector<int> &arr) 
{
    int ans = 0;
    
    //XOR ing all array elements
    for(int i = 0; i<arr.size(); i++ ) {
    	ans = ans^arr[i];
    }
	
    //XOR [1, n-1]
    for(int i = 1; i<arr.size();i++ ) {
    	ans = ans^i;
    }
    return ans;
}
