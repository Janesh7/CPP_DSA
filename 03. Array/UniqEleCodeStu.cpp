#include<iostream>
using namespace std;

// - Unique element Code Stduio Prob statement: Given an array,which has n elements(2m+1 elements). Where all elements appear exactly twice and there is exactly 1 elememt which appears only once .ie how 2m+1 where m is the number of duplicate elements.

// - optiomized solution:
//     - We kmnow that a^a = 0 ie XOR of the dsame element is always 0
//     - So if we XOR all the elements we will get the single remaining element as 0^0^0^0^a = 0^a = a, where there were 4 ele having duplicates (8 ele)which gave the result 0s upon XORing.

int findUnique(int *arr, int size)
{
    //Write your code here
    int ans = 0;
    
    for(int i = 0; i<size; i++ ) {
    	ans = ans^arr[i];
    }
    return ans;
}

int main()
{
    int arr[5]= {2,1,2,1,5};
    int ans = findUnique(arr,5);
    cout<<ans;
    return 0;
}